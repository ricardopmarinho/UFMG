#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"
#include "lanchonete.h"

void preencheCliente( TItemCliente *cliente, int tempo, int numeroCliente){
	cliente->Chave = numeroCliente;
	cliente->entrouLanchonete = tempo;
	cliente->saiuLanchonete = 0;
}

void saidaCliente(TItemCliente *cliente, int tempo){
	cliente->saiuLanchonete = tempo;
}

int tempoAtendimentoCliente(TItemCliente *cliente){
	return ((cliente->saiuLanchonete) - (cliente->entrouLanchonete));
}

void adicionaDoisClientesNaFila(TFila *fila, int *tempo, int *qntClientes){
	TItemCliente cliente;
	*qntClientes += 1;
	preencheCliente(&cliente, *tempo, *qntClientes);
	entraNaFila(cliente, fila);
	*qntClientes += 1;
	preencheCliente(&cliente, *tempo, *qntClientes);
	entraNaFila(cliente, fila);
}

void entraNaFila(TItemCliente cliente, TFila *fila){
	Enfileira(cliente, fila);
}

void Fila(TFila *fila, TItemCliente *cliente){
	Desenfileira(fila, cliente);
}

int pilhaBandejasVazia(TPilha bandejas){
	return PVazia(bandejas);
}

int pilhaBandejasCheia(TPilha bandejas){
	return (bandejas.Tamanho < 30);
}

void preencheBandeja(TItemBandeja *bandeja, int numeroBandeja){
	bandeja->Chave = numeroBandeja;
}

void retiraBandeja(TPilha *bandejas, TItemBandeja *bandeja){
	if(!pilhaBandejasVazia(*bandejas)){
		Desempilha(bandejas, bandeja);
	}
}

void adicionaBandeja(TPilha *bandejas, TItemBandeja *bandeja, int *qntBandejas){
	if(pilhaBandejasCheia(*bandejas)){
		*qntBandejas += 1;
		preencheBandeja(bandeja, *qntBandejas);
		Empilha(*bandeja, bandejas);	
	}
	else
		printf("Pilha de Bandejas Cheia!!!! Bandeja nao adicionada\n");
}

void vaiParaPosicao(TFila *fila, TItemCliente *caixa){
	Desenfileira(fila, caixa);
}

void saiDaPosicao(TItemCliente cliente, TFila *filaBandejas){
	Enfileira(cliente, filaBandejas);
}



void preenchePosicaoVazio(TItemCliente *caixa){
	caixa->Chave = 0;
	caixa->entrouLanchonete = 0;
	caixa->saiuLanchonete = 0;
}

int posicaoVazia(TItemCliente posicao){
	return (posicao.Chave == 0);
}

void trocaFilas(TFila *Fila1, TFila *Fila2){
	TFila *aux;
	aux = Fila1;
	Fila1 = Fila2;
	Fila2 = aux;
}