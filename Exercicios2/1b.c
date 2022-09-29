/*
Faça um programa que receba do usuário N pares de valores, onde cada PAR representa uma aresta 
bidirecional entre cada valor do par

Mostre uma matriz de adjacencia que represente esse grafo
Mostre uma lista de adjacencia que represente esse grafo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int valor;
    struct Vertice *proximo;
}Vertice;

Vertice *aloca_vertice(int valor){
    Vertice *vertice;
    vertice = (Vertice *)malloc(sizeof(Vertice));
    vertice->valor = valor;
    vertice->proximo = NULL;
    return vertice;
}

void insere_lista(Vertice *vertice, int valor){

    Vertice *aux;
    aux = vertice;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = aloca_vertice(valor);
    
}
void insere_aresta(Vertice **vertice, int origem, int destino){
    insere_lista(vertice[origem], destino);
    insere_lista(vertice[destino], origem);
}

void mostra_lista_adjacencia(Vertice *vertice){    
    Vertice *aux;
    aux = vertice;
    while(aux != NULL){
        printf("%d ->", aux->valor);
        aux = aux->proximo;
    }
}

int main(int argc, char const *argv[]){

    int qtd_vertices;
    int origem, destino;

    scanf("%d",&qtd_vertices);
    Vertice **vertice;
    vertice = (Vertice **)malloc(sizeof(Vertice *)*qtd_vertices);

    for(int i = 0; i < qtd_vertices; i++){
        vertice[i] = aloca_vertice(i);
    }
    for(int i = 0; i < qtd_vertices; i++){
        scanf("%d %d",&origem, &destino);
        insere_aresta(vertice,origem-1,destino-1);
    }
    for(int i = 0; i < qtd_vertices; i++){
        mostra_lista_adjacencia(vertice[i]);
    }
    
    return 0;
}
