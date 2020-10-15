#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "avl.h"
#include <string.h>


void inicializar(arvore *raiz) {
	*raiz = NULL;
}

int inicializarTabela(tabela *tab) {
	inicializar(&tab->indices);	
	tab->arquivo_dados = fopen("dados.dat", "a+b");
	tab->indices = carregar_arquivo("indices.dat", tab->indices);
	if(tab->arquivo_dados != NULL)
		return 1;
	else
		return 0;
}

void finalizar (tabela *tab) {
	fclose(tab->arquivo_dados);
	salvar_arquivo("indices.dat", tab->indices);
}

void adicionarLivro(tabela *tab, dado *livro){
	int cresceu;
	if(tab->arquivo_dados != NULL) {
		fseek(tab->arquivo_dados, 0L, SEEK_END);

		tipo_dado * novo = (tipo_dado *) malloc(sizeof(tipo_dado));
		novo->chave = livro->codigo;
		novo->indice = ftell(tab->arquivo_dados);

		fwrite(livro, sizeof(dado), 1, tab->arquivo_dados);
		tab->indices = adicionar(novo, tab->indices, &cresceu); //INSERIR O CRESCEU;
	}
}

// *******************************************************************************************************
arvore adicionar (tipo_dado *valor, arvore raiz, int *cresceu){
	if(raiz == NULL) {
		arvore novo = (arvore) malloc(sizeof(struct no_avl));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->fb = 0;
	  	*cresceu = 1; 
		return novo;
	}

	if(valor->chave > raiz->dado->chave) {
		raiz->dir = adicionar(valor, raiz->dir, cresceu);

        if(*cresceu) {
			switch(raiz->fb) {
				case 0:
					raiz->fb = 1;
                    *cresceu = 1;
					break;
			    case -1:
					raiz->fb = 0;
					*cresceu = 0;
					break;
				case 1:
					*cresceu = 0;
					return rotacionar(raiz);
			}
		}

	} else {
	   raiz->esq = adicionar(valor, raiz->esq, cresceu);

	   if(*cresceu){
		   switch(raiz->fb){
			   	case 0:
					raiz->fb = -1;
					*cresceu = 1;
					break;
				case 1:
					raiz->fb = 0;
					*cresceu = 0;
					break;
				case -1:
					*cresceu = 0;
					return rotacionar(raiz);					
		   }
	   }
	}
	return raiz;
}

arvore rotacionar(arvore raiz) {    //ADICIONADO ROTAÇÃO
	if(raiz->fb > 0) {
		switch(raiz->dir->fb) {
			case 0:
			case 1:
				return rotacao_simples_esquerda(raiz);
			case -1:
				return rotacao_dupla_esquerda(raiz);					
			} 
	} else {
		switch(raiz->esq->fb){
			case 0:
			case -1:
				return rotacao_simples_direita(raiz);
			case 1:
				return rotacao_dupla_direita(raiz);
		}
	}
}

arvore rotacao_simples_esquerda(arvore raiz) {
	arvore p, u, t1, t2, t3;
    //inicializa os ponteiros
	p = raiz;
	u = raiz->dir;
    t1 = p->esq;

    t2 = u->esq;
    t3 = u->dir;

    //Atualiza os ponteiros
	u->esq = p;
	p->dir = t2;

	if(u->fb == 1) {
		p->fb = 0;
		u->fb = 0;
	} else {
		p->fb = 1;
		u->fb = -1;
	}	    
	return u;
}

arvore rotacao_dupla_esquerda(arvore raiz) {
	arvore u, v, p;

	p = raiz;
	u = p->dir;
	v = u->esq;

	//rodando 1 vez
	u->esq = v->dir;
	v->dir = u;

	p->dir = v->esq;
	v->esq = p;

	if(v->fb == 0){
		p->fb = 0;
		u->fb = 0;
		v->fb = 0;
	}
	else if(v->fb == 1){
		p->fb = -1;
		u->fb = 0;
		v->fb = 0;
	}
	else{ 
		p->fb = 0;
		u->fb = 1;
		v->fb = 0;
	}
	return v;		
}

arvore rotacao_simples_direita(arvore raiz) {
	arvore p, u, t1, t2, t3;

	p = raiz;
	u = raiz->esq;
    t1 = p->dir;
	t2 = u->dir;
	t3 = u->esq;

	u->dir = p;
	p->esq = t2;
	
	if(u->fb == -1){
		u->fb = 0;
		p->fb = 0;
	}
	else{
		u->fb = 1;
		p->fb = -1;
	}
	return u;
}

arvore rotacao_dupla_direita(arvore raiz) {
	arvore u, p, v;

	p = raiz;
	u = p->esq;
	v = u->dir;

	u->dir = v->esq;
	v->esq = u;

	p->esq = v->dir;
	v->dir = p;

	if(v->fb == 0){
		p->fb = 0;
		u->fb = 0;
		v->fb = 0;
	}
	else if(v->fb == 1){
		p->fb = 0;
		u->fb = -1;
		v->fb = 0;
	}
	else{
		p->fb = 1;
		u->fb = 0;
		v->fb = 0;
	}
	return v;
}

//--------------------------------- MUDADO  --------------------------------------------------------

int altura(arvore raiz) {
	if(raiz == NULL) {
		return 0;
	}
	return 1 + maior(altura(raiz->dir), altura(raiz->esq));
}

int maior(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

//int maior_elemento(arvore raiz) {
	/*if(raiz != NULL){
		if(raiz->dir == NULL)
			return raiz->dado;
		else
			return maior_elemento(raiz->dir);
	}*/

	/*if(raiz == NULL)
		return NULL;
	if(raiz->dir == NULL)
		return raiz->dado;
	else
		return maior_elemento(raiz->dir);
}*/

/*int menor_elemento(arvore raiz) {
	if(raiz != NULL){
		if(raiz->esq == NULL)
			return raiz->dado;
		else
			return menor_elemento(raiz->esq);
	}

	/*if(raiz == NULL)
			return NULL;
	if(raiz->esq == NULL)
			return raiz->dado;
	else
		return menor_elemento(raiz->esq);
}*/

void pre_order(arvore raiz, tabela *tab) {
	if(raiz != NULL) {
		imprimir_elemento(raiz, tab);
		pre_order(raiz->esq, tab);
		pre_order(raiz->dir, tab);
	}
}

void pos_order(arvore raiz, tabela *tab) {
	if(raiz != NULL) {
		pos_order(raiz->esq, tab);
		pos_order(raiz->dir, tab);
		imprimir_elemento(raiz, tab);
	}
}

void in_order(arvore raiz, tabela *tab) {
	if(raiz != NULL) {
		in_order(raiz->esq, tab);
		imprimir_elemento(raiz, tab);
		in_order(raiz->dir, tab);
	}
}

void imprimir_elemento(arvore raiz, tabela * tab) {
	dado * temp = (dado *) malloc (sizeof(dado));
	fseek(tab->arquivo_dados, raiz->dado->indice, SEEK_SET);
	fread(temp, sizeof(dado), 1, tab->arquivo_dados);
	printf("[%d, %s, %s, %s ]\n", raiz->dado->chave, temp->titulo, temp->autor, temp->isbn);
	free(temp);
}

/*arvore remover (int valor, arvore raiz) {      //MUDAAAARRRR
	if(raiz == NULL) 
		return NULL;
	
	if(raiz->dado->chave == valor) {		
		if(raiz->esq == NULL) {
			return raiz->dir;
		}
		if(raiz->dir == NULL) {
			return raiz->esq;
		}
		raiz->dado = maior_elemento(raiz->esq);
		raiz->esq = remover(raiz->dado->chave, raiz->esq);
		return raiz;
	}	
	if(valor > raiz->dado->chave) {
			raiz->dir = remover(valor, raiz->dir);
	} else {
			raiz->esq = remover(valor, raiz->esq);
	}
	return raiz;
}*/

dado * ler_dados() {
	dado *novo = (dado *) malloc(sizeof(dado)); //MUDEI DE TIPO_DADO PARA DADO
	char * buffer = (char *) malloc(256 * sizeof(char));

	getchar() ;
	printf("Titulo: ");
	fgets(buffer, 255,  stdin);
	tirar_enter(buffer);
/*	novo->titulo = (char *) malloc ((strlen(buffer) + 1) * sizeof(char));
	strcpy(novo->titulo, buffer);*/
	novo->titulo = strdup(buffer);

	printf("Autor: ");
	fgets(buffer, 255,  stdin);
	tirar_enter(buffer);
	novo->autor = strdup(buffer);

	printf("Isbn: ");
	fgets(buffer, 255,  stdin);
	tirar_enter(buffer);
	novo->isbn = strdup(buffer);

	printf("Codigo: ");
	scanf("%d", &novo->codigo);
	free(buffer);

	return novo;
}

void tirar_enter(char *string) {
	string[strlen(string) -1] = '\0';
}

/*int salvar_arquivo(char *nome, arvore a){
	char* caminho = argv[4];
    FILE* arquivo_saida = freopen(caminho, "w", stdout);
    if(arquivo_saida == NULL){
		printf("\n \n   ERRO: Algum problema na abertura do arquivo de SAIDA!! \n");
		//mostra_help();
		return 1;
	}
	//imprimir(arvore->arvore);
	fclose(arquivo_saida);
}*/

void salvar_arquivo(char *nome, arvore a) {
	FILE *arq;
	arq = fopen(nome, "wb");
	if(arq != NULL) {
		salvar_auxiliar(a, arq);
		fclose(arq);
	}
}

void salvar_auxiliar(arvore raiz, FILE *arq){
	if(raiz != NULL) {
		fwrite(raiz->dado, sizeof(tipo_dado), 1, arq);
		salvar_auxiliar(raiz->esq, arq);
		salvar_auxiliar(raiz->dir, arq);
	}

}

arvore carregar_arquivo(char *nome, arvore a) {
	int cresceu; //////// OLAAAAAAAAAAAAAAAAAAARRRRRRRRRRRRRRRRR

	FILE *arq;
	arq = fopen(nome, "rb");
	tipo_dado * temp;
	if(arq != NULL) {
		temp = (tipo_dado *) malloc(sizeof(tipo_dado));
		while(fread(temp, sizeof(tipo_dado), 1, arq)) {
			
			a = adicionar(temp, a, &cresceu);			
			temp = (tipo_dado *) malloc(sizeof(tipo_dado));

		}
		fclose(arq);

	}
	return a;
}
