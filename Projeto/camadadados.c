#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadadados.h"

ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 0;
    e->num_jogadas = 0;
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
    e-> vencedor = 0;
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
     for(int i = 0; i < 32; i++)
     {
         e->jogadas[i].jogador1.coluna = -1;
         e->jogadas[i].jogador1.linha = -1;
         e->jogadas[i].jogador2.coluna =-1;
         e->jogadas[i].jogador2.linha =-1;
     }

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
    linha =  8 - c.linha ;
    return linha;
}

char conversorultimajogadacoluna (COORDENADA c) {


    char s1 = '0';


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


CASA obter_estado_casa (ESTADO *e, COORDENADA c)
{
    CASA casa;
    casa = e-> tab[c.coluna][c.linha];
    return casa;
}

void armazenar_jogada(ESTADO *e,JOGADA jog, int n)
{
    e->jogadas[n] = jog;
}

COORDENADA get_coord_jogador1 (ESTADO *e, int c) {
    COORDENADA coord  = e->jogadas[c].jogador1;

    return coord;
}

int get_coord_coluna (COORDENADA c) {
    int x = c.coluna;
    return  x;
}

COORDENADA get_coord_jogador2 (ESTADO *e, int c) {
    COORDENADA coord  = e->jogadas[c].jogador2;

    return coord;
}

void altera_ultimajogada (ESTADO *e, COORDENADA c) {
    e->ultima_jogada = c;
}

void set_casa (ESTADO *e, COORDENADA c, CASA valor) {
    e-> tab[c.coluna][c.linha] = valor;
}

COORDENADA get_ultima_jogada (ESTADO *e) {
    COORDENADA c = e -> ultima_jogada;

    return c;
}

void altera_estado_casa_branca (ESTADO *e, COORDENADA c) {
    e -> tab[c.coluna][c.linha] = BRANCA;
}

void incrementa_numero_jogadas (ESTADO *e) {
    e -> num_jogadas += 1;
}

void set_jogadas_jogador1 (ESTADO *e, COORDENADA c, int n) {
    e->jogadas[n].jogador1 = c;
}

COORDENADA get_jogadas_jogador1 (ESTADO *e, int n) {
    COORDENADA x = e -> jogadas[n].jogador1;

    return x;
}

void set_jogadas_jogador2 (ESTADO *e, COORDENADA c, int n) {
    e->jogadas[n].jogador2 = c;
}

COORDENADA get_jogadas_jogador2 (ESTADO *e, int n) {
    COORDENADA x = e -> jogadas[n].jogador2;

    return x;
}

void altera_estado_casa_preta (ESTADO *e, COORDENADA c) {
    e -> tab[c.coluna][c.linha] = PRETA;
}

int get_jogador_atual (ESTADO *e) {
    int x = e -> jogador_atual;

    return x;
}

void set_jogador_atual (ESTADO *e, int x) {
    e -> jogador_atual = x;
}

void set_jogador_vencedor (ESTADO *e, int x) {
    e -> vencedor = x;
}

void set_numero_jogadas (ESTADO *e, int x) {
    e -> num_jogadas = x;
}

void altera_estado_casa_vazio (ESTADO *e, COORDENADA c) {
    e -> tab[c.coluna][c.linha] = VAZIO;
}

void altera_ultimajogada_pos (ESTADO *e, int jogada) {
    e -> ultima_jogada.coluna = e -> jogadas[jogada-1].jogador2.coluna;
    e -> ultima_jogada.linha = e -> jogadas[jogada-1].jogador2.linha;
}

void set_casas_invalidas (ESTADO *e, int n) {
    e->jogadas[n].jogador1 = (COORDENADA){.coluna = -1, .linha = -1};
    e->jogadas[n].jogador2 = (COORDENADA){.coluna = -1, .linha = -1};
}

int get_num_jogadas (ESTADO *e) {
    int a = e -> num_jogadas;
    return a;
}
int get_jogador_vencedor (ESTADO *e) {
    int a = e -> vencedor;
    return a;
}

ESTADO *inicializar_estado_aux()
{
    ESTADO *aux = (ESTADO *)malloc(sizeof(ESTADO));
    aux->jogador_atual = 0;
    aux->num_jogadas = 0;
    aux->ultima_jogada.linha = 3;
    aux->ultima_jogada.coluna = 4;

    aux-> vencedor = 0;
    for (int i =0;i<8;i++){
        for (int j =0;j<8;j++){
            if (i == 7 && j == 0)
                aux->tab[i][j] = DOIS;
            else if (i == 0 && j == 7)
                aux->tab[i][j] = UM;
            else aux->tab[i][j] = VAZIO;
        }


    }
    aux->tab[4][3] = BRANCA;
    for(int i = 0; i < 32; i++)
    {
        aux->jogadas[i].jogador1.coluna = -1;
        aux->jogadas[i].jogador1.linha = -1;
        aux->jogadas[i].jogador2.coluna =-1;
        aux->jogadas[i].jogador2.linha =-1;
    }
    return aux;
}
void set_valores (ESTADO *e, int valores[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (e->tab[j][i] == PRETA)
                valores[j][i] = -2;
            else
                valores[j][i] = -1;
        }
}

