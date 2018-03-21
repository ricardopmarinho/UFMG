 #include <stdio.h>
 #include <stdlib.h>
 #include "FilaDin.h"
 
 void FFVazia(TipoFila *Fila){
	Fila->Frente = (TipoApontadorF) malloc(sizeof(TipoCelulaF));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
 }
 
 int FVazia(TipoFila Fila){
	return (Fila.Frente == Fila.Tras);
 }
 
 void Enfileira(TipoItemF x, TipoFila *Fila){
	Fila->Tras->Prox = (TipoApontadorF) malloc(sizeof(TipoCelulaF));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->Item = x;
	Fila->Tras->Prox = NULL;
 }
 
 void Desenfileira(TipoFila *Fila, TipoItemF *Item){
	TipoApontadorF aux;
	if(FVazia(*Fila)){
		printf("Erro fila vazia\n");
		return;
	}
	aux = Fila->Frente;
	Fila->Frente = Fila->Frente->Prox;
	*Item = Fila->Frente->Item;
	free(aux);
 }
 
 void ImprimeF(TipoFila Fila){
	TipoApontadorF Aux;
	Aux = Fila.Frente->Prox;
	while(Aux != NULL){
		printf("%d\n", Aux->Item.Chave);
		Aux = Aux->Prox;
	}
 }
 
