#ifndef _FILA_H_
#define _FILA_H_

// DEFINI��O DO TIPO
typedef int TipoChave;
typedef struct TItem {
    TipoChave ChaveFila;
    // outros componentes
} TItem;
typedef struct CelulaFila   *ApontadorFila;
typedef struct CelulaFila {
    TItem Item;
    ApontadorFila Prox;
} TCelula;
typedef struct {
    ApontadorFila Frente;
    ApontadorFila Tras;
    int TamanhoFila;
} TipoFila;

// CABE�ALHO DAS FUN�OES
void FFVazia(TipoFila *Fila);
int Vazia(TipoFila *Fila);
int TamanhoFila(TipoFila *Fila);
void Enfileira(TItem Item, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, TItem *Item);
#endif

