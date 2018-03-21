#include <stdio.h>
#include <stdlib.h>
#include "tad.h"


//Funcoes Tad Pilha de Bandejas

void faz_p_vazia (p_pilha *pilha)
{
	pilha->topo = malloc(sizeof(p_band));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;
}

int p_vazia (p_pilha *pilha)
{
	return (pilha->topo == pilha->fundo);
}

void empilha (p_pilha *pilha)
{
	if(pilha->tamanho < MAX_BANDEJA)
	{
		p_apontador aux = malloc(sizeof(p_band));
		aux->prox = pilha->topo;
		pilha->topo = aux;
		pilha->tamanho++;
	}
}

void desempilha (p_pilha *pilha)
{
	if (p_vazia(pilha))
	{
		fprintf(stderr, "Erro: pilha vazia\n");
		exit(-1);
	}
	p_apontador q = pilha->topo;
	pilha->topo = q->prox;
	free(q);
	pilha->tamanho--;
}

int tamanho (p_pilha *pilha)
{
	return pilha->tamanho;
}


//Funcoes Tad Fila de Clientes

void faz_f_vazia (f_fila *fila)
{
	fila->frente = malloc(sizeof(f_cliente));
	fila->tras = fila->frente;
	fila->frente->prox = NULL;
}

int f_vazia (f_fila *fila)
{
	return (fila->frente == fila->tras);
}

void enfileira (f_tempo x, f_fila *fila)
{
	fila->tras->prox = malloc(sizeof(f_cliente));
	fila->tras = fila->tras->prox;
	fila->tras->tempo = x;
	fila->tras->prox = NULL;
}

void desenfileira (f_fila *fila, f_tempo *tempo)
{
	if (f_vazia(fila))
	{
		fprintf(stderr, "Erro: fila vazia\n");
		exit(-1);
	}
	f_apontador q = fila->frente;
	fila->frente = fila->frente->prox;
	*tempo = fila->frente->tempo;
	free (q);
}


void troca_fila (f_fila *fila1, f_fila *fila2)
{
	f_tempo x;
	desenfileira (fila1, &x);
	enfileira (x, fila2);
}

void passa_tempo (int x, f_fila *fila)
{
	f_apontador q = fila->frente->prox;
	if (x == 1)
	{
		while (q != NULL)
		{
			q->tempo.tempo_fila++;
			q = q->prox;
		}
	}
	
	else if (x == 2)
	{
		while (q != NULL)
		{
			q->tempo.tempo_bandeja++;
			q = q->prox;
		}
	}
	
	else if (x == 3)
	{
		while (q != NULL)
		{
			q->tempo.tempo_almoco++;
			q = q->prox;
		}
	}
	
	else
	{
		fprintf(stderr, "Erro: valor invalido\n");
		exit(-1);
	}
}



