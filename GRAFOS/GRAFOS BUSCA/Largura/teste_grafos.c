#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main(int argc, char *argv[]){
    grafo g;
    char letraV;

    lerArquivo(&g, "arquivo");

    printf("Digite a origem: ");
    scanf("%c", &letraV);
    buscaLargura(&g, letraV);

}
