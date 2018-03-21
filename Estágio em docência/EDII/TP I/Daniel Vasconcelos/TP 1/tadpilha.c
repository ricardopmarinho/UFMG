#include <stdio.h>
#include <stdlib.h>
#include "tadpilha.h"

void FPVazia(TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(TipCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int PVazia(TPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipItem x, TPilha *Pilha) {
    PApontador Aux = malloc(sizeof(TipCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha, TipItem *Item) {
    if (PVazia(*Pilha)) {
        return;
    }
    PApontador q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha) {
    return Pilha.Tamanho;
}
