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
} Lestado;
/**
 * \brief Função que testa se a Coordenada pertence ao Tabuleiro;
 * @param c Coordenada
 * @return
 */
int dentroTabuleiro(COORDENADA c);
/**
 * \brief Função que cria uma lista com as Coordenadas dos Vizinhos de uma Coordenada
 * @param e Apontador para o Estado
 * @param c Coordenada
 * @return Uma Lista de Coordenadas
 */
LISTA vizinhos(ESTADO *e,COORDENADA c);
/**
 * \brief Função auxiliar para a Funcao FloodFill para alterar valores do tabuleiro.
 * @param e Apontador para o Estado
 * @param valores Valores do Tabuleiro
 * @param coord Coordenada
 * @param valor Valor a implementar
 */
void floodfillaux(ESTADO *e,int valores[8][8],COORDENADA  coord, int valor);
/**
\brief Função para devolver uma Coordenada com base no algoritmo FloodFill
 * @param e Apontador para o Estado
 * @return
 */
COORDENADA floodfill(ESTADO *e);
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
\brief Função para efetuar uma jogada
 * @param estado Apontador para estado;
 * @param c Coordenada;
 * @return
 */

int funcao_jogada (ESTADO *estado, COORDENADA c);
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
/**
\brief Função para jogadr com base no Algoritmo da distancia Euclidiana;
 * @param e
 */
void jog(ESTADO *e);
/**
\brief Função para jogar com base no Algoritmo FloodFill
 * @param e Apontador para Estado
 */
void jog2(ESTADO *e);
/**
\brief Funcao que possiblita retornar a uma jogada anterior
@param e Apontador para o estado
@param jogada Indicador da jogada para que queremos retornar
*/
void posJog(ESTADO *e, int jogada, ESTADO *aux);

#endif //RASTROSLI2_LOGICA_H
