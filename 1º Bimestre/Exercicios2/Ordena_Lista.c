/*
Faça um programa que receba do usuário N pares de valores, onde cada PAR representa uma aresta 
bidirecional entre cada valor do par

Mostre uma matriz de adjacencia que represente esse grafo
Mostre uma lista de adjacencia que represente esse grafo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    struct Lista *lista_adjacencia;
}Vertice;

typedef struct Lista{
    int tamanho_lista;
    struct Registro *inicio;
}Lista;

typedef struct Registro{
    int valor;
    struct Registro *proximo;
}Registro;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    return vertice;
}
Lista *aloca_lista(){
    Lista *lista;
    lista = (Lista *)calloc(1,sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho_lista = 0;
    return lista;
}
Registro *aloca_registro(){
    Registro *registro;
    registro = (Registro *)calloc(1,sizeof(Registro));
    registro->valor = 0;
    registro->proximo = NULL;
    return registro;
}

void insere_lista(Lista *lista, int valor){
    Registro *novo,*aux;
    novo = aloca_registro();
    novo->valor = valor;
    aux = lista->inicio;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->tamanho_lista++;
    }else{
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        lista->tamanho_lista++;
    }
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    if(vertice->lista_adjacencia == NULL)
        vertice->lista_adjacencia = aloca_lista();
    insere_lista(vertice[origem].lista_adjacencia, destino);
    insere_lista(vertice[destino].lista_adjacencia,origem);
}


void mostrar_lista(Lista *lista){
    Registro *aux;
    aux = lista->inicio;
    while(aux != NULL){
        printf("%d", aux->valor);
        aux = aux->proximo;
    }
}
void mostra_lista_adjacencia(Vertice *vertice){    
    for(int i=0; i<vertice->lista_adjacencia->tamanho_lista; i++){
        printf("%d -> ", i);
        mostrar_lista(vertice[i].lista_adjacencia);
    }
}

int main(int argc, char const *argv[]){

    int qtd_vertices;
    int origem, destino;

    scanf("%d",&qtd_vertices);
    Vertice *vertice;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_vertices; i++){
        scanf("%d %d",&origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    mostra_lista_adjacencia(vertice);
    return 0;
}
