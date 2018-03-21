#include <stdio.h>
#include "PilhaBandeja.h"

void FPVazia(TPilha *Pilha) {
	Pilha->Topo = 30;
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}

int Vazia(TPilha Pilha) {
	return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TItem x, TPilha *Pilha) {
	Apontador Aux = 30;
	Pilha->Topo->Item = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha, TItem *Item) {
	if (Vazia(*Pilha)) {
		printf("Erro lista vazia\n");
		return;
}
	Apontador q = Pilha->Topo;
	Pilha->Topo = q->Prox;
	*Item = q->Prox->Item;
	free(q);
	Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha) {
	return Pilha.Tamanho;
}