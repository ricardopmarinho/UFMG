#include "fila.h"

void FFVazia(TipoFila *Fila)
{
    Fila->Frente = (ApontadorFila) malloc(sizeof(TCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = 'NULL';
    Fila->TamanhoFila=0;
}

// Esta função retorna 1 (true) se a ‘Fila’ está vazia; senão retorna 0 (false)
int Vazia(TipoFila *Fila)
{
    return(Fila->TamanhoFila == 0);
}

int TamanhoFila(TipoFila *Fila)
{
    return (Fila->TamanhoFila);
}

void Enfileira(TItem x, TipoFila *Fila)
{
    Fila->Tras->Prox = (ApontadorFila) malloc(sizeof(TCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = 'NULL';
    Fila->TamanhoFila ++;
}

void Desenfileira(TipoFila *Fila, TItem *x)
{
    if (Vazia(Fila))
    {
        printf("Erro: A fila está vazia!!!\n");
        return 0;
    }
    ApontadorFila q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *x = Fila->Frente->Item;
    free(q);
    Fila->TamanhoFila --;
}
