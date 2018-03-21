#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdio.h>
#include <stdlib.h>

typedef struct bandeja {
	int id;
	struct bandeja * proximo;
} Bandeja;

typedef struct pilha {
	Bandeja * Topo;
	int tamanho;
} Pilha;

Bandeja * cria_bandeja(int id);
Pilha * pilha_vazia();
void mostrar_pilha(Pilha * pilha);
void push(Pilha * pilha);
void pop(Pilha * pilha);
void destruir_pilha(Pilha * pilha);

#endif