#define vertex int /*variavel do tipo inteiro que sera usada para n*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
    int vertice;     
    int aresta; 
    int **matriz_adjacencia; 
}Grafo;

typedef struct grafo *Grafo;

/*                      MATRIZ                              */
/*
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
}*/