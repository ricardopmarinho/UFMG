#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

void FFVazia (TFila *Fila){
	Fila->Frente = malloc(sizeof (TCelula));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
}

int Vazia (TFila Fila){
	return (Fila.Frente==Fila.Tras);
}

void Enfilera (TItem x, TFila *Fila){
	Fila->Tras->Prox = malloc(sizeof (TCelula));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->Item = x;
	Fila->Tras->Prox = NULL;
}

void Desenfilera (TFila *Fila, TItem *Item){
	if (Vazia (*Fila)){
		printf ("Erro: Fila Vazia\n");
		return;
	}
	Apontador q = Fila->Frente;
	Fila->Frente = Fila->Frente->Prox;
	*Item = Fila->Frente->Item;
	free(q);
}
