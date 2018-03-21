#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

void FPilhaVazia (TPilha *pilha){
	pilha->topo=malloc(sizeof(TCelula));
	pilha->topo->prox=NULL;
	pilha->fundo=pilha->topo;
	pilha->tamanho=0;	
}
int PVazia(TPilha pilha){
	return (pilha.topo==pilha.fundo);
}
void Empilha(TItem x, TPilha *pilha){
	Apontador aux = malloc(sizeof(TCelula));
	pilha->topo->item=x;
	aux->prox=pilha->topo;
	pilha->topo=aux;
	pilha->tamanho++;	
}
void Desempilha(TPilha *pilha, TItem *item){
	if(PVazia(*pilha)){
		printf("\nPilha vazia\n");
		return;
	}
	Apontador q=pilha->topo;
	pilha->topo=q->prox;
	*item=q->prox->item;
	free(q);
	pilha->tamanho--;	
}
int PTamanho(TPilha pilha){
	return pilha.tamanho;
}

void liberaP (TPilha *pilha){
	TItem p;
	while(pilha->topo->prox!=NULL){
		Desempilha(pilha,&p);		
	}
		free(pilha->topo);
		free(pilha);		
	}
	
void FFilaVazia (TFila *fila){
	fila->frente=malloc(sizeof(TCelula));
	fila->frente->prox=NULL;
	fila->tras=fila->frente;
	fila->tamanho=0;
}
int FVazia(TFila fila){
	return (fila.frente==fila.tras);
}
void Enfileira(TItem x, TFila *fila){
	fila->tras->prox = malloc(sizeof(TCelula));
	fila->tras = fila->tras->prox;
	fila->tras->item = x;
	fila->tras->prox = NULL;
	fila->tamanho++;
}
void Desenfileira(TFila *fila, TItem *item){
	if(FVazia(*fila)){
		printf("\n Fila vazia\n"); 
		return;
	}
	Apontador q = fila->frente;
	fila->frente = fila->frente->prox; 
	*item = fila->frente->item; 
	free(q);
	fila->tamanho--;
}
int FTamanho(TFila fila){
	return fila.tamanho;
}

void liberaF (TFila *fila){
	TItem p;
	while(fila->frente->prox!=NULL){
		Desenfileira(fila,&p);		
	}
		free(fila->frente);
		free(fila);		
	}	


void PassaTempo (TFila *fband, TFila *fcaixa, TFila *alim, TItem *caixa, TItem *band){
	Apontador p;
	if(caixa->tempo!=-1){
		caixa->tempo++;
	}
	if(band->tempo!=0){
		band->tempo++;
	}
	if(!FVazia(*fband)){
		p=fband->frente->prox;
		while(p!=NULL){
			p->item.tempo++;
			p=p->prox;			
		}
	}
	if(!FVazia(*fcaixa)){
		p=fcaixa->frente->prox;
		while(p!=NULL){
			p->item.tempo++;
			p=p->prox;			
		}
	}	
	if(!FVazia(*alim)){
		p=alim->frente->prox;
		while(p!=NULL){
			p->item.tempo++;
			p=p->prox;			
		}
	}	
}

void AndaAlimento (TFila *alim){          
	
	Apontador p;	
	if(!FVazia(*alim)){
		p=alim->frente->prox;
		while(p!=NULL){
			p->item.alim++;
			p=p->prox;			
		}
	}	
}		
	
void CriaBandeija (TPilha *pilha){		
	TItem x;
	x.tempo=0;
	x.alim=0;
	
	while(1){
		if(pilha->tamanho==30)
			break;
		Empilha(x,pilha);		
	}	
}

void EncheBandeija (TPilha *pilha){	
	if(pilha->tamanho==30){
		return;
	}
	int contador=0;
	TItem x;
	x.tempo=0;
	x.alim=0;
	
	while(1){
		if(contador==10)
			break;
		if(pilha->tamanho==30)
			break;		
		Empilha(x,pilha);
		contador++;
	}		
}

int TerminouServir (TFila fila){
	if(FVazia(fila)){
		return 0;	
	}
	if(fila.frente->prox->item.alim==4){
		return 1;
	}
	else{
		return 0;
	}
}

void ClienteEmbora (TFila *alim,TFila *fim){
	TItem aux;
	
	if(TerminouServir(*alim)){
		Desenfileira(alim,&aux);
		Enfileira (aux,fim);		
	}
	else
		return;	
}





