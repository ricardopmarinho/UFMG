#include <stdio.h>
#define MAX 1000

typedef struct{
	int chave;	
}TBandejas;


typedef struct celula_bandejas{
	TBandejas* bandeja;
	struct celula_bandejas *prox;
}t_celula_bandejas;

typedef struct{
	t_celula_bandejas *topo;
	t_celula_bandejas *fundo;
	int tamanho;
}pilha_bandejas;


pilha_bandejas FPvazia(void);
TBandejas* desempilha(pilha_bandejas*);
void libera_pilha(pilha_bandejas*);
void empilha(TBandejas*, pilha_bandejas*);
bool pilha_ta_vazia(pilha_bandejas);
int Tamanho(pilha_bandejas pilha);

