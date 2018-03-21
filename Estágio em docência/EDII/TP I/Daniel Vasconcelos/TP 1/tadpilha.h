#ifndef TADPILHA_H
#define TADPILHA_H


typedef struct {
	int Chave;
}TipItem;

typedef struct TipCelula *PApontador;

typedef struct TipCelula {
	TipItem Item;
	PApontador Prox;
} TipCelula;

typedef struct {
	PApontador Fundo;
	PApontador Topo;
	int Tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilha(TipItem x, TPilha *Pilha);

void Desempilha(TPilha *Pilha, TipItem *Item);

int Tamanho(TPilha Pilha);

#endif 