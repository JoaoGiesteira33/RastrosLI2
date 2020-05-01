/**
@file Bot.h
Funções para utilizar listas ligadas
*/
#ifndef BOT_BOT_H
#define BOT_BOT_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
\brief Tipo de dados para as listas ligadas.
*/
typedef struct nodo {
    /** apontador para o valor do nodo */
    void *valor;
    /** apontador para o proximo nodo*/
    struct nodo *prox;
} Nodo, *LISTA;
/**
\brief Tipo de dados para a casa
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#',
    //INVALIDA
} CASA;
/**
\brief Tipo de dados para os erros
*/
typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
} ERROS;
/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];
/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
    /** O nº de comando, usado no prompt */
    int num_comando;
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada;
    /** Vencedor atual(0 enquanto nenhum é) */
    int vencedor;
} ESTADO;
/**
\brief Funcao que armaneza jogadas
@param e Apontador para o estado
@param jog Jogada a ser guardada
@param n Número da jogada
*/
void armazenar_jogada(ESTADO *e,JOGADA jog, int n);
/**
\brief Funcao para alterar a ultima jogada no estado
 * @param e Apontador para o estado
 * @param c Coordenada a Alterar
 */
void altera_ultimajogada (ESTADO *e, COORDENADA c);
/**
\brief Muda o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@param V O novo valor para a casa
*/
void set_casa (ESTADO *e, COORDENADA c, CASA valor);
/**
\brief Funcao para alterar o Jogador Atual
 * @param e Apontador para o estado
 * @param x Jogador a Alterar
 */
void set_jogador_atual (ESTADO *e, int x);

/**
\brief Funcao para alterar o numero de jogadas
 * @param e Apontador para o estado
 * @param c Numero de Jogadas a alterar
 */
void set_numero_jogadas (ESTADO *e, int x);
/**
\brief Obtém o estado da casa
@param e Apontador para o estado
@param c A coordenada
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Funcao para devolver a coordenada do Jogador 1 numa Jogada c
 * @param e Apontador para o estado
 * @param c Numero da Jogada
 * @return A Coordenada
 */
COORDENADA get_coord_jogador1 (ESTADO *e, int c);
/**
\brief Funcao para devolver a coluna de uma jogada
 * @param c A coordenada
 * @return A coluna
 */
int get_coord_coluna (COORDENADA c);
/**
\brief Funcao para devolver a coordenada do Jogador 2 numa Jogada c
 * @param e Apontador para o estado
 * @param c Numero da Jogada
 * @return A Coordenada
 */
COORDENADA get_coord_jogador2 (ESTADO *e, int c);
/**
\brief  Converte a ultima jogada linha
@param c A Coordenada
*/
int conversorultimajogadalinha (COORDENADA c);
/**
\brief Converte a ultima jogada coluna
@param c A coordenada
*/
char conversorultimajogadacoluna (COORDENADA c);
/**
\brief Função para efetuar uma jogada
 * @param estado Apontador para estado;
 * @param c Coordenada;
 * @return
 */

int funcao_jogada (ESTADO *estado);
/**
\brief Funcao para alterar o estado da casa para Branca
 * @param e Apontador para o estado
 * @param c A coordenada a alterar
 */
void altera_estado_casa_branca (ESTADO *e, COORDENADA c);
/**
\brief Retorna o jogador atual
@param estado Apontador para o estado
*/
int obter_jogador_atual(ESTADO *estado);
/**
\brief Funcao para incrementar o numero de jogadas
 * @param e Apontador para o estado
 */
void incrementa_numero_jogadas (ESTADO *e);
/**
\brief Inicializa um estado
 */
/**
\brief Funcao para inserir uma Jogada do Jogador 1 no estado
* @param e Apontador para o estado
* @param c A coordenada a inserir
* @param n Numero da Jogada
*/
void set_jogadas_jogador1 (ESTADO *e, COORDENADA c, int n);
/**
\brief Funcao para inserir uma Jogada do Jogador 2 no estado
 * @param e Apontador para o estado
 * @param c A coordenada a inserir
 * @param n Numero da Jogada
 */
void set_jogadas_jogador2 (ESTADO *e, COORDENADA c, int n);
/**
\brief Retorna o número de jogadas
@param estado Apontador para o estado
*/
int obter_numero_de_jogadas(ESTADO *estado);
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

int get_valores (ESTADO *e, int valores[8][8], COORDENADA c);

LISTA proximo(LISTA L);

void set_valores (ESTADO *e, int valores[8][8]);
#endif //BOT_BOT_H
