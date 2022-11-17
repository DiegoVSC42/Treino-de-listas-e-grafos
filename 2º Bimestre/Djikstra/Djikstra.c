#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

typedef struct Aresta{
    int origem;
    int destino;
    int distancia;
}Aresta;

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

void descer_minimo(int indice){
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
    descer_minimo(indice);
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
    contador_heap;
    descer_minimo(1);
    return retorno;
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    Aresta aresta[1000];
    Elemento aux;
    int qtd_vertices,qtd_arestas;

    printf("\nDigite a quantidade de vertices e arestas : ");
    scanf("%d %d", &qtd_vertices,&qtd_arestas);
    printf("\nDigite a origem, destino e distancia de cada aresta");
    for(int i = 1; i < qtd_arestas ; i++){
        scanf("%d %d %d",aresta[i].origem,aresta[i].destino, aresta[i].distancia);
        insere_aresta(vertice,aresta[i].origem,aresta[i].destino);
    }
    
    return 0;
}
