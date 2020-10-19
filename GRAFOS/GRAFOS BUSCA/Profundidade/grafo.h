#ifndef GRAFO_H
#define GRAFO_H

struct lista{
    char info;
	char cor;
    struct lista *prox;
}; 

typedef struct lista Lista;

typedef struct grafo {
	int vertices;
	char *mapa;
	Lista **listaE;
} grafo;


void lerArquivo(grafo *g, char* nome);

Lista* inserirLista(Lista* l, char i);

void imprimeLista(Lista *l);

void imprimir(grafo *g);

void imprimirBusca(grafo *g, int posicao, int cor);

void visitar(grafo *g, int i, int *cor, int *cont, int *d, int *f);

void buscaProfundidade(grafo *g, char origem);

#endif
