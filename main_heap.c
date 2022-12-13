#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//Função de comparação
int comparador(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx - pty < 0){
		return -1;
	}else{
		if(ptx - pty > 0) return 1;
		else return 0;
	}
}

//Print para a estrutura
void print(void** vet, int P){
	int i;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < P; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	HEAP* vet = HEAP_create(10, comparador);
	printf("vet tamn %d\n", vet->N);
   	
   	int* x;
   	int i;
   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < 20; i++){
		x = malloc(sizeof(int));
		*x = rand() % 20;
		printf("%d ", *x);
		HEAP_add(vet, x);
	}
	 
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!");
  	int* x = HEAP_remove(vet);
  	
	print("%d \n", (*x));
   
	return 0;  
}
