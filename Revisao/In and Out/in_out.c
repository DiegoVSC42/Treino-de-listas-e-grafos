#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int in;
    int out;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->in = 0;
    vertice->out = 0;
    vertice->tamanho_lista = 0;
    return vertice;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void dfs(Vertice *vertice, int raiz, int contador){
    if(vertice[raiz].visitado == 0){
        vertice[raiz].visitado = 1;
        contador++;
        vertice[raiz].in = contador;
    }
    for(int i = 0; i < vertice[raiz].tamanho_lista; i++){
        contador++;
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],contador+1);
        }
    }
    contador++;
    vertice[raiz].out = contador;

}
void mostra_tabela(Vertice *vertice,int qtd_vertices){
    
    printf("\nV->I|O");

    for(int i = 1; i <= qtd_vertices ; i++){
        printf("\n%d->%d|%d", i, vertice[i].in, vertice[i].out);
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int contador = 0, raiz = 1;
    scanf("%d",&qtd_vertices);
    qtd_arestas = qtd_vertices-1;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0 ; i < qtd_arestas ; i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    dfs(vertice,raiz,contador);
    
    mostra_tabela(vertice,qtd_vertices);
    return 0;
}
