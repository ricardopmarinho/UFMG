#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pilhaTAD.h"

void IniciaPilha (TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(TPCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int VaziaP(TPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TPItem x, TPilha *Pilha) {
    ApontadorP Aux = malloc(sizeof(TPCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha, TPItem *Item) {
    if (VaziaP(*Pilha)) {
        //printf("\nErro lista vazia!");
        return;
    }
    ApontadorP q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha) {
    return Pilha.Tamanho;
}
