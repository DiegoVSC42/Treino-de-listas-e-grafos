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

void push(Fila *fila, int valor){
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
    int retorno;
    if(fila->tamanho == 0){
        retorno = -1;
    }else{
        retorno = fila->inicio->valor;
        fila->inicio = fila->inicio->proximo;
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
void bfs(Vertice *vertice, int raiz){
    Fila *fila;
    fila = (Fila*)malloc(sizeof(Fila));
    int atual;
    int filho;
    push(fila,raiz);
    while(fila->tamanho > 0){
        atual = pop(fila);
        vertice[atual].visitado = 1;
        for(int i = 0; i < vertice[atual].lista_adj[i];i++){
            filho = vertice[atual].lista_adj[i];
            if(vertice[filho].visitado == 0){
                push(fila,filho);
                vertice[filho].distancia = vertice[atual].distancia+1;
            }
        }
    }
}
void mostra_tudo(Vertice *vertice, int qtd_vertices,int raiz){
    printf("\nRaiz :    %d",raiz);
    for (int i = 1; i <= qtd_vertices; i++){
        printf("\nVertice   %d",i);
        printf("\nDistancia %d",vertice[i].distancia);
        printf("\nLista     ");
        for(int j = 0; j < vertice[i].tamanho_lista;j++){
            printf("%d ",vertice[i].lista_adj[j]);
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int raiz;
    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    vertice = (Vertice*)calloc(qtd_vertices+1, sizeof(Vertice));
    for(int i = 0; i < qtd_arestas;i++){
        scanf("%d %d",&origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    scanf("%d", &raiz);
    
    printf("\n#####   ANTES   #####\n");
    mostra_tudo(vertice,qtd_vertices,raiz);
    bfs(vertice,raiz);
    printf("\n#####   DEPOIS   #####\n");
    mostra_tudo(vertice,qtd_vertices,raiz);
    printf("\n");
    return 0;
}
