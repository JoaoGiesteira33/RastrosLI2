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
    /** Vencedor atual(0 enquanto nenhum é) */
    int vencedor;
} ESTADO;
/**
\brief Inicializa um estado
 */
ESTADO *inicializar_estado();

/**
\brief Retorna o jogador atual
@param estado Apontador para o estado
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Retorna o número de jogadas
@param estado Apontador para o estado
*/
int obter_numero_de_jogadas(ESTADO *estado);

/**
\brief Obtém a ultima jogada efetuada
@param estado Apontador para o estado
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
\brief Obtém o estado da casa
@param e Apontador para o estado
@param c A coordenada
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
//RASTROSLI2_CAMADADADOS_H
/**
\brief Funcao que traduz de string para COORDENADA
@param coord Apontador para uma coordenada
*/
COORDENADA str_to_coord(char *coord);
/**
\brief Funcao que armaneza jogadas
@param e Apontador para o estado
@param jog Jogada a ser guardada
@param n Número da jogada
*/
void armazenar_jogada(ESTADO *e,JOGADA jog, int n);
/**
\brief Funcao para devolver a coordenada do Jogador 1 numa Jogada c
 * @param e Apontador para o estado
 * @param c Numero da Jogada
 * @return A Coordenada
 */
COORDENADA get_coord_jogador1 (ESTADO *e, int c);
/**
\brief Funcao para devolver a coordenada do Jogador 2 numa Jogada c
 * @param e Apontador para o estado
 * @param c Numero da Jogada
 * @return A Coordenada
 */
COORDENADA get_coord_jogador2 (ESTADO *e, int c);
/**
\brief Funcao para devolver a coluna de uma jogada
 * @param c A coordenada
 * @return A coluna
 */
int get_coord_coluna (COORDENADA c);
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
\brief Funcao para devolver a coordenada da ultima jogada
 * @param e Apontador para o estado
 * @return A Coordenada
 */
COORDENADA get_ultima_jogada (ESTADO *e);
/**
\brief Funcao para alterar o estado da casa para Branca
 * @param e Apontador para o estado
 * @param c A coordenada a alterar
 */
void altera_estado_casa_branca (ESTADO *e, COORDENADA c);
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
\brief Funcao para alterar o Jogador Atual
 * @param e Apontador para o estado
 * @param x Jogador a Alterar
 */
void set_jogador_atual (ESTADO *e, int x);
/**
\brief Funcao para alterar o Vencedor do Jogo
 * @param e Apontador para o estado
 * @param c O Vencedor
 */
void set_jogador_vencedor(ESTADO *e, int x);
/**
\brief Funcao para alterar o numero de jogadas
 * @param e Apontador para o estado
 * @param c Numero de Jogadas a alterar
 */
void set_numero_jogadas (ESTADO *e, int x);
/**
\brief Funcao para alterar o estada de uma casa para Vazio
 * @param e Apontador para o estado
 * @param c A coordenada da casa a alterar
 */
void altera_estado_casa_vazio (ESTADO *e, COORDENADA c);
/**
\brief Funcao para alterar as coordenadas da ultima jogada na funcao pos
 * @param e Apontador para o estado
 * @param c Inteiro para indicar a Jogada a utilizar
 */
void altera_ultimajogada_pos (ESTADO *e, int jogada);
/**
\brief Funcao para obter a Coordenada do Jogador 1 numa certa Jogada
 * @param e Apontador para o estado
 * @param c Inteiro que indica a Jogada
 */
COORDENADA get_jogadas_jogador1 (ESTADO *e, int n);
/**
\brief Funcao para obter a Coordenada do Jogador 2 numa certa Jogada
 * @param e Apontador para o estado
 * @param c Inteiro que indica a Jogada
 */
COORDENADA get_jogadas_jogador2 (ESTADO *e, int n);
/**
\brief Funcao para alterar as coordenadas de casas nao utilizadas para -1
 * @param e Apontador para o estado
 * @param c Inteiro que indica a Jogada a alterar
 */
void set_casas_invalidas (ESTADO *e, int n);
/**
\brief Funcao para obter o numero de jogadas
 * @param e Apontador para o estado
 */
int get_num_jogadas (ESTADO *e);
ESTADO *inicializar_estado_aux();
#endif