
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Bot.h"

void inicializatab (ESTADO *e) {

    set_jogador_atual(e, 0);
    set_numero_jogadas(e, 0);
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
    e-> vencedor = 0;
    for (int i =0;i<8;i++){
        for (int j =0;j<8;j++){
            if (i == 7 && j == 0)
                e->tab[i][j] = DOIS;
            else if (i == 0 && j == 7)
                e->tab[i][j] = UM;
            else e->tab[i][j] = VAZIO;
        }
    }

    e->tab[4][3] = BRANCA;
    for(int i = 0; i < 32; i++) {
        e->jogadas[i].jogador1.coluna = -1;
        e->jogadas[i].jogador1.linha = -1;
        e->jogadas[i].jogador2.coluna =-1;
        e->jogadas[i].jogador2.linha =-1;
    }
}

ERROS ler (ESTADO* e,char*ficheiro) {
    FILE *fp;
    fp = fopen((ficheiro), "r");

    if (fp == NULL) return ERRO_ABRIR_FICHEIRO;

    char cha;
    COORDENADA coord;
    for (int c = 0; c < 8; c++) {
        for (int l = 0; l < 8; l++) {
            coord = (COORDENADA) {l, c};
            if (fscanf(fp, "%c", &cha) == 1) {

                set_casa(e, coord, cha);
                if (cha == BRANCA) {
                    altera_ultimajogada(e, coord);
                }
            }
        }
        if (fscanf(fp, "%c",&cha) == 1) {
            ;
        }
    }
    COORDENADA testa = {4, 3};  // Caso o tabuleiro ainda nao tenha sido inicializado
    if (get_ultima_jogada(e).coluna == testa.coluna && get_ultima_jogada(e).linha == testa.linha) {
        inicializatab(e);
    }
    else {
        int num_tokens;
        fseek(fp, 74, SEEK_SET);
        int indice = 0;
        set_numero_jogadas(e, 0);
        COORDENADA c1;
        COORDENADA c2;
        int num_jogad;
        char jog1_c, jog2_c;
        int jog1_l, jog2_l;
        char buffer[1024];
        while (fgets(buffer, 1024, fp) != NULL) {
            num_tokens = sscanf(buffer, "%d: %c%d %c%d", &num_jogad, &jog1_c, &jog1_l, &jog2_c, &jog2_l);
            if (num_tokens == 3) { // No caso de a Jogada Estar Incompleta
                c1.coluna = jog1_c - 'a';
                c1.linha = 8 - jog1_l;
                c2.coluna = (-1);
                c2.linha = (-1);
                armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
                set_jogador_atual(e, 1);
            } else {
                c1.coluna = jog1_c - 'a';
                c1.linha = 8 - jog1_l;
                c2.coluna = jog2_c - 'a';
                c2.linha = 8 - jog2_l;
                armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
                set_jogador_atual(e, 0);
                indice++;
            }
        }
        set_numero_jogadas(e,  (indice));
    }
    fclose(fp);
    return OK;
}

ERROS gravar (ESTADO *e,char *ficheiro) { // Funcao para gravar um jogo num ficheiro
    FILE *fp;
    fp = fopen(ficheiro, "w"); // Abre o ficheiro

    COORDENADA coord1;
    COORDENADA coord2;

    if (fp == NULL) return ERRO_ABRIR_FICHEIRO; // Caso nao consigamos abrir um ficheiro
    else {
        char c ='.';
        int i, j;
        for (j = 0; j <= 7; j++) {
            for (i = 0; i <= 7; i++) {
                COORDENADA cord = {i, j};
                switch (obter_estado_casa(e, cord)) { //Grava o Caracter conforme o Estado da Casa
                    case PRETA:
                        c = '#';
                        break;
                    case VAZIO:
                        c = '.';
                        break;
                    case BRANCA:
                        c = '*';
                        break;
                    case DOIS:
                        c = '2';
                        break;
                    case UM:
                        c = '1';
                        break;
                }
                fprintf(fp, "%c", c);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp,"\n");

        int l = 1;
        for (int g = 0; get_coord_coluna(get_coord_jogador1(e,g)) != -1; g++) { // Grava a lista de jogadas
            coord1 = get_coord_jogador1(e,g);
            coord2 = get_coord_jogador2(e,g);

            if (coord2.coluna != -1) { // Grava uma lista de Jogadas Completa
                fprintf(fp, "%02d: %c%d %c%d\n", l, conversorultimajogadacoluna(coord1),conversorultimajogadalinha(coord1),
                                                            conversorultimajogadacoluna(coord2),conversorultimajogadalinha(coord2));
                l++;
            } else { // Caso uma Jogada esteja incompleta
                fprintf(fp, "%02d: %c%d\n", l, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1));
                l++;
            }
        }
        fclose(fp); // Fecha o Ficheiro
    }
    return OK;
}

ESTADO *inicializar_estado() {

    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    set_jogador_atual(e, 0);
    set_numero_jogadas(e, 0);
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
    e-> vencedor = 0;
    for (int i =0;i<8;i++){
        for (int j =0;j<8;j++){
            if (i == 7 && j == 0)
                e->tab[i][j] = DOIS;
            else if (i == 0 && j == 7)
                e->tab[i][j] = UM;
            else e->tab[i][j] = VAZIO;
        }
    }
    e->tab[4][3] = BRANCA;
    for(int i = 0; i < 32; i++) {
        e->jogadas[i].jogador1.coluna = -1;
        e->jogadas[i].jogador1.linha = -1;
        e->jogadas[i].jogador2.coluna =-1;
        e->jogadas[i].jogador2.linha =-1;
    }
    return e;
}

LISTA vizinhos(ESTADO *e,COORDENADA c) {
    LISTA principal = criar_lista();

    COORDENADA *diagECima      = malloc(sizeof(COORDENADA));
    *diagECima = (COORDENADA) {c.coluna-1, c.linha - 1};
    COORDENADA *diagDCima      = malloc(sizeof(COORDENADA));
    *diagDCima = (COORDENADA) {c.coluna+1, c.linha - 1};
    COORDENADA *diagEBaixo     = malloc(sizeof(COORDENADA));
    *diagEBaixo = (COORDENADA) {c.coluna - 1, c.linha + 1};
    COORDENADA *diagDBaixo     = malloc(sizeof(COORDENADA));
    *diagDBaixo = (COORDENADA) {c.coluna + 1, c.linha + 1};
    COORDENADA *direita        = malloc(sizeof(COORDENADA));
    *direita = (COORDENADA) {c.coluna +1, c.linha};
    COORDENADA *esquerda       = malloc(sizeof(COORDENADA));
    *esquerda = (COORDENADA) {c.coluna - 1, c.linha};
    COORDENADA *baixo          = malloc(sizeof(COORDENADA));
    *baixo = (COORDENADA) {c.coluna, c.linha + 1};
    COORDENADA *cima           = malloc(sizeof(COORDENADA));
    *cima = (COORDENADA) {c.coluna, c.linha - 1};

    if (dentroTabuleiro(*diagECima)  && (obter_estado_casa(e,*diagECima)  != PRETA)) principal = insere_cabeca (principal,diagECima);
    if (dentroTabuleiro(*diagEBaixo) && (obter_estado_casa(e,*diagEBaixo) != PRETA)) principal = insere_cabeca (principal,diagEBaixo);
    if (dentroTabuleiro(*diagDCima)  && (obter_estado_casa(e,*diagDCima)  != PRETA)) principal = insere_cabeca (principal,diagDCima);
    if (dentroTabuleiro(*diagDBaixo) && (obter_estado_casa(e,*diagDBaixo) != PRETA)) principal = insere_cabeca (principal,diagDBaixo);
    if (dentroTabuleiro(*esquerda)   && (obter_estado_casa(e,*esquerda)   != PRETA)) principal = insere_cabeca (principal,esquerda);
    if (dentroTabuleiro(*direita)    && (obter_estado_casa(e,*direita)    != PRETA)) principal = insere_cabeca (principal,direita);
    if (dentroTabuleiro(*baixo)      && (obter_estado_casa(e,*baixo)      != PRETA)) principal = insere_cabeca (principal,baixo);
    if (dentroTabuleiro(*cima)       && (obter_estado_casa(e,*cima)       != PRETA)) principal = insere_cabeca (principal,cima);

    return principal;
}
COORDENADA verificaMelhorJogada (LISTA l, ESTADO * e){  //Função Para Verificar Qual o Vizinho Com uma Distancia Menor á casa Vencedora
    double dist;
    COORDENADA melhorCord = {-1,-1};  //Coordenada Iniciada Para Guardar a Melhor Coordenada
    COORDENADA cord;
    COORDENADA um = {0, 7};
    COORDENADA dois = {7,0 };
    double menorDist = 1000; //Variavel Inicializada Com Valor Exagerado para salvaguardar logo o primeiro valor
    //Caso para o Jogador 1
    if (get_jogador_atual(e) == 0) {
        while (l -> valor && l -> prox) {
            cord = *((COORDENADA *) (l->valor));
            dist = sqrt (((cord.coluna - um.coluna) * (cord.coluna - um.coluna)) + ((cord.linha - um.linha) * (cord.linha - um.linha)));
            if (menorDist >= dist && obter_estado_casa(e, cord) == VAZIO) {
                menorDist = dist;
                melhorCord = cord;
            }
            l = l -> prox; //Atualiza a lista
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
            l = l -> prox; //Atualiza a lista
        }
    }
    return melhorCord;
}
void floodfillaux (ESTADO *e, int valores[8][8],COORDENADA c, int valor) {

    LISTA vizinho = vizinhos(e, c);
    while (vizinho->valor != NULL && vizinho->prox != NULL && valor < 9) {
        COORDENADA casa = *(COORDENADA *) (vizinho->valor);
        if (valores[casa.coluna][casa.linha] == -1 || valores[casa.coluna][casa.linha] >= valor)
            valores[casa.coluna][casa.linha] = valor;

        floodfillaux(e, valores, *(COORDENADA *) (vizinho->valor), valor + 1);
        vizinho = vizinho->prox;
    }
    free(vizinho);
}
int floodfillaux1 (ESTADO *e, int valores[8][8]) {
    int r=0;

    LISTA vizinhoaux = vizinhos(e, get_ultima_jogada(e));
    while (vizinhoaux !=NULL && vizinhoaux->prox != NULL && r==0) {
        COORDENADA casaaux = *(COORDENADA *) (vizinhoaux->valor);
        if ((get_valores(valores,casaaux) == -1) || (get_valores(valores,casaaux) == -2)) {

            r = 0;
            vizinhoaux = vizinhoaux->prox;
        }
        else r=1;
    }

    return r;
}
COORDENADA floodfill(ESTADO *e) {
    int valores[8][8];
    set_valores (e, valores);

    if (get_jogador_atual(e) == 0) {
        COORDENADA c = (COORDENADA) {0,7};
        valores[0][7] = 0;
        floodfillaux(e, valores,c,1);
    } else {
        COORDENADA c = (COORDENADA) {7,0};
        valores[7][0] = 0;
        floodfillaux(e,valores,c,1);
    }
    COORDENADA melhorJogada = {-1,-1};

  if (floodfillaux1(e,valores)==0){
     melhorJogada= verificaMelhorJogada (vizinhos(e,get_ultima_jogada(e)), e);

  }else{

    int menor = 50;

    LISTA vizinho = vizinhos (e,get_ultima_jogada(e));

    while (vizinho->valor != NULL && vizinho->prox != NULL) {

        COORDENADA c = * ((COORDENADA *) (vizinho->valor));
        if (get_valores(valores, c) < menor) {
            menor = get_valores(valores, c);
            melhorJogada = c;
            vizinho = proximo (vizinho);
        } else vizinho = proximo (vizinho);
    }}



    return melhorJogada;
}


int encurralado (ESTADO *estado, COORDENADA c) {
    COORDENADA centro = c;

    COORDENADA cima = (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha + 1};

    COORDENADA baixo = (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha - 1};

    COORDENADA direita = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha};

    COORDENADA esquerda = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha};

    COORDENADA diagDBaixo = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha - 1};

    COORDENADA diagEBaixo = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha - 1};

    COORDENADA diagDCima = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha + 1};

    COORDENADA diagECima = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha + 1};


    if ((obter_estado_casa(estado,cima) == PRETA        || (obter_estado_casa(estado,cima) == BRANCA       || !dentroTabuleiro(cima))) &&
        (obter_estado_casa(estado,baixo) == PRETA       || (obter_estado_casa(estado,baixo) == BRANCA      || !dentroTabuleiro(baixo))) &&
        (obter_estado_casa(estado,direita) == PRETA     || (obter_estado_casa(estado,direita) == BRANCA    ||  !dentroTabuleiro(direita))) &&
        (obter_estado_casa(estado,esquerda) == PRETA    || (obter_estado_casa(estado,esquerda) == BRANCA   ||  !dentroTabuleiro(esquerda))) &&
        (obter_estado_casa(estado,diagDBaixo) == PRETA  || (obter_estado_casa(estado,diagDBaixo) == BRANCA ||!dentroTabuleiro(diagDBaixo))) &&
        (obter_estado_casa(estado,diagEBaixo) == PRETA  || (obter_estado_casa(estado,diagEBaixo) == BRANCA ||!dentroTabuleiro(diagEBaixo))) &&
        (obter_estado_casa(estado,diagDCima) == PRETA   || (obter_estado_casa(estado,diagDCima) == BRANCA  || !dentroTabuleiro(diagDCima))) &&
        (obter_estado_casa(estado,diagECima) == PRETA   || (obter_estado_casa(estado,diagECima) == BRANCA  || !dentroTabuleiro(diagECima))) )

        return 1;

    else return 0;
}

int verificaBotFinal(ESTADO *e, COORDENADA c) {
    int r = 0;
    if ((get_jogador_atual(e)==0) && (c.coluna == 0 && c.linha == 7)) r = 1;
    else if ((get_jogador_atual(e)==1) && (c.coluna == 7 && c.linha == 0)) r = 1;
    else if (encurralado(e,c) == 1) r = 1;

    return r;
}

COORDENADA verificaCheckMate(ESTADO *estado) {
    LISTA vizinho = vizinhos(estado,get_ultima_jogada(estado));
    COORDENADA cm = {-1,-1};

    while(vizinho->valor != NULL && ((cm.coluna ==-1 )&&(cm.linha ==-1))) {
        COORDENADA c = * ((COORDENADA *) (vizinho->valor));

        if ((verificaBotFinal(estado,c))==0) vizinho=vizinho->prox;
        else cm= c;
    }
    return cm;
}

int funcao_jogada (ESTADO *estado) { //Funcao que permite efetuar uma jogda

    COORDENADA cm = verificaCheckMate(estado); //Testa se é possivel deixar o jogador inimigo encurralado
    COORDENADA c = {-1,-1};
    //COORDENADA de = {-1,-1};


   //if ((cm.coluna == -1 ) && (cm.linha == -1)) c = floodfill (estado);

    COORDENADA cf = {-1,-1};

    if (!((cm.coluna == -1 )&&(cm.linha == -1))) cf = cm;


    else{
        c = floodfill (estado);
        cf=c;
    }

    altera_estado_casa_branca(estado, cf);
    int n = obter_numero_de_jogadas(estado);

    if (obter_jogador_atual(estado) == 1) set_jogadas_jogador2(estado, cf, n);
    else set_jogadas_jogador1(estado, cf, n);

    COORDENADA preta = get_ultima_jogada(estado);
    altera_estado_casa_preta(estado, preta);
    altera_ultimajogada(estado, cf);

    return 1;
}