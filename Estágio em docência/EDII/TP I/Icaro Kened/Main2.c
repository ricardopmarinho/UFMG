#include <stdio.h>
#include "FilaCant.h"
#include "PilhaCant.h"

#define EXPEDIENTE 240

int main(void){
	
	TFila *FilaCaixa;
	FilaCaixa = (TFila *) malloc(sizeof(TFila));

	TFila *FilaBandeja;
	FilaBandeja = (TFila *) malloc(sizeof(TFila));
	
	TPilha *PilhaBandeja;
	PilhaBandeja = (TPilha *) malloc(sizeof(TPilha));
	
	TFila *FilaAlimentos;
	FilaAlimentos = (TFila *) malloc(sizeof(TFila));
	
	TItem X;
	
	int AlunTotal = 0;
	int tempo = 0, TempoMedio = 0, AlunAtendidos = 0, cont = 0, j =0;
	
	
	while(cont < EXPEDIENTE){
	
	if (tempo % 20 == 0){
		for(j=0; j<= 12; j++){
			Empilha(X, &PilhaBandeja);
		}
	}
		
	for(i = tempo; i < tempo + 1; i++){
		Enfileira(X, &FilaCaixa);  //Duas pessoas foram enfileiradas na fila do caixa
		Enfileira(X, &FilaCaixa);
		AlunTotal = AlunTotal + 2; // numero de pessoas que entreram na fila
		tempo ++;  //contagem do tempo
	}
	
	Desenfileira(&FilaCaixa, &X);
	
	
	Enfileira(X, &FilaBandeja); //Passa o usuário já atendido na fila do caixa para a fila das bandejas
	tempo++;
	
	
	if(!Vazia(PilhaBandeja)){  //Verifica se possuem bandejas na pilha de bandejas (Retorna true se estiver vazia)
		
		Desenfileira(&FilaBandeja, &X);
		
		Desempilha(&PilhaBandeja, &X);
		
		Enfileira(X, &FilaAlimentos);
		tempo = tempo + 4;
		
		Desenfileira(&FilaAlimentos, &X);
		
		cont = cont + tempo;
		AlunAtendidos++;
	}
	
	else{
		printf("Sem bandejas");
	}
	
	}
	
	TempoMedio = tempo / AlunAtendidos;
	
	printf("O numero de pessoas atendidas foi de: %d", AlunAtendidos);
	
	printf("O tempo medio do atendimento dos alunos foi: %d", TempoMedio);
	
	return (0);
	

	
	
}