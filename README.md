# HEAP MÍNIMA
<img src="http://img.shields.io/static/v1?label=STATUS&message=FINALIZADO&color=GREEN&style=for-the-badge"/>
</p>


# Índice 

* [Título](#heap-mínima)
* [Índice](#índice)
* [Descrição do Código](#descrição-do-código)
* [Como baixar](#como-baixar)
* [Como compilar e executar](#como-compilar-e-executar)
* [Funcionalidades do Código](#funcionalidades-do-código)

# DESCRIÇÃO DO CÓDIGO 

O código apresentado utiliza uma blibioteca nomeada **heap.h** encontrada no repositório, utilizando as funções apresentadas na blibioteca o código permite ao usuário manipular uma Heap Mínima, podendo criar a Heap, adicionar elementos a esta, permitindo também a remoção de elementos da estrutura


# Como baixar 

> **Copie o comando abaixo:**
> 
> ```git clone https://github.com/cleopratr/WORK_LAB_T5```

# Como compilar e executar

> **Após ascessar a pasta com o código no terminal, digite:**
> 
> ```cd WORK_LAB_T5```
>
> ```gcc TR5_540344.c main_heap.c -o T5_540344```
> 
> **Para executar seu código, ainda no terminal digite:** 
> 
> ```./T5_540344```

# Funcionalidades do código

- `HEAP_create`: Recebe um inteiro n e um ponteiro comparado tipo COMP retornandoo novo conjunto de elementos, esta função cria um uma heap mínima
- `HEAP_add`: Recebe um ponteiro heap do tipo HEAP e um ponteiro tipo void chamado newelem, esta função adiciona um elemento a heap
- `HEAP_remove`: Recebe como parâmetro um ponteiro heap retornando aux, essa função remove um elemento da estrutura


