#include <stdio.h>
#include "camadadados.h"
#include "interface.h"

/**
 * Funcao Principal do Jogo Rastros
 */

int main()
{
    ESTADO *e = inicializar_estado();
    interpretador(e);

    return 0;
}
