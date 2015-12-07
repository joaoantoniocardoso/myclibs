#include "lista-duplamente-encadiada-heterogenea.h"

struct lista *criar_itemlista(void* dado_inicial){
	//cria itemlista
	struct itemlista *mitemlista = (struct itemlista*)malloc(sizeof(struct itemlista));

	//atribui dado inicial
	(*mitemlista).dado = dado_inicial;

	//anula ponteiros pois é o único elemento
	(*mitemlista).proximo = NULL;
	(*mitemlista).anterior = NULL;

	// //cria cabecalho
	struct lista *mlista = (struct lista*)malloc(sizeof(struct lista));
	(*mlista).size = 1;
	(*mlista).start = mitemlista;
	(*mlista).end = mitemlista;

	return mlista;
}

//insere um elemento no final da itemlista
struct itemlista *inserir_elemento_final(struct lista *mitemlista, void* dado_inicial){
	struct itemlista *novo_elemento = (struct itemlista*)malloc(sizeof(struct itemlista));
	struct itemlista *ultimo_antigo = (*mitemlista).end;

	//reaponta
	(*ultimo_antigo).proximo = novo_elemento;
	(*novo_elemento).anterior = (*mitemlista).end;
	(*mitemlista).end = novo_elemento;
	(*mitemlista).size++;

	//atribui dado inicial
	(*novo_elemento).dado = dado_inicial;

	return novo_elemento;
}

void percorre_lista(struct lista *mlista, void (*functionPtr)(void *dado, int n, va_list vargs), int n, ...){
	struct itemlista *mitemlista = (*mlista).start;
	int j;
	va_list args;

	va_start(args, n);
	for (j = 0; j < (*mlista).size ; j++){
		(*functionPtr)( (*mitemlista).dado, n, args);
		mitemlista = (*mitemlista).proximo;
	}
	va_end(args);
}



// struct itemlista *busca_elemento_itemlista(struct mitemlista *mitemlista, char itens, void* dado){
// 	printf("Buscando...");
// 	int i, j;
// 	struct itemlista *mmitemlista = (*mitemlista).start;

// 	if(itens && 10){
// 		for (i=0;i<(*mitemlista).size;i++){
// 			if( (*(*mmitemlista).dado).c == dado.c){
// 				//compara o proximo se tiver configurado
// 				if(itens && 01){
// 					for (j=0;j<(*mitemlista).size;j++){
// 						if( (*(*mmitemlista).dado).i == dado.i){
// 							printf("\nElemento encontrado.\n");
// 							return mmitemlista;
// 						}else{
// 						mmitemlista = (*mmitemlista).proximo;
// 						printf(".");
// 						}
// 					}
// 				}else{
// 					printf("\nElemento encontrado.\n");
// 					return mmitemlista;
// 				}
// 			}else{
// 			mmitemlista = (*mmitemlista).proximo;
// 			printf(".");
// 			}
// 		}
// 	}
	
// 	printf("\nA itemlista foi percorrida e o elemento não foi encontrado. Pressione <enter> para continuar.\n");
// 	getchar();

// 	return NULL;
// }

void* remover_elemento(struct lista *mlista, struct itemlista *elemento){
	// if (elemento==NULL) return NULL; //erro
	// else{
		struct itemlista *elemento_anterior = (*elemento).anterior;
		struct itemlista *elemento_proximo = (*elemento).proximo;
		
		// if((*elemento).proximo == NULL){
		// 	//ultimo
		// 	(*mlista).end = (*elemento).anterior;
		// 	(*elemento_anterior).proximo = NULL;

		// }else if((*elemento).anterior == NULL){
		// 	//primeiro
		// 	(*mlista).start = (*elemento).proximo;
		// 	(*elemento_proximo).anterior = NULL;
		// }else{
			(*elemento_anterior).proximo = (*elemento).proximo;
			(*elemento_proximo).anterior = (*elemento).anterior;
		// }

		(*mlista).size--;
		// free((*elemento).dado);
		// free(elemento);

		return NULL;//(*elemento).dado; //ok
	// }
}

// void imprimir_itemlista(struct lista *mitemlista){
// 	printf("A sua itemlista é: ");
// 	struct itemlista *mmitemlista = (*mitemlista).start;
// 	int i;
// 	for (i = 0; i < (*mitemlista).size ; i++){
// 		printf("%d,", (*(*mmitemlista).dado).i);
// 		printf("%c", (*(*mmitemlista).dado).c);
// 		printf("\t");
// 		mmitemlista = (*mmitemlista).proximo;
// 	}
// }