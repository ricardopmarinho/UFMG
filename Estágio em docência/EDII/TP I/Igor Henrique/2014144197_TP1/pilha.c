#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

//PILHA
void FPVazia(TPilha *Pilha){
	Pilha->Topo = malloc(sizeof(TCelulaBandeja));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int PVazia(TPilha Pilha){
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TItemBandeja x, TPilha *Pilha){
    ApontadorBandeja Aux = malloc(sizeof(TCelulaBandeja));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha, TItemBandeja *Item){
    if (PVazia(*Pilha)){
        printf("Erro lista vazia\n");    
        return;
    }
    ApontadorBandeja q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha){
    return Pilha.Tamanho;
}

void liberaPilha(TPilha *Pilha){
    ApontadorBandeja aux, auxprox;
    aux = Pilha->Fundo;
    if(PVazia(*Pilha)){
        while(aux != NULL){
          auxprox = aux->Prox;
          free(aux);
          aux = auxprox;
        }
    }
}


