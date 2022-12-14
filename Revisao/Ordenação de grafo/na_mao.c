#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int tamanho_lista;
    int lista_adj[1000];
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
//insertion sort
void ordena_grafo(Vertice *vertice,int qtd_vertices){
    int i,j,k,atual;
    //somente para o grafo
    for(i = 1; i <= qtd_vertices; i++){
        //vai do inicio ate o final da lista
        for(j = 1 ; j < vertice[i].tamanho_lista; j++){
            //adiciona o vertice atual a uma variavel auxiliar
            atual = vertice[i].lista_adj[j];
            //verifica se o vertice atual é menor que o indice anterior ao atual
            for(k = j - 1 ; k >= 0 && atual < vertice[i].lista_adj[k]; k--){
                //se for ele troca os dois de lugar
                vertice[i].lista_adj[k+1] = vertice[i].lista_adj[k]; 
            }
            //coloca o valor que foi substituido no seu lugar correto
            vertice[i].lista_adj[k+1] = atual; 
        }
    }
}
void mostra_lista(Vertice *vertice, int qtd_vertices){
    for(int i = 1 ; i <= qtd_vertices ; i++){
        printf("\n%d->",i);
        for(int j = 0; j < vertice[i].tamanho_lista;j++){
            printf("%d ",vertice[i].lista_adj[j]);
        }
    }
}
int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0 ; i < qtd_arestas ; i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    mostra_lista(vertice,qtd_vertices);
    ordena_grafo(vertice,qtd_vertices);
    mostra_lista(vertice,qtd_vertices);
    printf("\n");
    return 0;   
}
