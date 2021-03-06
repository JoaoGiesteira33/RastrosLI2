#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "camadadados.h"
#include "lista.h"
#define BUF_SIZE 1024

void movimentos (ESTADO*e) { //Função que imprime a lista de movimentos
    if (get_num_jogadas(e) == 0) printf("%02d:     \n",1);
    else {
        int g;
        for (g = 0; g < (get_num_jogadas(e) - 1); g++) { //Imprime a Lista de Jogadas até á ultima Jogada
            COORDENADA coord1 = get_coord_jogador1(e, g);
            COORDENADA coord2 = get_coord_jogador2(e, g);

            printf("%02d: %c%d %c%d\n", g + 1, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1),
                                                       conversorultimajogadacoluna(coord2), conversorultimajogadalinha(coord2));
        }

        COORDENADA coord1 = get_coord_jogador1(e, g);
        COORDENADA coord2 = get_coord_jogador2(e, g);
        //Imprime a Jogada Atual
        if (get_jogador_atual(e) == 1) printf("%02d: %c%d\n", g + 1, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1)); //Caso ainda so tenha jogado o Jogador 1
        else printf("%02d: %c%d %c%d\n", g + 1, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1),
                                                        conversorultimajogadacoluna(coord2), conversorultimajogadalinha(coord2));
    }
}

void mostrar_tabuleiro (ESTADO* estado) { // Funcao para imprimir um tabuleiro
    char c = 0;
    int j, i;

    for (j = 0; j <= 7; j++) { // Imprimir uma informacao das linhas
        printf("%d|",8-j);
        for (i = 0; i <= 7; i++) {
            COORDENADA cord = {i,j};
            switch (obter_estado_casa (estado, cord)) { //Imprime o Caracter conforme o Estado da Casa
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
     printf("  a b c d e f g h"); // Imprime uma Funcao das Colunas
     printf("\n PL%d Jogada %d\n Coordenada Atual %c%d\n", get_jogador_atual(estado)+1, obter_numero_de_jogadas(estado),
                                                                   conversorultimajogadacoluna(get_ultima_jogada(estado)),
                                                                   conversorultimajogadalinha(get_ultima_jogada(estado)));
}

ERROS gravar (ESTADO *e,char *ficheiro) { // Funcao para gravar um jogo num ficheiro
    FILE *fp;
    fp = fopen(ficheiro, "w"); // Abre o ficheiro

    COORDENADA coord1;
    COORDENADA coord2;

    if (fp == NULL) return ERRO_ABRIR_FICHEIRO; // Caso nao consigamos abrir um ficheiro
    else {
        char c ='.';
        int i, j;
        for (j = 0; j <= 7; j++) {
            for (i = 0; i <= 7; i++) {
                COORDENADA cord = {i, j};
                switch (obter_estado_casa(e, cord)) { //Grava o Caracter conforme o Estado da Casa
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
        fprintf(fp,"\n");

        int l = 1;
        for (int g = 0; get_coord_coluna(get_coord_jogador1(e,g)) != -1; g++) { // Grava a lista de jogadas
            coord1 = get_coord_jogador1(e,g);
            coord2 = get_coord_jogador2(e,g);

            if (coord2.coluna != -1) { // Grava uma lista de Jogadas Completa
                fprintf(fp, "0%d: %c%d %c%d\n", l, conversorultimajogadacoluna(coord1),conversorultimajogadalinha(coord1),
                                                           conversorultimajogadacoluna(coord2),conversorultimajogadalinha(coord2));
                l++;
        } else { // Caso uma Jogada esteja incompleta
                fprintf(fp, "0%d: %c%d\n", l, conversorultimajogadacoluna(coord1), conversorultimajogadalinha(coord1));
                l++;
            }
        }
        fclose(fp); // Fecha o Ficheiro
    }
    return OK;
}

ERROS ler (ESTADO* e,char*ficheiro) { // Funcao para ler um jogo a partir de um Ficheiro
    FILE *fp;
    fp = fopen(strcat(ficheiro, ".txt"), "r");
    if (fp == NULL) return ERRO_ABRIR_FICHEIRO; // Caso nao consigamos abrir o Ficheiro

        char cha;
        COORDENADA coord;
        for (int c = 0; c < 8; c++) {
            for (int l = 0; l < 8; l++) {
                coord = (COORDENADA) {l, c};
                if (fscanf(fp, "%c", &cha) == 1) {
                    set_casa(e, coord, cha);
                    if (cha == BRANCA) altera_ultimajogada(e, coord);
                }
            }
            if (fscanf(fp, "%c",&cha) == 1){
                ;
            }
        }
        int num_tokens;
        fseek(fp, 74, SEEK_SET);
        int indice = 0;
        set_numero_jogadas(e, 0);
        COORDENADA c1;
        COORDENADA c2;
        int num_jogad;
        char jog1_c, jog2_c;
        int jog1_l, jog2_l;
        while ((num_tokens = fscanf(fp, "%2d: %c%d %c%d", &num_jogad, &jog1_c, &jog1_l, &jog2_c, &jog2_l) != EOF)) {
            if (num_tokens == 3) { // No caso de a Jogada Estar Incompleta
                c1.coluna = jog1_c - 'A';
                c1.linha = jog1_l - '1';
                c2.coluna = (-1);
                c2.linha = (-1);
                armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
                set_jogador_atual(e, 0);
            } else {
                c1.coluna = jog1_c - 'A';
                c1.linha = 8 - jog1_l;
                c2.coluna = jog2_c - 'A';
                c2.linha = 8 - jog2_l;
                armazenar_jogada(e, (JOGADA) {c1, c2}, indice);
                set_jogador_atual(e, 1);
                indice++;
            }
        }
        set_numero_jogadas(e, (indice));
        fclose(fp);
        mostrar_tabuleiro(e);
        return OK;
    }

    void jogar (ESTADO *estado, COORDENADA c) { // Função que permite efetuar uma Jogada
        // Testa varias condicoes validas para uma Jogada
        if ( verifica_movimentos(estado, c) && verifica_vazio(estado,c) && !(jogada_final(estado, c)) ) funcao_jogada (estado,c);
        else { // Casos de Fim de Jogo
            int jogador = get_jogador_atual(estado);

            if (c.coluna == 0 && c.linha == 7) { //no caso de chegar a casa final do Jogador 1
                set_jogador_vencedor(estado, 1);
                altera_estado_casa_branca(estado, c);
                altera_estado_casa_preta(estado, get_ultima_jogada(estado));
                altera_ultimajogada(estado, c);
            } else if (c.coluna == 7 && c.linha == 0) {  //no caso de chegar a casa final do Jogador 2
                set_jogador_vencedor(estado, 2);
                altera_estado_casa_branca(estado, c);
                altera_estado_casa_preta(estado, get_ultima_jogada(estado));
                altera_ultimajogada(estado, c);
            } else if (encurralado(estado) && (jogador == 0)) set_jogador_vencedor(estado, 2); //nos casos de os Jogadores se encontrarem rodeados, ou sejam, sem possiblidades de jogarem
              else if (encurralado(estado) && (jogador == 1)) set_jogador_vencedor(estado, 1);    //nos casos de os Jogadores se encontrarem rodeados, ou sejam, sem possiblidades de jogarem
              else printf("A jogada nao é válida, tente novamente\n");
        }
    }

int interpretador (ESTADO *e,ESTADO *aux) { // Interpretador de Comandos do Jogo

    char linha[BUF_SIZE];
    char col[2], lin[2];
    char file[BUF_SIZE];
    int jogada;
    int ultima_jogada_pos = 0;

    while (get_jogador_vencedor(e) == 0) { // Condicao de detecao de fim do Jogo
        if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            if (ultima_jogada_pos == 0) { // Condicao para testar uma pos seguida de uma jogada
                jogar(e, coord);
                mostrar_tabuleiro(e);
                if (encurralado(e) == 1) { // Condicao para Testar se o Jogador ficou encurralado
                    if (get_jogador_atual(e) == 0) set_jogador_vencedor(e, 2); // No caso de o Jogador ter jogado e deixado o outro player encurralado
                    else set_jogador_vencedor(e, 1);
                }
                ultima_jogada_pos = 0;
            } else { // No caso de termos efetuado pos seguido de jog
                *e = *aux;  // Copia o estado auxiliar e liberta a memoria alocada
                free(aux);
                jogar(e, coord);
                mostrar_tabuleiro(e);
                ultima_jogada_pos = 0;
            }
        }
        // Comando Ler
        if (sscanf(linha, "ler %s", file) == 1) {
            if (ler(e, file) == OK) printf("\nFicheiro lido com sucesso!\n"); // Caso a funcao ler tenha sido efetuada com sucesso
            else (printf("\nErro ao ler o ficheiro!\n")); // Caso contrario
            ultima_jogada_pos = 0;
        }
        // Comando Gravar
        if (sscanf(linha, "gr %s", file) == 1) {
            if ((gravar(e, strcat(file, ".txt"))) == OK) printf("Ficheiro gravado com sucesso!\n"); // Caso a funcao ler tenha sido efetuada com sucesso
            else (printf("\nErro ao gravar o ficheiro!\n")); // Caso contrario
        }
        // Comando Quit
        if (strcmp(linha, "Q\n") == 0) {
            printf("Até à próxima!");
            exit(0);
        }
        // Comando movs
        if (strcmp(linha, "movs\n") == 0) movimentos(e);
        // Comando pos
        if (sscanf(linha, "pos %d", &jogada) == 1) {
            posJog(e, jogada, aux);
            ultima_jogada_pos = 1; // Condicao para permitir testar se se efetua uma jogada depois do comando jog
        }
        // Comando jog
        if (strcmp(linha, "jog\n") == 0) {
            if (ultima_jogada_pos == 0) jog(e);
            else {
                *e = *aux;
                free(aux);
                jog(e);
            }
            ultima_jogada_pos = 0;
        }
        // Comando jog2
        if (strcmp(linha, "jog2\n") == 0) {
            if (ultima_jogada_pos == 0) jog2(e);
            else {
                *e = *aux;
                free(aux);
                jog2(e);
            }
            ultima_jogada_pos = 0;
        }
    }   // Caso de Fim de Jogo e Mensagem de Congratulação
        printf("Muitos Parabéns, o jogo acabou e o vencedor é o Jogador %d", get_jogador_vencedor(e));
        return 1;
    }

