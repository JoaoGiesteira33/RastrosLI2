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
void movimentos(ESTADO*e);
/**
\brief Função que mostra o tabuleiro
@param estado O estado
*/
void mostrar_tabuleiro(ESTADO *estado);
/**
\brief Grava o estado do tabuleiro
@param e Apontador para o estado
@param ficheiro Apontador para o nome do ficheiro
 @returns Devolve OK se conseguiu gravar
*/
ERROS gravar(ESTADO *e,char *ficheiro);
/**
\brief Função que faz a leitura do tabuleiro
@param e Apontador para o estado
@param ficheiro Apontador para o nome do ficheiro
@returns Devolve OK se conseguiu ler
*/
ERROS ler (ESTADO* e,char*ficheiro);
/**
\brief Função principal que efetua a jogada.
@param estado Apontador para o estado
@param c A coordenada
*/
void jogar(ESTADO *estado, COORDENADA c);
/**
\brief Interpretador de comandos
@param e Apontador para o estado
@returns Devolve 1 no final do programa
*/
int interpretador(ESTADO *e,ESTADO *aux);



#endif //RASTROSLI2_INTERFACE_H
