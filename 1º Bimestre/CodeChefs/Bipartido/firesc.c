/*
https://www.codechef.com/problems/FIRESC?tab=statement
*/
#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

typedef struct Vertice{
    int visitado;
    int tamanho_lista;
    int lista_adj[1000];
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->visitado = 0;
    return vertice;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}
void dfs(Vertice *vertice, int raiz, int *cont_caps){
    if(vertice[raiz].visitado != 0){
        return;
    }
    (*cont_caps)++;
    vertice[raiz].visitado = 1;
    for(int i = 0; i < vertice[raiz].tamanho_lista; i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],cont_caps);
        }
    }
}
int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_testes;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int cont_caps;
    int *vet_caps;
    long long int max_rotas,max_caps;
    scanf("%d",&qtd_testes);
    for(int k = 0 ; k < qtd_testes ; k++){
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertice = aloca_vertice(qtd_vertices);
        vet_caps = (int*)calloc(qtd_vertices, sizeof(int));
        for(int i = 0 ; i < qtd_arestas ; i++){
            scanf("%d %d", &origem,&destino);
            insere_aresta(vertice,origem,destino);
        }
        max_rotas = 0;
        cont_caps = 0;
        for(int i = 1; i <= qtd_vertices; i++){
            cont_caps = 0;
            if(vertice[i].visitado == 0){
                dfs(vertice,i,&cont_caps);
                max_rotas++;
                vet_caps[i] = cont_caps;
            }
        }
        max_caps = 1;
        for(int i = 0 ; i < qtd_vertices;i++){
            if(vet_caps[i] != 0){
                max_caps = (max_caps * vet_caps[i]) % mod;
            }
        }

 
        printf("%lld %lld\n", max_rotas, max_caps);
    }
    printf("\n");
    
    return 0;
}
