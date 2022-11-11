/*
Faça um programa que receba do usuário N pares de valores, onde cada PAR representa uma aresta 
bidirecional entre cada valor do par

Mostre uma matriz de adjacencia que represente esse grafo
Mostre uma lista de adjacencia que represente esse grafo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{

    int tamanho_lista;
    int lista_adjacencia[1000];

}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)malloc(sizeof(Vertice)*(qtd_vertices+1));
    vertice->tamanho_lista = 0;
    return vertice;
}
void insere_aresta(Vertice *vertice,int origem, int destino){
    vertice[origem].lista_adjacencia[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adjacencia[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void ordena_vertice_bubble(Vertice *vertice, int qtd_vertices){
    int aux;
    for(int i = 0; i < qtd_vertices; i++){
        for(int j = vertice[i].tamanho_lista - 1; j >= 1; j--){
            for(int k = 0 ; k < j ; k++){
                if(vertice[i].lista_adjacencia[k] > vertice[i].lista_adjacencia[k+1]){
                    aux = vertice[i].lista_adjacencia[k];
                    vertice[i].lista_adjacencia[k] = vertice[i].lista_adjacencia[k+1];
                    vertice[i].lista_adjacencia[k+1] = aux;
                }
            }
        }
    }
}


void mostra_lista_adjacencia(Vertice *vertice,int qtd_vertices){
    for(int i = 1; i <= qtd_vertices;i++){
        printf("%d->", i);
        for(int j = 0; j < vertice[i].tamanho_lista;j++){
            printf("%d ",vertice[i].lista_adjacencia[j]);
        }
        printf("\n");
    }
}
void ordena_vertice_insertion(Vertice *vertice, int qtd_vertices){
    int aux, k;
    for(int i = 0; i < qtd_vertices; i++){
        for(int j = 1; j < vertice[i].tamanho_lista;j++){
            aux = vertice[i].lista_adjacencia[j];
            for(k = j - 1 ; k >= 0 && aux < vertice[i].lista_adjacencia[k]; k--){
                vertice[i].lista_adjacencia[k+1] = vertice[i].lista_adjacencia[k];
            }
            vertice[i].lista_adjacencia[k+1] = aux;
            
        }
    }
}

int main(int argc, char const *argv[]){

    int origem,destino;
    int qtd_vertices;
    int qtd_arestas;
    scanf("%d", &qtd_vertices);
    scanf("%d", &qtd_arestas);
    Vertice *vertice;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 1; i <= qtd_arestas; i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
        ordena_vertice_insertion(vertice,qtd_vertices);
    }
    printf("\nLista de adjacencia:\n");
    mostra_lista_adjacencia(vertice,qtd_vertices);

    return 0;
}
