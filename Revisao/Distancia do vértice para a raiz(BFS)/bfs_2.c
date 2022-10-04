#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int distancia;
    int visitado;
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

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = calloc(qtd_vertices+1, sizeof(Vertice));
    vertice->distancia = 0;
    vertice->visitado = 0;
    vertice->tamanho_lista = 0;
    return vertice; 
}

Fila *aloca_fila(){
    Fila *fila;
    fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

Elemento *aloca_elemento(){
    Elemento *elemento;
    elemento = (Elemento *)malloc(sizeof(Elemento));
    elemento->proximo = NULL;
    elemento->valor = 0;
}

void insere_fila(Fila *fila,int valor){
    Elemento *novo,*aux;
    novo = aloca_elemento();
    novo->valor = valor;
    aux = fila->inicio;
    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
        fila->tamanho++;
    }else{
        fila->fim->proximo = novo;
        fila->fim = novo;
        fila->tamanho++;
    }
}

int remove_fila(Fila *fila){
    int valor_removido;
    if(fila->tamanho == 0){
        return -1;
    }else{
        valor_removido = fila->inicio->valor;
        fila->inicio = fila->inicio->proximo;
        fila->tamanho--;
        return valor_removido;
    }
}

void insere_aresta(Vertice *vertice,int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void bfs(Vertice *vertice, int raiz){
    Fila *fila;
    int atual;
    int filho;
    fila = aloca_fila();
    insere_fila(fila,raiz);
    while(fila->tamanho > 0){
        atual = remove_fila(fila);
        vertice[atual].visitado = 1;
        for(int i = 0; i < vertice[atual].tamanho_lista;i++){
            filho = vertice[atual].lista_adj[i];
            if(vertice[filho].visitado == 0){
                vertice[filho].distancia = vertice[atual].distancia + 1;
                insere_fila(fila,filho);
            }
        }
    }
}

void mostrar_distancias(Vertice *vertice,int qtd_vertices, int raiz){
    for(int i = 1; i <= qtd_vertices; i++){
        printf("Vertice: %d\n",i);
        printf("Distancia: %d\n",vertice[i].distancia);
        printf("Lista de Adjacencias: ");
        for(int j = 0; j < vertice[i].tamanho_lista;j++){
            printf("%d ",vertice[i].lista_adj[j]);
        }
        printf("\n");
    }
    
    for(int i = 1; i <= qtd_vertices;i++){
        printf("Distancia da raiz %d para o vertice %d = %d\n",raiz,i,vertice[i].distancia);
    }
}
int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int raiz;
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d", &origem,&destino);
        insere_aresta(vertice,origem,destino);
    }
    scanf("%d", &raiz);
    bfs(vertice,raiz);
    mostrar_distancias(vertice,qtd_vertices,raiz);
    return 0;
}
