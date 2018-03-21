#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

void FPVazia(TipoPilha *Pilha){
	Pilha->Topo = (TipoApontadorP) malloc(sizeof(TipoCelulaP));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}

int PVazia(TipoPilha Pilha){
	return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoItemP x, TipoPilha *Pilha){
	TipoApontadorP Aux;
	Aux = (TipoApontadorP) malloc(sizeof(TipoCelulaP));
	Pilha->Topo->Item = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItemP *Item){
	TipoApontadorP q;
	if(PVazia(*Pilha)){
		printf("Erro: Lista vazia\n");
		return;
	}
	q = Pilha->Topo;
	Pilha->Topo = q->Prox;
	*Item = q->Prox->Item;
	free(q);
	Pilha->Tamanho--;
}

int TamanhoPilha(TipoPilha Pilha){
	return (Pilha.Tamanho);
}

void ImprimePilha(TipoPilha *Pilha){
	TipoPilha Pilhaux;
	TipoItemP x;
	FPVazia(&Pilhaux);
	while(!PVazia(*Pilha)){
		Desempilha(Pilha, &x);
		Empilha(x, &Pilhaux);
	}
	while(!PVazia(Pilhaux)){
		Desempilha(&Pilhaux, &x);
		putchar(x.Chave);
	}
	putchar('\n');
}