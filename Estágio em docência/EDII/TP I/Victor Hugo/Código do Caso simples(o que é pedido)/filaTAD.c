#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "filaTAD.h"


//FUNCOES/////////////////////////////////////////////////////////////////////////////////////////////////////////////


//basicamente é o init fila.Aponta a fila frente e tras para uma "cabeça" vazia.
void IniciaFila(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

//funcao que checa se a fila esta vazia
int Vazia(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}

//-----------------------//------------------------------------------//
//enfilera x na fila e o coloca na ultima celula
void Enfileira(Aluno* x, TFila *Fila) {
	if( x != NULL){
		Fila->Tras->Prox = malloc(sizeof(TCelula));
		Fila->Tras = Fila->Tras->Prox;
		Fila->Tras->Item = x;
		Fila->Tras->Prox = NULL;
	}
	else{
		return;
	}
}

//funcao que nulifica aluno
void Nulifica(Aluno* Item){
	Item->posicao = -1;
	Item->ultima = -1;
	Item->tempo = -1;
	Item->arroz = -1;
	Item->feijao = -1;
	Item->guarnicao = -1;
	Item->salada = -1;
}

// -----------------------//--------------------------------------//
//funcao verifica se Fila se encontra vazia e caso não desinfileira o primeiro, passando para o segundo o "primeiro".
Aluno* Desenfileira(TFila *Fila) {
    if (Vazia(*Fila)) {
        //printf("\nErro: fila vazia!");
        return NULL;
    }
	else{
    //apontador q é usado para remover a celula da frente que sairá
		Apontador q = Fila->Frente;
		Fila->Frente = Fila->Frente->Prox;
		Aluno* p = q->Item;
		free(q);
		return p;
	}
}