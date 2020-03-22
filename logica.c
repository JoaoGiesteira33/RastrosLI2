#include "camadadados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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


int verifica_vazio(ESTADO *estado, COORDENADA c) {
    int c2, l2;

    c2 = c.coluna;
    l2 = c.linha;
    if (estado->tab[c2][l2] == VAZIO || estado->tab[c2][l2] == UM || estado->tab[c2][l2] == DOIS)
        return 1;
    else
        return 0;
}


int funcao_jogada (ESTADO *estado, COORDENADA c) {

    //Pode jogar
    estado -> tab[c.coluna][c.linha] = BRANCA;
    if(obter_jogador_atual(estado) == 1)
        estado -> num_jogadas += 1;

    //Atualiza a peça de onde sai
    int x = estado ->ultima_jogada.linha;
    int y = estado-> ultima_jogada.coluna;
    estado -> tab [y] [x] = PRETA;
    estado -> ultima_jogada.coluna = c.coluna;
    estado -> ultima_jogada.linha = c.linha;
    //Atualiza o jogador
    if (estado-> jogador_atual == 1)
        estado-> jogador_atual = 0;
    else
        estado-> jogador_atual = 1;

    //printf("jogar %d  %d\n", c.linha, c.coluna);
    return 1;

}

int encurralado (ESTADO *estado) {
       //coordenada da peça branca atual
       int ujc = estado -> ultima_jogada.coluna;
       int ujl = estado -> ultima_jogada.linha;

       COORDENADA cima;
       cima.coluna = ujc;
       cima.linha = ujl + 1;

       COORDENADA baixo;
       baixo.coluna = ujc;
       baixo.linha = ujl - 1;

       COORDENADA direita;
       direita.coluna = ujc + 1;
       direita.linha = ujl;

       COORDENADA esquerda;
       esquerda.coluna = ujc - 1;
       esquerda.linha = ujl;

       COORDENADA diagDBaixo;
       diagDBaixo.coluna = ujc + 1;
       diagDBaixo.linha = ujl - 1;

       COORDENADA diagEBaixo;
       diagEBaixo.coluna = ujc - 1;
       diagEBaixo.linha = ujl - 1;

       COORDENADA diagDCima;
       diagDCima.coluna = ujc + 1;
       diagDCima.linha = ujl + 1;

       COORDENADA diagECima;
       diagECima.coluna = ujc - 1;
       diagECima.linha = ujl + 1;

       if ((obter_estado_casa(estado,cima)) == PRETA && (obter_estado_casa(estado,baixo)) == PRETA && (obter_estado_casa(estado,direita)) == PRETA && (obter_estado_casa(estado,esquerda)) == PRETA
       && (obter_estado_casa(estado,diagDBaixo)) == PRETA && (obter_estado_casa(estado,diagEBaixo)) == PRETA && (obter_estado_casa(estado,diagDCima)) == PRETA && (obter_estado_casa(estado,diagECima)) == PRETA ) return 0;
       else return 1;
}

int jogada_final (ESTADO *estado, COORDENADA c) {
    int jogador = obter_jogador_atual(estado);
    if (c.coluna == 0 && c.linha == 7 && jogador == 1) {


        return 0;
    }//Casa final do Jogador 1
    else if (c.coluna == 7 && c.linha == 0 && jogador == 2) return 0; //Casa final do Jogador 2
    else {

        if (encurralado(estado) == 1) return 1;
        else return 0;

    }

}
int jogar(ESTADO *estado, COORDENADA c)
{
    //Pode jogar
    if (verifica_movimentos(estado, c) && verifica_vazio(estado,c) && jogada_final(estado, c)) {
        funcao_jogada (estado,c);
    }
    else  // Casos para congratular o jogador
    {
        int jogador = obter_jogador_atual(estado);

        if (c.coluna == 0 && c.linha == 7 && jogador == 1)
            printf("Parabens, o vencedor é o Jogador 1\n"); //no caso de chegar a casa final do Jogador 1
        else if (c.coluna == 7 && c.linha == 0 && jogador == 2)
            printf("Parabens, o vencedor é o Jogador 2\n"); //no caso de chegar a casa final do Jogador 2
        else if  (encurralado(estado)&&(jogador == 1))
            printf("Parabens, o vencedor é o Jogador 2\n"); //nos casos de os Jogadores se encontrarem rodeados, ou sejam, sem possiblidades de jogarem
        else if  (encurralado(estado)&&(jogador == 2)) printf("Parabens, o vencedor é o Jogador 1\n");
        else  printf("A jogada nao é válida, tente novamente\n");
    }
        return 0;

}
