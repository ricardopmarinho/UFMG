#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "lanchonete.h"
#define TEMPOMAXIMO 240 //4 horas

int main(int argc, char ** argv){

	TFila filafichas, filabandejas;
	TPilha pilhabandejas;
	TItemCliente caixa, pegandobandeja;
	TItemBandeja bandeja, bandejaretirada;
	
	int qntClientes = 0, qntBandejas = 0, tamfilacaixa = 0, tamfilabandejas = 0;
	long int tempogeral = 0;
	int tempo = 0, j = 0;
	double mediatempo = 0;

	FFVazia(&filafichas);
	FFVazia(&filabandejas);
	FPVazia(&pilhabandejas);

	//Preenche a posicao do caixa e de pegar bandeja sem cliente inicial
	preenchePosicaoVazio(&caixa);
	preenchePosicaoVazio(&pegandobandeja);

	//Faz todos os movimentos dos clientes enquanto houver clientes na lanchonete
	do{
		//Cada espaço de tempo 2 pessoas entram na fila do caixa
		if(tempo < TEMPOMAXIMO){
			adicionaDoisClientesNaFila(&filafichas, &tempo, &qntClientes);
			tamfilacaixa += 2;	
		}

		//Cada periodo de tempo especifico adiciona bandejas na pilha
		if((tempo % 12) == 0){
			for(j = 0; j < 10; j++){
				adicionaBandeja(&pilhabandejas, &bandeja, &qntBandejas);	
			}
		}

		//Se houver cliente com a bandeja ele vai servir os alimentos e vai ser contado o tempo gasto de servir e o tempo de ficar na posicao
		if(!posicaoVazia(pegandobandeja)){
			retiraBandeja(&pilhabandejas, &bandejaretirada);
			saidaCliente(&pegandobandeja, tempo+5);
			tempogeral += tempoAtendimentoCliente(&pegandobandeja);
		}
		
		//Se houver cliente na fila das bandejas e houver bandeja ele vai para posicao de pegar a bandeja
		if( (!FVazia(filabandejas)) && (!pilhaBandejasVazia(pilhabandejas))){
			vaiParaPosicao(&filabandejas, &pegandobandeja);
			tamfilabandejas -= 1;
		}
		//Caso não tenha bandeja ou não tenha pessoa na fila a posicao de pegar bandeja fica vazia
		else{
			preenchePosicaoVazio(&pegandobandeja);
		}

		//Se o caixa não estiver vazio o cliente sai do caixa e vai para fila de bandejas
		if(!posicaoVazia(caixa)){
			saiDaPosicao(caixa, &filabandejas);
			preenchePosicaoVazio(&caixa);
			tamfilabandejas += 1;
		}

		//Se houver cliente na fila do caixa ele vai para o caixa
		if(!FVazia(filafichas)){
			vaiParaPosicao(&filafichas, &caixa);
			tamfilacaixa -= 1;
		}	
		
		tempo++;
	}while ((!posicaoVazia(pegandobandeja)) || (!FVazia(filabandejas)) || (!posicaoVazia(caixa)) || (!FVazia(filafichas)));

	mediatempo = (double)tempogeral / (double)qntClientes;

	liberaPilha(&pilhabandejas);
	liberaFila(&filafichas);
	liberaFila(&filabandejas);

	printf("quantidade de clientes atendidos: %i\n", qntClientes);
	printf("Tempo total desde a entrada do primeiro cliente ate a saida do ultimo cliente: %i\n", tempo);
	printf("\nMedia de tempo: %f\n", mediatempo);
	
	return 1;
}