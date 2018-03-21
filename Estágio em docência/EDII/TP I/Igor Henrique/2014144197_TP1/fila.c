#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void FFVazia(TFila *Fila){
    Fila->Frente = malloc(sizeof(TCelulaCliente));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int FVazia(TFila Fila){
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TItemCliente x, TFila *Fila){
    Fila->Tras->Prox = malloc(sizeof(TCelulaCliente));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
}

void Desenfileira(TFila *Fila, TItemCliente *Item){
    if (FVazia(*Fila)){ 
        printf("Erro: fila vazia\n");
        return;
    }
    ApontadorCliente q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->Item;
    free(q);
}

void liberaFila(TFila *Fila){
    if(FVazia(*Fila)){
        ApontadorCliente aux, auxprox;
        aux = Fila->Frente;
        while(aux != NULL){
            auxprox = aux->Prox;
            free(aux);
            aux = auxprox;
        }
    }
}

