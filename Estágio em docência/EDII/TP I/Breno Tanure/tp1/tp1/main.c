#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filas.h"
#include "pilhas.h"
#define MAX_BANDEJAS 30
#define usuarios 2


int main(int argc, char const *argv[]){

	int tempo=240, i, p=0, x=0, l=0, num_pessoas=0, atendidos=0, soma_tempo=0;
	TPessoa* cliente;
	TPessoa* outro_cliente;
	TPessoa* caixa = NULL;
	TPessoa* saiu = NULL;
	TBandejas *bandejas = malloc(30*(sizeof(TBandejas)));
	pilha_bandejas pilha = FPvazia();



	for(i=0; i<30; i++){
		empilha(bandejas, &pilha);
		printf("empilhou\n");
		printf("tamanho da pilha: %d\n", Tamanho(pilha));
	}
//-------------------criando as filas------------------------------------------------------------//
	fila_pessoas fila_caixa = cria_fila_pessoas(); //cria a fila do caixa
	fila_pessoas fila_bandejas = cria_fila_pessoas(); //cria a fila das bandejas
	printf("criou filas\n");
//----------------------------------------------------------------------------------------------//


	for(i=0; i<tempo; i++){ //de 0 a 4h (60 min *4)
		cliente = malloc(sizeof(TPessoa));
		outro_cliente = malloc(sizeof(TPessoa));
		cliente->chegada = i;     //guarda a hora na qual o cliente chegou na fila
		outro_cliente->chegada = i;//

		insere_fila_pessoas(&fila_caixa, cliente);      ///
		insere_fila_pessoas(&fila_caixa, outro_cliente); ///chegam 2 clientes por vez
		printf("inseriu na fila do caixa\n");
		//printf("tempo chegada: %d\n", cliente->chegada);
		num_pessoas+=2;
		
		printf("cliente chegada: %d\n", cliente->chegada);
		printf("outro_cliente chegada: %d\n", outro_cliente->chegada);
		if(caixa != NULL){
			insere_fila_pessoas(&fila_bandejas, caixa); //vai à fila de bandejas
			caixa = remove_fila_pessoas(&fila_caixa);
		}

		else{
			caixa = remove_fila_pessoas(&fila_caixa);
		}

		 //pega a ficha
		printf("removeu caixa e inseriu nas bandejas\n");

	//-------//a cada 12 intervalos de tempo, +bandejas até 30-------//
		if(i%12 == 0){ 
			for(x=0; x<10; x++){
				if(Tamanho(pilha)==30){
					break;
				}
				empilha(bandejas, &pilha);
				printf("trabalhou nas bandejas\n");
			}
		}
	//-----------------------------------------------------------------------------//
		
		if(pilha_ta_vazia(pilha) == false){ //o cliente só sai da fila quando ha bandejas para ele
				desempilha(&pilha);
				remove_fila_pessoas(&fila_bandejas); //pegou a bandeja
				printf("saiu da fila de bandejas\n");
				cliente->saida = i+4; //pega cada um dos 4 alimentos em um tempo cada

				cliente->tempo_gasto = cliente->saida - cliente->chegada;
				soma_tempo += cliente->tempo_gasto;
				atendidos++;
				free(cliente);
				free(outro_cliente);
		}



	} // fim do for





	printf("Acabou. Pessoas: %d\n", num_pessoas);
	printf("Atendidos: %d\n", atendidos);
	printf("Tempo gasto de geral: %d\n", soma_tempo);


	return 0;
}
	




