#include "pilha.h"

t_pilha* FPVazia(){
	t_pilha *pilha = (t_pilha*)malloc(sizeof(t_pilha));
	pilha->topo = (t_campo*)malloc(sizeof(t_campo));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->topo->item.chave = 0;
	pilha->tamanho = 0;
	return pilha;
}

int VaziaP(t_pilha pilha){
	return(pilha.topo == pilha.fundo);
}
void Empilha(t_conteudo item, t_pilha *pilha){
	t_ponteiro aux = (t_campo*)malloc(sizeof(t_campo));
	pilha->topo->item = item;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

void Desempilha(t_conteudo *item, t_pilha *pilha){
	t_ponteiro aux = pilha->topo;
	pilha->topo = aux->prox;
	*item = aux->prox->item;
	free(aux);
	pilha->tamanho--;
}

void DestroiPilha(t_pilha *pilha){
	while(!VaziaP(*pilha)){
		t_ponteiro aux = pilha->topo;
		pilha->topo = pilha->topo->prox;
		free(aux);
		pilha->tamanho--;
	}
	free(pilha->fundo);
	free(pilha);
}

int VerificaPMaior(t_pilha **pilha, int tam_pilha){
	
	int k, indice = 0;
	
	for(k = 1; k < tam_pilha; k++){
		if(pilha[k]->tamanho > pilha[indice]->tamanho){
			indice = k;
		}
	}
	return indice;
}