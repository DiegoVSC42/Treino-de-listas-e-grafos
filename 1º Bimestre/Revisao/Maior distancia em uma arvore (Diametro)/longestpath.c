/*
https://www.spoj.com/problems/PT07Z/
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int tamanho_lista;
    int lista_adj[10000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices + 1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->distancia = 0;
    vertice->tamanho_lista = 0;
    return vertice;
}

void dfs(Vertice *vertice, int raiz, int distancia){
    if(vertice[raiz].visitado != 0){
        return;
    }
    vertice[raiz].visitado = 1;
    vertice[raiz].distancia = distancia;
    for(int i = 0; i < vertice[raiz].tamanho_lista;i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],distancia+1);
        }
    }
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices,qtd_arestas;
    int origem,destino;
    int *vet_origem, *vet_destino;
    int maior_caminho = 0;
    int distancia = 0;
    int raiz = 1;
    int index_big_dist;
    scanf("%d", &qtd_vertices);
    qtd_arestas = qtd_vertices-1;
    vertice = aloca_vertice(qtd_vertices);
    vet_origem = (int*)calloc(qtd_arestas,sizeof(int));
    vet_destino = (int*)calloc(qtd_arestas,sizeof(int));
    for(int i = 0 ; i < qtd_arestas ; i++){
        scanf("%d %d",&origem, &destino);
        vet_origem[i] = origem;
        vet_destino[i] = destino;
        insere_aresta(vertice,origem,destino);
    }
    dfs(vertice,raiz,distancia);
    for(int i = 1; i <= qtd_vertices; i++){
        if(maior_caminho < vertice[i].distancia)
            maior_caminho = vertice[i].distancia;
            index_big_dist = i;
    }
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas;i++){
        insere_aresta(vertice,vet_origem[i],vet_destino[i]);
    }
    dfs(vertice,index_big_dist,distancia);
    for(int i = 1; i <= qtd_vertices ; i ++){
        if(maior_caminho < vertice[i].distancia)
            maior_caminho = vertice[i].distancia;
    }
    printf("%d", maior_caminho);
    printf("\n");
    return 0;
}
