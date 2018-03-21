#include "pilha.h"

void FPVazia(TPilha *Pilha) {
    Pilha->Topo = (ApontadorPilha*) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = 'NULL';
    Pilha->Tamanho = 0;
}
int Vvazia(TPilha *Pilha) {
    return (Pilha->Topo == Pilha->Fundo);
}

void Empilha(TipoItem x, TPilha *Pilha) {
    ApontadorPilha Aux = (ApontadorPilha*) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}
void Desempilha(TPilha *Pilha, TipoItem *Item) {
    if (Vazia(*Pilha)) {
        printf("Erro lista vazia\n");
        return;
    }
    ApontadorPilha q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}
int Tamanho(TPilha Pilha) {
    return Pilha.Tamanho;
}
