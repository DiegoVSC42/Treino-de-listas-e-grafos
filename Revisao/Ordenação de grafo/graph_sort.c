#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int tamanho_lista;
    int *lista_adj;
}Vertice;

Vertice *aloca_vertice(int qtd_vertices,int qtd_arestas){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices,sizeof(Vertice));
    vertice->lista_adj = (int *)calloc(qtd_arestas,sizeof(int));
    return vertice;
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}
int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int compare1(const void *a, const void *b){
    //se trocar a e b de lugar na hora de colocar os parametros
    //o algoritimo ordena de forma decrescente
    if(*(int*)a > *(int*)b) 
        return 1;
    if(*(int*)a < *(int*)b)
        return -1;
    if(*(int*)a == *(int*)b)
        return 0;
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
    vertice = aloca_vertice(qtd_vertices,qtd_arestas);
    for(int i = 0 ; i < qtd_arestas ; i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    mostra_lista(vertice,qtd_vertices);
    
    for(int i = 1; i <= qtd_vertices; i++){
        qsort(vertice[i].lista_adj,1000,sizeof(int),compare);
    }
    mostra_lista(vertice,qtd_vertices);
    printf("\n");
    return 0;   
}
