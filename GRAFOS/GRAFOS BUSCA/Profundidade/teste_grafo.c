#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, int* argv) {
	grafo g;
	char v;

    lerArquivo(&g, "arquivo");
 	imprimir(&g);

	printf("Digite a origem: ");
	scanf("%c", &v);
	buscaProfundidade(&g, v);  

   return 0;

}