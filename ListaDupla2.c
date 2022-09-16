#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int valor;
    int tamanho;
    struct Lista *anterior;
    struct Lista *inicio;
    struct Lista *proximo;
    struct Lista *fim;
}Lista;

Lista *aloca_lista(){
    Lista *lista;
    lista = (Lista *)calloc(1,sizeof(Lista));
    lista->valor = 0;
    lista->tamanho = 0;
    lista->anterior = NULL;
    lista->inicio = NULL;
    lista->proximo = NULL;
    lista->fim = NULL;
    return lista;
}
int insere_inicio(Lista *lista,int valor){
    if(lista == NULL){
        return 0;
    }
    Lista *novo,*aux = NULL;            
    novo = aloca_lista();
    novo->valor = valor;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->inicio->anterior = novo;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->tamanho++;
}
int insere_fim(Lista *lista,int valor){
    if(lista == NULL){
        return 0;
    }
    Lista *novo;
    novo = aloca_lista();
    novo->valor = valor;
    /*Lista *aux;
    aux = aloca_lista();
    aux = lista->inicio;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
    */
    if(lista->inicio == NULL){
        insere_inicio(lista, valor);
    }else{
        lista->fim->proximo = novo;
        novo->anterior = lista->fim;
        lista->fim = novo;
    }
    lista->tamanho++;
}

int insere_ordenado(){
    
}

int verifica_valor(Lista *lista, int valor){
    if(lista == NULL){
        return 0;    
    }
    Lista *aux;
    aux = aloca_lista();
    aux = lista->inicio;
    while(aux != NULL){
        if(aux->valor == valor){
            return 1;
        }
        aux = aux->proximo;
    }
}
int remover_inicio(Lista *lista,int dado){

    Lista *atual,*proximo,*anterior;

    if(lista->inicio == NULL){
        return 0;
    }else{
        atual = lista->inicio;
        while(atual != NULL){
            proximo = atual->proximo;
            anterior = atual->anterior;
            if(atual->valor == dado){
                if(anterior != NULL){
                    if(proximo !=  NULL){
                        anterior->proximo = atual->proximo;
                        proximo->anterior = anterior;
                        free(atual);
                        break;
                    }else{
                        anterior->proximo = NULL;
                        atual->fim = anterior;
                        free(atual);
                        break;
                    }
                }else{
                    if(proximo !=  NULL){
                        proximo->anterior = NULL;
                        atual->inicio = proximo;        
                        free(atual);
                        break;
                    }else{
                        free(atual);
                    }
                }
            }else{
                atual = atual->proximo;
            }
        }
    }
}
int remove_valor(Lista *lista, int valor){
    if(lista == NULL){
        return 0;    
    }
    Lista *aux;
    aux = aloca_lista();
    aux = lista->inicio;
    while(aux != NULL){
        if(aux->valor = valor){
            if(aux->anterior != NULL){
                if(aux->proximo != NULL){
                    aux->anterior->proximo = aux->proximo;
                    aux->proximo->anterior = aux->anterior;
                    free(aux);
                    break;
                }else{
                    aux->anterior->proximo = NULL;
                    aux->fim = aux->anterior;
                    free(aux);
                    break;
                }
            }else{
                if(aux->proximo != NULL){
                    aux->proximo->anterior = NULL;
                    aux->inicio = aux->proximo;
                    free(aux);
                    break;
                }else{
                    free(aux);
                }
            }
        }else{
            aux = aux->proximo;
        }
        
    }
    return 0;
}

void mostra_lista(Lista *lista){
    
    if(lista == NULL){
        printf("Lista nula\n");
        return;
    }
    if(lista->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }

    Lista *aux;
    aux = lista->inicio;
    while (aux != NULL){
        printf("%d ",aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
    
}
void mostra_lista_invertida(Lista *lista){
    if(lista == NULL){
        printf("Lista nula\n");
        return;
    }
    if(lista->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }
    Lista *aux;
    aux = lista->fim;
    while (aux != NULL){
        printf("%d ",aux->valor);
        aux = aux->anterior;
    }
    printf("\n");
    
}


int main(int argc, char const *argv[]){

    Lista *lista;
    lista = aloca_lista();
    insere_inicio(lista,42);
    mostra_lista(lista);
    insere_inicio(lista,12);
    mostra_lista(lista);
    insere_fim(lista,13);
    mostra_lista(lista);
    insere_fim(lista,452);
    mostra_lista(lista);
    insere_inicio(lista,122);
    mostra_lista(lista);
    insere_fim(lista,43);
    mostra_lista(lista);
    mostra_lista_invertida(lista);
    printf("%d\n", verifica_valor(lista,122));
    printf("%d\n", verifica_valor(lista,69));
    remover_inicio(lista,13);
    mostra_lista(lista);
    return 0;
}

