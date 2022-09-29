/*
https://assessment.hackerearth.com/pt-br/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/
*/
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
void dfs(Vertice *vertice,int raiz, int distancia){
    vertice[raiz].visitado = 1;
    vertice[raiz].distancia = distancia;
    for(int i = 0; i < vertice[raiz].tamanho_lista;i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],distancia+1);
        }
    }
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int qtd_gurias;
    int *gurias;
    int raiz = 1;
    int guria_proxima;
    gurias = (int*)calloc(qtd_gurias,sizeof(int));
    scanf("%d",&qtd_vertices);
    qtd_arestas = qtd_vertices-1;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d",&origem, &destino);
    }
    scanf("%d", &qtd_gurias);
    for(int i = 0; i < qtd_gurias; i++){
        scanf("%d",&gurias[i]);
    }
    guria_proxima = gurias[0];
    for(int i = 0; i < qtd_gurias; i++){
        if(vertice[gurias[i]].distancia < vertice[guria_proxima].distancia ){
            guria_proxima = gurias[i];
        }else{
            if(vertice[gurias[i]].distancia == vertice[guria_proxima].distancia){
                if(gurias[i] < guria_proxima){
                    guria_proxima = gurias[i];
                }
            }
        }
    }
    printf("Guria escolhida: %d", guria_proxima);
    printf("\n");
    return 0;
}
