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
             if (i == 7 && j == 0)
                 e->tab[i][j] = DOIS;
             else if (i == 0 && j == 7)
                 e->tab[i][j] = UM;
             else e->tab[i][j] = VAZIO;
         }


    }
     e->tab[4][3] = BRANCA;

    return e;
}


int obter_jogador_atual(ESTADO *estado)
{
    int jog;
    jog = estado -> jogador_atual;
    return jog;
}



int obter_numero_de_jogadas(ESTADO *estado)
{
    int numJogadas;
    numJogadas = estado-> num_jogadas;

    return numJogadas;
}


COORDENADA obter_ultima_jogada (ESTADO *estado) {

    COORDENADA ultimajogadafinal;
    ultimajogadafinal.linha = estado -> ultima_jogada.linha;
    ultimajogadafinal.coluna = estado -> ultima_jogada.coluna;
    return ultimajogadafinal;

}
int conversorultimajogadalinha (COORDENADA c){
    int linha;
    linha = c.linha +1;
    return linha;
}

char conversorultimajogadacoluna (COORDENADA c) {
    //char *s1 = (char*) malloc(2*sizeof(char));

    char s1 = '0';
   // s1[1]=(char)((c -> linha)+1);
    //char *coord;
   // coord = (char) malloc(2sizeof(char));

    switch (c.coluna) {
        case 0:
            s1 = 'A';
            break;
        case 1:
            s1 = 'B';
            break;
        case 2:
            s1  = 'C';
            break;
        case 3:
            s1  = 'D';
            break;
        case 4:
            s1 = 'E';
            break;
        case 5:
            s1 = 'F';
            break;
        case 6:
            s1 = 'G';
            break;
        case 7:
            s1 = 'H';
            break;

    }
    return s1;
}


CASA obter_estado_casa(ESTADO *e, COORDENADA c)
{
    CASA casa;
    casa = e-> tab[c.coluna][c.linha];
    return casa;
}
