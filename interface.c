#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "camadadados.h"
#define BUF_SIZE 1024

int movimentos(ESTADO*e) {
    for (int g = 0; e->jogadas[g].jogador1.coluna != -1; g++)
    {
        COORDENADA coord1 = get_coord_jogador1(e, g);
        COORDENADA coord2 = get_coord_jogador2 (e, g);

        if (coord2.coluna != -1)
            printf("%02d: %c%d %c%d\n", g+1 ,conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1),conversorultimajogadacoluna(coord2), conversorultimajogadalinha(coord2));
        else
            printf("%02d: %c%d\n",g+1,conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1));
    }
}

 void mostrar_tabuleiro (ESTADO* estado){
    char c = 0;
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
// funcao a dar erro linha 4 nao aparece ao ler
ERROS gravar(ESTADO *e,char *ficheiro){
    FILE *fp;
    fp = fopen(ficheiro, "w");

    COORDENADA coord1;
    COORDENADA coord2;

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
                fprintf(fp, "%c", c);


            }
            fprintf(fp, "\n");


        }
        //fprintf(fp,"\n PL%d Jogada%d\n Coordenada Anterior %c%d\n", obter_jogador_atual(e), obter_numero_de_jogadas(e),conversorultimajogadacoluna(obter_ultima_jogada(e)),conversorultimajogadalinha(obter_ultima_jogada(e)));
        fprintf(fp,"\n");
        int l = 1;
        for (int g = 0; get_coord_coluna(get_coord_jogador1(e,g)) != -1; g++) {
            coord1 = get_coord_jogador1(e,g);
            coord2 = get_coord_jogador2(e,g);

            if (coord2.coluna != -1) {
                fprintf(fp, "0%d: %c%d %c%d\n", l, conversorultimajogadacoluna(coord1),
                        conversorultimajogadalinha(coord1), conversorultimajogadacoluna(coord2),
                        conversorultimajogadalinha(coord2));
                l++;
        }
            else {
                fprintf(fp, "0%d: %c%d\n", l, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1));
                l++;
            }
        }
        fclose(fp);
    }
    return OK;
}

ERROS ler (ESTADO* e,char*ficheiro) {
    FILE *fp;
    fp = fopen(strcat(ficheiro, ".txt"), "r");

    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro");
        return ERRO_ABRIR_FICHEIRO;
    }
    char cha;
    COORDENADA coord;
    for (int c = 0; c < 8; c++) {
        for (int l = 0; l < 8; l++) {
            coord = (COORDENADA) {.coluna = l, .linha = c};
            fscanf(fp, "%c", &cha);
            set_casa(e, coord, cha);
            if (cha == BRANCA) {
                altera_ultimajogada(e, coord);
            }
        }
        fscanf(fp, "%c", &cha);
    }

    int num_jog;
    fseek (fp, 8, SEEK_SET);
    char linha[BUF_SIZE];
    int indice = 0;
    e-> num_jogadas = 0;
    while (fgets(linha, BUF_SIZE, fp) != NULL) {
        int nada;
        int num_jogad;
        char jog1[BUF_SIZE];
        char jog2[BUF_SIZE];
        int num_tokens = sscanf (linha, "%d%d: %s %s", &nada ,&num_jogad, jog1, jog2);
        if (num_tokens == 4) {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = str_to_coord(jog2);
            armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
            e -> jogador_atual = 0;
            indice++;
        }else
            {
            COORDENADA c1 = str_to_coord(jog1);
            COORDENADA c2 = {-1, -1};
            armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
            e -> jogador_atual = 1;
        }
        e -> num_jogadas = num_jogad;

    }
    e -> num_jogadas = num_jog;

        fclose(fp);
        mostrar_tabuleiro(e);
        return OK;
}


int interpretador (ESTADO *e){

    char linha[BUF_SIZE];
    char col[2], lin[2];
    char file[BUF_SIZE];

    while(e->vencedor==0 ) {
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jogar(e, coord);
            mostrar_tabuleiro(e);
        }

        if (sscanf(linha, "ler %s", file) == 1) {
            if (ler(e, file) == OK) {
                printf("\nFicheiro lido com sucesso!\n");
            }
            else (printf("\nErro ao ler o ficheiro!\n"));
        }

        if (sscanf(linha, "gr %s", file) == 1) {
            if ((gravar (e, strcat(file, ".txt"))) == OK) {
                printf("Ficheiro gravado com sucesso!\n");
            }
            else (printf("\nErro ao gravar o ficheiro!\n"));
        }

        if (strcmp(linha, "Q\n") == 0) {
            printf("Até à próxima!");
            exit(0);
        }

        if (strcmp(linha, "movs\n") == 0) {
            movimentos(e);
        }
    }
    printf("O jogo acabou e o vencedor é o Jogador %d",e->vencedor);
    return 1;
}

