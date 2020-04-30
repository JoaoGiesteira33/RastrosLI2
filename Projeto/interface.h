/**
@file interface.h
Interpretador e funcões complementares a este.
*/


#ifndef RASTROSLI2_INTERFACE_H
#define RASTROSLI2_INTERFACE_H

#include "camadadados.h"
/**
\brief Funcao que imprime as jogadas no ecrã.
@param e Apontador para o ficheiro
*/
int movimentos(ESTADO*e);
/**
\brief Função que mostra o tabuleiro
@param estado O estado
*/
void mostrar_tabuleiro(ESTADO *estado);
/**
\brief Grava o estado do tabuleiro
@param e Apontador para o estado
@param ficheiro Apontador para o nome do ficheiro
*/
ERROS gravar(ESTADO *e,char *ficheiro);
/**
\brief Função principal que efetua a jogada.
@param estado Apontador para o estado
@param c A coordenada
*/
int jogar(ESTADO *estado, COORDENADA c);
/**
\brief Interpretador de comandos
@param e Apontador para o estado
*/
int interpretador(ESTADO *e,ESTADO *aux);




int converteDecimal (char v[]);
#endif //RASTROSLI2_INTERFACE_H
