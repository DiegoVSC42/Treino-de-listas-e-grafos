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
    struct Elemento *primeiro;
    struct Elemento *ultimo;
}Fila;

typedef struct Elemento{
    int valor;
    struct Elemento *proximo;
}Elemento;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->distancia = 0;
    vertice->tamanho_lista = 0;
    vertice->visitado = 0;
    return vertice;
}

void insere_fila(Fila *fila, int valor){
    Elemento *novo;
    novo = (Elemento *)calloc(1, sizeof(Elemento));
    novo->valor = valor;
    if(fila->tamanho == 0){
        fila->primeiro = novo;
        fila->ultimo = novo;
    }else{
        fila->ultimo->proximo = novo;
        fila->ultimo = novo;
    }
    fila->tamanho++;
}
int is_empty(Fila *fila){
    if (fila->tamanho == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int remove_fila(Fila *fila){
    if(is_empty(fila)){
        return -1;
    }else{
        int valor_removido;
        valor_removido = fila->primeiro->valor;
        fila->primeiro = fila->primeiro->proximo;
        fila->tamanho--;
        return valor_removido;
    }
}

void bfs(Vertice *vertice, int raiz){
    Fila *fila;
    fila = calloc(1,sizeof(Fila));
    int atual;
    int filho;
    insere_fila(fila,raiz);

    while(!is_empty(fila)){
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
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void mostrar_tudo(Vertice *vertices, int qtd_vertices)
{
    int i, j;

    for (i = 1; i <= qtd_vertices; i++)
    {
        printf("\n Vertice: %d", i);
        printf("\n Distancia: %d", vertices[i].distancia);
        printf("\n Lista de adjacencias: ");

        for (j = 0; j < vertices[i].tamanho_lista; j++)
        {
            printf("%d ", vertices[i].lista_adj[j]);
        }
    }
}
int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int raiz;
    int qtd_cc;
    printf("\nDigite a quantidade de vertices e arestas:\n");
    scanf("%d %d",&qtd_vertices, &qtd_arestas);
    vertice = aloca_vertice(qtd_vertices);
    
    printf("\nDigite as arestas\n");
    for(int i = 0; i < qtd_arestas;i++){
        scanf("%d %d", &origem, &destino);
        insere_aresta(vertice,origem,destino);
    }
    printf("\nDigite a raiz\n");
    scanf("%d", &raiz);
    
    bfs(vertice,raiz);
    mostrar_tudo(vertice,qtd_vertices);
    for(int i = 1; i <= qtd_vertices; i++){
        printf("\nDistancia do vertice %d para a raiz %d = %d",i,raiz,vertice[i].distancia);
    }
    printf("\n");
    return 0;
}



