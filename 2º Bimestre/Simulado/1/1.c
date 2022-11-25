#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int tamanho_lista;
    int lista_adj[1000];
    int in;
    int lower;
}Vertice;
typedef struct Aresta{
    int origem;
    int destino;
}Aresta;

int count;

int min(int a, int b) { return a < b ? a : b; }

void dfs(Vertice *vertice,int raiz, int pai){
    int filho;
    vertice[raiz].visitado = 1;
    vertice[raiz].in = count;
    vertice[raiz].lower = count;
    count++;
    for(int i = 0 ; i < vertice[raiz].tamanho_lista ; i++){
        filho = vertice[raiz].lista_adj[i];
        if(filho != pai){
            if(vertice[filho].visitado == 1){
                vertice[raiz].lower = min(vertice[raiz].lower, vertice[filho].in);
            }else{
                dfs(vertice,filho,raiz);
                if(vertice[raiz].in < vertice[filho].lower){
                    printf("\nA estrada que conecta a cidade %d a %d nao pode entrar em reforma.",raiz,filho);
                }
                vertice[raiz].lower = min(vertice[raiz].lower,vertice[filho].lower);
            }
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
    int qtd_vertices,qtd_arestas;
    Vertice *vertice;
    Aresta *aresta;
    //Digite a quantidade de vertice e arestas
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    aresta = (Aresta *)calloc(qtd_arestas+1,sizeof(Aresta));
    //Digite as arestas
    for(int i = 1; i <= qtd_arestas; i++){
        scanf("%d %d", &aresta[i].origem, &aresta[i].destino);
        insere_aresta(vertice,aresta[i].origem,aresta[i].destino);
    }
    //mostra_lista(vertice,qtd_vertices);
    dfs(vertice,1,1);
    printf("\n");
    return 0;
}
