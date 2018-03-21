#include <stdio.h>
#include<stdlib.h>
//main
int caso1(int num);
int caso3(int num);
int caso2(int num);
int casoAleatorio(int num);

//fila

typedef int TFChave;
typedef struct TItemFila {
    TFChave Chave;
	
} TItemFila;

typedef struct CelulaFila   	
	*ApontadorFila;


typedef struct CelulaFila {
    TItemFila Item;
    ApontadorFila Prox;
} TCelulaFila;

typedef struct {
    ApontadorFila Frente;
    ApontadorFila Tras;
	int TamanhoFila;
} TFila;

void FFVazia(TFila *Fila);
int VerificaFVazia(TFila Fila);
void Enfileira(TItemFila x, TFila *Fila);
void Desenfileira(TFila *Fila, TItemFila *Item);
void ImprimeFila(TFila Fila);
int TamanhoFila(TFila Fila);
//pilha
typedef int TChavePilha;

typedef struct {
    TChavePilha Chave;
    // outros componentes
} TItemPilha;

typedef struct CelulaPilha *ApontadorPilha;

typedef struct CelulaPilha {
    TItemPilha Item;
    ApontadorPilha Prox;
} TCelulaPilha;

typedef struct {
    ApontadorPilha Fundo;
    ApontadorPilha Topo;
    int TamanhoPilha;
} TPilha;

void FPVazia(TPilha *Pilha);
int VerificaPVazia(TPilha Pilha);
void Empilha(TItemPilha x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TItemPilha *Item);
int TamanhoPilha(TPilha Pilha);













