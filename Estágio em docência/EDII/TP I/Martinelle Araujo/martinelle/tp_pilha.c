#include "tp_pilha.h"

#define MAX 30

void FPVazia(TPilha *Pilha) {

  Pilha->Topo = MAX;
}

int Vazia(TPilha Pilha) {
  return (Pilha.Topo == 0);
}

void Empilha10(TPilha *Pilha) {
  Pilha->Topo+= 10;
  if (Pilha->Topo >= MAX)
    Pilha->Topo= MAX;
}

void Desempilha(TPilha *Pilha) {
  if (Vazia(*Pilha))
  printf("Erro: pilha vazia\n");
  else {
    Pilha->Topo--;
  }
}

int Tamanho(TPilha Pilha) {
  return Pilha.Topo;
}
