#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->distancia = 0;
    vertice->visitado = 0;
    vertice->tamanho_lista = 0;
    return vertice;
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}
int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int qtd_gurias;
    int *gurias;
    gurias = (int*)calloc(qtd_gurias,sizeof(int));
    scanf("%d",&qtd_vertices);
    qtd_arestas = qtd_vertices-1;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d",&origem, &destino);
    }
    

    return 0;
}
