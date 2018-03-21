#include <stdio.h>
#include <stdlib.h>
#include "tp.h"

void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(CelulaF));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

void FPVazia(TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(CelulaP));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int FVazia(TFila F) {
    return (F.Frente == F.Tras);
}

int PVazia(TPilha P) {
    return (P.Topo == P.Fundo);
}

void Enfileira(TItem x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(CelulaF));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->NumPessoa = x;
    Fila->Tras->Prox = NULL;
}

void Empilha(/*TItem x,*/ TPilha *Pi) {
    Prato Aux = malloc(sizeof(CelulaP));
    //Pi->Topo->NumPrato = x;
    Aux->Prox = Pi->Topo;
    Pi->Topo = Aux;
    Pi->Tamanho++;
}

void Desenfileira(TFila *Fila, TItem *Item) {
    if (FVazia(*Fila)) {
        printf("Erro: fila vazia\n");
        return;
    }
    Pessoa q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->NumPessoa;
    free(q);
    //return Item->Chave;
}

void Desempilha(TPilha *Pi/*, TItem *Item*/) {
    if (PVazia(*Pi)) {
        printf("Erro lista vazia\n");    
        return;
    }
    Prato q = Pi->Topo;
    Pi->Topo = q->Prox;
    //*Item = q->Prox->NumPrato;
    free(q);
    Pi->Tamanho--;
}

void ChegaCliente(TFila *Fi, TItem *cont,int tempo){
	cont->Chave +=1;
	cont->Time = tempo;
	//printf("chave: %d",cont->Chave);
		Enfileira(*cont,Fi);
	cont->Chave +=1;
	cont->Time = tempo;
	//printf("chave: %d",cont->Chave);
		Enfileira(*cont,Fi);
}

void Caixa(TFila *Ent,TFila *Sai){
	TItem Ficha;
	Desenfileira(Ent,&Ficha);
	Enfileira(Ficha,Sai);
}

void VerificaTudo(int tempo,TPilha *Pr){
	int k,tam = 30 - Pr->Tamanho;
		if((tempo % 12)==0){				
			if(tam > 0 && tam < 10){						
				for(k=0;k<tam;k++){
					Empilha(Pr);
				}			
			}
			else if(tam > 10 && tam <31){
				for(k=0;k<10;k++){
					Empilha(Pr);
				}
			}
		}		
}