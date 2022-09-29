/*
https://www.spoj.com/problems/PT07Z/
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

Vertice *aloca_verice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices + 1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->distancia = 0;
    vertice->tamanho_lista = 0;
    return vertice;
}
