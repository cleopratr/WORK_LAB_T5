#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP* HEAP_create(int n, COMP* compara){
    HEAP* novo = malloc(sizeof(HEAP)); // ponteiro para o conjunto heap
    novo -> N = n; // tamanho do vetor
    novo -> P = 0; // num de elementos do vetor
    novo -> elems = malloc(sizeof(void*) * n);
    for(int r = 0; r < n; r++){ // r é contador e index (posição do vetor) // a função for percorre o vetor
        novo -> elems[r] = NULL; // novo -> elems vetor de ponteiros 
    }
    novo -> comparador  = compara; // definindo a função comparador do vetor
    return novo; // retornando o conjunto de elementos
} 

void HEAP_add(HEAP* heap, void* newelem){
    if(heap -> P < heap -> N){
        if(heap -> P == 0){ // checando se o número de elemtos é igual a zero
           heap -> elems[0] = newelem; // vetor recebe novo elemento
           heap -> P++; // adiciona mais um ao número de elementos ao vetor 
        }else{
            int pos = heap -> P; // posição do vetor
            int pai = (pos - 1 )/ 2; // indice do pai
            heap -> elems [pos] = newelem; // adicionando na última posição do vetor
            while(heap -> comparador(heap -> elems[pos], heap -> elems[pai])== 1){ // enquanto o elemento na posição é menor que o pai dele 
                void* aux = heap -> elems[pai]; // acessando o vetor no index pai e salvando em aux
                heap -> elems[pai] = heap -> elems[pos]; // trocando as posições
                heap -> elems[pos] = aux; // trocando pos para aux que era pai 
                pos = pai; // pos se torna pai
                pai = (pos - 1)/ 2; // novo pai sendo calculado
                if(pai< 0) break;
            }
            heap->P++;
        }
    }
}

void* HEAP_remove(HEAP* heap){
	if(heap->P > 0){
		void* aux = heap->elems[0]; // salva o primeiro elemento em um auxiliar
		heap->elems[0] = heap->elems[heap->P - 1]; // remove o primeiro utilizando o segundo elemento
		heap->P--;
		int pos = 0; // sobe a posição para zero
		int filho = 2*pos + 1; // e a posição do filho para um
		while(filho < heap->P){ // verifica se o elemento existe
			if(filho + 1 < heap->P){ // checa se ainda existe filho na direita
				if(heap->comparador(heap->elems[filho], heap->elems[filho + 1]) == -1){ // se existir faço a comparação se o primeiro e o segundo
					filho++; // se o primeiro for menor que o segundo, soma-se mais um ao filho
				}
			}
			if(heap->comparador(heap->elems[pos], heap->elems[filho]) == -1){ // se for menor que o filho é trocado de local
				void* aux2 = heap->elems[pos];
				heap->elems[pos] = heap->elems[filho];
				heap->elems[filho] = aux2;
				pos = filho;
				filho = 2*pos + 1;
			}else{
				break;
			}
		}
		return aux;
	}
} 

