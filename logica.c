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
    if (estado->tab[c2][l2] == VAZIO)
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

    estado -> tab [y] [x] = PRETA;
    //Atualiza o jogador
    if (estado-> jogador_atual == 1)
        estado-> jogador_atual = 0;
    else
        estado-> jogador_atual = 1;

    printf("jogar %d  %d\n", c.linha, c.coluna);
    return 1;

}
/**
\brief Função para determinar se as casas em volta da casa atual se encontram todas no estado Preta.
*/
int encurralado (ESTADO *estado) {
       //coordenada da peça branca atual
       int ujc = estado -> ultima_jogada.coluna;
       int ujl = estado -> ultima_jogada.linha;

       COORDENADA *cima;
       cima -> coluna = ujc;
       cima -> linha = ujl + 1;

       COORDENADA *baixo;
       baixo -> coluna = ujc;
       baixo -> linha = ujl - 1;

       COORDENADA *direita;
       direita -> coluna = ujc + 1;
       direita -> linha = ujl;

       COORDENADA *esquerda;
       esquerda -> coluna = ujc - 1;
       esquerda -> linha = ujl;

       COORDENADA *diagDBaixo;
       diagDBaixo -> coluna = ujc + 1;
       diagDBaixo -> linha = ujl - 1;

       COORDENADA *diagEBaixo;
       diagEBaixo-> coluna = ujc - 1;
       diagEBaixo -> linha = ujl - 1;

       COORDENADA *diagDCima;
       diagDCima -> coluna = ujc + 1;
       diagDCima -> linha = ujl + 1;

       COORDENADA *diagECima;
       diagECima -> coluna = ujc - 1;
       diagECima -> linha = ujl + 1;

       if ((obter_estado_casa(estado,*cima)) == PRETA && (obter_estado_casa(estado,*baixo)) == PRETA && (obter_estado_casa(estado,*direita)) == PRETA && (obter_estado_casa(estado,*esquerda)) == PRETA
       && (obter_estado_casa(estado,*diagDBaixo)) == PRETA && (obter_estado_casa(estado,*diagEBaixo)) == PRETA && (obter_estado_casa(estado,*diagDCima)) == PRETA && (obter_estado_casa(estado,*diagECima)) == PRETA ) return 0;
       else return 1;
}




/**
\brief Função para determinar o final do Jogo e consequente mensagem de congratulação.
*/
int jogada_final (ESTADO *estado, COORDENADA c) {
   int jogador = obter_jogador_atual(estado);
   if (c.coluna == 0 && c.linha == 7 && jogador == 1) return 0;//Casa final do Jogador 1
        else if (c.coluna == 7 && c.linha == 0 && jogador == 2) return 0; //Casa final do Jogador 2
        else if (encurralado(estado));

        }

/**
\brief Função principal que efetua a jogada.
*/
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
            printf("Parabens, o vencedor é o Jogador 1"); //no caso de chegar a casa final do Jogador 1
        else if (c.coluna == 7 && c.linha == 0 && jogador == 2)
            printf("Parabens, o vencedor é o Jogador 2"); //no caso de chegar a casa final do Jogador 2
        else if  (encurralado(estado)&&(jogador == 1))
            printf("Parabens, o vencedor é o Jogador 2"); //nos casos de os Jogadores se encontrarem rodeados, ou sejam, sem possiblidades de jogarem
        else if  (encurralado(estado)&&(jogador == 2)) printf("Parabens, o vencedor é o Jogador 1");
        else  printf("A jogada nao é válida, tente novamente");
    }

        return 0;

}
