#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int distancia;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

typedef struct Fila{
    int tamanho;
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

typedef struct Elemento{
    int valor;
    struct Elemento *proximo;
}Elemento;

void push(Fila *fila,int valor){
    Elemento *novo;
    novo = (Elemento*)calloc(1,sizeof(Elemento));
    novo->valor = valor;
    if(fila->tamanho == 0){
        fila->inicio = novo;
        fila->fim = novo;
    }else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}

int pop(Fila *fila){
    if(fila->tamanho == 0){
        return -1;
    }else{
        int retorno = fila->inicio->valor;
        fila->inicio = fila->inicio->proximo;
        fila->tamanho--;
        return retorno;
    }
}

int main(int argc, char const *argv[]){
    Fila *fila_teste;
    fila_teste = (Fila*)calloc(1,sizeof(Fila));
    push(fila_teste,1);
    push(fila_teste,2);
    push(fila_teste,3);

    printf("%d", pop(fila_teste));
    printf("%d", pop(fila_teste));
    printf("%d", pop(fila_teste));
    printf("\n");
    push(fila_teste,3);
    push(fila_teste,2);
    push(fila_teste,1);

    printf("%d", pop(fila_teste));
    printf("%d", pop(fila_teste));
    printf("%d", pop(fila_teste));
    printf("\n");
    return 0;
}


