#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int distancia;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;
typedef struct Aresta{
    int origem;
    int destino;
    int distancia;
}Aresta;
typedef struct Elemento{
    int vertice;
    int distancia;
}Elemento;

Elemento heap[1000];
int contador_heap = 0;
int count = 1;
int define_pai(int indice){
    return indice / 2;
}
int define_filho_esquerda(int indice){
    return indice * 2;
}
int define_filho_direita(int indice){
    return indice * 2 + 1;
}

void subir_minimo(int indice){
    if(indice > 1){
        Elemento aux;
        int pai = define_pai(indice);
        if(heap[indice].distancia < heap[pai].distancia){
            aux = heap[indice];
            heap[indice] = heap[pai];
            heap[pai] = aux;
            subir_minimo(pai);
        }
    }
}

void descer_minimo(int indice){
    if(contador_heap > indice*2){
        int menor = indice;
        int esquerda = define_filho_esquerda(indice);
        int direita = define_filho_direita(indice);
        if(esquerda <= contador_heap && heap[esquerda].distancia < heap[indice].distancia){
            menor = esquerda;
        }
        if(direita <= contador_heap && heap[direita].distancia < heap[indice].distancia){
            menor = direita;
        }
        Elemento aux;
        aux = heap[indice];
        heap[indice] = heap[menor];
        heap[menor] = aux;
        descer_minimo(menor);
    }
}

int push(Elemento x){
    contador_heap++;
    heap[contador_heap] = x;
    subir_minimo(contador_heap);
}
Elemento pop(){
    Elemento retorno;
    if(contador_heap == 0){
        retorno.vertice = -1;
        retorno.distancia = -1;
        return retorno;
    }
    retorno = heap[1];
    heap[1] = heap[contador_heap];
    contador_heap--;
    descer_minimo(1);
    return retorno;
}
void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void mostra_arestas(Aresta *aresta, int qtd_arestas){
    printf("\nGRAFO");
    for(int i  = 1; i <= qtd_arestas; i++){
        printf("\nOrigem: %d | Destino: %d | Distancia %d ",aresta[i].origem,aresta[i].destino,aresta[i].distancia);
    }
    printf("\n");
}

void mostra_lista(Vertice *vertice, int qtd_vertices){
    printf("\nLISTA DE ADJACENCIAS");
    for(int i = 1; i <= qtd_vertices; i++){
        printf("\nVertice %d \nLista -> ", i);
        for(int j = 0 ; j < vertice[i].tamanho_lista;j++){
            printf("%d ",vertice[i].lista_adj[j]);
        }
    }
    printf("\n");
}

void inicializar_distancias(Vertice *vertice, int qtd_vertices){
    for(int i = 1; i <= qtd_vertices; i++){
        vertice[i].distancia = 9999;
    }
}

void dijkstra(Vertice *vertice,int qtd_vertices,Aresta *aresta, int qtd_arestas,int raiz){
    int atual, distancia_atual;
    Elemento elemento_aux;
    inicializar_distancias(vertice,qtd_vertices);
    vertice[raiz].distancia = 0;
    elemento_aux.distancia = 0;
    elemento_aux.vertice = raiz;
    push(elemento_aux);
    while(contador_heap > 0){
        elemento_aux = pop();
        atual = elemento_aux.vertice;
        distancia_atual = elemento_aux.distancia;
        if(vertice[atual].tamanho_lista == 0){
            return;
        }
        for(int i = 0; i < vertice[atual].tamanho_lista; i++){
            for(int j = 1 ; j <= qtd_arestas ; j++){
                if(aresta[j].origem == atual && aresta[j].destino == vertice[atual].lista_adj[i]
                || aresta[j].destino == atual && aresta[j].origem == vertice[atual].lista_adj[i]){
                    if(distancia_atual + aresta[j].distancia < vertice[vertice[atual].lista_adj[i]].distancia){
                        vertice[vertice[atual].lista_adj[i]].distancia = distancia_atual + aresta[j].distancia;
                        elemento_aux.distancia = vertice[vertice[atual].lista_adj[i]].distancia;
                        elemento_aux.vertice = vertice[atual].lista_adj[i];
                        push(elemento_aux);
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    Aresta *aresta;
    Elemento aux;
    int raiz;
    int qtd_vertices,qtd_arestas;

    //printf("\nDigite a quantidade de vertices e arestas : ");
    scanf("%d %d", &qtd_vertices,&qtd_arestas);
    vertice = (Vertice*)calloc(qtd_vertices + 1,sizeof(Vertice));
    aresta = (Aresta*)calloc(qtd_arestas + 1,sizeof(Aresta));
    //printf("\nDigite a origem, destino e distancia de cada aresta\n");
    for(int i = 1; i <= qtd_arestas ; i++){
        scanf("%d %d %d",&aresta[i].origem,&aresta[i].destino, &aresta[i].distancia);
        insere_aresta(vertice,aresta[i].origem,aresta[i].destino);
    }
    //printf("\nDigite a raiz: ");
    scanf("%d",&raiz);
    mostra_arestas(aresta,qtd_arestas);
    mostra_lista(vertice,qtd_vertices);
    printf("\nRaiz: %d\n",raiz);
    dijkstra(vertice,qtd_vertices,aresta,qtd_arestas,raiz);
    printf("\nDIJKSTRA");
    for(int i = 1; i <= qtd_vertices ; i++){
        printf("\nMenor distancia entre o %d e %d : %d",raiz,i,vertice[i].distancia);
    }
    printf("\n\n");
    return 0;
}
