#include "camadadados.h"
#include "logica.h"
#include <stdio.h>
#include <math.h>
/**
 @file logica.c
 Funcão Jogar e funcões complementares a esta.
 */


/**
\brief Funcão que verifica se a casa para a qual o jogador pretende jogar é valida, ou seja, se encontra-se na distancia de uma casa.
 */
int verifica_movimentos (ESTADO *estado, COORDENADA c)
{
   int c1, c2, linha1, linha2;
    c1 =   estado->ultima_jogada.coluna;
    linha1 = estado->ultima_jogada.linha;
    c2 =  c.coluna;
    linha2 =  c.linha;
    if ((abs(c1-c2)== 1) || (abs(linha1-linha2)== 1)){
        return 1;
    }
    else
        return 0;
}

/**
\brief Funcão que verifica se a casa para onde o jogador pretende jogar é válida, neste caso Vazia.
*/
int verifica_vazio(ESTADO *estado, COORDENADA c) {
    int c2, l2;

    c2 = c.coluna;
    l2 = c.linha;
    if (estado->tab[l2][c2] == VAZIO)
        return 1;
    else
        return 0;
}

/**
\brief Função que altera o estado da casa e alterna a vez de jogar.
*/
int funcao_jogada (ESTADO *estado, COORDENADA c) {

    //Pode jogar
    estado -> tab[c.linha][c.coluna] = BRANCA;
    //Atualiza a peça de onde sai
    int x = estado ->ultima_jogada.linha;
    int y = estado-> ultima_jogada.coluna;

    estado -> tab [x] [y] = PRETA;
    //Atualiza o jogador
    if (estado-> jogador_atual == 1)
        estado-> jogador_atual = 0;
    else
        estado-> jogador_atual = 1;

    printf("jogar %d  %d\n", c.linha, c.coluna);
    return 1;

}
/**
\brief Função principal que efetua a jogada.
*/
int jogar(ESTADO *estado, COORDENADA c)
{

    if (verifica_movimentos(estado, c) && verifica_vazio(estado,c))  {

        funcao_jogada (estado,c);

    }

    else
    {
        //Nao pode jogar
        return 0;
    }
}
