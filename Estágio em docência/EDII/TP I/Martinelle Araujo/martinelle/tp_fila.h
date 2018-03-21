#include<stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct TFItem {
    TChave Chave;
    // outros componentes
} TFItem;

typedef struct CelulaF  	*ApontadorF;


typedef struct CelulaF {
    TFItem FItem;
    ApontadorF Prox;
} TCelulaF;

typedef struct {
    ApontadorF Frente;
    ApontadorF Tras;
} TFila;

void FFVazia(TFila *Fila);

int VaziaF(TFila Fila) ;

void Enfileira(TFItem x, TFila *Fila);

void Enfileira2(TFila *ficha, int inicio);

void Desenfileira(TFila *Fila);
