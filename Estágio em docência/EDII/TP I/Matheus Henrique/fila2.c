#include <stdlib.h>
#include "pessoa.h"
#include "fila2.h"

void InitFila2(Tfila2 *Fila2){
	Fila2->Frente2 = malloc(sizeof(TcelulaFila2));
	Fila2->Tras2 = Fila2->Frente2;
	Fila2->Tras2->Prox = NULL;
}

void Enfileira2(Tpessoa x, Tfila2 *Fila2){
	Fila2->Tras2->Prox = malloc(sizeof(TcelulaFila2));
	Fila2->Tras2 = Fila2->Tras2->Prox;
	Fila2->Tras2->Pessoa = x;
	Fila2->Tras2->Prox = NULL;
}

void Desenfileira2(Tpessoa *x, Tfila2 *Fila2){
	ApontadorFila2 q = Fila2->Frente2;
	Fila2->Frente2 = Fila2->Frente2->Prox;
	*x = Fila2->Frente2->Pessoa;
	free(q);
}