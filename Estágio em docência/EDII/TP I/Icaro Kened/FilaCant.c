#include <stdio.h>
#include "FilaCant.h"

void FFVazia(TFila *Fila) {
	Fila->Frente = malloc(sizeof(TCelula));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
}

int Vazia(TFila Fila) {
	return (Fila.Frente == Fila.Tras);
}


void Enfileira(TItem x, TFila *Fila) {
	Fila->Tras->Prox = malloc(sizeof(TCelula));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->Item = x;
	Fila->Tras->Prox = NULL;
}


void Desenfileira(TFila *Fila, TItem *Item) {
	if (Vazia(*Fila)) {
		printf("Erro: fila vazia\n");
		return;
	}
	Apontador q = Fila->Frente;
	Fila->Frente = Fila->Frente->Prox;
	*Item = Fila->Frente->Item;
	free(q);
}