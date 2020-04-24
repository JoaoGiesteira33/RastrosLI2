#include "camadadados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lista.h"
#define BUF_SIZE 1024

/*
    0 -1 -2 -3 -4 -5 -6 -7
    1  0 -1 -2 -3 -4 -5 -6
    2  1  0 -1 -2 -3 -4 -5
    3  2  1  0 -1 -2 -3 -4
    4  3  2  1  0 -1 -2 -3
    5  4  3  2  1  0 -1 -2
    6  5  4  3  2  1  0 -1
    7  6  5  4  3  2  1  0
*/

int avaliaEstado(ESTADO *e) {
//FAZER FUNÇAO AUXILIAR PARA IR BUSCAR ESTAS COORDENADAS @CORONA
    int c = e->ultima_jogada.coluna;
    int l = e->ultima_jogada.linha;

    if(c == l)
        return 0;
    else if(c>l)
        return l-c;
    else
        return l-c;

}

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

int jogar (ESTADO *estado, COORDENADA c)
{
    //Pode jogar
    if (verifica_movimentos(estado, c) && verifica_vazio(estado,c) && !(jogada_final(estado, c))) {
        funcao_jogada (estado,c);
    }
    else  // Casos para congratular o jogador
    {
        int jogador = obter_jogador_atual(estado);

        if (c.coluna == 0 && c.linha == 7) {
             set_jogador_vencedor(estado, 1);
             altera_estado_casa_branca(estado, c);
             altera_estado_casa_preta(estado, get_ultima_jogada(estado));
             altera_ultimajogada(estado, c);
            }       //no caso de chegar a casa final do Jogador 1

            else if (c.coluna == 7 && c.linha == 0) {
                     set_jogador_vencedor(estado, 2);
                     altera_estado_casa_branca(estado, c);
                     altera_estado_casa_preta(estado, get_ultima_jogada(estado));
                     altera_ultimajogada(estado, c);
            }       //no caso de chegar a casa final do Jogador 2

            else if (encurralado(estado) && (jogador == 0)) {
                     set_jogador_vencedor(estado, 2);
            }
           //nos casos de os Jogadores se encontrarem rodeados, ou sejam, sem possiblidades de jogarem
            else if (encurralado(estado) && (jogador == 1)) {
                     set_jogador_vencedor(estado, 2);
            }
            else
                     printf("A jogada nao é válida, tente novamente\n");
    }

        return 0;
}
