#include "function.h"

void DesenfileiraEnfileira(TFila *FilaS, TFila *FilaE) {
    if (VaziaF(*FilaS)) {
        printf("Erro: fila VaziaF\n");
        return;
    }
    FilaS->Frente = FilaS->Frente->Prox;
    TFItem *Item = (TFItem*) malloc(sizeof(TFItem));
    *Item = FilaS->Frente->FItem;
    Enfileira(*Item, FilaE);
}

int PegarBandeja(TPilha *pilha_bandejas, TFila *bet){
  if( (pilha_bandejas->Topo>0) && !(VaziaF(*bet)) ){
    Desempilha(pilha_bandejas);
    Desenfileira(bet);
    return 1;
  }else{
    return 0;
  }
}
