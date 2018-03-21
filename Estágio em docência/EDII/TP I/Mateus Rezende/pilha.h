#include<stdio.h>
#include <stdlib.h>

typedef int t_chave;

typedef struct t_conteudo{
	t_chave chave;
}t_conteudo;

typedef struct t_campo *t_ponteiro;

typedef struct t_campo{
	t_conteudo item;
	t_ponteiro prox;
}t_campo;

typedef struct t_pilha{
	t_ponteiro fundo, topo;
	int tamanho;
}t_pilha;

t_pilha* FPVazia();
int VaziaP(t_pilha pilha);
void Empilha(t_conteudo item, t_pilha *pilha);
void Desempilha(t_conteudo *item, t_pilha *pilha);
void DestroiPilha(t_pilha *pilha);
int VerificaPMaior(t_pilha **pilha, int tam_pilha);
