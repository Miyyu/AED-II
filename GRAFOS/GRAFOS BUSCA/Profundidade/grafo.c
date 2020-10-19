#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

#define BRANCO 0
#define CINZA 1
#define PRETO 2


void lerArquivo(grafo *g, char* nome){
	FILE *arq;
	arq = fopen(nome, "r");

	if(arq != NULL){

		char buffer[16];
		fgets(buffer, 15, arq);

		char *vert = strtok(buffer," "); //Separar a string em um espaço
		char *are = strtok(NULL, "\n");

		g->vertices = atoi(vert);

		g->mapa = (char *) malloc(sizeof(char) * g->vertices);
		g->listaE = (Lista **) malloc(sizeof(Lista*) * g->vertices);	


		for(int i = 0; i < g->vertices; i++){ 
			fscanf(arq,"%c",&g->mapa[i]);
			if(g->mapa[i] == '\n'){
				i--;
			}
		}

		char aux[15];
		while(fgets(aux, 16, arq) != NULL){ 
			char primeiro, segundo;
			int valorA, valorB, verdade = 0;

			for(int i = 0; i < g->vertices; i++){
				if(aux[0] == g->mapa[i]){
					primeiro = g->mapa[i];
					valorA = i;
					verdade += 1;
				}
				if(aux[1] == g->mapa[i]){
					segundo = g->mapa[i];
					valorB = i;	
					verdade += 1;
				}  
				if(verdade == 2){
					g->listaE[valorA] = inserirLista(g->listaE[valorA], segundo);
					g->listaE[valorB] = inserirLista(g->listaE[valorB], primeiro);

					verdade = 0;
				}			                   
			}
		}
		fclose(arq);

	}
	else{
		printf("Arquivo não existe!\n");
	}
}

Lista* inserirLista(Lista* l, char i){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprimeLista(Lista *l){
    Lista *p;
    for(p = l; p != NULL; p = p->prox){
            printf("%c ", p->info);
    }
}

void imprimir(grafo *g) {
		Lista **aux;

		aux = g->listaE;

		for(int i =0; i < g->vertices; i++) {
				printf("\t%c: ", g->mapa[i]);
				imprimeLista(g->listaE[i]);					
				printf("\n");
		}
}

void imprimirBusca(grafo *g, int posicao, int cor){
	if(cor == 1){
		printf("%c foi pintado de CINZA\n", g->mapa[posicao]);		
	}else if(cor == 2){
		printf("%c foi pintado de PRETO\n", g->mapa[posicao]);
	}		
}

void visitar(grafo *g, int i, int *cor, int *cont, int *d, int *f){
	int j, chave;	
	cor[i] = CINZA;
	//imprimirBusca(g, i, 1);
	*cont = *cont + 1;
	d[i] = *cont;
	
	Lista *v = g->listaE[i];
 	while(v != NULL){
		//Busca a posição do elemento no mapa
		for(j = 0; j < g->vertices; j++){
			if(g->mapa[j] == v->info){
				chave = j;	
			}		
		}	
				
		if(cor[chave] == BRANCO){
			visitar(g, chave, cor, cont, d, f);	
		}
		v = v->prox;
	}

	printf(" %c ⇠", g->mapa[i]);
	cor[i] = PRETO;
	//imprimirBusca(g, i, 2);
	*cont = *cont + 1;	
	f[i] = *cont;
}

void buscaProfundidade(grafo *g, char origem){
	//Inicializo o array de cor de acordo com o número de vértices		
	int *cor = (int *) malloc(sizeof(int) * g->vertices);
	int cont = 0;
	int *d = (int *) malloc(sizeof(int) * g->vertices);
	int *f = (int *) malloc(sizeof(int) * g->vertices);
		
	//Inicializa todos os elementos com a cor branca
	for(int i = 0; i < g->vertices; i++){
		cor[i] = BRANCO;
	}

	for(int i = 0; i < g->vertices; i++){
		if(origem == g->mapa[i] && cor[i] == BRANCO){
			visitar(g, i, cor, &cont, d, f);			
		}
	}
	printf("\n");
	for(int i = 0; i < g->vertices; i++){ //Verificando para o caso de grafos separados
		if(cor[i] == BRANCO){
			printf("Origem: %c\n", g->mapa[i]);
			visitar(g, i, cor, &cont, d, f);
			printf("\n");			
		}
	}
	printf("\n");

	printf("\tDescoberto\n");	
	for(int i = 0; i < g->vertices; i++){
		printf("\t%d", d[i]); 
	}
	printf("\n\tFinalizado\n");	
	for(int i = 0; i < g->vertices; i++){
		printf("\t%d", f[i]); 
	}
	printf("\n");
}