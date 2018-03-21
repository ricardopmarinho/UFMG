#include <stdio.h>
#include <stdlib.h>
#include "BibliTP.h"


// Funções para manipulação da fila
void CriaFila(TFila *Fila) {
	Fila->Frente = malloc(sizeof(TCelula));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
	Fila->Tamanho++;
}
int Vazia(TFila Fila) {
	return (Fila.Frente == Fila.Tras);
}
void Enfileira(TCliente cliente, TFila *Fila) {
	Fila->Tras->Prox = malloc(sizeof(TCelula));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->Cliente = cliente;
	Fila->Tras->Prox = NULL;
}
void Desenfileira(TFila *Fila, TCliente *Cliente) {
	if (Vazia(*Fila)) {
		printf("Erro: fila vazia\n");
		return;
	}
	Apontador aux = Fila->Frente;
	Fila->Frente = Fila->Frente->Prox;
	*Cliente = Fila->Frente->Cliente;
	free(aux);
}
//Funções para manipulação do tempo
void inicializaTempo(TCliente *cliente){
    cliente->Tempo_Chegada = 0;
}
void AttTempo (TCliente *cliente){
    cliente->Tempo_Chegada += 1;
}
// Funções para manipulação da pilha
void FPVazia(TPilha *Pilha) {
	Pilha->Topo = malloc(sizeof(TCelula));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}
int Vaziap(TPilha Pilha) {
	return (Pilha.Topo == Pilha.Fundo);
}
void Empilha(TCliente x, TPilha *Pilha) {
	Apontador Aux = malloc(sizeof(TCelula));
	Pilha->Topo->Cliente = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}
void Desempilha(TPilha *Pilha, TCliente *Cliente) {
	if (Vaziap(*Pilha)) {
		printf("Erro pilha vazia\n");
		return;
	}
	Apontador aux = Pilha->Topo;
	Pilha->Topo = aux->Prox;
	*Cliente = aux->Prox->Cliente;
	free(aux);
	Pilha->Tamanho--;
}
int Tamanho(TPilha Pilha) {
	return Pilha.Tamanho;
}
