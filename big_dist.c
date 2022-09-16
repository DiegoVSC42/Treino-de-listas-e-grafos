//https://www.spoj.com/problems/PT07Z/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int qtd_arestas;//tamanho da lista de adjacencia
    int lista_adj[1000];
    int visitado;
    int distancia;
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->qtd_arestas = 0;
    vertice->distancia = 0;
    return vertice;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].qtd_arestas] = destino;
    vertice[origem].qtd_arestas++;
    vertice[destino].lista_adj[vertice[destino].qtd_arestas] = origem;
    vertice[destino].qtd_arestas++;
}

void dfs(Vertice *vertice, int raiz, int distancia){

    if(vertice[raiz].visitado != 0){
        return;
    }
    vertice[raiz].visitado = 1;
    vertice[raiz].distancia = distancia;
    for(int i = 0; i < vertice[raiz].qtd_arestas; i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],distancia+1);
        }
    }
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices,qtd_arestas,origem,destino,distancia = 0;
    int big_dist = 0;
    int aux;
    
    scanf("%d", &qtd_vertices);
    vertice = aloca_vertice(qtd_vertices);
    qtd_arestas = qtd_vertices-1;
    for(int i = 0; i < qtd_arestas; i++) {
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }

    dfs(vertice,1,distancia);

    
    printf("Distancia: ");
    for(int i = 1; i <= qtd_vertices; i++){
        printf("%d ",vertice[i].distancia);
    }
    printf("\n");
    for(int i = 1; i <= qtd_vertices; i++){
        if(big_dist < vertice[i].distancia){
            big_dist = vertice[i].distancia;
            aux = i;
        }
    }
    printf("bd1: %d\n", big_dist);
    printf("aux: %d\n", aux);
    for(int i = 0; i < qtd_vertices; i++){
        vertice[i].distancia = 0;
        vertice[i].visitado = 0;
    }
    dfs(vertice,aux,distancia);
    
    printf("Distancia: ");
    for(int i = 1; i <= qtd_vertices; i++){
        printf("%d ",vertice[i].distancia);
    }
    printf("\n");
    printf("bd1: %d\n", big_dist);
    printf("aux: %d\n", aux);
    /*
    for(int i = 0; i < qtd_vertices;i++){
        vertice[i].visitado = 0;
        vertice[i].distancia = 0;
    }
    dfs(vertice,aux,0);
    printf("Distancia: ");
    for(int i = 1; i <= qtd_vertices; i++){
        printf("%d ",vertice[i].distancia);
    }
    printf("\n");
    big_dist = 0;

    for(int i = 1; i <= qtd_vertices; i++){
        if(big_dist < vertice[i].distancia){
            big_dist = vertice[i].distancia;
        }
    }
    printf("bd2: %d\n", big_dist);

    */
    return 0;
}
