#include<stdio.h>
#include<stdlib.h>

typedef int t_chave;

typedef struct t_item{
	t_chave chave;
	int tempo;
	
}t_item;

typedef struct t_celula *t_apontador;

typedef struct t_celula{
	t_item item;
	t_apontador prox;
}t_celula;

typedef struct t_fila{
	t_apontador frente;
	t_apontador tras;
	int tamanho;
}t_fila;

t_fila* FFVazia();
int VaziaF(t_fila fila);
void Enfileira(t_item item, t_fila *fila);
void Desenfileira(t_item *item, t_fila *fila);
void DestroiFila(t_fila *fila);
t_item RetornaPrimeiro(t_fila *fila);
int VerificaFMenor(t_fila **fila, int tam_fila);
int VerificaFMaior(t_fila **fila, int tam_fila);