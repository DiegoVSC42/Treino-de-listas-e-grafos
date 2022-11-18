#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int tam_lista_adj;
    int lista_adj[1000];
}Vertice;

typedef struct Aresta{
    int origem;
    int destino;
    int distancia;
}Aresta;

void insere_aresta(Vertice *vertice, Aresta aresta){
    vertice[aresta.origem].lista_adj[vertice[aresta.origem].tam_lista_adj] = aresta.destino;
    vertice[aresta.origem].tam_lista_adj++;
    vertice[aresta.destino].lista_adj[vertice[aresta.destino].tam_lista_adj] = aresta.origem;
    vertice[aresta.destino].tam_lista_adj++;
}

void prim(Vertice *vertice, int raiz){

}

int main(int argc, char const *argv[]){
    
    Vertice *vertice;
    Aresta aresta[1000];
    int qtd_vertices, qtd_arestas;

    printf("\nDigite a quantidade de vertices e arestas");
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice = (Vertice*)calloc(qtd_vertices + 1,sizeof(Vertice));
    printf("\nDigite as arestas e seus respectivos pesos");
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d %d",aresta[i].origem,aresta[i].destino,aresta[i].distancia);
        insere_aresta(vertice,aresta[i]);
    }
    return 0;
}

