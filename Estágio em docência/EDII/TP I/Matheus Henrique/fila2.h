#include "pessoa.h"
#ifndef FILA2_H
#define FILA2_H

typedef struct celulaFila2 *ApontadorFila2;

typedef struct celulaFila2{
	Tpessoa Pessoa;
	ApontadorFila2 Prox;
}TcelulaFila2;

typedef struct{
	ApontadorFila2 Frente2, Tras2;
}Tfila2;

void InitFila2(Tfila2 *Fila2);
void Enfileira2(Tpessoa x, Tfila2 *Fila2);
void Desenfileira2(Tpessoa *x, Tfila2 *Fila2);

#endif