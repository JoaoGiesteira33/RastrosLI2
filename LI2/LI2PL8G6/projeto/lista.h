/**
@file lista.h
Funções para utilizar listas ligadas
*/

#ifndef RASTROSLI2_LISTA_H
#define RASTROSLI2_LISTA_H
/** @struct Nodo
 * @brief Lista de Apontadores
 * @var Nodo::*valor
 * *valor representa um apontador para o enderenco de memoria alocado
 * @var Nodo::*prox
 * *prox representa um apontador para o proximo nodo
 */
typedef struct nodo {
    /** apontador para o valor do nodo */
    void *valor;
    /** apontador para o proximo nodo*/
    struct nodo *prox;
} Nodo, *LISTA;
/**
\brief Função que cria uma lista ligada
@returns A lista criada
*/
LISTA criar_lista(); // Cria uma lista vazia
/**
\brief Função que insere um nodo no ínicio da lista
@param l Lista ligada
@param valor Apontador para o valor do nodo a inserir
@returns A nova lista
*/
LISTA insere_cabeca(LISTA L, void *valor); // Insere um valor na cabeça da lista
/**
\brief Função que devolve a cabeça da lista
@param l Lista ligada
*/
void *devolve_cabeca(LISTA L); // Devolve a cabeça da lista
/**
\brief Função que insere um nodo no ínicio da lista
@param l Lista ligada
@param valor Apontador para o valor do nodo a inserir
@returns A nova lista
*/
LISTA proximo(LISTA L); // Devolve a cauda da lista
/**
\brief Função que remove a cabeça da lista e devolve a cauda
@param l Lista ligada
@returns A nova lista
*/
LISTA remove_cabeca(LISTA L); // Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
/**
\brief Função que verifica se a lista está vazia
@param l Lista ligada
@returns Devolve 1 se a lista estiver vazia
*/
int lista_esta_vazia(LISTA L); // Devolve verdareiro se a lista é vazia
#endif //RASTROSLI2_LISTA_H
