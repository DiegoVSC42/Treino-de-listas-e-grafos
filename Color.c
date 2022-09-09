#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int cor;
}Vertice;

Vertice *aloca_vertice(){
    Vertice *vertice;
    vertice->visitado = 0;
    vertice->tam_lista_adj = 0;
    vertice->cor = 0;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tam_lista_adj] = destino;
    vertice[origem].tam_lista_adj++;
    vertice[destino].lista_adj[vertice[destino].tam_lista_adj] = origem;
    vertice[destino].tam_lista_adj++;
}

int main(){

    Vertice *vertice;
    vertice = aloca_vertice();
    int qtd_vertices, cor,origem,destino;
    printf("Digite a quantidade de vertices: ");
    scanf("%d", &qtd_vertices);
    printf("Digite a cor de cada vertice:\n");
    for(int i = 0; i < qtd_vertices; i++){
        printf("Vertice %d: ", i);
        scanf("%d", &cor);
        vertice[i].cor = cor;
    }
    printf("Digite as arestas: \n");
    for(int i = 0; i < qtd_vertices; i++){
        scanf("%d %d", &origem,&destino);
        insere_aresta(vertice,origem,destino);
    }

}