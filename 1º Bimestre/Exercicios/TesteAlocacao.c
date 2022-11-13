#include <stdio.h>
#include <stdlib.h>

typedef struct Vetor{
    int *vector;
}Vetor;

typedef struct Teste{
    Vetor *teste_vetor;
}Teste;

Vetor *aloca_vetor(int N){
    Vetor *vetor;
    vetor = (Vetor *) malloc(sizeof(Vetor));
    vetor->vector = (int*)malloc(N * sizeof(int));
    return vetor;
}

int main(int argc, char const *argv[]){

    int n;
    scanf("%d", &n);
    
    /*Teste *teste;
    teste = (Teste *) malloc(sizeof(Teste));
    teste->teste_vetor = (Vetor *) malloc(sizeof(Vetor));
    teste->teste_vetor->vector = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &teste->teste_vetor->vector[i]);
    }

    for(int i=0; i<n; i++){
        printf("%d", teste->teste_vetor->vector[i]);
    }
    */
    Vetor *vetor;
    
    //ALOCANDO SEM CRIAR FUNCAO
    /*
    vetor = (Vetor *) malloc(sizeof(Vetor));
    vetor->vector = (int*)malloc(n*sizeof(int));
    */

    //ALOCANDO COM FUNCAO
    vetor = aloca_vetor(n);

    for(int i=0; i<n; i++){
        scanf("%d", &vetor->vector[i]);
    }
    for(int i=0; i<n; i++){
        printf("%d", vetor->vector[i]);
    }
    printf("\n");
    return 0;
}
