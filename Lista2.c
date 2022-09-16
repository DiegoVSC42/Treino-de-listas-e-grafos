#define vertex int
#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;

struct node { 
    vertex w; 
    link next; 
};


struct graph {
    int V; 
    int A; 
    link *adj; 
};
typedef struct graph *Graph;

static link NEWnode( vertex w, link next) { 
    link a = malloc( sizeof (struct node));
    a->w = w; 
    a->next = next;     
    return a;                         
}

Graph GRAPHinit( int V) { 
    Graph G = malloc( sizeof *G);
    G->V = V; 
    G->A = 0;
    G->adj = malloc( V * sizeof (link));
    for (vertex v = 0; v < V; ++v) 
        G->adj[v] = NULL;
    return G;
}
void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
    for (link a = G->adj[v]; a != NULL; a = a->next) 
        if (a->w == w) 
            return;
    G->adj[v] = NEWnode( w, G->adj[v]);
    G->A++;
}


int main(int argc, char const *argv[]){
    int N,a,b;
    Graph graph;
    printf("Insira o numero de arestas: ");
    scanf("%d", &N);

    graph = GRAPHinit(N*2);
    printf("Digite os pares com valores de 0 a %d\n", (N*2) - 1);
    
    for(int i = 0; i < N ; i++){
        scanf("%d %d",&a,&b);
        GRAPHinsertArc(graph,a,b);
        GRAPHinsertArc(graph,b,a);
        GRAPHinsertArc(graph,a,a);
        GRAPHinsertArc(graph,b,b);
    }
    printf("%d", graph->A);
    printf("%d", graph->V);
    printf("%d", graph->adj[0]->w);
    return 0;
}
