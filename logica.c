#include "camadadados.h"
#include "logica.h"
#include <stdio.h>
#include <math.h>

int verifica_movimentos(ESTADO *estado, COORDENADA c)
{
    int c1, c2, l1, l2;
    c1 = estado->ultima_jogada.coluna;
    l1 = estado->ultima_jogada.linha;
    c2 = c.coluna;
    l2 = c.linha;

    if ((sqrt((c1 - c2) ^ 2 - (l1 - l2) ^ 2)) == 1)
        return 1;
    else
        return 0;
}

int jogar(ESTADO *estado, COORDENADA c)
{
    printf("jogar %d %d\n", c.coluna, c.linha);
    //Primeiro verifica se pode jogar^
    if (verifica_movimentos(estado, c))
    {
        //Pode jogar
        estado->tab[c.linha][c.coluna] = BRANCA;
        int x = estado->ultima_jogada.linha;
        int y = estado->ultima_jogada.coluna;
        estado->tab[x][y] = PRETA;

        return 1;
    }
    else
    {
        //Nao pode jogar
        return 0;
    }
}
