#include "fila.h"

t_fila* FFVazia(){
	t_fila *fila = (t_fila*)malloc(sizeof(t_fila));
	fila->frente = (t_celula*)malloc(sizeof(t_celula));
	fila->tras = fila->frente;
	fila->tras->prox = NULL;
	fila->tras->item.chave = 0;
	fila->tras->item.tempo = 0;
	fila->tamanho = 0;
	return fila;
}

int VaziaF(t_fila fila){
	return(fila.frente == fila.tras);
}

void Enfileira(t_item item, t_fila *fila){
	fila->tras->prox = (t_celula*)malloc(sizeof(t_celula));
	fila->tras = fila->tras->prox;
	fila->tras->item = item;
	fila->tras->prox = NULL;
	fila->tamanho++;
	
}

void Desenfileira(t_item *item, t_fila *fila){
	if(VaziaF(*fila)){
		printf("\nERRO! A fila ja esta vazia.\n");
		return;
	}
	t_apontador aux = fila->frente;
	fila->frente = fila->frente->prox;
	*item = fila->frente->item;
	free(aux);
	fila->tamanho--;
}

void DestroiFila(t_fila *fila){
	while(!VaziaF(*fila)){
		t_apontador aux = fila->frente;
		fila->frente = fila->frente->prox;
		free(aux);
		fila->tamanho--;
	}
	free(fila->frente);
	free(fila);

}

t_item RetornaPrimeiro(t_fila *fila){
	return fila->frente->item;
}

int VerificaFMenor(t_fila **fila, int tam_fila){
	
	int k, indice = 0;
	
	for(k = 1; k < tam_fila; k++){
		if(fila[k]->tamanho < fila[indice]->tamanho){
			indice = k;
		}
	}
	return indice;
}

int VerificaFMaior(t_fila **fila, int tam_fila){
	
	int k, indice = 0;
	
	for(k = 1; k < tam_fila; k++){
		if(fila[k]->tamanho > fila[indice]->tamanho){
			indice = k;
		}
	}

	return indice;
}
