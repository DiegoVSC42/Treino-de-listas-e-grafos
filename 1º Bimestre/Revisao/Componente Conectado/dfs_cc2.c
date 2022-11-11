/*
https://www.hackerearth.com/pt-br/problem/algorithm/connected-components-in-a-graph/
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
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
void dfs(Vertice *vertice, int raiz){
    if (vertice[raiz].visitado!=0){
        return;
    }
    vertice[raiz].visitado = 1;
    for(int i = 0; i < vertice[raiz].tamanho_lista; i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i]);
        }
    }
}
int main(int argc, char const *argv[]){
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int qtd_cc = 0;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    Vertice *vertice;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice, origem, destino);
    }

    for(int i = 1; i <= qtd_vertices ; i++){
        if(vertice[i].visitado == 0){
            dfs(vertice,i);
            qtd_cc++;
        }
    }   
    printf("%d\n", qtd_cc);
    printf("\n");
    return 0;
}
