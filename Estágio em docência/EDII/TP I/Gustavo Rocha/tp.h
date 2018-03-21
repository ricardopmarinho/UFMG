#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int tempo;
	int alim;
}TItem;

typedef struct celula
	*Apontador;
	
typedef struct celula{
	TItem item;
	Apontador prox;	
}TCelula;

typedef struct {
	Apontador fundo;
	Apontador topo;
	int tamanho;	
}TPilha;

typedef struct {
	Apontador frente;
	Apontador tras;
	int tamanho;	
}TFila;

void FPilhaVazia (TPilha *pilha);
int PVazia(TPilha pilha);
void Empilha(TItem x, TPilha *pilha);
void Desempilha(TPilha *pilha, TItem *item);
int PTamanho(TPilha pilha);
void liberaP (TPilha *pilha);

void FFilaVazia (TFila *fila);
int FVazia(TFila fila);
void Enfileira(TItem x, TFila *fila);
void Desenfileira(TFila *fila, TItem *item);
int FTamanho(TFila fila);
void liberaF (TFila *fila);


void PassaTempo (TFila *fband, TFila *fcaixa, TFila *alim, TItem *caixa, TItem *band);
void AndaAlimento (TFila *alim);
void CriaBandeija (TPilha *pilha);
void EncheBandeija (TPilha *pilha);
int TerminouServir (TFila fila);		//testa se o cliente ja serviu os 4 alimentos
void ClienteEmbora (TFila *alim,TFila *fim);






