#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
#include "PilhaDin.h"
#define TEMPO 240
#define MAXBANDEJAS 30
#define NUM_PESSOAS 480

int main(int argc, char *argv[]){
	// Declaração de variaveis
	int i, j;
	int TempoMedio=0, IdAluno=0;
	int PessoasAtendidas=0, PessoasEnfileiradas=0;	
	//Declaração de TAD's Fila
	TipoFila fila_caixa, fila_bandeja, fila_alimentos;
	TipoItemF *pessoa;
	pessoa = (TipoItemF*) malloc((NUM_PESSOAS) * sizeof(TipoItemF));
	TipoItemF Aux;
	//Declaração de TAD's Pilha
	TipoPilha pilha_bandeja;
	TipoItemP bandeja;	
	bandeja.Chave =0;
	
	FFVazia(&fila_caixa); //Cria Fila Vazia para representar a fila para pegar a ficha
	FFVazia(&fila_bandeja); //Fila para pegar bandejas e talheres	
	FFVazia(&fila_alimentos);// Fila para servir os alimentos
	FPVazia(&pilha_bandeja); // Pilha de bandejas
	
	for(i=0; i<TEMPO; i++){ //Iteração que simula cada espaço de tempo, que é equivalente a um minuto
		
		if(i%12 == 0 && i != 0){ //Verifica se ja se passaram 12 iteraçoes
			for(j=0; j<10; j++){ // Se sim, 10 bandejas sao adicionadas a pilha de bandejas			
				if(TamanhoPilha(pilha_bandeja) < MAXBANDEJAS){ // Respeitando o limite de bandejas da pilha
					bandeja.Chave ++;
					Empilha(bandeja, &pilha_bandeja);
					printf("Empilhou bandeja %d\n",bandeja.Chave);
				}
			}
		}
		
		if(i == 0){			
			pessoa[IdAluno].Chave = IdAluno;			
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Primeira pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Segunda pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;

			PessoasEnfileiradas += 2;
		}
		else if(i == 1){
			pessoa[IdAluno].Chave = IdAluno;			
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Primeira pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Segunda pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;

			PessoasEnfileiradas += 2;			
			
			Desenfileira(&fila_caixa, &Aux); //O primeiro usuario da fila é atendido
			
			Enfileira(Aux, &fila_bandeja); // O primeiro usuario chega na fila de bandejas
		}
		else if(i == 2){
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Primeira pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Segunda pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;

			PessoasEnfileiradas += 2;			
			
			Desenfileira(&fila_caixa, &Aux); //O primeiro usuario da fila é atendido
			Aux.Ficha = 1;
			//printf("Pessoa : %d\n",Aux.Chave);
			
			Enfileira(Aux, &fila_bandeja); // O primeiro usuario chega na fila de bandejas
			
			Desenfileira(&fila_bandeja, &Aux); // O primeiro usuario vai pegar a bandeja
			
			if(!PVazia(pilha_bandeja)){ // Verifica se existem bandejas na pilha
				Desempilha(&pilha_bandeja, &bandeja); //Usuario pega uma bandeja da pilha
			}
		}
		else if(i >= 3 && i <= 6){
			
			Enfileira(Aux, &fila_alimentos);
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Primeira pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Segunda pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;

			PessoasEnfileiradas += 2;			
			
			Desenfileira(&fila_caixa, &Aux); //O primeiro usuario da fila é atendido
			Aux.Ficha = 1;
			//printf("Pessoa : %d\n",Aux.Chave);
			
			Enfileira(Aux, &fila_bandeja); // O primeiro usuario chega na fila de bandejas
			
			Desenfileira(&fila_bandeja, &Aux); // O primeiro usuario vai pegar a bandeja
			
			if(!PVazia(pilha_bandeja)){ // Verifica se existem bandejas na pilha
				Desempilha(&pilha_bandeja, &bandeja); //Usuario pega uma bandeja da pilha
			}			
		}
		else if(i > 6){
			Enfileira(Aux, &fila_alimentos);
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Primeira pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;
			
			pessoa[IdAluno].Chave = IdAluno;
			pessoa[IdAluno].TempoGasto = i;
			Enfileira(pessoa[IdAluno], &fila_caixa); //Segunda pessoa que chega na fila em um espaco de tempo
			//printf("Pessoa %d chegou na fila da ficha\n",pessoa[IdAluno].Chave);
			IdAluno ++;

			PessoasEnfileiradas += 2;			
			
			Desenfileira(&fila_caixa, &Aux); //O primeiro usuario da fila é atendido
			Aux.Ficha = 1;
			//printf("Pessoa : %d\n",Aux.Chave);
			
			Enfileira(Aux, &fila_bandeja); // O primeiro usuario chega na fila de bandejas			
			
			if(!PVazia(pilha_bandeja)){ // Verifica se existem bandejas na pilha
				Desenfileira(&fila_bandeja, &Aux);
				
				Desempilha(&pilha_bandeja, &bandeja); //Usuario pega uma bandeja da pilha
				
				Desenfileira(&fila_alimentos, &Aux);
				
				Aux.TempoGasto = i - Aux.TempoGasto;
				//printf("Tempo %d\n",Aux.TempoGasto);
				
				TempoMedio += Aux.TempoGasto;
				PessoasAtendidas++;
			}
			else{
				printf("Aguardando a reposicao de bandejas.\n");
			}
		}
		
	}

	TempoMedio = TempoMedio / PessoasAtendidas;
	PessoasEnfileiradas = PessoasEnfileiradas - PessoasAtendidas;
	printf("O numero total de pessoas atendidas foi de %d\n", PessoasAtendidas);
	printf("Tempo medio de atendimento dos alunos: %d minutos\n", TempoMedio);	
	return 0;
}