/*
https://assessment.hackerearth.com/pt-br/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int lower;
    int tamanho_lista;
    int back_edges[1000];
    int ponte[1000];
    int lista_adj[1000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->lower = 0;
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
void dfs(Vertice *vertice,int raiz, int distancia,int lower,Vertice *pai){
    int local_back = 0;
    int local_ponte = 0;

    vertice[raiz].visitado = 1;
    vertice[raiz].distancia = distancia;
    for(int i = 0; i < vertice[raiz].tamanho_lista;i++){
        
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],distancia+1,lower,&vertice[raiz]);
        }
        if(vertice[raiz].lista_adj[i] != raiz && vertice[vertice[raiz].lista_adj[i]].visitado == 1){
            vertice[raiz].back_edges[local_back] = vertice[raiz].lista_adj[i];
            local_back++;
            if(vertice[vertice[raiz].lista_adj[i]].distancia > pai[raiz].lower){
                vertice[raiz].lower = pai[raiz].lower;
            }else{
                vertice[raiz].lower = vertice[raiz].distancia;
            }
            // vertice[vertice[raiz].lista_adj[i]].lower
        }
        if(vertice[vertice[raiz].lista_adj[i]].lower > pai[raiz].lower){
            vertice[raiz].lower = pai[raiz].lower;
        }else{
            vertice[raiz].lower = vertice[vertice[raiz].lista_adj[i]].lower;
        }
        if(vertice[vertice[raiz].lista_adj[i]].lower > vertice[raiz].distancia){
            vertice[raiz].ponte[local_ponte] = vertice[raiz].lista_adj[local_ponte];
            local_ponte++;
        }
    }
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int distancia = 0;
    int raiz = 1;
    int lower = 0;
    scanf("%d %d",&qtd_vertices, &qtd_arestas);
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d",&origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    dfs(vertice,raiz,distancia,lower, NULL);
    for(int i = 1 ; i <= qtd_vertices;i++){
        for(int j = 0 ; j < vertice[i].tamanho_lista;j++){
            printf("%d %d", i, vertice[i].ponte[j]);
        }
    }
    
    printf("\n");
    return 0;
}
