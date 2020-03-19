#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "camadadados.h"
#define BUF_SIZE 1024

/**
 @file interface.c
 Interpretador e funcões complementares a este.
 */

/**
\brief Funcao que inicializa o tabuleiro.
*/
 void mostrar_tabuleiro (ESTADO estado){

    int j, i;
    for (j = 0; j <= 7; j++)
    {
        for (i = 0; i <= 7; i++)
        {   COORDENADA c = {i,j};
            switch (obter_estado_casa (&estado, c))
            {
                case PRETA:
                    printf("#");
                    break;
                case VAZIO:
                    printf(".");
                    break;
                case BRANCA:
                    printf("*");
                    break;
            }
        }
        putchar ('/n');
    }
    printf("\n Efetue uma Jogada");
}



/**
\brief Funcao que inicializa e permite jogar.
*/
int interpretador(ESTADO *e){

    char linha[BUF_SIZE];
    char col[2], lin[2];

    if ( fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if ( strlen (linha) == 3 && sscanf (linha, "%[a-h]%[1-8]", col, lin) == 2)
    {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar (e, coord);
        mostrar_tabuleiro (*e);
    }
    return 1;
}

