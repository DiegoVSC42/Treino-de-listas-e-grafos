/*
https://www.beecrowd.com.bgcr/judge/pt/problems/view/1928
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Vertice{
    long int visitado;
    long int distancia;
    long int valor;
    long int tamanho_lista;
    long int lista_adj[500000];
}Vertice;

Vertice *aloca_vertice(long int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->distancia = 0;
    vertice->valor = 0;
    vertice->tamanho_lista = 0;
    return vertice;
}
typedef struct Fila{
    long int tamanho;
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

typedef struct Elemento{
    long int valor;
    struct Elemento *prox;
}Elemento;

void push(Fila *fila, long int valor){
    Elemento *novo;
    novo = (Elemento*)calloc(1,sizeof(Elemento));
    novo->valor = valor;
    if(fila->tamanho == 0){
        fila->inicio = novo;
        fila->fim = novo;
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}
long int pop(Fila *fila){
    long int retorno;
    if(fila->tamanho == 0){
        return -1;
    }else{
        retorno = fila->inicio->valor;
        fila->inicio = fila->inicio->prox;
        fila->tamanho--;
    }
    return retorno;
}
void insere_aresta(Vertice *vertice, long int origem, long int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void bfs(Vertice *vertice,long int raiz){
    Fila *fila;
    fila = (Fila*)calloc(1,sizeof(Fila));
    long int atual;
    long int filho;
    push(fila,raiz);
    while(fila->tamanho > 0){
        atual = pop(fila);
        vertice[atual].visitado = 1;
        for(long int i = 0 ; i < vertice[atual].tamanho_lista;i++){
            filho = vertice[atual].lista_adj[i];
            if(vertice[filho].visitado == 0){
                vertice[filho].distancia = vertice[atual].distancia+1;
                push(fila,filho);
            }
        }
    }
}

void mostrar_tudo(Vertice *vertice, long int qtd_vertices)
{
    long int i, j;

    for (i = 1; i <= qtd_vertices; i++)
    {
        printf("\n Vertice:     %li", i);
        printf("\n Valor :      %li", vertice[i].valor);
        printf("\n Distancia :  %li",vertice[i].distancia);
        printf("\n Lista:       ");
        for (j = 0; j < vertice[i].tamanho_lista; j++)
        {
            printf("%li ", vertice[i].lista_adj[j]);
        }
        printf("\n");
    }
    printf("\n");
}

long int main(long int argc, char const *argv[]){
    Vertice *vertice;
    long int qtd_cartas;
    long int *vetor_cartas;
    long int qtd_vertices, qtd_arestas;
    long int origem, destino;
    long int max_pontos = 0;
    long int *vet_origem, *vet_destino;
    long int *vet_dist;
    long int aux,raiz;
    scanf("%li",&qtd_cartas);
    vetor_cartas = (long int*)calloc(qtd_cartas+1,sizeof(long int));
    qtd_vertices = qtd_cartas;
    
    for(long int i = 1 ; i <= qtd_cartas ; i++){
        scanf("%li",&vetor_cartas[i]);
    }
    qtd_arestas = qtd_vertices - 1;
    vet_origem  = (long int*)calloc(qtd_arestas,sizeof(long int));
    vet_destino = (long int*)calloc(qtd_arestas,sizeof(long int));
    for(long int i = 0 ; i < qtd_arestas ; i++){
        scanf("%li %li",&origem,&destino);
        vet_origem[i] = origem;
        vet_destino[i] = destino;
    }
    vet_dist = (long int*)calloc(qtd_cartas+1,sizeof(long int));
    
    for(long int i = 1; i <= qtd_cartas/2;i++){
        vertice = aloca_vertice(qtd_vertices);
        for(long int j = 0 ; j < qtd_arestas; j++){
            insere_aresta(vertice,vet_origem[j],vet_destino[j]);
        }
        for(long int k = 1 ; k <= qtd_vertices; k++){
            vertice[k].valor = vetor_cartas[k];
        }
        
        for(long int j = 1; j <= qtd_vertices; j++){
            if(vertice[j].valor == i){
                raiz = j;
            }
        }

        bfs(vertice,raiz);
        /*
        printf("\n\nRAIZ: %li\n",raiz);
        mostrar_tudo (vertice,qtd_vertices);
        */
        
        for(long int j = 1 ; j<= qtd_vertices ;j++){
            if(vertice[j].valor == vertice[raiz].valor){
                vet_dist[i] = vertice[j].distancia;
                break;
            }
        }
        /*
        printf("\nDISTANCIA");
        for(long int j = 1; j <= qtd_cartas;j++){
            printf(" %li",vet_dist[j]);
        }
        */
    }

    for(long int i = 1 ; i <= qtd_cartas/2;i++){
        max_pontos = max_pontos + vet_dist[i];
    }
    printf("%li",max_pontos);
    printf("\n");
    return 0;
}
