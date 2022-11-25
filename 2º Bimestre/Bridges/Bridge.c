#include <stdio.h>
#include <stdlib.h>

int count;

typedef struct Vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;
}Vertice;

typedef struct Aresta{
    int origem;
    int destino;
}Aresta;

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tam_lista_adj] = destino;
    vertice[origem].tam_lista_adj++;
    vertice[destino].lista_adj[vertice[destino].tam_lista_adj] = origem;
    vertice[destino].tam_lista_adj++;
}

int menor(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}
int menor2(int a, int b){ return a < b ? a : b;}

void dfs(Vertice *vertice,int raiz,int pai){
    int filho;
    vertice[raiz].visitado = 1;
    vertice[raiz].in = count;
    vertice[raiz].lower = count;
    count++;
    for(int i = 0 ; i < vertice[raiz].tam_lista_adj;i++){
        filho = vertice[raiz].lista_adj[i];
        if(filho == pai){
            continue;
        }else{
            if(vertice[filho].visitado == 1){
                //back_edge
                vertice[raiz].lower = menor2(vertice[raiz].lower,vertice[filho].in);
            }else{
                dfs(vertice,filho,raiz);
                if(vertice[raiz].in < vertice[filho].lower){
                    // é ponte
                    printf("\nPonte entre %d e %d",raiz,filho);
                }
                vertice[raiz].lower = menor2(vertice[raiz].lower,vertice[filho].lower);
            }
        }
    }
    
}

void mostra_lista(Vertice *vertice,int qtd_vertices){
    for(int i = 1 ; i <= qtd_vertices;i++){
        printf("\n%d -> ",i);
        for(int j = 0 ; j < vertice[i].tam_lista_adj;j++){
            printf("%d ", vertice[i].lista_adj[j]);
        }
    }
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

