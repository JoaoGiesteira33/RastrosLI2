//
// Created by julio on 03/05/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aux.h"

void armazenar_jogada(ESTADO *e,JOGADA jog, int n) {
    e->jogadas[n] = jog;
}

void altera_ultimajogada (ESTADO *e, COORDENADA c) {
    e->ultima_jogada = c;
}

void set_casa (ESTADO *e, COORDENADA c, CASA valor) {
    e-> tab[c.coluna][c.linha] = valor;
}

void set_jogador_atual (ESTADO *e, int x) {
    e -> jogador_atual = x;
}

void set_numero_jogadas (ESTADO *e, int x) {
    e -> num_jogadas = x;
}

CASA obter_estado_casa (ESTADO *e, COORDENADA c) {
    CASA casa;
    casa = e-> tab[c.coluna][c.linha];
    return casa;
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

int conversorultimajogadalinha (COORDENADA c) {
    int linha;
    linha =  8 - c.linha ;
    return linha;
}

char conversorultimajogadacoluna (COORDENADA c) {
    char s1 = '0';
    switch (c.coluna) {
        case 0:
            s1 = 'a';
            break;
        case 1:
            s1 = 'b';
            break;
        case 2:
            s1  = 'c';
            break;
        case 3:
            s1  = 'd';
            break;
        case 4:
            s1 = 'e';
            break;
        case 5:
            s1 = 'f';
            break;
        case 6:
            s1 = 'g';
            break;
        case 7:
            s1 = 'h';
            break;

    }
    return s1;
}


void altera_estado_casa_branca (ESTADO *e, COORDENADA c) {
    e -> tab[c.coluna][c.linha] = BRANCA;
}

int obter_jogador_atual(ESTADO *estado) {
    int jog;
    jog = estado -> jogador_atual;
    return jog;
}

void incrementa_numero_jogadas (ESTADO *e) {
    e -> num_jogadas += 1;
}

void set_jogadas_jogador1 (ESTADO *e, COORDENADA c, int n) {
    e->jogadas[n].jogador1 = c;
}

void set_jogadas_jogador2 (ESTADO *e, COORDENADA c, int n) {
    e->jogadas[n].jogador2 = c;
}

int obter_numero_de_jogadas(ESTADO *estado) {
    int numJogadas = estado-> num_jogadas;
    return numJogadas;
}

void set_valores (ESTADO *e, int valores[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (e->tab[j][i] == PRETA) valores[j][i] = -2;
            else valores[j][i] = -1;
        }
}

LISTA proximo (LISTA L) {
    LISTA cauda;
    if (L -> prox != NULL) cauda = L -> prox;
    else cauda = NULL;
    return cauda;
}

int get_valores ( int valores[8][8], COORDENADA c) {
    int a = valores[c.coluna][c.linha];
    return a;
}

void altera_estado_casa_preta (ESTADO *e, COORDENADA c) {
    e -> tab[c.coluna][c.linha] = PRETA;
}

COORDENADA get_ultima_jogada (ESTADO *e) {
    COORDENADA c = e -> ultima_jogada;
    return c;
}

int get_jogador_atual (ESTADO *e) {
    int x = e -> jogador_atual;
    return x;
}

LISTA criar_lista() { // Funcao que cria uma lista
    LISTA nova = malloc(sizeof(Nodo)); // Reserva Memoria
    nova ->prox = NULL;
    nova->valor = NULL;
    return nova;
}

LISTA insere_cabeca(LISTA L, void *valor) { // Insere um Nodo na Lista
    LISTA nova = malloc(sizeof(Nodo)); // Reserva Memoria para o novo nodo
    nova-> valor= valor;
    nova-> prox= L;
    return nova;
}

int dentroTabuleiro(COORDENADA c) {
    return (c.linha < 8 && c.linha >= 0 && c.coluna < 8 && c.coluna >= 0);
}
