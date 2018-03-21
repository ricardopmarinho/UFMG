#include <stdlib.h>
#include <stdio.h>
#include "DecFuncFila.h"

void FFVazia(TFila *Fila)
{
    Fila->Frente = malloc(sizeof(FTCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->FProx = NULL;
    Fila->FTamanho = 0;
}

int VaziaFila(TFila Fila)
{
    return  (Fila.Frente == Fila.Tras);
}

void Enfileira(int x, TFila *Fila)
{
    Fila->Tras->FProx = malloc(sizeof(FTCelula));
    Fila->Tras = Fila->Tras->FProx;
    Fila->Tras->Pessoa = x;
    Fila->Tras->FProx = NULL;
    Fila->FTamanho++;
}

void Desenfileira(int *x, TFila *Fila)
{
    if(VaziaFila(*Fila)){
        printf("Erro: fila vazia\n");
        return;
    }
    FApontador q = Fila->Frente;
    Fila->Frente = Fila->Frente->FProx;
    *x = Fila->Frente->Pessoa;
    free(q);
    Fila->FTamanho--;
}

int TamanhoFila(TFila Fila)
{
    return Fila.FTamanho;
}
