/**
@file interface.h
Definição da interface do jogo
*/


#ifndef RASTROSLI2_INTERFACE_H
#define RASTROSLI2_INTERFACE_H

#include "camadadados.h"
/**
\brief Interpretador de comandos
@param e Apontador para o estado
*/
int interpretador(ESTADO *e);

/**
\brief Função que mostra o tabuleiro
@param estado O estado
*/
void mostrar_tabuleiro(ESTADO estado);
#endif //RASTROSLI2_INTERFACE_H
