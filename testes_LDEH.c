#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "lista-duplamente-encadiada-heterogenea.h"

struct dados{
	int i;
	char c;
};

void imprimir_lista(void *dado, int n, ...){
	struct dados *mdado = dado;
	printf("%d,", (*mdado).i);
	printf("%c", (*mdado).c);
	printf("\t");
}

//
//busca_item(void *dado, int numero_de_parametros, int i, int c, struct dados ret);
//
void busca_item(void *dado, int n, ...){
	va_list args;
	char a=0;

	va_start(args, n); 
	struct dados *mdado = (struct dados*) dado;
	
	//recebe os parametros em ordem
	int icomp = (int) va_arg(args, int);
	char ccomp = (char) va_arg(args, int);
	struct dados *retorno = va_arg(args, struct dados*);

	//começa a comparação
	if((*mdado).i == icomp){
		printf("\nint ok\n");
		a++;
	}
	if((*mdado).c == ccomp){
		printf("\nchar ok\n");
		a++;
	}

	va_end(args);

	//retorna
	retorno = a>=2?dado:NULL;
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
	percorre_lista(lista1, &imprimir_lista );
	
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
		percorre_lista(lista1, &imprimir_lista );
	}

	//testando a remoção de dados na lista
	printf("\nInsira um elemento a ser removido da itemlista: ");
	dado_temp = (struct dados*)malloc(sizeof(struct dados));
	scanf("%d,%c", &a, &c);
	(*dado_temp).i = a;
	(*dado_temp).c = c;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//TODO: busca pelo elemento
	
	// void (*busca)(void *dado, int n, ...) = &busca_item();
	//eu pensava que daria para usar algo assim:
	// percorre_lista(lista1, busca(NULL, 2, a, c) );
	//mas consigo apenas sem passar nada, como:
	percorre_lista(lista1, &busca_item);
	//então teria que pensar numa forma de passar os parâmetros para usar na comparação dentro da função busca

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//TODO: remover elemento
	// remover_elemento(lista1, (void*)dado_temp);
	
	//TODO: procurar elemento novamente para verificar remoção
	// printf("\nO valor foi removido\n");
	printf("A sua itemlista é: ");
	percorre_lista(lista1, &imprimir_lista );
	getchar();

	return 0;
}