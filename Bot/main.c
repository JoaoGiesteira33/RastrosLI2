#include <stdio.h>
#include <stdlib.h>
#include "Bot.c"
#include "Bot.h"
#include <time.h>

int main(int argc, char* argv[]) {

    if (argc == 3) {
        clock_t start, end;
        double cpu_time_used;
        char *ficheiroR, *ficheiroE;
        ficheiroR = argv[1];
        ficheiroE = argv[2];
        ESTADO *e = inicializar_estado();
        ler(e, ficheiroR);
        start = clock();
        funcao_jogada(e);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        gravar(e, ficheiroE);
        printf ("Tempo de CPU : %f\n", cpu_time_used);
    }
    return 0;
}
