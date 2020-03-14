#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadados.h"

ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *)malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
     for (int i =0;i<8;i++){
         for (int j =0;j<8;j++){
             e->tab[i][j] = VAZIO;
         }


    }
     e->tab[3][4] = BRANCA;

    return e;
}

int obter_jogador_atual(ESTADO *estado)
{
    int jog;
    jog = estado->jogador_atual;
    return jog;
}
int obter_numero_de_jogadas(ESTADO *estado)
{
    int numJogadas;
    numJogadas = estado->num_jogadas;

    return numJogadas;
}
CASA obter_estado_casa(ESTADO *e, COORDENADA c)
{
    CASA casa;
    casa = e->tab[c.linha][c.coluna];
    return casa;
}
