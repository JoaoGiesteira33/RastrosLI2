/**
@file lista.h
Funções para utilizar listas ligadas
*/


#ifndef RASTROSLI2_LISTA_H
#define RASTROSLI2_LISTA_H
/**
\brief Tipo de dados para as listas ligadas.
*/
typedef struct nodo {
    /** apontador para o valor do nodo */
    void *valor;
    /** apontador para o proximo nodo*/
    struct nodo *prox;
} Nodo, *LISTA;

// Cria uma lista vazia

/**
\brief Função que cria uma lista ligada

*/
LISTA criar_lista();
// Insere um valor na cabeça da lista
/**
\brief Função que insere um nodo no ínicio da lista
@param l Lista ligada
@param valor Apontador para o valor do nodo a inserir
*/
LISTA insere_cabeca(LISTA L, void *valor);
// Devolve a cabeça da lista
/**
\brief Função que devolve a cabeça da lista
@param l Lista ligada
*/
void *devolve_cabeca(LISTA L);
/**
\brief Função que insere um nodo no ínicio da lista
@param l Lista ligada
@param valor Apontador para o valor do nodo a inserir
*/
// Devolve a cauda da lista
LISTA proximo(LISTA L);
/**
\brief Função que remove a cabeça da lista e devolve a cauda
@param l Lista ligada
*/
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
/**
\brief Função que verifica se a lista está vazia
@param l Lista ligada
*/
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);
#endif //RASTROSLI2_LISTA_H
