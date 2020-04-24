#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "camadadados.h"
#include "lista.h"
#define BUF_SIZE 1024

void posJog(ESTADO *e,int jogada,ESTADO *aux)
{
     *aux = *e;

     int n = 31;
     if (jogada >= obter_numero_de_jogadas(e) || jogada < 0)
     {
         printf("Número de jogada inválida\n");
     } else {

         //printf("Copiou\n");
         set_jogador_atual(aux,0);
         set_numero_jogadas(aux, jogada);
         altera_estado_casa_vazio(aux,get_ultima_jogada(aux));
         altera_ultimajogada_pos(aux, jogada);

         while (n >= jogada)
         {
             COORDENADA x = get_jogadas_jogador1(aux, n);
             COORDENADA y = get_jogadas_jogador2(aux, n);

             altera_estado_casa_vazio(aux, x);
             altera_estado_casa_vazio(aux, y);

             set_casas_invalidas(aux, n);
             n--;
         }

         n = 0;
         if (jogada == 0) {
             aux->ultima_jogada.coluna = 4;
             aux->ultima_jogada.linha = 3;
             aux->tab[4][3] = BRANCA;
         }

         while ( n < jogada )
             {
                 COORDENADA x = get_jogadas_jogador1 (aux, n);
                 COORDENADA y = get_jogadas_jogador2 (aux, n);

                 altera_estado_casa_preta (aux , x);
                 altera_estado_casa_preta (aux, y);

                 n++;
             }

             COORDENADA ult = get_ultima_jogada(aux);
             altera_estado_casa_branca(aux, ult);
         }
     mostrar_tabuleiro(aux);

}

void jog (ESTADO *e){
    COORDENADA c = get_ultima_jogada (e);

    LISTA principal = criar_lista();



    COORDENADA cima     = (COORDENADA) {.coluna = c.coluna, .linha = c.linha + 1};

    COORDENADA baixo    = (COORDENADA) {.coluna = c.coluna, .linha = c.linha - 1};

    COORDENADA direita  = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha};

    COORDENADA esquerda = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha};

    COORDENADA diagDBaixo = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha - 1};

    COORDENADA diagEBaixo = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha - 1};

    COORDENADA diagDCima  = (COORDENADA) {.coluna = c.coluna + 1, .linha = c.linha + 1};

    COORDENADA diagECima  = (COORDENADA) {.coluna = c.coluna - 1, .linha = c.linha + 1};


    if ((obter_estado_casa(e,cima))       == VAZIO) principal = insere_cabeca (principal,&cima);
    if ((obter_estado_casa(e,baixo))      == VAZIO) principal = insere_cabeca (principal,&baixo);
    if ((obter_estado_casa(e,direita))    == VAZIO) principal = insere_cabeca (principal, &direita);
    if ((obter_estado_casa(e,esquerda))   == VAZIO) principal = insere_cabeca (principal, &esquerda);
    if ((obter_estado_casa(e,diagDBaixo)) == VAZIO) principal = insere_cabeca (principal, &diagDBaixo);
    if ((obter_estado_casa(e,diagDCima))  == VAZIO) principal = insere_cabeca (principal, &diagDCima);
    if ((obter_estado_casa(e,diagEBaixo)) == VAZIO) principal = insere_cabeca (principal, &diagEBaixo);
    if ((obter_estado_casa(e,diagECima))  == VAZIO) principal = insere_cabeca (principal, &diagECima);


   COORDENADA novaCasa = verificaMelhorJogada (principal, e);

   jogar(e,novaCasa);
   mostrar_tabuleiro(e);

}

int movimentos(ESTADO*e) {
    int g;
    for (g = 0;  g < (get_num_jogadas(e) - 1); g++) {
        COORDENADA coord1 = get_coord_jogador1(e, g);
        COORDENADA coord2 = get_coord_jogador2 (e, g);

        printf("%02d: %c%d %c%d\n", g+1 ,conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1),conversorultimajogadacoluna(coord2), conversorultimajogadalinha(coord2));
    }


    COORDENADA coord1 = get_coord_jogador1 (e, g);
    COORDENADA coord2 = get_coord_jogador2 (e, g);

    if (get_jogador_atual(e) == 1) {
        printf("%02d: %c%d\n", g + 1, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1));
    }
    else {
        printf("%02d: %c%d %c%d\n", g + 1,conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1),conversorultimajogadacoluna(coord2), conversorultimajogadalinha(coord2));
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
 int num_tokens;
    fseek(fp, 74, SEEK_SET);
    int indice = 0;
    e-> num_jogadas = 0;
    COORDENADA c1;
    COORDENADA c2;
    int num_jogad;
    char jog1_c, jog1_l, jog2_c, jog2_l;
    while (( num_tokens = fscanf (fp,"%2d: %c%d %c%d", &num_jogad, &jog1_c, &jog1_l, &jog2_c, &jog2_l) != EOF)) {
        if (num_tokens == 3) {
            c1.coluna = jog1_c - 'A';
            c1.linha = jog1_l - '1';
            c2.coluna = (-1);
            c2.linha = (-1);
            armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
            set_jogador_atual(e, 1);
        } else {
            c1.coluna = jog1_c - 'A';
            c1.linha = 8 - jog1_l ;
            c2.coluna = jog2_c - 'A';
            c2.linha = 8 - jog2_l;
            armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
            set_jogador_atual(e, 0);
            indice++;
        }
    }
    set_numero_jogadas(e, (indice));
    fclose(fp);
    mostrar_tabuleiro(e);
    return OK;
}


int interpretador (ESTADO *e,ESTADO *aux){

    char linha[BUF_SIZE];
    char col[2], lin[2];
    char file[BUF_SIZE];
    int jogada;
    int ultima_jogada_pos = 0;


    while ( e->vencedor == 0 ) {
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            if (ultima_jogada_pos == 0) {
                jogar(e, coord);
                mostrar_tabuleiro(e);
                ultima_jogada_pos = 0;
            } else {
                *e = *aux;
                free(aux);
                jogar(e, coord);
                mostrar_tabuleiro(e);
                ultima_jogada_pos = 0;
            }
        }

        if (sscanf(linha, "ler %s", file) == 1) {
            if (ler(e, file) == OK) {
                printf("\nFicheiro lido com sucesso!\n");
            }
            else (printf("\nErro ao ler o ficheiro!\n"));
            ultima_jogada_pos = 0;
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

        if (sscanf(linha, "pos %d", &jogada) == 1) {
            posJog(e,jogada,aux);
            ultima_jogada_pos = 1;
        }
        if (strcmp(linha, "jog\n") == 0) {
            jog(e);
        }

        if (strcmp(linha, "jog2\n") == 0) {
            jog(e);
        }

    }
    printf("Muitos Parabens, o jogo acabou e o vencedor é o Jogador %d", get_jogador_vencedor(e));
    return 1;
}

