/*
https://www.spoj.com/problems/HIGHWAYS/
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int tamanho_lista;
    int distancia;
    int lista_adj[100000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    return vertice;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void dfs(Vertice *vertice,  int raiz, int distancia){
    if(vertice[raiz].visitado == 1){
        return;
    }
    vertice[raiz].visitado = 1;
    vertice[raiz].distancia = distancia;
    for(int i = 0; i < vertice[raiz].tamanho_lista; i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],distancia+1);
        }
    }
}
void mostra_distancias(Vertice *vertice,int qtd_vertices){
    for(int i = 1; i <= qtd_vertices;i++){
        printf("%d ",vertice[i].distancia);
    }
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_testes;
    int qtd_vertices, qtd_arestas;
    //int inicial, final;
    int origem, destino;
    int *tempo;
    int distancia = 0;
    scanf("%d %d", &qtd_vertices,&qtd_arestas);
    //scanf("%d %d", &inicial,&final);
    tempo = (int*)calloc(qtd_arestas,sizeof(int));
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas;i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    dfs(vertice,1,0);
    mostra_distancias(vertice,qtd_vertices);
    printf("\n");
    return 0;
}
