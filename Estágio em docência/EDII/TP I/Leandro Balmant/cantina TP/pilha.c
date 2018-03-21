#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

void FPVazia(PilhaPratos *Pilha){
  Pilha->Topo = malloc(sizeof(TCelulaPilha));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

int PilhaVazia(PilhaPratos Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void EmpilhaPratos(TItemPilha x, PilhaPratos *Pilha){
    Apontador Aux = malloc(sizeof(TCelulaPilha));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void DesempilhaPratos(PilhaPratos *Pilha, TItemPilha *Item){
    if (PilhaVazia(*Pilha)) {
      printf("Erro lista vazia\n");
      return;
  }
    Apontador q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

void TamanhoPilha(PilhaPratos Pilha){
  int i;
  i = Pilha.Tamanho;
   printf("tamanho é \n", i);
}

int EscolhePilha(PilhaPratos **Pilha, int nPilha){
  int i,a;
  int maior = -1;
  if(nPilha == 1){
    return 0;
  }

  for (i = 0; i < nPilha; i++) {
    if((*Pilha)[i].Tamanho > maior){
      maior = (*Pilha)[i].Tamanho;
      a = i;
    }
  }
  return a;
}

void FazArranjoPilha(PilhaPratos *Pilha, int nPilha){
  int i;
  for(i=0;i<nPilha;i++){
    FPVazia(&Pilha[i]);
  }
}
