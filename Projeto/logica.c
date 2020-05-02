#include "camadadados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lista.h"
#define BUF_SIZE 1024



LISTA vizinhos (ESTADO *e,COORDENADA c) { //Função para obter uma lista com as coordenadas vizinhas e com estado diferente de PRETA
    LISTA principal = criar_lista();

    COORDENADA *diagECima      = malloc(sizeof(COORDENADA));
    *diagECima = (COORDENADA)  {c.coluna-1, c.linha - 1};
    COORDENADA *diagDCima      = malloc(sizeof(COORDENADA));
    *diagDCima = (COORDENADA)  {c.coluna+1, c.linha - 1};
    COORDENADA *diagEBaixo     = malloc(sizeof(COORDENADA));
    *diagEBaixo = (COORDENADA) {c.coluna - 1, c.linha + 1};
    COORDENADA *diagDBaixo     = malloc(sizeof(COORDENADA));
    *diagDBaixo = (COORDENADA) {c.coluna + 1, c.linha + 1};
    COORDENADA *direita        = malloc(sizeof(COORDENADA));
    *direita = (COORDENADA)    {c.coluna +1, c.linha};
    COORDENADA *esquerda       = malloc(sizeof(COORDENADA));
    *esquerda = (COORDENADA)   {c.coluna - 1, c.linha};
    COORDENADA *baixo          = malloc(sizeof(COORDENADA));
    *baixo = (COORDENADA)      {c.coluna, c.linha + 1};
    COORDENADA *cima           = malloc(sizeof(COORDENADA));
    *cima = (COORDENADA)       {c.coluna, c.linha - 1};

    if (dentroTabuleiro(*diagECima)  && (obter_estado_casa(e,*diagECima)  != PRETA)) principal = insere_cabeca (principal,diagECima);
    else free(diagECima);
    if (dentroTabuleiro(*diagEBaixo) && (obter_estado_casa(e,*diagEBaixo) != PRETA)) principal = insere_cabeca (principal,diagEBaixo);
    else free(diagEBaixo);
    if (dentroTabuleiro(*diagDCima)  && (obter_estado_casa(e,*diagDCima)  != PRETA)) principal = insere_cabeca (principal,diagDCima);
    else free(diagDCima);
    if (dentroTabuleiro(*diagDBaixo) && (obter_estado_casa(e,*diagDBaixo) != PRETA)) principal = insere_cabeca (principal,diagDBaixo);
    else free(diagDBaixo);
    if (dentroTabuleiro(*esquerda)   && (obter_estado_casa(e,*esquerda)   != PRETA)) principal = insere_cabeca (principal,esquerda);
    else free(esquerda);
    if (dentroTabuleiro(*direita)    && (obter_estado_casa(e,*direita)    != PRETA)) principal = insere_cabeca (principal,direita);
    else free(direita);
    if (dentroTabuleiro(*baixo)      && (obter_estado_casa(e,*baixo)      != PRETA)) principal = insere_cabeca (principal,baixo);
    else free(baixo);
    if (dentroTabuleiro(*cima)       && (obter_estado_casa(e,*cima)       != PRETA)) principal = insere_cabeca (principal,cima);
    else free(cima);

    return principal;
}

void floodfillaux (ESTADO *e, int valores[8][8],COORDENADA c, int valor) { //Função auxiliar para alterar os valores das casas segundo o algoritmo FloodFill

    LISTA vizinho = vizinhos(e, c); //Calcula a lista de vizinhos segundo uma coordenada
    while ( vizinho->valor != NULL && vizinho->prox != NULL && valor < 9) {
            COORDENADA casa = *(COORDENADA *) (vizinho->valor);
            if (valores[casa.coluna][casa.linha] == -1 || valores[casa.coluna][casa.linha] >= valor) {
                valores[casa.coluna][casa.linha] = valor;
            }
            floodfillaux(e, valores, *(COORDENADA *) (vizinho->valor), valor + 1);
            vizinho = vizinho -> prox;
        }
    free(vizinho);
}

COORDENADA floodfill(ESTADO *e){ //Função que devolve uma Coordenada segundo o Algoritmo FloodFilll

    int valores[8][8];
    set_valores(e,valores); //Inicializa um array de valores a -1

    if (get_jogador_atual(e) == 0) { //Algoritmo FloodFill a iniciar na casa do Jogador 1
        COORDENADA c = (COORDENADA) {0,7};
        valores[0][7] = 0;
        floodfillaux(e, valores,c,1);
    } else { //Algoritmo FloodFill a iniciar na casa do Jogador 2
        COORDENADA c = (COORDENADA) {7,0};
        valores[7][0] = 0;
        floodfillaux(e,valores,c,1);
    }
    COORDENADA melhorJogada = {-1,-1}; // Coordenada Iniciada para Guardar a Possivel Coordenada a Jogar
    int menor = 50; //valor iniciado para ser possivel a partir da primeira atribuição

    LISTA vizinho = vizinhos(e,get_ultima_jogada(e));
    while (vizinho->valor != NULL && vizinho->prox != NULL) {
        COORDENADA c = * ((COORDENADA *) (vizinho->valor));

        if (get_valores(valores, c) < menor) {
            menor = get_valores(valores, c);
            melhorJogada = c;
            vizinho = vizinho->prox;
        } else
            vizinho = vizinho->prox;
    }
    return melhorJogada;
}

COORDENADA verificaMelhorJogada (LISTA l, ESTADO * e){  //Função Para Verificar Qual o Vizinho Com uma Distancia Menor á casa Vencedora
    double dist;
    COORDENADA melhorCord = {-1,-1};    //Coordenada Iniciada Para Guardar a Melhor Coordenada
    COORDENADA cord;
    COORDENADA um = {0, 7};
    COORDENADA dois = {7,0 };
    double menorDist = 1000; // Variavel Inicializada Com Valor Exagerado para salvaguardar logo o primeiro valor
    //Caso para o Jogador 1
    if (get_jogador_atual(e) == 0) {
        while (l -> valor && l -> prox) {
        cord = *((COORDENADA *) (l->valor));
        dist = sqrt (((cord.coluna - um.coluna) * (cord.coluna - um.coluna)) + ((cord.linha - um.linha) * (cord.linha - um.linha)));
        if (menorDist >= dist && obter_estado_casa(e, cord) == VAZIO) {
            menorDist = dist;
            melhorCord = cord;
        }
        l = l -> prox;
        }
    }
    //Caso para o Jogador 2
    if (get_jogador_atual(e) == 1) {
        while (l -> valor && l -> prox) {
            cord = * ((COORDENADA *) (l->valor));
            dist = sqrt (((dois.coluna - cord.coluna) * (dois.coluna - cord.coluna)) + ((cord.linha -  dois.linha) * (cord.linha -  dois.linha)));
            if (menorDist >= dist && obter_estado_casa(e, cord) == VAZIO) {
                menorDist = dist;
                melhorCord = cord;
            }
            l = l -> prox;
        }
    }
    return melhorCord;
}

int verifica_movimentos (ESTADO *estado, COORDENADA c) { // Função para verificar se a casa se encontra na distancia de uma casa, Função Auxiliar da Jog
    int c1, c2, linha1, linha2;
    c1 =  (get_ultima_jogada(estado)).coluna;
    linha1 = (get_ultima_jogada(estado)).linha;
    c2 =  c.coluna;
    linha2 = c.linha;
    if (((abs(c1-c2)== 1) && (abs(linha1-linha2))== 0) || ((abs(c1-c2)== 0) && (abs(linha1-linha2))== 1) || ((abs(c1-c2)== 1) && (abs(linha1-linha2))== 1)) {
        return 1;
    }
    else return 0;
}


int verifica_vazio(ESTADO *estado, COORDENADA c) { //Função para Verificar se uma Casa não se encontra no Estado Preta
    if (obter_estado_casa(estado, c) == VAZIO ||obter_estado_casa(estado, c)  == UM || obter_estado_casa(estado, c) == DOIS)
        return 1;
    else 
        return 0;
}

int funcao_jogada (ESTADO *estado, COORDENADA c) { //Função que efetua uma jogada
    altera_estado_casa_branca(estado,c); //Muda o estado da Coordenada para onde se jogou para Branca

    if (obter_jogador_atual(estado) == 0) incrementa_numero_jogadas(estado); //Atualiza o Numero de Jogadas

    int n = obter_numero_de_jogadas(estado)-1;

    if (obter_jogador_atual(estado) == 0) set_jogadas_jogador1(estado, c, n); //Atualiza a Lista de Jogadas para o Jogador 1
    else set_jogadas_jogador2(estado, c, n); //Atualiza a Lista de Jogadas para o Jogador 2

    COORDENADA preta = get_ultima_jogada(estado);

    altera_estado_casa_preta(estado, preta); //Atualiza a peça de onde sai
    altera_ultimajogada(estado, c); //Atualiza a ultima Jogada

    if (get_jogador_atual(estado) == 1) set_jogador_atual(estado, 0); //Atualiza o Jogador
    else set_jogador_atual(estado, 1);

    return 1;
}

int encurralado (ESTADO *estado) { //Função para detetar se as Casas em redor se encontram todas com o estado PRETA


       COORDENADA centro = get_ultima_jogada(estado);
       COORDENADA cima =       (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha + 1};
       COORDENADA baixo =      (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha - 1};
       COORDENADA direita =    (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha};
       COORDENADA esquerda =   (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha};
       COORDENADA diagDBaixo = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha - 1};
       COORDENADA diagEBaixo = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha - 1};
       COORDENADA diagDCima =  (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha + 1};
       COORDENADA diagECima =  (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha + 1};

       //Testa o Estado das Casas e ao mesmo tempo se se encontram dentro do Tabuleiro, caso que nos garante que funcione nas extremidades do tabuleiro
       if ( (obter_estado_casa(estado,cima) == PRETA       || !dentroTabuleiro(cima)) &&
            (obter_estado_casa(estado,baixo) == PRETA      || !dentroTabuleiro(baixo)) &&
            (obter_estado_casa(estado,direita) == PRETA    || !dentroTabuleiro(direita)) &&
            (obter_estado_casa(estado,esquerda) == PRETA   || !dentroTabuleiro(esquerda)) &&
            (obter_estado_casa(estado,diagDBaixo) == PRETA || !dentroTabuleiro(diagDBaixo)) &&
            (obter_estado_casa(estado,diagEBaixo) == PRETA || !dentroTabuleiro(diagEBaixo)) &&
            (obter_estado_casa(estado,diagDCima) == PRETA  || !dentroTabuleiro(diagDCima)) &&
            (obter_estado_casa(estado,diagECima) == PRETA  || !dentroTabuleiro(diagECima)) )

           return 1;
       else return 0;
}

int jogada_final (ESTADO *estado, COORDENADA c) { //Função para Testar se pretendemos jogar para uma casa vencedora
     if (c.coluna == 0 && c.linha == 7) return 1; //Casa final do Jogador 1
     else if (c.coluna == 7 && c.linha == 0) return 1; //Casa final do Jogador 2
     else if (encurralado(estado) == 1) return 1; //Caso Encurralado
     else return 0;
    }

void jog (ESTADO *e) { //Função que permite jogar segundo o Algoritmo da Distancia Heuclidiana
    COORDENADA c = get_ultima_jogada (e);
    LISTA principal = criar_lista();

    COORDENADA cima       = (COORDENADA) {.coluna = c.coluna, .linha = c.linha + 1};
    COORDENADA baixo      = (COORDENADA) {.coluna = c.coluna, .linha = c.linha - 1};
    COORDENADA direita    = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha};
    COORDENADA esquerda   = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha};
    COORDENADA diagDBaixo = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha - 1};
    COORDENADA diagEBaixo = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha - 1};
    COORDENADA diagDCima  = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha + 1};
    COORDENADA diagECima  = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha + 1};

    if ((obter_estado_casa(e,cima))       == VAZIO) principal = insere_cabeca (principal,&cima);
    if ((obter_estado_casa(e,baixo))      == VAZIO) principal = insere_cabeca (principal,&baixo);
    if ((obter_estado_casa(e,direita))    == VAZIO) principal = insere_cabeca (principal, &direita);
    if ((obter_estado_casa(e,esquerda))   == VAZIO) principal = insere_cabeca (principal, &esquerda);
    if ((obter_estado_casa(e,diagDBaixo)) == VAZIO) principal = insere_cabeca (principal, &diagDBaixo);
    if ((obter_estado_casa(e,diagDCima))  == VAZIO) principal = insere_cabeca (principal, &diagDCima);
    if ((obter_estado_casa(e,diagEBaixo)) == VAZIO) principal = insere_cabeca (principal, &diagEBaixo);
    if ((obter_estado_casa(e,diagECima))  == VAZIO) principal = insere_cabeca (principal, &diagECima);

    COORDENADA novaCasa = verificaMelhorJogada (principal, e); //Coordenada com a menor distancia

    jogar(e,novaCasa);
    mostrar_tabuleiro(e);
}

void jog2(ESTADO *e) { //Função que permite jogar segundo o Algoritmo FloodFill
    COORDENADA novaCasa = floodfill(e);
    jogar(e,novaCasa);
    mostrar_tabuleiro(e);
}

void posJog(ESTADO *e, int jogada, ESTADO *aux) { //Função auxiliar para permitir atualizar o tabuleiro conforme a jogada que pretendemos
    *aux = *e; //inicializa um estado auxiliar
    int n = 31;
    if (jogada >= obter_numero_de_jogadas(e) || jogada < 0) printf("Número de jogada inválida\n"); //Testa se a Jogada que pretendemos ver é valida
    else { // Altera o Estado Auxiliar
        set_jogador_atual(aux,0);
        set_numero_jogadas(aux, jogada);
        altera_estado_casa_vazio(aux,get_ultima_jogada(aux));
        altera_ultimajogada_pos(aux, jogada);

        while (n >= jogada) //Elimina as jogadas superiores há que queremos e complemtentos
        {
            COORDENADA x = get_jogadas_jogador1(aux, n);
            COORDENADA y = get_jogadas_jogador2(aux, n);

            altera_estado_casa_vazio(aux, x);
            altera_estado_casa_vazio(aux, y);

            set_casas_invalidas(aux, n);
            n--;
        }

        n = 0;
        if (jogada == 0) {  //Caso para a Pos 0
            COORDENADA inicial = {4, 3};
            altera_ultimajogada(aux, inicial);
            altera_estado_casa_branca(aux, inicial);
        }
        while ( n < jogada ) { //Atualiza o Estado até a jogada que desejamos
            COORDENADA x = get_jogadas_jogador1 (aux, n);
            COORDENADA y = get_jogadas_jogador2 (aux, n);

            altera_estado_casa_preta (aux , x);
            altera_estado_casa_preta (aux, y);

            n++;
        }

        COORDENADA ult = get_ultima_jogada(aux);
        altera_estado_casa_branca(aux, ult);
    }
    mostrar_tabuleiro(aux);
}


