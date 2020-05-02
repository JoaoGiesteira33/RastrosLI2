#include "lista.h"
#include <stdlib.h>


LISTA criar_lista() { // Funcao que cria uma lista
LISTA nova = malloc(sizeof(Nodo)); // Reserva Memoria
nova ->prox = NULL;
nova->valor = NULL;
return nova;
}

LISTA insere_cabeca(LISTA L, void *valor) { // Insere um Nodo na Lista
    LISTA nova = malloc(sizeof(Nodo)); // Reserva Memoria para o novo nodo
    nova-> valor= valor;
    nova-> prox= L;
    return nova;
}

void *devolve_cabeca(LISTA L) { // Funcao que Devolve a cabeca da lista
    void* ans;
    if (L) ans = L->valor;
    else ans =NULL;
    return ans;
}

LISTA proximo(LISTA L) { // Funcao para percorrer a lista
    LISTA cauda;
    cauda = ((L ) ? L->prox : NULL);
    return cauda;
}

LISTA remove_cabeca(LISTA L) { // Funcao para remover um nodo da lista (cabeca)
    LISTA nova;
    nova = L;
    L = proximo (L);
    free(nova); // Liberta a Memoria alocada
    return L;
}

int lista_esta_vazia(LISTA L) {  // Verifica se a lista esta vazia
    int r ;
    if (L -> valor == NULL) r=1; else r=0;
    return r;
}
