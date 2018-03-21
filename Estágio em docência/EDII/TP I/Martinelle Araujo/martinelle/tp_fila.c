#include "tp_fila.h"

void FFVazia(TFila *Fila) {
    Fila->Frente = (TCelulaF*) malloc(sizeof(TCelulaF));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}


int VaziaF(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}


void Enfileira(TFItem x, TFila *Fila) {
    Fila->Tras->Prox = (TCelulaF*) malloc(sizeof(TCelulaF));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->FItem = x;
    Fila->Tras->Prox = NULL;
}

void Enfileira2(TFila *ficha, int inicio) {
  TFItem *x = (TFItem*) malloc(sizeof(TFItem));
  x->Chave = 2*inicio+1;
  Enfileira(*x,ficha);
  x->Chave = 2*inicio+2;
  Enfileira(*x,ficha);
}

void Desenfileira(TFila *Fila) {
    if (VaziaF(*Fila)) {
        printf("Erro: fila VaziaF\n");
        return;
    }
    ApontadorF q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    free(q);
}
