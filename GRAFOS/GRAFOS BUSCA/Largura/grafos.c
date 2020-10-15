#include "grafos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lerArquivo(grafo *g, char* nome){

    FILE *arq;
    arq = fopen(nome, "r");    

    char buffer[40];
    fgets(buffer, 10, arq);

    char *vert = strtok(buffer," "); //Separar a string em um espaço
    char *are = strtok(NULL, "\n");

    char lista[atoi(vert)];
    for(int i = 0; i < sizeof(lista); i++){ // armazendo dentro da lista
        fscanf(arq,"%c",&lista[i]);
        if(lista[i] == '\n'){
            i--;
        }
    }
    g->vertices = atoi(vert);
    g->arestas = atoi(are);
    g->nomesArestas = lista;

    //printf("V:%d A:%d", g->vertices, g->arestas);
    gerarMatriz(atoi(vert), g);
    //imprimirMatriz(g->vertices, g);

    
}

void imprimirMatriz(int m, grafo *g){
    printf("MATRIZ:\n ");
    printf(" ");
    for(int k = 0; k <  m; k++){
        printf("%c ",g->nomesArestas[k]);
    }
    printf("\n");
    for(int i = 0; i < m; i++){
        printf("%c ",g->nomesArestas[i]);
        for(int j = 0; j < m; j++){
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nVALOR VERTICES: %d\n", g->vertices);
    printf("VALOR VERTICES: %d\n", g->arestas);

}

void gerarMatriz(int m, grafo *g){
    //printf("VALOR DE VERT:%d\n", g->vertices);

    int **mat;

    mat = (int**) malloc(m * sizeof(int*)); // colunas

    for(int i = 0; i < m; i++){
        mat[i] = (int*) malloc(m * sizeof(int)); //linhas
    }
    g->matriz = mat;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == j){
                g->matriz[i][j] = 1;
            }
            else{
                g->matriz[i][j] = 0;
            }
        }
    }
}

void gerarArestas(grafo *g){
    
}


