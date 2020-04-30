#include <stdio.h>
#include <stdlib.h>
#include "Bot.c"
#include "Bot.h"


int main(int argc, char* argv[]) {

    if (argc == 3) {
        char *ficheiroR, *ficheiroE;
        ficheiroR = argv[1];
        ficheiroE = argv[2];
        ESTADO *e = inicializar_estado();
        ler(e, ficheiroR);
        funcao_jogada(e);
        gravar(e, ficheiroE);
    }
    return 0;
}
