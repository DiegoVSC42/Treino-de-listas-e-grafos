#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    //se trocar a e b de lugar na hora de colocar os parametros
    //o algoritimo ordena de forma decrescente
    if(*(int*)a > *(int*)b) 
        return 1;
    if(*(int*)a < *(int*)b)
        return -1;
    if(*(int*)a == *(int*)b)
        return 0;
}

int main(int argc, char const *argv[]){

    int vetor[5];

    vetor[0] = 5;
    vetor[1] = 4;
    vetor[2] = 3;
    vetor[3] = 2;
    vetor[4] = 1;

    printf("Vetor desordenado\n");
    for(int i = 0; i < 5 ; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    qsort(vetor,5,sizeof(int),compare);
    //qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
    //base      =   ponteiro para o primeiro elemento
    //nitems    =   numero de elementos do array
    //size      =   tamanho em bytes de cada elemento do array
    //compar    =   funcao criada para o problema e que compara 2 elementos
    printf("Vetor ordenado\n");
    for(int i = 0; i < 5 ; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
    return 0;
}
