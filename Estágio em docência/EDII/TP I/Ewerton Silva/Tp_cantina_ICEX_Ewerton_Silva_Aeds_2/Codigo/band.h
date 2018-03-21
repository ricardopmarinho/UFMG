#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef struct Celula *Apontador;

typedef struct Celula {
    TItem Item;
    Apontador Prox;
} TCelula;

typedef struct {
    Apontador Fundo;
    Apontador Topo;
    int Tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilha(TItem x, TPilha *Pilha);
void Desempilha(TPilha *Pilha);
int Tamanho(TPilha Pilha);
TItem emiplha_bandeja(TItem n_band, int x);
int destroi_pilha(TPilha *Pilha);