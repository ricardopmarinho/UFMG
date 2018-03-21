#include <stdio.h>
#include <stdlib.h>
#include "band.h" //inclui os Protótipos

void FPVazia(TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(TCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia(TPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TItem x, TPilha *Pilha) {
    Apontador Aux = malloc(sizeof(TCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha) {
    if (Vazia(*Pilha)) {
        //printf("Erro Pilha vazia\n");
        return;
    }
    Apontador q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    free(q);
    Pilha->Tamanho--;
}


int Tamanho(TPilha Pilha) {
    return Pilha.Tamanho;
}

TItem emiplha_bandeja(TItem n_band, int x){
	
	n_band.Chave = x; // o = 2 = 1
	return n_band;
}


int destroi_pilha(TPilha *Pilha){
	
	while(Pilha->Topo == Pilha->Fundo){
		Apontador q = Pilha->Topo;
		Pilha->Topo = q->Prox;
		free(q);
	}
	
	
}