#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"

void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
    Fila->Tamanho = 0;
}

int Vazia(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TItem x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
    Fila->Tamanho++;
}


void Desenfileira(TFila *Fila, TItem *Item) {
    if (Vazia(*Fila)) {
        printf("Erro: fila vazia\n");
        return;
    }
    ApontadorFila q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->Item;
    Fila->Tamanho--;
    free(q);
}


void exibe(TFila Fila){
  if (Vazia(Fila)) {
      printf("Erro: fila vazia\n");
      return;
  }
    int i=0;
    ApontadorFila q = Fila.Frente;
    ApontadorFila p = Fila.Tras;
  while(q != p){
    printf("fila %d \n", i );
    i++;
    q = q->Prox;
  }


}

int EscolheFila(TFila **Fila, int nFila){

  int i,a;
  int menor = 10000000;
  if(nFila == 1){
    return 0;
  }

  for (i = 0; i < nFila; i++) {
    if((*Fila)[i].Tamanho < menor){
      menor = (*Fila)[i].Tamanho;
      a = i;
    }
  }

  return a;
}

int EscolheFilaMaior(TFila **Fila, int nFila){

  int i,a;
  int maior = -1;
  if(nFila == 1){
    return 0;
  }

  for (i = 0; i < nFila; i++) {

    if((*Fila)[i].Tamanho > maior){
      maior = (*Fila)[i].Tamanho;
      a = i;
    }
  }
  return a;
}

void FazArranjoFila(TFila *Fila, int nFila){
  int i;
  for(i=0;i<nFila;i++){
    FFVazia(&Fila[i]);
  }
}
