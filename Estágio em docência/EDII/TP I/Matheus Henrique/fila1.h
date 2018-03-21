#include "pessoa.h"
#ifndef FILA1_H
#define FILA1_H

typedef struct celulaFila1 *ApontadorFila1;

typedef struct celulaFila1{
	Tpessoa Pessoa;
	ApontadorFila1 Prox;
}TcelulaFila1;

typedef struct{
	ApontadorFila1 Frente1, Tras1;
}Tfila1;

void InitFila1(Tfila1 *Fila1);
void Enfileira1(Tpessoa x, Tfila1 *Fila1);
void Desenfileira1(Tpessoa *x, Tfila1 *Fila1);

#endif