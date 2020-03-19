#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadados.h"

/**
 @file camadadados.c
 Função estado e funções auxiliares a esta.
 */

/**
\brief Função que inicializa o estado inicial.
 */
ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *)malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
     for (int i =0;i<8;i++){
         for (int j =0;j<8;j++){
             if (i == 7 && j == 0)
                 printf("2");
             else if (i == 0 && j == 7)
                 printf("1");
             else e->tab[i][j] = VAZIO;
         }


    }
     e->tab[3][4] = BRANCA;

    return e;
}

/**
\brief Função que devolve o jogador atual.
 */
int obter_jogador_atual(ESTADO *estado)
{
    int jog;
    jog = estado->jogador_atual;
    return jog;
}


/**
\brief Função que devolve o numero de Jogadas.
 */
int obter_numero_de_jogadas(ESTADO *estado)
{
    int numJogadas;
    numJogadas = estado-> num_jogadas;

    return numJogadas;
}

/**
\brief Função que devolve a ultima jogada efetuada.
*/
COORDENADA *obter_ultima_jogada (ESTADO *estado) {

    COORDENADA *ultimajogadafinal;
    ultimajogadafinal -> linha = estado -> ultima_jogada.linha;
    ultimajogadafinal -> coluna = estado -> ultima_jogada.coluna;
    return ultimajogadafinal;

}

char *conversorultimajogada (COORDENADA *c) {

    char s1[2] = {0,((c -> linha)+1)};
    switch (c -> coluna) {
        case 0:
            s1 [0] = 'A';
            break;
        case 1:
            s1 [0] = 'B';
            break;
        case 2:
            s1 [0] = 'C';
            break;
        case 3:
            s1 [0] = 'D';
            break;
        case 4:
            s1 [0] = 'E';
            break;
        case 5:
            s1 [0] = 'F';
            break;
        case 6:
            s1 [0] = 'G';
            break;
        case 7:
            s1 [0] = 'H';
            break;

    }
    return s1;
}

/**
\brief Função que devolve o estado da casa da respetiva coordenada.
 */
CASA obter_estado_casa(ESTADO *e, COORDENADA c)
{
    CASA casa;
    casa = e->tab[c.linha][c.coluna];
    return casa;
}
