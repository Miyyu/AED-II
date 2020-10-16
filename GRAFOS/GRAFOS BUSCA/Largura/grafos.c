#include "grafos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lerArquivo(grafo *g, char* nome){

    FILE *arq;
    arq = fopen(nome, "r");   

    char buffer[16];
    fgets(buffer, 15, arq);

    char *vert = strtok(buffer," "); //Separar a string em um espaço
    char *are = strtok(NULL, "\n");

    char lista[atoi(vert)];
    for(int i = 0; i < sizeof(lista); i++){ // armazendo dentro da lista os vertices, para depois usar seus indices para a matriz
        fscanf(arq,"%c",&lista[i]);
        if(lista[i] == '\n'){ //caso encontre algum \n, decrementar o for para não inserir vazio na lista
            i--;
        }
    }
    g->vertices = atoi(vert); //tranformando a string vert em um int
    g->arestas = atoi(are);
    g->nomesArestas = lista; //passando a lista de vertices para o grafo

    gerarMatriz(atoi(vert), g);

    char aux[5]; //auxiliar para pegar o restante da leitura do arquivo

    while(fgets(aux, 6, arq) != NULL){ //lendo o restante do arquivo até ele ser NULL :: fgets recebe o nome do auxiliar que vai receber a str, o tamanho dessa str, e de que arquivo

        int primeiro, segundo;    //criando variáveis para colocar os valores que representam o indice do que está na lista

        for(int i = 0; i < sizeof(lista); i++){ //percorrendo a lista com os vertices
            if(aux[0] == lista[i]){ //verificando se o aux[0], no caso o primeiro caractere da linha, é igual a algum da lista
                primeiro = i; //e pego o seu indice
            }
            if(aux[1] == lista[i]){ //verificando se o aux[0], no caso o segundo caractere da linha, é igual a algum da lista
                segundo = i;
            }            
        }
        inserirMatriz(primeiro, segundo, g);

        /*char *valorA = strtok(buffer," "); //Separar a string em um espaço
        char *valorB = strtok(NULL, "\n");

        char A = valorA;
        char B = valorB;

        for(int i = 0; i < sizeof(lista); i++){
            if(A == lista[i]){
                int primeiro = i;
                printf("Primeiro valor = %d\n", primeiro);
            }
            if(B == lista[i]){
                int segundo = i;
                printf("SEGUNDO valor = %d\n", segundo);
            }
            
        }  */      
    }

    fclose(arq);
    imprimirMatriz(g->vertices, g);

}

void imprimirMatriz(int m, grafo *g){
    printf("MATRIZ:\n ");
    printf(" ");
    for(int k = 0; k <  m; k++){ //printar a primeira com os valores dos vertices
        printf("%c ",g->nomesArestas[k]);
    }
    printf("\n");
    for(int i = 0; i < m; i++){ // printar o restante da matriz
        printf("%c ",g->nomesArestas[i]);
        for(int j = 0; j < m; j++){
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
    //printf("\nVALOR VERTICES: %d\n", g->vertices);
   // printf("VALOR VERTICES: %d\n", g->arestas);

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
            if(i == j){ //caso os valores sejam o mesmo, colocar 1, para ter a linha diagonal na matriz
                g->matriz[i][j] = 1; 
            }
            else{ //senãao, atribuir tudo a 0
                g->matriz[i][j] = 0;
            }
        }
    }
    return;
}

/*void gerarArestas(grafo *g, char valor1, char valor2){

    /*for(int i = 0; i < sizeof(lista2); i++){
        for(int j = 0; j < sizeof(lista1); j++){
            if(lista2[i] == lista1[j]){
                printf("vALOR 1:%d | valor 2:%d\n", lista2[i], lista1[j]);
                printf("valor do i = %d | valor do j = %d\n", i, j);
                inserirMatriz(i, j, g);
            }
            continue;
        }
    }  
     imprimirMatriz(g->vertices, g);  
}*/

void inserirMatriz(int aux1, int aux2, grafo *g){

    for(int i = 0; i < sizeof(g->vertices) + 2; i++){
        for(int j = 0; j < sizeof(g->vertices) + 2; j++){
            if(i == aux1 && j == aux2){ //Comparando para ver se o i é igual o valor que está em aux
                g->matriz[i][j] = 1;
            }
            if(j == aux1 && i == aux2){ //o inverso
                g->matriz[i][j] = 1;
            }
        }
    }
    return;
}



