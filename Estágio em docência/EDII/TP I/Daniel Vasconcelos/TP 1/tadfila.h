#ifndef TADFILA_H
#define TADFILA_H


typedef struct TItem{
	int Chave;
	int Tempo;
	int Bandeja;
}TItem;

typedef struct Celula *Apontador;

typedef struct Celula{
	TItem Item;
	Apontador Prox;
}TCelula;

typedef struct{
	Apontador Frente;
	Apontador Tras;
}TFila;

void FFVazia (TFila *Fila);
int Vazia (TFila Fila);
void Enfilera (TItem x, TFila *Fila);
void Desenfilera (TFila *Fila, TItem *Item);

#endif 