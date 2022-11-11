/*
https://www.beecrowd.com.br/judge/pt/problems/view/2079
(a) sempre existe um caminho entre duas cidades que passa por uma ou mais ligações; 
(b) não existem dois caminhos diferentes entre duas cidades quaisquer.
(c) não é permitido criar bases em duas cidades vizinhas.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int base;
    int visitado;
    int tamanho_lista;
    int lista_adj[6000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->base = 0;
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
    if(vertice[raiz].visitado != 0){
        return;
    }

    vertice[raiz].visitado = 1;

    for(int i = 0 ; i < vertice[raiz].tamanho_lista ; i++){
        /*
        if(vertice[raiz].base == 1){
            vertice[vertice[raiz].lista_adj[i]].base = 0;
        }*/
        
        if(vertice[raiz].base == 0){
            vertice[vertice[raiz].lista_adj[i]].base = 1;
        }
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i]);
        }

    }

}
int mostra_base(Vertice *vertice,int qtd_vertices){
    for(int i = 1 ; i <= qtd_vertices ; i++){
        printf("Vertice %d: base: %d\n",i,vertice[i].base);
    }
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_testes;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int contador_base = 0;
    //scanf("%d", &qtd_testes);

    scanf("%d", &qtd_vertices);
    vertice = aloca_vertice(qtd_vertices);
    qtd_arestas = qtd_vertices - 1;
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d", &origem,&destino);
        insere_aresta(vertice,origem,destino);
    }

    dfs(vertice,1);
    mostra_base(vertice, qtd_vertices);
    for(int i = 1; i <= qtd_vertices; i++){
        if(vertice[i]. base == 1){
            contador_base++;
        }
    }
    printf("Quantidade de bases : %d\n", contador_base);
    return 0;
}
