#include <stdlib.h>
#include <stdio.h>
#include "DecFuncPilha.h"

void FPVazia(TPilha *Pilha)
{
    Pilha->Topo = malloc(sizeof(PTCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->PProx = NULL;
    Pilha->PTamanho = 0;
}

int VaziaPilha(TPilha Pilha)
{
    return(Pilha.Topo == Pilha.Fundo);
}

void Empilha(TBandeja x, TPilha *Pilha)
{
    PApontador Aux = malloc(sizeof(PTCelula));
    Pilha->Topo->Bandeja = x;
    Aux->PProx = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->PTamanho++;
}

void Desempilha(TBandeja *x, TPilha *Pilha)
{
    if(VaziaPilha(*Pilha)){
        printf("Erro: pilha vazia\n");
        return;
    }
    PApontador q = Pilha->Topo;
    Pilha->Topo = q->PProx;
    *x = q->PProx->Bandeja;
    free(q);
    Pilha->PTamanho--;
}

int TamanhoPilha(TPilha Pilha)
{
    return Pilha.PTamanho;
}
