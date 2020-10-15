#ifndef GRAFOS_H
#define GRAFOS_H
#include <stdlib.h>
#include <stdio.h>

typedef enum CORES{BRANCO, CINZA, PRETO} COR;

typedef struct vertice {
	char letra;
	char *adjacentes;
	int cor;
	struct vertice *pai;
} vertice;

typedef struct grafo{
    int **matriz;
    int vertices;
    int arestas;
    char *nomesArestas;
}grafo;

void lerArquivo(grafo *g, char* nome);
void gerarMatriz(int m, grafo *g);
//void preencherMatriz(int **mat, int m);
void imprimirMatriz(int v, grafo *g);


#endif