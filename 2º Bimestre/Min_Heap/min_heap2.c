#include <stdio.h>
#include <stdlib.h>


typedef struct Elemento{
    int vertice;
    int distancia;
}Elemento;
typedef struct Heap{
    int tamanho;
    Elemento *vetor;
}Heap;
Heap aloca_heap(int tamanho_limite){
    Heap heap;
    heap.vetor = (Elemento*)calloc(tamanho_limite, sizeof(Elemento));
    heap.tamanho = 0;
    return heap;
}

int define_pai(int indice){
    return indice / 2;
}
int define_filho_esquerda(int indice){
    return indice * 2;
}
int define_filho_direita(int indice){
    return (indice * 2) + 1;
}

void subir_minimo(Heap heap,int indice){
    if(indice > 1){
        Elemento aux;
        int pai = define_pai(indice);
        if(heap.vetor[indice].distancia < heap.vetor[pai].distancia){
            aux = heap.vetor[indice];
            heap.vetor[indice] = heap.vetor[pai];
            heap.vetor[pai] = aux;
            subir_minimo(heap,pai);
        }
    }
}

void desce_minimo(Heap heap,int indice){
    if(heap.tamanho < indice * 2){
        return;
    }
    int esquerda = define_filho_esquerda(indice);
    int direita = define_filho_direita(indice);

    int menor = indice;

    if(esquerda <= heap.tamanho && heap.vetor[esquerda].distancia < heap.vetor[menor].distancia){
        menor = esquerda;
    }
    if (direita <= heap.tamanho && heap.vetor[direita].distancia < heap.vetor[menor].distancia){
        menor = direita;
    }
    if (menor == indice)
        return;

    Elemento aux;

    aux = heap.vetor[indice];
    heap.vetor[indice] = heap.vetor[menor];
    heap.vetor[menor] = aux;
    desce_minimo(heap,menor);
}
int push(Heap heap, Elemento valor){
    heap.tamanho++;
    heap.vetor[heap.tamanho] = valor;
    subir_minimo(heap,heap.tamanho);
}
Elemento pop(Heap heap){
    Elemento retorno;
    if(heap.tamanho == 0){
        retorno.distancia = -1;
        retorno.vertice = -1;
        return retorno;
    }

    retorno = heap.vetor[1];
    printf("\n %d", heap.vetor[1]);
    heap.vetor[1] = heap.vetor[heap.tamanho];
    heap.tamanho--;
    desce_minimo(heap,1);
    return retorno;
}

int main(int argc, char const *argv[]){
    Heap heap;
    heap = aloca_heap(1000);
    Elemento aux;
    aux.distancia = 1;
    aux.vertice = 1;
    push(heap,aux);
    aux.distancia = 10;
    aux.vertice = 10;
    push(heap,aux);
    aux.distancia = 2;
    aux.vertice = 2;
    push(heap,aux);
    aux.distancia = 9;
    aux.vertice = 9;
    push(heap,aux);

    Elemento retorno;

    while(retorno.distancia != -1){
        retorno = pop(heap);
        if(retorno.distancia != -1){
            printf("\n Vertice: %d Distancia %d", retorno.vertice, retorno.distancia);
        }
    }
    return 0;
}
