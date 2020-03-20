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
    char c;
    int j, i;

    FILE *filepointer;

    filepointer=fopen("fich.txt", "w");

    for (j = 0; j <= 7; j++)
    {
        for (i = 0; i <= 7; i++)
        {   COORDENADA cord = {i,j};
            switch (obter_estado_casa (&estado, cord))
            {
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
            fprintf(filepointer,"%c ",c);
            printf("%c ",c);

        }
        fprintf(filepointer,"\n");
        printf("\n");

    }


    fprintf(filepointer ,"\n PL%d Jogada%d\n", obter_jogador_atual(&estado), obter_numero_de_jogadas(&estado) /*falta a funcao que devolve a as coordenadas da ultima jogada
 * do tipo CharINT (D4, F5)*/);
    fclose(filepointer);
}



/**
\brief Funcao que inicializa e permite jogar.
*/
int interpretador(ESTADO *e){

    char linha[BUF_SIZE];
    char col[2], lin[2];


    mostrar_tabuleiro (*e);

    /*if ( fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if ( strlen (linha) == 3 && sscanf (linha, "%[a-h]%[1-8]", col, lin) == 2)
    {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar (e, coord);
        mostrar_tabuleiro (*e);
    }*/
    return 1;
}

