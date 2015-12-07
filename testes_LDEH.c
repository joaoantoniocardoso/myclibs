#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "lista-duplamente-encadiada-heterogenea.h"

struct dados{
	int i;
	char c;
};

static void imprimir_item(void *dado, int n, va_list vargs){
	struct dados *mdado = dado;
	printf("%d,", (*mdado).i);
	printf("%c", (*mdado).c);
	printf("\t");
}

//
//busca_item(void *dado, int numero_de_parametros, int i, int c, struct dados ret);
//

static void busca_item(void *dado, int n, va_list vargs){
	char a=0;

	struct dados *mdado = (struct dados*) dado;
	
	//recebe os parametros em ordem
	int icomp = (int) va_arg(vargs, int);
	char ccomp = (char) va_arg(vargs, int);
	struct dados *retorno = va_arg(vargs, struct dados*);

	//começa a comparação
	if((*mdado).i == icomp){
		// printf("\nint ok\n");
		a++;
	}
	if((*mdado).c == ccomp){
		// printf("\nchar ok\n");
		a++;
	}

	//retorna
	if (retorno!=NULL) retorno = a>=2?dado:NULL;
}

int main(){
	int a;
	char c;
	struct dados *dado_temp;

	//testando a criação da lista
	printf("Insira o primeiro item de sua itemlista no formato <inteiro,char> ");
	dado_temp = (struct dados*)malloc(sizeof(struct dados));
	scanf("%d,%c", &a, &c);
	getchar(); //limpar o buffer
	(*dado_temp).i = a;
	(*dado_temp).c = c;
	struct lista *lista1 = criar_itemlista((void*)dado_temp);
	printf("A sua itemlista é: ");
	percorre_lista(lista1, &imprimir_item, 0);
	
	//testando inserção de dados na lista
	int i;
	for(i = 0; i<2; i++){
		printf("\nInsira um novo elemento em sua itemlista  no formato <inteiro char>: ");
		dado_temp = (struct dados*)malloc(sizeof(struct dados));
		scanf("%d,%c", &a, &c);
		getchar();
		(*dado_temp).i = a;
		(*dado_temp).c = c;
		inserir_elemento_final(lista1, (void*)dado_temp);
		printf("A sua itemlista é: ");
		percorre_lista(lista1, &imprimir_item, 0);
	}

	//testando a remoção de dados na lista
	printf("\nInsira um elemento a ser removido da itemlista: ");
	dado_temp = (struct dados*)malloc(sizeof(struct dados));
	scanf("%d,%c", &a, &c);
	(*dado_temp).i = a;
	(*dado_temp).c = c;

	printf("Buscando...");
	percorre_lista(lista1, &busca_item, 2, a, c, dado_temp);
	if(dado_temp!=NULL)	{
		printf("\nElemento encontrado: ");
		imprimir_item(dado_temp, 0, NULL);
	}else printf("\n O elemento buscado não foi encontrado\n");

	//TODO: remover elemento
	// remover_elemento(lista1, (void*)dado_temp);
	
	//TODO: procurar elemento novamente para verificar remoção
	// printf("\nO valor foi removido\n");
	printf("A sua itemlista é: ");
	percorre_lista(lista1, &imprimir_item, 0);
	getchar();

	return 0;
}