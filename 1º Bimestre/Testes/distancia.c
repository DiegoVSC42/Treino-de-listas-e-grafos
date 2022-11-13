#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int distancia;
}vertice;


void mostrar_tudo (vertice * vertices, int qtd_vertices){
    int i,j;
    for(i=1;i<=qtd_vertices;i++){
        //printf("\n Vertice: %d",i);
        //printf("\n Lista de adjacencias: ");
        for(j=0;j<vertices[i].tam_lista_adj;j++){
            //printf("%d ",vertices[i].lista_adj[j]);
        }
    }
}
void dfs(vertice * vertices, int qtd_vertices, int raiz, int distancia){
    int i;
    if (vertices[raiz].visitado!=0){
        return;
    }
    // //printf("\n %d",raiz);
    vertices[raiz].visitado = 1;
    vertices[raiz].distancia = distancia;
    for(i=0;i<vertices[raiz].tam_lista_adj;i++){
        if (vertices[vertices[raiz].lista_adj[i]].visitado==0){
            dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i],distancia+1);
        }
    }
}
int main(int argc, char const *argv[]){

    int qtd_vertices;         //vertices
    int qtd_estradas;       // arestas
    int qtd_gurias;         
    int bishu = 1;
    int u,v,q,x,qtd_cc = 0;
    int i;
    vertice *vertices;
    

    //printf("Digite a quantidade de paÃ­ses: ");
    scanf("%d", &qtd_vertices);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    //printf("Digite as estradas:\n");
    for(i = 0; i < qtd_vertices -1; i++){
        scanf("%d %d",&u,&v);
        vertices[u].lista_adj[vertices[u].tam_lista_adj] = v;
        vertices[u].tam_lista_adj++;
        vertices[u].lista_adj[vertices[v].tam_lista_adj] = u;
        vertices[u].tam_lista_adj++;
    }
    dfs(vertices,qtd_vertices,1,0);
    //printf("\n%d",qtd_cc);
    //printf("Digite a quantidade de garotas: ");
    scanf("%d", &q);
    //printf("Digite as cidades das garotas:\n");
    for(i = 0; i < q; i++){
        scanf("%d", &x);
    }
    printf("Mostrando distancias\n");
    for(i = 0; i < qtd_vertices ; i++){
        printf("%d",vertices[i].distancia);
    }
    

    return 0;
}

/*
int main(){
    int qtd_vertices, qtd_arestas;
    int i,a,b,qtd_cc=0;
    vertice * vertices;
    scanf("%d %d",&qtd_vertices, &qtd_arestas);
    // //printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // //printf("\n Quantidade de arestas: %d\n",qtd_arestas);
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    for(i=0;i<qtd_arestas;i++){
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }
    // mostrar_tudo(vertices,qtd_vertices);
    for(i=1;i<=qtd_vertices;i++){
        if (vertices[i].visitado==0){
            dfs(vertices,qtd_vertices,i);
            qtd_cc++;
        }
    }
    //printf("\n%d",qtd_cc);
    // dfs(vertices,qtd_vertices,1);
    return 0;
}*/
