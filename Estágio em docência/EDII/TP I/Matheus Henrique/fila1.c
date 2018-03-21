#include <stdlib.h>
#include "pessoa.h"
#include "fila1.h"

void InitFila1(Tfila1 *Fila1){
	Fila1->Frente1 = malloc(sizeof(TcelulaFila1));
	Fila1->Tras1 = Fila1->Frente1;
	Fila1->Tras1->Prox = NULL;
}

void Enfileira1(Tpessoa x, Tfila1 *Fila1){
	Fila1->Tras1->Prox = malloc(sizeof(TcelulaFila1));
	Fila1->Tras1 = Fila1->Tras1->Prox;
	Fila1->Tras1->Pessoa = x;
	Fila1->Tras1->Prox = NULL;
}

void Desenfileira1(Tpessoa *x, Tfila1 *Fila1){
	ApontadorFila1 q = Fila1->Frente1;
	Fila1->Frente1 = Fila1->Frente1->Prox;
	*x = Fila1->Frente1->Pessoa;
	free(q);
}