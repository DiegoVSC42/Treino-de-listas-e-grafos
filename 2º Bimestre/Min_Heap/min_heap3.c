#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int vertice;
    int distancia;
}Elemento;

Elemento heap[1000];
int contador_heap = 0;

int define_pai(int indice){
    return indice / 2;
}
int define_filho_esquerda(int indice){
    return indice * 2;
}
int define_filho_direita(int indice){
    return indice * 2 + 1;
}

void subir_minimo(int indice){
    if(indice > 1){
        Elemento aux;
        int pai = define_pai(indice);
        if(heap[indice].distancia < heap[pai].distancia){
            aux = heap[indice];
            heap[indice] = heap[pai];
            heap[pai] = aux;
            subir_minimo(pai);
        }
    }
}
void desce_minimo(int indice){
    if(contador_heap < indice * 2){
        return;
    }
    int menor = indice;
    int esquerda = define_filho_esquerda(indice);
    int direita = define_filho_direita(indice);
    if(esquerda <= contador_heap && heap[esquerda].distancia < heap[indice].distancia){
        menor = esquerda;
    }
    if(direita <= contador_heap && heap[direita].distancia < heap[indice].distancia){
        menor = direita;
    }
    if(menor == indice){
        return;
    }
    Elemento aux;

    aux = heap[indice];
    heap[indice] = heap[menor];
    heap[menor] = aux;
    desce_minimo(indice);
}

int push(Elemento x){
    contador_heap++;
    heap[contador_heap] = x;
    subir_minimo(contador_heap);
}

Elemento pop(){
    Elemento retorno;
    if(contador_heap == 0){
        retorno.vertice = -1;
        retorno.distancia = -1;
        return retorno;
    }
    retorno = heap[1];
    heap[1] = heap[contador_heap];
    contador_heap--;
    desce_minimo(1);
    return retorno;
}
int main(int argc, char const *argv[]){
    Elemento aux;
    aux.distancia = 1;
    aux.vertice = 1;
    push(aux);
    aux.distancia = 10;
    aux.vertice = 10;
    push(aux);
    aux.distancia = 2;
    aux.vertice = 2;
    push(aux);
    aux.distancia = 9;
    aux.vertice = 9;
    push(aux);

    Elemento retorno;

    while(retorno.distancia != -1){
        retorno = pop(heap);
        if(retorno.distancia != -1){
            printf("\n Vertice: %d Distancia %d", retorno.vertice, retorno.distancia);
        }
    }
    return 0;
}
