#include <stdio.h>
#include <stdlib.h>
#include "TADs.h"

//TAD de Fila apresentado pelo professor Adriano em um de seus PowerPoints, ligeiramente alterado.

void FFVazia(TFila *Fila)
{
    Fila->Frente = malloc(sizeof(TCelulaFila));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int FVazia(TFila Fila)
{
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(int x, TFila *Fila)
{
    Fila->Tras->Prox = malloc(sizeof(TCelulaFila));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->TempoQuandoEntrou = x;
    Fila->Tras->Prox = NULL;
}

int Desenfileira(TFila *Fila)
{
    if (FVazia(*Fila))
    {
        printf("Erro: fila vazia\n");
        return 0;
    }
    int x;
    Apontador q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    x = Fila->Frente->TempoQuandoEntrou;
    free(q);
    return x;
}

void DesalocaFila(TFila *Fila)
{
    while(!FVazia(*Fila))
    {
        Desenfileira(Fila);
    }
    free(Fila->Frente);
    free(Fila);
}

//TAD de Pilha apresentado pelo professor Adriano em um de seus PowerPoints, ligeiramente alterado.

void FPVazia(TPilha *Pilha)
{
    Pilha->Topo = malloc(sizeof(TCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int PVazia(TPilha Pilha)
{
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TPilha *Pilha)
{
    ApontadorP Aux = malloc(sizeof(TCelula));
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha)
{
    if (PVazia(*Pilha))
    {
        printf("Erro lista vazia\n");
        return;
    }
    ApontadorP q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha)
{
    return Pilha.Tamanho;
}

void DesalocaPilha(TPilha *Pilha)
{
    while(!PVazia(*Pilha))
    {
        Desempilha(Pilha);
    }
    free(Pilha->Topo);
    free(Pilha);
}
