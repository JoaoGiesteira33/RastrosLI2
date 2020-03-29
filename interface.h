/**
@file interface.h
Interpretador e funcões complementares a este.
*/


#ifndef RASTROSLI2_INTERFACE_H
#define RASTROSLI2_INTERFACE_H

#include "camadadados.h"
/**
\brief Funcao que traduz de string para COORDENADA
@param coord Apontador para uma coordenada
*/
COORDENADA str_to_coord(char *coord);
/**
\brief Funcao que imprime as jogadas no ecrã.
@param e Apontador para oo ficheiro
*/
int movimentos(ESTADO*e);
/**
\brief Funcao que inicializa o tabuleiro.
@param file Apontador para um ficheiro
*/
ERROS lerFicheiro(char *fich);
/**
\brief Interpretador de comandos
@param e Apontador para o estado
*/
int interpretador(ESTADO *e);

/**
\brief Grava o estado do tabuleiro
@param e Apontador para o estado
@param ficheiro Apontador para o nome do ficheiro
*/
ERROS gravar(ESTADO *e,char *ficheiro);
/**
\brief Função que mostra o tabuleiro
@param estado O estado
*/
void mostrar_tabuleiro(ESTADO *estado);
#endif //RASTROSLI2_INTERFACE_H
