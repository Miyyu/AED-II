#ifndef GRAFOS_H
#define GRAFOS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct grafo{
    int **matriz;
    int vertices; 
	int arestas;
    char mapa[SIZE];
}grafo;


typedef struct fila{
	char vertice;
	struct fila *prox;
}fila;

fila* adicionarFila(fila *fila,char v);
fila* removerFila(fila *fila);

void lerArquivo(grafo *g, char* nome);
void gerarMatriz(int m, grafo *g);
void inserirMatriz(int aux1, int aux2, grafo *g);
void imprimirMatriz(int v, grafo *g);
int procurarInicio(grafo *g, char letraV);
void buscaLargura(grafo *g,char origem);

#endif