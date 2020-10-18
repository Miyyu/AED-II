#ifndef GRAFOS_H
#define GRAFOS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

enum cor{BRANCO, CINZA, PRETO};


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

fila* push(fila *fila,char v);
fila* pop (fila *fila);

void lerArquivo(grafo *g, char* nome);
void gerarMatriz(int m, grafo *g);
//mapa *gerarArestas(grafo *g, char valorV, int numero);
void inserirMatriz(int aux1, int aux2, grafo *g);
void imprimirMatriz(int v, grafo *g);
int procurarInicio(grafo *g, char letraV);
void buscaLargura(grafo *g,char origem);

#endif