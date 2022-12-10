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
            int pos = heap -> P;
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
    void* lixeira = heap -> elems[0];

    int pos = 0;
    int filho1 = 1;
    int filho2 = 2;
    while(2*pos + 1 < heap->N && (heap -> elems[filho1]!= NULL || heap -> elems[filho2]!= NULL)){ //verifica se os dois filhos são diferentes de null
        if(heap -> elems[filho1]!= NULL && heap -> elems[filho2]!= NULL){ 
            if(*(int*)(heap -> elems[filho1]) < *(int*)(heap -> elems[filho2])){ //verifica se o primeiro filho é menor que o segundo
                heap -> elems[pos] = heap -> elems[filho1]; // sobe o primeiro filho menor para cima
                pos = filho1; // pos vira filho 1
                filho1 = 2*pos+1; // recalcula filho1 e filho2
                filho2 = 2*pos+2;
            }else{
                heap -> elems[pos] = heap -> elems[filho2]; // POS SE TORNA O FILHO DOIS
                pos = filho2;
                filho1 = 2*pos+1; // RECALCULA OS FILHOS
                filho2 = 2*pos+2;
            }
        } else{ // CASO DE SER APENAS UM FILHO
            if(heap -> elems[filho1]!= NULL){ 
                heap -> elems[pos] = heap -> elems[filho1];
                pos = filho1;
                filho1 = 2*pos+1;
                filho2 = 2*pos+2;        
            }else{
                heap -> elems[pos] = heap -> elems[filho2];
                pos = filho2;
                filho1 = 2*pos+1;
                filho2 = 2*pos+2;              
            }
        }
    }
    if(filho2 < 2 * pos + 1);
    heap -> elems[pos] = NULL; // REMOVE O VALOR QUE IRÁ SE REPETIR DEIXANDO NULL
    heap->P--;
    return lixeira;
} 

   