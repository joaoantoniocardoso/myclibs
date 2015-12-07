#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct itemlista{
	void *dado;
	struct itemlista *anterior;
	struct itemlista *proximo;
};

struct lista{
	int size;
	struct itemlista *start;
	struct itemlista *end;
};

struct lista *criar_itemlista(void* dado_inicial);
//insere um elemento no final da itemlista
struct itemlista *inserir_elemento_final(struct lista *mitemlista, void* dado_inicial);
void percorre_lista(struct lista *mlista, void (*functionPtr)(void *dado, int i, ...));

//retorna ponteiro para o dado removido para que o usuário possa dar um free();
void* remover_elemento(struct lista *mlista, struct itemlista *elemento);
