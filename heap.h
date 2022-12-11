#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

/*Definicao do tipo de funcao a ser utilizado para comparacao
Esta função recebe dois valores x e y e retorna

1 : se x é menor que y.
0 : se x é equivalente a y.
-1: se x é maior que y na ordem.
*/
typedef int COMP(void* x, void* y);

//Uma Heap estatico. Os elementos do vetor estao colocadoo no vetor
//de acordo com a ordem indicada por comparador.
typedef struct heap{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}HEAP;

/**
Cria um heap vazio de tamanho n e com funcao de comparacao compara

@param n: o tamanho do heap
@param compara: a funcao de comparacao

@return um ponteiro para uma estrutura HEAP, observe que este ponteiro ja
deve apontar para a estrutura, ou seja, a alocacao de memoria deve ser feita nele.
*/
HEAP* HEAP_create(int n, COMP* compara);

/**
Adiciona o elemento newelem ao Heap, na posicao correta se for possível
ainda incluir o elemento (se existe espaco no vetor elems). Observe que 
a estrutura deve respeitar a regra da heap, ou seja, para todo i temos que 
x[i] é menor que ou equivalente a x[2*i] e a x[2*i+1].

@param heap: o heap a ter o elemento incluído
@param newelem: o elemento a ser adicionado
*/
void HEAP_add(HEAP* heap, void* newelem);

/**
Remove o menor elemento do heap, de acordo com a funcao compara

@param heap: o heap a ter seu elemento removido

@return um ponteiro para o elemento que foi removido do heap.
*/
void* HEAP_remove(HEAP* heap);


#endif
