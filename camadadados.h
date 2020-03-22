/**
@file camadadados.h
Definição do estado e das funções que o manipulam
*/

#ifndef RASTROSLI2_CAMADADADOS_H
#define RASTROSLI2_CAMADADADOS_H
/**
\brief Tipo de dados para a casa
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
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
} ESTADO;

/**
\brief Inicializa um estado
 */
ESTADO *inicializar_estado();

/**
\brief Retorna o jogador atual
@param e Apontador para o estado
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Retorna o número de jogadas
@param e Apontador para o estado
*/
int obter_numero_de_jogadas(ESTADO *estado);

/**
\brief Obtém a ultima jogada efetuada
@param e Apontador para o estado
*/
COORDENADA obter_ultima_jogada (ESTADO *estado);

/**
\brief Função auxiliar do prompt
@param c A Coordenada
*/
int conversorultimajogadalinha (COORDENADA c);
/**
\brief Converte a ultima jogada coluna
@param c A coordenada
*/
char conversorultimajogadacoluna (COORDENADA c);

/**
\brief Muda o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@param V O novo valor para a casa
*/
void set_casa(ESTADO *e, COORDENADA c, CASA V);

/**
\brief Obtém o estado da casa
@param e Apontador para o estado
@param c A coordenada
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
#endif //RASTROSLI2_CAMADADADOS_H
