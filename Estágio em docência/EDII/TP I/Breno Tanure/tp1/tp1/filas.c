#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

struct t_celula_pessoa {
	TPessoa* pessoa;
	celula_pessoa* prox;
};


fila_pessoas cria_fila_pessoas(void){
	fila_pessoas filac;
	filac.final = NULL;
	filac.inicio = NULL;

	return filac;
}

void libera_fila_pessoas(fila_pessoas* filac){
	if(filac != NULL){
		celula_pessoa* aux;
		while(filac->inicio != NULL){
			aux = filac->inicio;
			filac->inicio = filac->inicio->prox;
			free(aux);
		}
		
		filac->final = NULL;
	}
}


void insere_fila_pessoas(fila_pessoas *filac, TPessoa* aluno) {
	if (filac == NULL){
		return;
	}

	if (fpessoas_ta_vazia(*filac)){
		filac->inicio = malloc(sizeof(celula_pessoa));
		filac->inicio->prox = NULL;
		filac->inicio->pessoa = aluno;
		filac->final = filac->inicio;

		return;
	}

	filac->final->prox = malloc(sizeof(celula_pessoa));
	filac->final = filac->final->prox;
	filac->final->pessoa = aluno;
	filac->final->prox = NULL;
}

TPessoa* remove_fila_pessoas(fila_pessoas *filac){
	TPessoa* aluno;

	if(filac == NULL){
		return NULL;
	}

	if(fpessoas_ta_vazia(*filac)) { //fila vazia
		return NULL;
	}

	celula_pessoa *aux = filac->inicio;
	filac->inicio = filac->inicio->prox;

	if(filac->inicio == NULL){ //fila ficou vazia
		filac->final = NULL;
	}

	aluno = aux->pessoa;

	free(aux);

	return aluno;
}


bool fpessoas_ta_vazia(fila_pessoas filac){
	return filac.inicio == NULL && filac.final == NULL;
}





