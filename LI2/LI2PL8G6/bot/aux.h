
#ifndef BOT2_AUX_H
#define BOT2_AUX_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** @struct Nodo
 * @brief Lista de Apontadores
 * @var Nodo::*valor
 * *valor representa um apontador para o enderenco de memoria alocado
 * @var Nodo::*prox
 * *prox representa um apontador para o proximo nodo
 */
typedef struct nodo {
    /** apontador para o valor do nodo */
    void *valor;
    /** apontador para o proximo nodo*/
    struct nodo *prox;
} Nodo, *LISTA;
/** @enum CASA
 * @brief Tipo de dados para a casa
 * @var CASA::UM
 * UM representa a casa do Jogador 1
 * @var CASA::DOIS
 * DOIS representa a casa do Jogador 2
 * @var CASA::VAZIO
 * Vazio representa uma casa que ainda nao foi jogada
 * @var CASA::BRANCA
 * Branca representa a ultima peca jogada
 * @var CASA::PRETA
 * Preta representa as casas jogadas
 */
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#',
    //INVALIDA
} CASA;
/** @enum ERROS
 * @brief Tipo de dados para ler ficheiros
 * @var ERROS::OK
 * OK representa que conseguiu abrir o ficheiro
 * @var ERROS::COORDENADA_INVALIDA
 * COORDENADA_INVALIDA representa que a Coordenada lida e invalida
 * @var ERROS::ERRO_LER_TAB
 * ERRO_LER_TAB representa mau formato do ficheiro
 * @var ERROS::ERRO_ABRIR_Ficheiro
 * ERRO_ABRIR_Ficheiro representa que nao conseguiu abrir o ficheiro
 */
typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
} ERROS;
/** @struct COORDENADA
 * @brief Tipo de dados sobre uma Coordenada
 * @var COORDENADA::coluna
 * coluna representa a componente coluna do tabuleiro
 * @var COORDENADA::linha
 * linha representa a componente coluna do tabuleiro
 */
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
/** @struct JOGADA
 * @brief Tipo de dados para armazenar uma Jogada
 * @var JOGADA::jogador1
 * jogador1 representa a coordenada que o jogador 1 jogou
 * @var JOGADA::jogador2
 * jogador2 representa a coordenada que o jogador 2 jogou
 */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
/** @enum JOGADA
 * @brief Tipo de dados para armazenar as jogadas
 */
typedef JOGADA JOGADAS[32];
/** @struct ESTADO
 * @brief Tipo de dados que envolve toda a informação decorrente do jogo
 * @var ESTADO::CASA
 * CASA representa o estado de cada casa do tabuleirp
 * @var ESTADO::JOGADAS
 * JOGADAS representa a lista de jogadas
 * @var ESTADO::num_jogadas
 * num_jogadas representa o numero de jogadas
 * @var ESTADO::jogador_atual
 * jogador_atual representa o jogador a jogar
 * @var ESTADO::num_comando
 * num_comando usado no prompt
 * @var ESTADO::ultima_jogada
 * ultima_jogada representa a ultima jogada
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
\brief Funcao para definir os valores da matriz segundo o algoritmo FloodFill
 * @param e Apontador para o estado
 * @param valores Matriz de valores
 */
void set_valores (ESTADO *e, int valores[8][8]);
/**
\brief Devolve a
@param estado Apontador para o estado
@param c Coordenada
*/
LISTA proximo(LISTA L);
/**
\brief Retorna o valor de uma coordenada
@param valores Valores do Tabuleiro
@param c Coordenada
 */
int get_valores (int valores[8][8], COORDENADA c);
/**
\brief Funcao para alterar o estado da casa para Preta
@param e Apontador para o estado
@param c A coordenada a alterar
 */
void altera_estado_casa_preta (ESTADO *e, COORDENADA c);
/**
\brief Funcao para devolver a coordenada da ultima jogada
@param e Apontador para o estado
@returns A Coordenada
 */
COORDENADA get_ultima_jogada (ESTADO *e);
/**
\brief Funcao para devolver o Jogador Atual
@param e Apontador para o estado
@returns O jogador atual
 */
int get_jogador_atual (ESTADO *e);
// Cria uma lista vazia
/**
\brief Função que cria uma lista ligada
@returns A lista criada
*/
LISTA criar_lista();
// Insere um valor na cabeça da lista
/**
\brief Função que insere um nodo no ínicio da lista
@param l Lista ligada
@param valor Apontador para o valor do nodo a inserir
@returns A nova lista
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
\brief Função que testa se a Coordenada pertence ao Tabuleiro;
@param c Coordenada
@returns Devolve 1 se está dentro do tabuleiro
 */
int dentroTabuleiro(COORDENADA c);
#endif //BOT2_AUX_H
