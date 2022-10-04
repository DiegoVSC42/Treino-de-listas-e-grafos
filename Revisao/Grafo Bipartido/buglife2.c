/*
https://www.spoj.com/problems/BUGLIFE/
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int cor;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
    return vertice;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

int dfs(Vertice *vertice, int raiz, int cor){
    vertice[raiz].visitado = 1;
    vertice[raiz].cor = cor;
    for(int i = 0; i < vertice[raiz].tamanho_lista; i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],cor*(-1));
        }
    }
}


int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_casos;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int raiz = 1,cor = 1;
    int suspicious = 0;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0 ; i < qtd_arestas; i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    for(int i = 1; i < qtd_vertices;i++){
        if(vertice[i].visitado == 0){
            dfs(vertice,i,cor);
        }
    }
    
    for(int i = 1; i <= qtd_vertices; i++){
        printf("Cor do vertice %d: %d\n",i,vertice[i].cor);
    }
    
    for(int i = 1; i <= qtd_vertices; i++){
        for(int j = 0; j < vertice[i].tamanho_lista;j++){
            if(vertice[i].cor == vertice[vertice[i].lista_adj[j]].cor){
                suspicious = 1;
            }
        }
    }
    //printf("Scenario #%d:\n",j+1);
    if(suspicious){
        printf("Suspicious bugs found!\n");
    }else{
        printf("No suspicious bugs found!\n");
    }
    printf("\n");
    return 0;
}

