#include <stdio.h>
#include "camadadados.h"
#include "interface.h"

/**
 * Funcao Principal do Jogo Rastros
 */

int main()
{
    ESTADO *e = inicializar_estado();
    ESTADO *aux = inicializar_estado_aux();
    mostrar_tabuleiro(e);
    interpretador(e,aux);

    return 0;
}

//Corrigir pos da jogada atual
//Letras maiusculas(sera)
//Atualizar casa vencedora no tabuleiro
//Pos 0 tudo fodido