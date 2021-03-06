/**
@file camadadados.h
Definição do estado e das funções que o manipulam
*/
#ifndef RASTROSLI2_CAMADADADOS_H
#define RASTROSLI2_CAMADADADOS_H
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
\brief Inicializa um estado
 */
ESTADO *inicializar_estado();
/**
\brief Retorna o número de jogadas
@param estado Apontador para o estado
@returns O número de jogadas
*/
int obter_numero_de_jogadas(ESTADO *estado);
/**
\brief  Converte a ultima jogada linha
@param c A Coordenada
@returns A linha da última jogada
*/
int conversorultimajogadalinha (COORDENADA c);
/**
\brief Converte a ultima jogada coluna
@param c A coordenada
@returns A coluna da última jogada
*/
char conversorultimajogadacoluna (COORDENADA c);
/**
\brief Obtém o estado da casa
@param e Apontador para o estado
@param c A coordenada
@returns O estado da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
/**
\brief Funcao que armaneza jogadas
@param e Apontador para o estado
@param jog Jogada a ser guardada
@param n Número da jogada
*/
void armazenar_jogada(ESTADO *e,JOGADA jog, int n);
/**
\brief Funcao para devolver a coordenada do Jogador 1 numa Jogada c
@param e Apontador para o estado
@param c Numero da Jogada
@return A Coordenada
 */
COORDENADA get_coord_jogador1 (ESTADO *e, int c);
/**
\brief Funcao para devolver a coordenada do Jogador 2 numa Jogada c
@param e Apontador para o estado
@param c Numero da Jogada
@return A Coordenada
 */
COORDENADA get_coord_jogador2 (ESTADO *e, int c);
/**
\brief Funcao para devolver a coluna de uma jogada
@param c A coordenada
@return A coluna
 */
int get_coord_coluna (COORDENADA c);
/**
\brief Funcao para alterar a ultima jogada no estado
@param e Apontador para o estado
@param c Coordenada a Alterar
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
\brief Funcao para devolver a coordenada da ultima jogada
@param e Apontador para o estado
@returns A Coordenada
 */
COORDENADA get_ultima_jogada (ESTADO *e);
/**
\brief Funcao para alterar o estado da casa para Branca
@param e Apontador para o estado
@param c A coordenada a alterar
 */
void altera_estado_casa_branca (ESTADO *e, COORDENADA c);
/**
\brief Funcao para incrementar o numero de jogadas
@param e Apontador para o estado
 */
void incrementa_numero_jogadas (ESTADO *e);
/**
\brief Funcao para inserir uma Jogada do Jogador 1 no estado
@param e Apontador para o estado
@param c A coordenada a inserir
@param n Numero da Jogada
 */
void set_jogadas_jogador1 (ESTADO *e, COORDENADA c, int n);
/**
\brief Funcao para inserir uma Jogada do Jogador 2 no estado
@param e Apontador para o estado
@param c A coordenada a inserir
@param n Numero da Jogada
 */
void set_jogadas_jogador2 (ESTADO *e, COORDENADA c, int n);
/**
\brief Funcao para alterar o estado da casa para Preta
@param e Apontador para o estado
@param c A coordenada a alterar
 */
void altera_estado_casa_preta (ESTADO *e, COORDENADA c);
/**
\brief Funcao para devolver o Jogador Atual
@param e Apontador para o estado
@returns O jogador atual
 */
int get_jogador_atual (ESTADO *e);
/**
\brief Funcao para alterar o Jogador Atual
@param e Apontador para o estado
@param x Jogador a Alterar
 */
void set_jogador_atual (ESTADO *e, int x);
/**
\brief Funcao para alterar o Vencedor do Jogo
@param e Apontador para o estado
@param c O Vencedor
 */
void set_jogador_vencedor(ESTADO *e, int x);
/**
\brief Funcao para alterar o numero de jogadas
@param e Apontador para o estado
@param c Numero de Jogadas a alterar
 */
void set_numero_jogadas (ESTADO *e, int x);
/**
\brief Funcao para alterar o estada de uma casa para Vazio
@param e Apontador para o estado
@param c A coordenada da casa a alterar
 */
void altera_estado_casa_vazio (ESTADO *e, COORDENADA c);
/**
\brief Funcao para alterar as coordenadas da ultima jogada na funcao pos
@param e Apontador para o estado
@param c Inteiro para indicar a Jogada a utilizar
 */
void altera_ultimajogada_pos (ESTADO *e, int jogada);
/**
\brief Funcao para obter a Coordenada do Jogador 1 numa certa Jogada
@param e Apontador para o estado
@param n Inteiro que indica a Jogada
@returns A coordenada
 */
COORDENADA get_jogadas_jogador1 (ESTADO *e, int n);
/**
\brief Funcao para obter a Coordenada do Jogador 2 numa certa Jogada
@param e Apontador para o estado
@param n Inteiro que indica a Jogada
@returns A coordenada
 */
COORDENADA get_jogadas_jogador2 (ESTADO *e, int n);
/**
\brief Funcao para alterar as coordenadas de casas nao utilizadas para -1
@param e Apontador para o estado
@param c Inteiro que indica a Jogada a alterar
 */
void set_casas_invalidas (ESTADO *e, int n);
/**
\brief Funcao para obter o numero de jogadas
@param e Apontador para o estado
@returns O número de jogadas
 */
int get_num_jogadas (ESTADO *e);
/**
\brief Função para inicializar um estado auxiliar que nos permite andar jogadas para a frente na funcao pos.
@returns O novo estado
 */
ESTADO *inicializar_estado_aux();
/**
\brief Função para obter o jogador vencedor.
@param e Apontador para o estado
@returns O jogador vencedor
 */
int get_jogador_vencedor (ESTADO *e);
/**
\brief Funcao que atualiza os valores das casas para a floodfill
@param e Apontador para o estado
@param valores Valores do tabuleiro
 */
void set_valores (ESTADO *e, int valores[8][8]);
/**
\brief Função que testa se a Coordenada pertence ao Tabuleiro;
@param c Coordenada
@returns Devolve 1 se está dentro do tabuleiro
 */
int dentroTabuleiro(COORDENADA c);
/**
\brief Função que devolve o valor de uma coordenada segundo o Algoritmo FloodFill
 * @param valores Matriz de Valores
 * @param c Coordenada
 * @return Valor da Coordenada
 */
int get_valores (int valores[8][8], COORDENADA c);

#endif