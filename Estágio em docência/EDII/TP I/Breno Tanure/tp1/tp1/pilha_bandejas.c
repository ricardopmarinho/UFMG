#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilhas.h"

pilha_bandejas FPvazia(void){
	pilha_bandejas pilha;
	pilha.topo = NULL;
	pilha.fundo = NULL;

	return pilha;
}


bool pilha_ta_vazia(pilha_bandejas pilha){
	return (pilha.topo == pilha.fundo);
}
		

void empilha(TBandejas* x, pilha_bandejas* pilha){
	if(pilha == NULL){
		return;
	}


	t_celula_bandejas* aux = malloc(sizeof(t_celula_bandejas));
	aux->bandeja = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;

}

TBandejas* desempilha(pilha_bandejas *pilha){
	TBandejas* bandeja;

	if(pilha == NULL){
		return NULL;
	}

	if(pilha_ta_vazia(*pilha)){
		//printf("Erro: pilha vazia\n");
		return NULL;
	}
	t_celula_bandejas *aux = pilha->topo;
	pilha->topo =  aux->prox;

	if(pilha->topo == NULL){ //pilha ficou vazia
		pilha->fundo = NULL;
	}

	bandeja = aux->bandeja;
	free(aux);
	pilha->tamanho--;
	return bandeja;
}



int Tamanho(pilha_bandejas pilha){
	return (pilha.tamanho);
}

void libera_pilha(pilha_bandejas* pilha){
	if(pilha != NULL){
		t_celula_bandejas* aux;
		while(pilha->topo != NULL){
			aux = pilha->topo;
			pilha->topo = pilha->topo->prox;
			free(aux);
		}

		pilha->fundo = NULL;
	}
}



