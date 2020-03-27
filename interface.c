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
        printf("%d|",8-j);
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
     printf("  a b c d e f g h");

    printf("\n PL%d Jogada %d\n Coordenada Atual %c%d\n", obter_jogador_atual(estado)+1, obter_numero_de_jogadas(estado),conversorultimajogadacoluna(obter_ultima_jogada(estado)),conversorultimajogadalinha(obter_ultima_jogada(estado)));

}

ERROS gravar(ESTADO *e,char *ficheiro){
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
    fp=fopen(strcat(ficheiro,".txt"),"r");

    char cha;

    if (fp==NULL)
        return ERRO_ABRIR_FICHEIRO;

    while((cha = fgetc(fp)) != EOF)
        putchar(cha);


    fclose(fp);
    return OK;
}

int interpretador(ESTADO *e){

    char linha[BUF_SIZE];
    char col[2], lin[2];
    char file[BUF_SIZE];

    while(e->vencedor==0 ){
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8'-*lin };
            jogar(e, coord);
            mostrar_tabuleiro(e);
            movimentos(e);
        }

        if (sscanf(linha, "ler %s", file) == 1) {
            ler(e, file);
            printf("\nFicheiro lido com sucesso!\n");
        }

        if (sscanf(linha, "gr %s", file) == 1) {
            gravar(e, strcat(file, ".txt"));
            printf("Ficheiro gravado com sucesso!\n");
        }

        if(strcmp(linha,"Q\n") == 0)
        {
            printf("Até à próxima!");
            exit(0);}

        //if (sscanf(linha, "movs\n", file) == 0){
           // movimentos(e,e->num_jogadas);
           // printf("");


    }
    printf("O jogo acabou e o vencedor é o Jogador %d",e->vencedor);
    return 1;
}

