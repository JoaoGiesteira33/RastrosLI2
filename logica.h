/**
@file logica.h
Definição da lógica do programa
*/


#ifndef RASTROSLI2_LOGICA_H
#define RASTROSLI2_LOGICA_H

/**
\brief Funcão que verifica se a casa para a qual o jogador pretende jogar é valida, ou seja, se encontra-se na distancia de uma casa.
@param e Apontador para o estado
@param c A coordenada
*/
int verifica_movimentos(ESTADO *estado, COORDENADA c);
/**
\brief Funcão que verifica se a casa para onde o jogador pretende jogar é válida, neste caso Vazia.
@param e Apontador para o estado
@param c A coordenada
*/
int verifica_vazio(ESTADO *estado, COORDENADA c);
/**
\brief Função principal que efetua a jogada.
@param e Apontador para o estado
@param c A coordenada
*/
int jogar(ESTADO *estado, COORDENADA c);
/**
\brief Função que verifica se o jogador não tem mais nenhuma jogada válida
@param e Apontador para o estado
*/
int encurralado (ESTADO *estado);
/**
\brief Função para determinar o final do Jogo e consequente mensagem de congratulação.
@param e Apontador para o estado
@param c A coordenada
*/
int jogada_final (ESTADO *estado, COORDENADA c);
#endif //RASTROSLI2_LOGICA_H
