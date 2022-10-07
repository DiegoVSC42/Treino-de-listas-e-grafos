/*
https://www.beecrowd.com.br/judge/pt/problems/view/1692
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Vertice{
    int visitado;
    int distancia;
    int valor;
    int tamanho_lista;
    int lista_adj[50000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->visitado = 0;
    vertice->distancia = 0;
    vertice->valor = 0;
    vertice->tamanho_lista = 0;
    return vertice;
}
typedef struct Fila{
    int tamanho;
    struct Elemento *inicio;
    struct Elemento *fim;
}Fila;

typedef struct Elemento{
    int valor;
    struct Elemento *prox;
}Elemento;

void push(Fila *fila, int valor){
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
int pop(Fila *fila){
    int retorno;
    if(fila->tamanho == 0){
        return -1;
    }else{
        retorno = fila->inicio->valor;
        fila->inicio = fila->inicio->prox;
        fila->tamanho--;
    }
    return retorno;
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void bfs(Vertice *vertice,int raiz){
    Fila *fila;
    fila = (Fila*)calloc(1,sizeof(Fila));
    int atual;
    int filho;
    push(fila,raiz);
    while(fila->tamanho > 0){
        atual = pop(fila);
        vertice[atual].visitado = 1;
        for(int i = 0 ; i < vertice[atual].tamanho_lista;i++){
            filho = vertice[atual].lista_adj[i];
            if(vertice[filho].visitado == 0){
                vertice[filho].distancia = vertice[atual].distancia+1;
                push(fila,filho);
            }
        }
    }
}

void mostrar_tudo(Vertice *vertices, int qtd_vertices)
{
    int i, j;

    for (i = 1; i <= qtd_vertices; i++)
    {
        printf("\n Vertice: %d", i);
        printf("\n Valor : %d", vertices[i].valor);
        printf("\n Lista de adjacencias: ");

        for (j = 0; j < vertices[i].tamanho_lista; j++)
        {
            printf("%d ", vertices[i].lista_adj[j]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_cartas;
    int *vetor_cartas;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int max_pontos = 0;
    int *vet_origem, *vet_destino;
    int *vet_dist;
    scanf("%d",&qtd_cartas);
    vetor_cartas = (int*)calloc(qtd_cartas+1,sizeof(int));
    qtd_vertices = qtd_cartas;
    
    for(int i = 1 ; i <= qtd_cartas ; i++){
        scanf("%d",&vetor_cartas[i]);
    }
    qtd_arestas = qtd_vertices - 1;
    vet_origem  = (int*)calloc(qtd_arestas,sizeof(int));
    vet_destino = (int*)calloc(qtd_arestas,sizeof(int));
    for(int i = 0 ; i < qtd_arestas ; i++){
        scanf("%d %d",&origem,&destino);
        vet_origem[i] = origem;
        vet_destino[i] = destino;
    }
    vet_dist = (int*)calloc(qtd_cartas+1,sizeof(int));
    
    for(int i = 1; i <= qtd_cartas/2;i++){
        vertice = aloca_vertice(qtd_vertices);
        for(int j = 0 ; j < qtd_arestas; j++){
            insere_aresta(vertice,vet_origem[j],vet_destino[j]);
        }
        for(int k = 1 ; k <= qtd_vertices; k++){
            vertice[k].valor = vetor_cartas[k];
        }
        
        mostrar_tudo (vertice,qtd_vertices);
        
        bfs(vertice,i);
        
        for(int j=1;j<=qtd_vertices;j++)
        {
            printf("\n Distancia do vertice %d para a raiz %d = %d",j,i,vertice[j].distancia);
        }
        printf("\n");
        
        for(int j = 1 ; j <= qtd_vertices;j++){
            if (vertice[j].valor == vertice[i].valor){
                vet_dist[i] = vertice[j].distancia;
                printf("\nENTREI %d\n",i);
            }
        }
        
        printf("\nDISTANCIA");
        for(int j = 1; j <= qtd_cartas;j++){
            printf(" %d",vet_dist[j]);
        }
        
    }

    for(int i = 1 ; i <= qtd_cartas/2;i++){
        max_pontos = max_pontos + vet_dist[i];
    }
    printf("\n%d",max_pontos);
    printf("\n");
    return 0;
}
