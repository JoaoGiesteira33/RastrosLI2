//
// Created by daniel on 17/04/20.
//

#include "lista.h"
#include <stdlib.h>


LISTA criar_lista(){
LISTA nova = malloc(sizeof(Nodo));
nova ->prox = NULL;
return nova;
}

LISTA insere_cabeca (LISTA L, void *valor){
    LISTA nova = malloc(sizeof(Nodo));
    nova->valor= valor;
    nova->prox= L;
    return nova;
}

void *devolve_cabeca(LISTA L){
    void* ans;
    if (L) ans = L->valor;
    else ans = NULL;
    return ans;
}


LISTA proximo (LISTA L){
    LISTA cauda;
    cauda = ((L) ? L -> prox : NULL);

    return cauda;
}

LISTA remove_cabeca (LISTA L){
    LISTA nova;
    nova = L;
    L = proximo (L);
    free(nova);
    return L;
}

int lista_esta_vazia(LISTA L){
    int r ;
    if (L) r = 0; else r = 1;
    return r;
}
