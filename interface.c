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


void lerFicheiro(char *fich)
{
    FILE *fp;
    fp = fopen(fich,"r");

    if(fp == NULL){
        printf("O ficheiro é inexistente.\n");
    }

    char linha[64];

    while(fgets(linha,64,fp) != NULL){
        printf("%s",linha);
    }
    fclose(fp);
}

 void mostrar_tabuleiro (ESTADO estado){
    char c;
    int j, i;



    for (j = 0; j <= 7; j++)
    {
        if(j<=7)
            printf("%d|",j+1);
        for (i = 0; i <= 7; i++)
        {COORDENADA cord = {i,j};
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
            printf("%c ",c);

        }
        printf("\n");

    }
    printf("  a b c d e f g h");

    //fprintf(filepointer ,"\n PL%d Jogada%d\n", obter_jogador_atual(&estado), obter_numero_de_jogadas(&estado));
    // falta a funcao que devolve a as coordenadas da ultima jogada do tipo CharINT (D4, F5)
    printf("\n PL%d Jogada%d\n", obter_jogador_atual(&estado), obter_numero_de_jogadas(&estado));

}

void gravar(ESTADO *e)
{
    FILE *ficheiro  = fopen("fich.txt", "w");

    char c;
    int i,j;

    for (j = 0; j <= 7; j++)
    {
        for (i = 0; i <= 7; i++)
        {   COORDENADA cord = {i,j};
            switch (obter_estado_casa (&e, cord))
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
            fprintf(ficheiro,"%c ",c);


        }
        fprintf(ficheiro,"\n");



    }
    fclose(ficheiro);
}
/**
\brief Funcao que inicializa e permite jogar.
*/
int interpretador(ESTADO *e){

    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nomefich[] = "fich.txt";
    if ( fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if ( strlen (linha) == 3 && sscanf (linha, "%[a-h]%[1-8]", col, lin) == 2)
    {
        COORDENADA coord;
        coord.coluna = *col - 'a';
        coord.linha = *lin - '1';
        printf("boas");
        e =jogar (e, coord);
        mostrar_tabuleiro (*e);
        lerFicheiro(nomefich);
    }
    return 1;
}

