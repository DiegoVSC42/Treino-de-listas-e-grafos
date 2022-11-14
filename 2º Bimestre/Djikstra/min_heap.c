#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    int tamanho;
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

typedef struct Elemento{
    int valor;
    int distancia;
    struct Elemento *proximo;
}Elemento;

void push(Fila *fila,int valor,int distancia){
    Elemento *novo;
    novo = (Elemento*)malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->distancia = distancia;
    if(fila->tamanho == 0){
        fila->inicio = novo;
        fila->fim = novo;
    }else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}

Elemento *pull(Fila *fila){
    Elemento *cont;
    cont = malloc(sizeof(Elemento));
    cont = fila->inicio;
    Elemento *aux;
    aux = malloc(sizeof(Elemento));
    aux = fila->inicio;
    Elemento *ant;
    ant = malloc(sizeof(Elemento));
    ant = fila->inicio;
    Elemento *atual;
    atual = malloc(sizeof(Elemento));
    atual = ant->proximo;
    if(fila->tamanho > 0){
        /*
        // REMOVER DO INICIO
        Elemento *retorno;
        retorno = malloc(sizeof(Elemento));
        retorno = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        fila->tamanho--;
        return retorno;
        */
        for(int i = 0; i < fila->tamanho;i++){
            if (cont->distancia > aux->distancia){
                cont = aux;   
            }
            aux = aux->proximo;
        }
        while(ant != NULL){
            ant = ant->proximo;
        }
        fila->tamanho--;
        return cont;
    }
}
void mostra_fila(Fila *fila){
    Elemento *aux;
    aux = fila->inicio;
    while(aux != NULL){
        printf("(%d %d)",aux->valor,aux->distancia);
        printf("\n");
        aux = aux->proximo;
    }
}
int main(int argc, char const *argv[]){
    Fila *fila_teste;
    Elemento *elemento_teste;
    fila_teste = (Fila*)malloc(sizeof(Fila));
    elemento_teste = (Elemento*)malloc(sizeof(Elemento));	
    push(fila_teste,1,1);
    push(fila_teste,3,5);
    push(fila_teste,5,4);
    push(fila_teste,7,2);
    push(fila_teste,9,3);

    mostra_fila(fila_teste);
    elemento_teste = pull(fila_teste);
    printf("\nValor %d |Distancia: %d\n",elemento_teste->valor,elemento_teste->distancia);
    mostra_fila(fila_teste);
    elemento_teste = pull(fila_teste);
    printf("\nValor %d |Distancia: %d\n",elemento_teste->valor,elemento_teste->distancia);
    mostra_fila(fila_teste);
    elemento_teste = pull(fila_teste);
    printf("\nValor %d |Distancia: %d\n",elemento_teste->valor,elemento_teste->distancia);
    mostra_fila(fila_teste);
    return 0;
}
