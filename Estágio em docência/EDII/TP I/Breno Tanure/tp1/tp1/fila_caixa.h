#include <stdio.h>

typedef struct{
		int chave;
		//int ficha=0, bandeja=0, alimento1=0, alimento2=0, alimento3=0, alimento4=0;
		int chegada=0;
		int saida=0;
}TPessoa;

typedef struct{
	TPessoa dados;
	celula *prox;
}celula;

typedef struct{
	celula *inicio;
	celula *final;
}fila_caixa;

typedef struct{
	celula* inicio;
	celula* final;
}fila_bandejas;



fila_caixa* cria_fila_caixa();
fila_bandejas* cria_fila_bandejas();
void libera_fila_caixa(fila_caixa* filac);
void libera_fila_bandejas(fila_bandejas* filab);
int tamanho_fila_caixa(fila_caixa* filac);
int tamanho_fila_bandejas(fila_bandejas* filab);
//int fila_caixa_cheia(fila_caixa* filac);
//int fila_bandejas_cheia(fila_bandejas* filab);
int fila_caixa_vazia(fila_caixa* filac);
int fila_bandejas_vazia(fila_bandejas* filab);