#include <stdio.h>
#include <stdlib.h>
#include "tad.h" 

//para gerar numeros aleatorios


void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCelulaFila));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
	Fila->TamanhoFila=0;
}

int VerificaFVazia(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TItemFila x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCelulaFila));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
	Fila->TamanhoFila++;
}

void Desenfileira(TFila *Fila, TItemFila *Item) {
    if (VerificaFVazia(*Fila)) { 
        printf("Erro: fila vazia\n");
        return;
    }
    ApontadorFila q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->Item;
    free(q);
	Fila->TamanhoFila--;
}

void ImprimeFila(TFila Fila){
  ApontadorFila aux = Fila.Frente->Prox;
  while (aux != NULL) 
    { printf("%d\n", aux->Item.Chave);
      aux = aux->Prox;
    }
}

int TamanhoFila(TFila Fila) {
    return Fila.TamanhoFila;
}

void FPVazia(TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(TCelulaPilha));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->TamanhoPilha = 0;
}

int VerificaPVazia(TPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TItemPilha x, TPilha *Pilha) {
    ApontadorPilha Aux = malloc(sizeof(TCelulaPilha));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->TamanhoPilha++;
}

void Desempilha(TPilha *Pilha, TItemPilha *Item) {
    if (VerificaPVazia(*Pilha)) {
        printf("Erro lista vazia\n");    
        return;
    }
    ApontadorPilha q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->TamanhoPilha--;
}

int TamanhoPilha(TPilha Pilha) {
    return Pilha.TamanhoPilha;
}



