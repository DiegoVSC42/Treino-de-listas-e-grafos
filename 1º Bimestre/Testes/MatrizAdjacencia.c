#define vertex int /*variavel do tipo inteiro que sera usada para n*/
#include <stdio.h>
#include <stdlib.h>

struct grafo{
    int vertice;     
    int aresta; 
    int **matriz_adjacencia; 
};

typedef struct grafo *Grafo;

int **matriz_inteiros(int linhas, int colunas, int valor){
    int **matriz = malloc(linhas * sizeof(int*));
    for(vertex i = 0 ; i < linhas ; i++){
        matriz[i] = malloc(colunas * sizeof(int*));
    }
    for(vertex i = 0 ; i < linhas ; i++){
        for (vertex j = 0; j < colunas; ++j)
            matriz[i][j] = valor;
    }
    return matriz;
}

Grafo inicia_grafo(int vertice){
    Grafo grafo;
    grafo = malloc(sizeof(Grafo));
    grafo->vertice = vertice;
    grafo->aresta = 0;
    grafo->matriz_adjacencia = matriz_inteiros(vertice,vertice,0);
    return grafo;
}

void insere_aresta(Grafo grafo, vertex L, vertex C){
    if(grafo->matriz_adjacencia[L][C] == 0){
        grafo->matriz_adjacencia[L][C] = 1;
        grafo->aresta++;
    }
}

void remove_aresta(Grafo grafo, vertex L, vertex C){ 
    if (grafo->matriz_adjacencia[L][C] == 1) {
        grafo->matriz_adjacencia[L][C] = 0; 
        grafo->aresta;
    }
}

/* PARA IMPRIMIR COMO LISTA*/
/*
void mostra_grafo(Grafo grafo) { 
    for (vertex L = 0; L < grafo->vertice; L++) {
        printf("%2d:", L);
        for (vertex C = 0; C < grafo->vertice; C++)
            if (grafo->matriz_adjacencia[L][C] == 1) 
                printf( " %2d", C);
        printf("\n");
    }
}*/

void mostra_grafo(Grafo grafo) { 
    printf("   ");
    for(vertex C = 0; C < grafo->vertice ; C++){
        printf("%d  ",C);
    }
    printf("\n");
    for (vertex L = 0; L < grafo->vertice; L++){
        printf("%d: " ,L);
        for (vertex C = 0; C < grafo->vertice; C++)
            printf("%d  ",grafo->matriz_adjacencia[L][C]);
        printf("\n");
    }
}
int main(int argc, char const *argv[]){
    
    int N;
    int a,b;
    Grafo grafo;

    printf("Digite a quantidade de arestas: ");
    scanf("%d", &N);

    grafo = inicia_grafo(N*2);

    printf("Digite os pares com valores de 0 a %d\n", (N*2) - 1);
    
    for(int i = 0; i < N ; i++){
        scanf("%d %d",&a,&b);
        insere_aresta(grafo,a,b);
        insere_aresta(grafo,b,a);
        insere_aresta(grafo,a,a);
        insere_aresta(grafo,b,b);
    }
    mostra_grafo(grafo);
    return 0;
}
