#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cliente {
	int id;
	bool status;
	struct cliente * proximo;
} Cliente;

typedef struct fila {
	Cliente * inicio;
	int tamanho;
} Fila;

Cliente * cria_cliente(int id, bool status);
Fila * fila_vazia();
void adicionar(int id, bool status, Fila * fila);
void deletar(int id, Fila * fila);
void mostrar_fila(Fila * fila);
void reiniciar_atividade(Fila * fila);
void destruir_fila(Fila * fila);
int retirar_da_fila(Fila * fila);

#endif

