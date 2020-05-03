/**
@file Bot.h
Funções para utilizar listas ligadas
*/
#ifndef BOT_BOT_H
#define BOT_BOT_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aux.h"

/**
\brief Função para efetuar uma jogada
 * @param estado Apontador para estado;
 * @param c Coordenada;
 * @return
 */
int funcao_jogada (ESTADO *estado);
/**
\brief Inicializa um estado
 */
ESTADO *inicializar_estado();
/**
\brief Funcao para devolver a coordenada da ultima jogada
 * @param e Apontador para o estado
 * @return A Coordenada
 */
COORDENADA get_ultima_jogada (ESTADO *e);
/**
\brief Funcao para alterar o estado da casa para Preta
 * @param e Apontador para o estado
 * @param c A coordenada a alterar
 */
void altera_estado_casa_preta (ESTADO *e, COORDENADA c);
/**
\brief Funcao para devolver o Jogador Atual
 * @param e Apontador para o estado
 */
int get_jogador_atual (ESTADO *e);
/**
 * \brief Função auxiliar para a Funcao FloodFill para alterar valores do tabuleiro.
 * @param e Apontador para o Estado
 * @param valores Valores do Tabuleiro
 * @param coord Coordenada
 * @param valor Valor a implementar
 */
void floodfillaux(ESTADO *e,int valores[8][8],COORDENADA  coord, int valor);
/**
\brief Função auxiliar que verifica se a floodill esta a ser efeciente, caso contrário usa outro algoritmo
 * @param e Apontador para o Estado
 * @param valores Valores do Tabuleiro
 */
int floodfillaux1 (ESTADO *e, int valores[8][8]);
/**
\brief Função para devolver uma Coordenada com base no algoritmo FloodFill
 * @param e Apontador para o Estado
 * @return
 */
COORDENADA floodfill(ESTADO *e);
/**
\brief Função que cria uma lista ligada
*/
LISTA criar_lista();
// Insere um valor na cabeça da lista
/**
\brief Função que insere um nodo no ínicio da lista
@param l Lista ligada
@param valor Apontador para o valor do nodo a inserir
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
 * \brief Função que cria uma lista com as Coordenadas dos Vizinhos de uma Coordenada
 * @param e Apontador para o Estado
 * @param c Coordenada
 * @return Uma Lista de Coordenadas
 */
LISTA vizinhos(ESTADO *e,COORDENADA c);
/**
 * \brief Função que testa se a Coordenada pertence ao Tabuleiro;
 * @param c Coordenada
 * @return
 */
int dentroTabuleiro(COORDENADA c);
/**
\brief Grava o estado do tabuleiro
@param e Apontador para o estado
@param ficheiro Apontador para o nome do ficheiro
*/
ERROS gravar (ESTADO *e,char *ficheiro);
/**
\brief Função que faz a leitura do tabuleiro
@param e Apontador para o estado
@param ficheiro Apontador para o nome do ficheiro
*/
ERROS ler (ESTADO* e, char *ficheiro);
/**
\brief Inicializa um estado
 */
ESTADO *inicializar_estado();
/**
\brief Verifica se uma peça está encurralada
@param estado Apontador para o estado
@param c Coordenada
*/
COORDENADA verificaMelhorJogada (LISTA l, ESTADO * e);
int encurralado (ESTADO *estado, COORDENADA c);
/**
\brief Verifica se jogada leva à vitoria do jogador ou à derrota do jogador adversário
@param e Apontador para o estado
@param c Coordenada
*/
int verificaBotFinal(ESTADO *e, COORDENADA c);
/**
\brief Analisa todas as jogadas possiveis fazendo uso da botFinal
@param estado Apontador para o estado
*/
COORDENADA verificaCheckMate(ESTADO *estado);
/**
\brief Funcao para inicializar um tabuleiro
 * @param e Apontador para o estado
 */
void inicializatab (ESTADO *e);
#endif //BOT_BOT_H
