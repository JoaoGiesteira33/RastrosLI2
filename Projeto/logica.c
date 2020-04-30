#include "camadadados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lista.h"
#define BUF_SIZE 1024
#include <time.h>

/*
    0 -1 -2 -3 -4 -5 -6 -7
    1  0 -1 -2 -3 -4 -5 -6
    2  1  0 -1 -2 -3  # -5
    7  6  #  #  #  #  # -4
    7  6  #  * -1  #     #
    #  #  #  #  #  #  6  7
    1  1  2  3  4  5  6  7
    0  1  2  3  4  5  6  7
*/
int dentroTabuleiro(COORDENADA c)
{
    return (c.linha < 8 && c.linha >= 0 && c.coluna < 8 && c.coluna >= 0);
}
LISTA vizinhos(ESTADO *e,COORDENADA c)
{
    LISTA principal = criar_lista();

    COORDENADA *diagECima     = malloc(sizeof(COORDENADA));
    *diagECima = (COORDENADA) {c.coluna-1, c.linha - 1};
    COORDENADA *diagDCima     = malloc(sizeof(COORDENADA));
    *diagDCima = (COORDENADA) {c.coluna+1, c.linha - 1};
    COORDENADA *diagEBaixo     = malloc(sizeof(COORDENADA));
    *diagEBaixo = (COORDENADA) {c.coluna - 1, c.linha + 1};
    COORDENADA *diagDBaixo     = malloc(sizeof(COORDENADA));
    *diagDBaixo = (COORDENADA) {c.coluna + 1, c.linha + 1};
    COORDENADA *direita     = malloc(sizeof(COORDENADA));
    *direita = (COORDENADA) {c.coluna +1, c.linha};
    COORDENADA *esq     = malloc(sizeof(COORDENADA));
    *esq = (COORDENADA) {c.coluna - 1, c.linha};
    COORDENADA *baixo     = malloc(sizeof(COORDENADA));
    *baixo = (COORDENADA) {c.coluna, c.linha + 1};
    COORDENADA *cima     = malloc(sizeof(COORDENADA));
    *cima = (COORDENADA) {c.coluna, c.linha - 1};

    if (dentroTabuleiro(*diagECima)  && (obter_estado_casa(e,*diagECima)  != PRETA)) principal = insere_cabeca (principal,diagECima);
    if (dentroTabuleiro(*diagEBaixo) && (obter_estado_casa(e,*diagEBaixo) != PRETA)) principal = insere_cabeca (principal,diagEBaixo);
    if (dentroTabuleiro(*diagDCima)  && (obter_estado_casa(e,*diagDCima)  != PRETA)) principal = insere_cabeca (principal,diagDCima);
    if (dentroTabuleiro(*diagDBaixo) && (obter_estado_casa(e,*diagDBaixo) != PRETA)) principal = insere_cabeca (principal,diagDBaixo);
    if (dentroTabuleiro(*esq)        && (obter_estado_casa(e,*esq)        != PRETA)) principal = insere_cabeca (principal,esq);
    if (dentroTabuleiro(*direita)    && (obter_estado_casa(e,*direita)    != PRETA)) principal = insere_cabeca (principal,direita);
    if (dentroTabuleiro(*baixo) && (obter_estado_casa(e,*baixo)  != PRETA)) principal = insere_cabeca (principal,baixo);
    if (dentroTabuleiro(*cima) && (obter_estado_casa(e,*cima)    != PRETA)) principal = insere_cabeca (principal,cima);

    return principal;
}

void floodfillaux (ESTADO *e, int valores[8][8],COORDENADA c, int valor) {

    LISTA vizinho = vizinhos(e, c);
    COORDENADA fil = *(COORDENADA *) (vizinho->valor);
    while (vizinho->valor != NULL && vizinho->prox != NULL && valor < 8) {
            COORDENADA casa = *(COORDENADA *) (vizinho->valor);
            if (valores[casa.coluna][casa.linha] == -1 || valores[casa.coluna][casa.linha] >= valor) {
                valores[casa.coluna][casa.linha] = valor;
            }
            floodfillaux(e, valores, *(COORDENADA *) (vizinho->valor), valor + 1);
            vizinho = vizinho -> prox;
        }
  //  int r = lista_esta_vazia(vizinho);
 //   if (r == 1 ) {
 //       floodfillaux(e, valores, fil, valor + 1);


//    }
    free(vizinho);

/*
    for (int j = 0; j <= 7; j++) {
        printf("%d|", 8 - j);
        for (int i = 0; i <= 7; i++) {
            printf("%d ", valores[i][j]);
        }
        printf("\n");
    }*/
}


COORDENADA floodfill(ESTADO *e){

    int valores[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (e->tab[j][i] == PRETA)
                valores[j][i] = -2;
            else
                valores[j][i] = -1;
        }

    if (get_jogador_atual(e) == 0) {
        COORDENADA c = (COORDENADA) {0,7};
        valores[0][7] = 0;
        floodfillaux(e, valores,c,1);
    } else
    {
        COORDENADA c = (COORDENADA) {7,0};
        valores[7][0] = 0;
        floodfillaux(e,valores,c,1);
    }

    COORDENADA melhorJogada = {-1,-1};
    int menor = 50;

    LISTA vizinho = vizinhos(e,get_ultima_jogada(e));
    while(vizinho->valor != NULL && vizinho->prox != NULL)
    {
        COORDENADA c = * ((COORDENADA *) (vizinho->valor));
        if(valores[c.coluna][c.linha] < menor) {
            menor = valores[c.coluna][c.linha];
            melhorJogada = c;
            vizinho = vizinho->prox;
        } else
            vizinho = vizinho->prox;
    }
    return melhorJogada;
}
/*
int max(int a, int b)
{
    return (a>b ? a : b);
}
int min(int a, int b)
{
    return (a<b ? a : b);
}

int minmax(ESTADO *e, int profundidade, int jogadorMax) {
    if (profundidade == 0 || get_jogador_vencedor(e) != 0)
        return avaliaEstado(e);

    if (jogadorMax) {
        maxEval = -100;
        for (getAllPossiblePlays){
            int eval = minmax(possibleplay1, profundidade - 1, 0);
            int maxEval = max(maxEval, eval);
        }
        return maxEval;
    }else{
        minEval = +100;
        for(getAllPossiblePlays){
            eval = minmax(child, profundidade - 1, 1);
            int minEval = min(minEval, eval);
        }
        return minEval;
    }
}
*/
COORDENADA verificaMelhorJogada (LISTA l, ESTADO * e){
    double dist;
    COORDENADA melhorCord = {-1,-1};
    COORDENADA  cord;
    COORDENADA um = {0, 7};
    COORDENADA dois = {7,0 };
    double menorDist = 1000;

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

int verifica_movimentos (ESTADO *estado, COORDENADA c)
{
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


int verifica_vazio(ESTADO *estado, COORDENADA c) {

    if (obter_estado_casa(estado, c) == VAZIO ||obter_estado_casa(estado, c)  == UM || obter_estado_casa(estado, c) == DOIS)
        return 1;
    else
        return 0;
}


int funcao_jogada (ESTADO *estado, COORDENADA c) {
    //Pode jogar
    altera_estado_casa_branca(estado,c);

    if (obter_jogador_atual(estado) == 0)
        incrementa_numero_jogadas(estado);
    //Atualiza o array de jogadas

    int n = obter_numero_de_jogadas(estado)-1;

    if (obter_jogador_atual(estado) == 0){
        set_jogadas_jogador1(estado, c, n);
    }

    else {
        set_jogadas_jogador2(estado, c, n);
    }

    //Atualiza a peça de onde sai
    COORDENADA preta = get_ultima_jogada(estado);

    altera_estado_casa_preta(estado, preta);
    altera_ultimajogada(estado, c);
    //Atualiza o jogador
    if (get_jogador_atual(estado) == 1)
        set_jogador_atual(estado, 0);
    else
        set_jogador_atual(estado, 1);

    //printf("jogar %d  %d\n", c.linha, c.coluna);
    return 1;

}

int encurralado (ESTADO *estado) {
       //coordenada da peça branca atual

       COORDENADA centro = get_ultima_jogada(estado);

       COORDENADA cima = (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha + 1};

       COORDENADA baixo = (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha - 1};

       COORDENADA direita = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha};

       COORDENADA esquerda = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha};

       COORDENADA diagDBaixo = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha - 1};

       COORDENADA diagEBaixo = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha - 1};

       COORDENADA diagDCima = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha + 1};

       COORDENADA diagECima = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha + 1};


       if ((obter_estado_casa(estado,cima) == PRETA  ||  get_linha_coordenada (cima) == -1) &&
           (obter_estado_casa(estado,baixo) == PRETA ||  get_linha_coordenada(baixo) == -1) &&
           (obter_estado_casa(estado,direita) == PRETA  ||  get_coluna_coordenada (direita) == -1) &&
           (obter_estado_casa(estado,esquerda) == PRETA ||  get_coluna_coordenada (esquerda) == -1) &&
           (obter_estado_casa(estado,diagDBaixo) == PRETA || (get_coluna_coordenada (diagDBaixo) == -1 && get_linha_coordenada(diagDBaixo) == -1)) &&
           (obter_estado_casa(estado,diagEBaixo) == PRETA || (get_coluna_coordenada (diagEBaixo) == -1 && get_linha_coordenada(diagEBaixo) == -1))&&
           (obter_estado_casa(estado,diagDCima) == PRETA || (get_coluna_coordenada (diagDCima) == -1 && get_linha_coordenada(diagDCima) == -1))&&
           (obter_estado_casa(estado,diagECima) == PRETA || (get_coluna_coordenada (diagECima) == -1 && get_linha_coordenada(diagECima) == -1)))
           return 1;
       else return 0;
}

int jogada_final (ESTADO *estado, COORDENADA c) {
     if (c.coluna == 0 && c.linha == 7) {
        return 1;
    }//Casa final do Jogador 1
        else if (c.coluna == 7 && c.linha == 0)
        return 1; //Casa final do Jogador 2
        else {
        if (encurralado(estado) == 1) {
            return 1;}
        else return 0;
    }
}

void jog (ESTADO *e){
    COORDENADA c = get_ultima_jogada (e);

    LISTA principal = criar_lista();



    COORDENADA cima     = (COORDENADA) {.coluna = c.coluna, .linha = c.linha + 1};

    COORDENADA baixo    = (COORDENADA) {.coluna = c.coluna, .linha = c.linha - 1};

    COORDENADA direita  = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha};

    COORDENADA esquerda = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha};

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


    COORDENADA novaCasa = verificaMelhorJogada (principal, e);

    jogar(e,novaCasa);
    mostrar_tabuleiro(e);

}

void jog2(ESTADO *e)
{
    COORDENADA novaCasa = floodfill(e);

    jogar(e,novaCasa);
    mostrar_tabuleiro(e);
}

void posJog(ESTADO *e,int jogada,ESTADO *aux)
{
    *aux = *e;

    int n = 31;
    if (jogada >= obter_numero_de_jogadas(e) || jogada < 0)
    {
        printf("Número de jogada inválida\n");
    } else {

        //printf("Copiou\n");
        set_jogador_atual(aux,0);
        set_numero_jogadas(aux, jogada);
        altera_estado_casa_vazio(aux,get_ultima_jogada(aux));
        altera_ultimajogada_pos(aux, jogada);

        while (n >= jogada)
        {
            COORDENADA x = get_jogadas_jogador1(aux, n);
            COORDENADA y = get_jogadas_jogador2(aux, n);

            altera_estado_casa_vazio(aux, x);
            altera_estado_casa_vazio(aux, y);

            set_casas_invalidas(aux, n);
            n--;
        }

        n = 0;
        if (jogada == 0) {
            aux->ultima_jogada.coluna = 4;
            aux->ultima_jogada.linha = 3;
            aux->tab[4][3] = BRANCA;
        }

        while ( n < jogada )
        {
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


