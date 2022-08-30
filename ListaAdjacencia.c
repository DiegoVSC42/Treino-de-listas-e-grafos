#define vertex int /*variavel do tipo inteiro que sera usada para n*/
#include <stdio.h>
#include <stdlib.h>


typedef struct grafo{
    int vertice;     
    int aresta; 
    link *lista_adjacencia;
}*Grafo;

//typedef struct grafo *Grafo;

typedef struct node *link;
struct node{ 
    vertex w;  
    link prox; 
}node;


link novo_no(vertex w, link prox){
    link a = malloc(sizeof(link));
    a->w = w;
    a->prox = prox;
    return a;
}

Grafo inicia_grafo(int vertice) { 
    Grafo grafo = malloc( sizeof *grafo);
    grafo->vertice = vertice; 
    grafo->aresta = 0;
    grafo->lista_adjacencia = malloc(vertice * sizeof (link));
    for (vertex i = 0; i < vertice; i++) 
        grafo->lista_adjacencia[i] = 0;
    return grafo;
}

void insere_aresta(Grafo grafo, vertex v, vertex w) { 
    for (link a = grafo->lista_adjacencia[v]; a != 0; a = a->prox) 
        if (a->w == w) 
            return;
    grafo->lista_adjacencia[v] = novo_no( w, grafo->lista_adjacencia[v]);
    grafo->aresta++;
    
}
/*
void mostra_grafo(Grafo grafo) { 

    for(int i = 0; i < grafo->aresta; i++) { 
        printf("%d", grafo->lista_adjacencia[i]);
    }
}
int main(int argc, char const *argv[]){
    int N;
    int a,b;
    Grafo *grafo;
    
    printf("Digite a quantidade de arestas: ");
    scanf("%d", &N);

    grafo = inicia_grafo(N*2);

    printf("Digite os pares com valores de 0 a %d\n", (N*2)-1);

    for(int i = 0; i < N; i++){
        scanf("%d %d",&a ,&b);
        insere_aresta(grafo,a,b);
        insere_aresta(grafo,b,a);
        insere_aresta(grafo,a,a);
        insere_aresta(grafo,b,b);
    }
    mostra_grafo(grafo);
    return 0;
}
*/

int main(){
    return 0;
}