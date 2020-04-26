/**
@file logica.h
Definição da lógica do programa
*/

#ifndef RASTROSLI2_LOGICA_H
#define RASTROSLI2_LOGICA_H

#include "lista.h"

typedef struct lEstado{
    ESTADO *e;
    struct lEstado *prox;
}Lestado;
int dentroTabuleiro(COORDENADA c);
LISTA vizinhos(ESTADO *e,COORDENADA c);
void floodfillaux(ESTADO *e,int valores[8][8],COORDENADA  coord, int valor);
COORDENADA floodfill(ESTADO *e);
int max(int a, int b);
int minmax(COORDENADA posAtual, int profundidade, int player);
/**
\brief Funcão que verifica qual é a melhor Coordenada
@param l Lista de coordenadas possíveis
@param c A coordenada
@param e Apontador para o estado
*/
COORDENADA verificaMelhorJogada (LISTA l, ESTADO * e);
/**
\brief Funcão que verifica se a casa para a qual o jogador pretende jogar é valida, ou seja, se encontra-se na distancia de uma casa.
@param estado Apontador para o estado
@param c A coordenada
*/
int verifica_movimentos(ESTADO *estado, COORDENADA c);
/**
\brief Funcão que verifica se a casa para onde o jogador pretende jogar é válida, neste caso Vazia.
@param estado Apontador para o estado
@param c A coordenada
*/
int verifica_vazio(ESTADO *estado, COORDENADA c);
/**
\brief Função principal que efetua a jogada.
@param estado Apontador para o estado
@param c A coordenada
*/
int movimentos(ESTADO*e);
int jogar(ESTADO *estado, COORDENADA c);
/**
\brief Função que verifica se o jogador não tem mais nenhuma jogada válida
@param estado Apontador para o estado
*/
int encurralado (ESTADO *estado);
/**
\brief Função para determinar o final do Jogo e consequente mensagem de congratulação.
@param estado Apontador para o estado
@param c A coordenada
*/
int jogada_final (ESTADO *estado, COORDENADA c);

#endif //RASTROSLI2_LOGICA_H
