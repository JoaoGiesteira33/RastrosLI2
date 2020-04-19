#include "camadadados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lista.h"
#define BUF_SIZE 1024


COORDENADA verificaMelhorJogada (LISTA l,COORDENADA c, ESTADO * e){
    int x = c.coluna;
    int y =c.linha;
    LISTA  aux = l;
    double menorDist=1000.0;
    double dist;
    COORDENADA melhorCord = {-1,-1};
    COORDENADA  cord ;

    while (l->valor && l->prox ){
    //for (aux=l;aux;aux=aux->prox) {
        cord = *((COORDENADA *) (l->valor));
        int x1 = cord.coluna;
        int y1 =cord.linha;
        dist = sqrt(((x - x1) *(x-x1)) - ((y - y1)* (y - y1) ));
        if (menorDist>=dist) {
            menorDist= dist;
            melhorCord = cord;

        }
        l = l->prox;
    }

    return melhorCord;
}

int verifica_movimentos (ESTADO *estado, COORDENADA c)
{
   int c1, c2, linha1, linha2;
    c1 =  (get_ultima_jogada(estado)).coluna;
    linha1 = (get_ultima_jogada(estado)).linha;
    c2 =  c.coluna;
    linha2 = c.linha;
    if (((abs(c1-c2)== 1) && (abs(linha1-linha2))== 0) || ((abs(c1-c2)== 0) && (abs(linha1-linha2))== 1) || ((abs(c1-c2)== 1) && (abs(linha1-linha2))== 1)) {
        return 1;
    }
    else return 0;
}


int verifica_vazio(ESTADO *estado, COORDENADA c) {

    if (obter_estado_casa(estado, c) == VAZIO ||obter_estado_casa(estado, c)  == UM || obter_estado_casa(estado, c) == DOIS)
        return 1;
    else
        return 0;
}


int funcao_jogada (ESTADO *estado, COORDENADA c) {
    COORDENADA jogada;

    //Pode jogar
    altera_estado_casa_branca(estado,c);

    if (obter_jogador_atual(estado) == 0)
        incrementa_numero_jogadas(estado);
    //Atualiza o array de jogadas

    int n = obter_numero_de_jogadas(estado)-1;

    if (obter_jogador_atual(estado) == 0){
        set_jogadas_jogador1(estado, c, n);
    }

    else {
        set_jogadas_jogador2(estado, c, n);
    }

    //Atualiza a peça de onde sai
    COORDENADA preta = get_ultima_jogada(estado);

    altera_estado_casa_preta(estado, preta);
    altera_ultimajogada(estado, c);
    //Atualiza o jogador
    if (get_jogador_atual(estado) == 1)
        set_jogador_atual(estado, 0);
    else
        set_jogador_atual(estado, 1);

    //printf("jogar %d  %d\n", c.linha, c.coluna);
    return 1;

}

int encurralado (ESTADO *estado) {
       //coordenada da peça branca atual

       COORDENADA centro = get_ultima_jogada(estado);

       COORDENADA cima = (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha + 1};


       COORDENADA baixo = (COORDENADA) {.coluna = centro.coluna, .linha = centro.linha - 1};

       COORDENADA direita = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha};

       COORDENADA esquerda = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha};

       COORDENADA diagDBaixo = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha - 1};

       COORDENADA diagEBaixo = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha - 1};

       COORDENADA diagDCima = (COORDENADA) {.coluna = centro.coluna + 1, .linha = centro.linha + 1};

       COORDENADA diagECima = (COORDENADA) {.coluna = centro.coluna - 1, .linha = centro.linha + 1};


       if ((obter_estado_casa(estado,cima)) == PRETA &&
          (obter_estado_casa(estado,baixo)) == PRETA &&
          (obter_estado_casa(estado,direita)) == PRETA &&
          (obter_estado_casa(estado,esquerda)) == PRETA &&
          (obter_estado_casa(estado,diagDBaixo)) == PRETA &&
          (obter_estado_casa(estado,diagEBaixo)) == PRETA &&
          (obter_estado_casa(estado,diagDCima)) == PRETA &&
          (obter_estado_casa(estado,diagECima)) == PRETA ) return 1;
       else return 0;
}

int jogada_final (ESTADO *estado, COORDENADA c) {
     if (c.coluna == 0 && c.linha == 7) {
        return 1;
    }//Casa final do Jogador 1
    else if (c.coluna == 7 && c.linha == 0)
        return 1; //Casa final do Jogador 2
    else {
        if (encurralado(estado) == 1)
            return 1;
        else
            return 0;
    }
}

int jogar(ESTADO *estado, COORDENADA c)
{
    //Pode jogar
    if (verifica_movimentos(estado, c) && verifica_vazio(estado,c) && !(jogada_final(estado, c))) {
        funcao_jogada (estado,c);
    }
    else  // Casos para congratular o jogador
    {
        int jogador = obter_jogador_atual(estado);

        if (c.coluna == 0 && c.linha == 7)
            set_jogador_vencedor(estado, 1);
            // printf("Parabens, o vencedor é o Jogador 1\n"); //no caso de chegar a casa final do Jogador 1
        else if (c.coluna == 7 && c.linha == 0)
            set_jogador_vencedor(estado, 2);
            //printf("Parabens, o vencedor é o Jogador 2\n"); //no caso de chegar a casa final do Jogador 2
        else if  (encurralado(estado)&&(jogador == 0))
            set_jogador_vencedor(estado, 2);
            //printf("Parabens, o vencedor é o Jogador 2\n"); //nos casos de os Jogadores se encontrarem rodeados, ou sejam, sem possiblidades de jogarem
        else if  (encurralado(estado)&&(jogador == 1))
            set_jogador_vencedor(estado, 2);
            //printf("Parabens, o vencedor é o Jogador 1\n");
        else
            printf("A jogada nao é válida, tente novamente\n");
    }

        return 0;

}
