#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int valor;
    int tamanho;
    struct Lista *anterior;
    struct Lista *inicio;
    struct Lista *proximo;
}Lista;
Lista *aloca_lista(){
    Lista *novo;
    novo = (Lista*)calloc(1,sizeof(Lista));
    return novo;
}
int incluir_ordenado_lista(Lista *l, int x){
    if (l == NULL){
        return 0;
    }
    Lista *novo, *aux = NULL;
    novo = aloca_lista();
    novo->valor = x;
    if (l->inicio == NULL || x == 0){
        l->inicio = novo;
    }else{
        int inserido = 0;
        aux = l->inicio;
        while (aux != NULL && inserido == 0){
            if (aux->valor == novo->valor){
                return 0;
            }
            if (aux->valor < novo->valor){
                l->anterior = aux;
                aux = aux->proximo;
            }else{
                if (l->anterior == NULL){
                    l->inicio = novo;
                }else{
                    l->anterior->proximo = novo;
                }
                novo->proximo = aux;
                inserido = 1;
            }
        }
        if (inserido == 0){
            l->anterior->proximo = novo;
            inserido = 1;
        }
    }
    l->tamanho++;
    return 1;
}
void mostrar_lista(Lista *lista){
    if(lista == NULL){
        printf("lista nula\n");
        return;
    }
    if(lista->inicio == NULL){
        printf("lista vazia\n");
        return;
    }
    Lista *aux;
    aux = lista->inicio;
    while(aux != NULL){
        printf("%d ",aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}
int main(int argc, char const *argv[]){

    Lista *lista;
    lista = aloca_lista();
    incluir_ordenado_lista(lista,5);
    incluir_ordenado_lista(lista,4);
    incluir_ordenado_lista(lista,3);
    incluir_ordenado_lista(lista,1);
    incluir_ordenado_lista(lista,2);
    mostrar_lista(lista);

    return 0;
}
