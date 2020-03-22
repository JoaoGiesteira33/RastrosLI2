#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "camadadados.h"
#define BUF_SIZE 1024




 void mostrar_tabuleiro (ESTADO* estado){
    char c=0;
    int j, i;



    for (j = 0; j <= 7; j++)
    {
        for (i = 0; i <= 7; i++)
        {   COORDENADA cord = {i,j};
            switch (obter_estado_casa (estado, cord))
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



    // falta a funcao que devolve a as coordenadas da ultima jogada do tipo CharINT (D4, F5) conversorultimajogada(obter_ultima_jogada(estado))
    printf("\n PL%d Jogada%d\n Coordenada Anterior %c%d", obter_jogador_atual(estado), obter_numero_de_jogadas(estado),conversorultimajogadacoluna(obter_ultima_jogada(estado)),conversorultimajogadalinha(obter_ultima_jogada(estado)));

}

ERROS gravar(ESTADO *e,char *ficheiro) {
    FILE *fp;
    fp = fopen(ficheiro, "w");

    if (fp == NULL) {
        return ERRO_ABRIR_FICHEIRO;
    }
    else{


        char c ='.';
        int i, j;


        for (j = 0; j <= 7; j++) {
            for (i = 0; i <= 7; i++) {
                COORDENADA cord = {i, j};
                switch (obter_estado_casa(e, cord)) {
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
                fprintf(fp, "%c ", c);


            }
            fprintf(fp, "\n");


        }
        fprintf(fp,"\n PL%d Jogada%d\n Coordenada Anterior %c%d", obter_jogador_atual(e), obter_numero_de_jogadas(e),conversorultimajogadacoluna(obter_ultima_jogada(e)),conversorultimajogadalinha(obter_ultima_jogada(e)));
        fclose(fp);
    }
    return OK;
}

ERROS ler (ESTADO* e,char*ficheiro ){
    FILE*fp;
    fp=fopen(ficheiro,"r");

    if (fp==NULL)
        return ERRO_ABRIR_FICHEIRO;
    else {
        //codigo para ler ficheiro
    }


    fclose(fp);
    return OK;
}

int interpretador(ESTADO *e){

    char linha[BUF_SIZE];
    char col[2], lin[2];

    mostrar_tabuleiro (e);
    if ( fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if ( strlen (linha) == 3 && sscanf (linha, "%[a-h]%[1-8]", col, lin) == 2)
    {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar (e, coord);
        //gravar (e,ficheiro);
        mostrar_tabuleiro (e);
    }
    return 1;
}

