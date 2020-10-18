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
    strcpy(g->mapa , lista); //passando a lista de vertices para o grafo

    gerarMatriz(atoi(vert), g);

    char aux[15]; //auxiliar para pegar o restante da leitura do arquivo
    while(fgets(aux, 16, arq) != NULL){ //lendo o restante do arquivo até ele ser NULL :: fgets recebe o nome do auxiliar que vai receber a str, o tamanho dessa str, e de que arquivo

        int primeiro, segundo;    //criando variáveis para colocar os valores que representam o indice do que está na lista

        for(int i = 0; i < sizeof(lista); i++){ //percorrendo a lista com os vertices
            if(aux[0] == lista[i]){ //verificando se o aux[0], no caso o primeiro caractere da linha, é igual a algum da lista
                primeiro = i; //e pego o seu indice
            }
            if(aux[1] == lista[i]){ //verificando se o aux[1], no caso o segundo caractere da linha, é igual a algum da lista
                segundo = i;
            }            
        }
        inserirMatriz(primeiro, segundo, g);     
    }
    fclose(arq);
    imprimirMatriz(g->vertices, g);
}

void imprimirMatriz(int m, grafo *g){
    printf("MATRIZ:\n ");
    printf(" ");
    for(int k = 0; k <  m; k++){ //printar a primeira com os valores dos vertices
        printf("%c ",g->mapa[k]);
    }
    printf("\n");
    for(int i = 0; i < m; i++){ // printar o restante da matriz
        printf("%c ",g->mapa[i]);
        for(int j = 0; j < m; j++){
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

void gerarMatriz(int m, grafo *g){
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

void inserirMatriz(int aux1, int aux2, grafo *g){

    for(int i = 0; i < g->vertices; i++){
        for(int j = 0; j < g->vertices; j++){
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

fila* push(fila *fila,char v){
    struct fila *aux = fila;
    if(aux == NULL){
        struct fila *novo = malloc(sizeof(fila));
        novo->vertice = v;
        novo->prox = NULL;
        return novo;
    }
    else{
        struct fila *novo = malloc(sizeof(fila));
        novo->vertice = v;
        novo->prox = fila;
        return novo;
    }
}
fila* pop(fila *fila){
    if(fila != NULL){
        char v = fila->vertice;
        if(fila->prox != NULL){
            fila = fila->prox;
        }
        else{
            fila = NULL;
        }
    return fila;
    }
}
void buscaLargura(grafo *g, char origem){

    int tam = g->vertices;
    int visitado[tam]; 

    for(int i = 0;i < g->vertices; i++){ //colocar o i = 0
        visitado[i] = 0; //inicializando a lista de visitados com 0;
    }

    fila *f = NULL;
    fila *adjacentes = NULL;
    
    for(int i = 0; i < g->vertices; i++){ //busca início
        if(origem == g->mapa[i]){
            f = push(f, g->mapa[i]);//enfileirando origem g->mapa[i]
            visitado[i] = 1; //visitado[i] = 1; 
            break;            
        }
    }    


    while(f != NULL){  //<-------
        char nomeVertice = f->vertice;
        f = pop(f); //pop
        for(int i = 0; i < g->vertices; i++){ //busca o caractere da lista
            if(nomeVertice == g->mapa[i]){ 
                // busca adjacentes----------------------------------------
                for(int j = 0; j < g->vertices ; j++){
                    if(g->matriz[i][j] == 1 && j != i ){                        

                        if(visitado[j] == 0){
                            adjacentes = push(adjacentes, g->mapa[j]);
                        }                                                    
                    }
                }
            }
        }         
        while(adjacentes != NULL){ //o vetor de não visitados não estiver vazio
            char adjVertice = adjacentes->vertice;
            adjacentes = pop(adjacentes);
            for(int i = 0; i < g->vertices; i++){ //busca vertice
                if(adjVertice == g->mapa[i]){
                    if(visitado[i] == 0){
                        f = push(f,g->mapa[i]);//enfileirando adjvert
                        printf("%c ", adjVertice);
                        visitado[i] = 1; //visitado[i] = 1;
                    }                    
                }
            }            
        }
    }
    printf("\n");
}