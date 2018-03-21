#include <stdio.h>
#include <stdlib.h>
#include "filas.h" //inclui os Protótipos

//funcoes de manuzeio da filas

void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCel));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int FVazia(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(USUARIO x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCel));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Itemm = x;
    Fila->Tras->Prox = NULL;
}

void Enfileira_caixa(USUARIO x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCel));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Itemm = x;
    Fila->Tras->Prox = NULL;
}

void Desenfileira(TFila *Fila, USUARIO *recebido) {
    if (FVazia(*Fila)) {
        printf("Erro: fila vazia\n");
        return;
    }
    Apont q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *recebido = Fila->Frente->Itemm;
    free(q);
}

//USUARIO inicia_serv_comida(USUARIO comida, int x){
USUARIO insere_val_users(USUARIO comida, int x){
	comida.tempo_entrada = x;
	return comida;
}
int retorna_entrada(USUARIO comida){
	return comida.tempo_entrada;


}

int destroi_fila (TFila *Fila){
	
	while(Fila->Frente == Fila->Tras){
		Apont q = Fila->Frente;
		Fila->Frente = Fila->Frente->Prox;
		free(q);
	}
	
	
}