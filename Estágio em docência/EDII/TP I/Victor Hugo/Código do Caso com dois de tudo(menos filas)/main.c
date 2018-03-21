#include "filaTAD.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pilhaTAD.h"



int main(){
	//Inteiros usados ao longo do programa , de forma organizada.
	int TempoMaxMinutos = 240;
	int QtdBandejas = 30;
	int QuantidadeMaximaPessoas = TempoMaxMinutos * 2;
    int minutos;//cada minuto do for
	int ContadorAlunos = 0;//faz o papel de contar alunos usados no for(2 por minuto)
	int i;
	int TmpTotalAcabaram = 0;
	
	//criando fila ficha
	TFila FilaFicha;
	IniciaFila(&FilaFicha);
	
	//criando fila bandeja
	TFila FilaBandeja;
	IniciaFila(&FilaBandeja);
	
	//Filas de servir alimento
	
	TFila FilaGuarnicao;
	IniciaFila(&FilaGuarnicao);
	
	TFila FilaSalada;
	IniciaFila(&FilaSalada);
	
	
	//Fila de quem terminou
	TFila FilaTerminou;
	IniciaFila(&FilaTerminou);
	
	//criando PilhaBandejas
	TPilha PilhaBandejas;
	TPilha PilhaBandejasUsadas;
	IniciaPilha(&PilhaBandejas);
	IniciaPilha(&PilhaBandejasUsadas);
	
	TPilha SPilhaBandejas;
	TPilha SPilhaBandejasUsadas;
	IniciaPilha(&SPilhaBandejas);
	IniciaPilha(&SPilhaBandejasUsadas);
	
	
	//criando o vetor de alunos que vao ser atendidos
	Aluno *pessoas;
	pessoas = (Aluno*) malloc(QuantidadeMaximaPessoas * sizeof(Aluno));
	
	//criando o vetor de bandejas que vão ser disponiveis e as empilhando
	TPItem *bandejas;
	bandejas = (TPItem*) malloc(QtdBandejas * sizeof(TPItem));
	TPItem *Sbandejas;
	Sbandejas = (TPItem*) malloc(QtdBandejas * sizeof(TPItem));
	
	for(i = 0; i < QtdBandejas; i++){
		Empilha(bandejas[i], &PilhaBandejas);
	}
	
	for(i = 0; i < QtdBandejas; i++){
		Empilha(Sbandejas[i], &SPilhaBandejas);
	}
	
	//da a posicao numero para cada um
	for(i = 0; i < QuantidadeMaximaPessoas ; i++){
		pessoas[i].posicao = i + 1;
		pessoas[i].ultima = 0;
		pessoas[i].tempo = 0;
		//printf("\nposicao %d = %d", i , pessoas[i].posicao);
	}
	
	//criando a bandeja auxiliar
	TPItem bandejaAux , bandejaAuxA, SbandejaAux, SbandejaAuxA;
	
	//criando itens auxiliares para movimento entre as 4 filas finais
	Aluno *Termina,*Arroz, *Feijao, *Guarnicao, *Salada;
	
	
	Termina = NULL;
	Arroz = NULL;
	Feijao = NULL;
	Guarnicao = NULL;
	Salada = NULL;
	
	Aluno *STermina,*SArroz, *SFeijao, *SGuarnicao, *SSalada;
	
	
	STermina = NULL;
	SArroz = NULL;
	SFeijao = NULL;
	SGuarnicao = NULL;
	SSalada = NULL;
	
	
	//ocorre mesma situacao da de caixa(essa e para a bandeja)
	Aluno* talher;
	Aluno* Stalher;
	talher = NULL;
	Stalher = NULL;
	//iniciando o caixa como nulo
	Aluno* caixa;
	caixa = NULL;
	Aluno* Scaixa;
	Scaixa = NULL;
	
	////////////////////////////////////////LOOP QUE EMULA A CANTINA ///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	for( minutos = 0 ; minutos < TempoMaxMinutos ; minutos++){
		
		////////////CASO DAS BANDEJAS SENDO ADICIONADAS ( 10 A CADA 12 MINUTOS)//////////////////////////////////////
		if( minutos % 12 == 0){
			//se a quantidade de bandeja usada for menor que 10 , adiciona só a qtd de bandeja que falta
			if(Tamanho(PilhaBandejasUsadas) < 10){
				for(i = 0; i < Tamanho(PilhaBandejasUsadas) ; i++){
					Desempilha((&PilhaBandejasUsadas) , (&bandejaAuxA));
					Empilha( bandejaAuxA , (&PilhaBandejas));
				}
			}
			
			else{
				//se nao adiciona 10 bandejas a cada 12 mins
				for(i = 0; i < 10 ; i++){
					Desempilha((&PilhaBandejasUsadas) , (&bandejaAuxA));
					Empilha( bandejaAuxA , (&PilhaBandejas));
				}
			}
		}
		
		if( minutos % 12 == 0){
			//se a quantidade de bandeja usada for menor que 10 , adiciona só a qtd de bandeja que falta
			if(Tamanho(SPilhaBandejasUsadas) < 10){
				for(i = 0; i < Tamanho(SPilhaBandejasUsadas) ; i++){
					Desempilha((&SPilhaBandejasUsadas) , (&SbandejaAux));
					Empilha( SbandejaAux , (&SPilhaBandejas));
				}
			}
			
			else{
				//se nao adiciona 10 bandejas a cada 12 mins
				for(i = 0; i < 10 ; i++){
					Desempilha((&SPilhaBandejasUsadas) , (&SbandejaAux));
					Empilha( SbandejaAux , (&SPilhaBandejas));
				}
			}
		}
		
	
		///////CHEGADA DE DOIS/////////////////////////////////
		//os dois que vao chegar na fila de ficha a cada minuto
		Enfileira( &pessoas[ContadorAlunos], (&FilaFicha));	
		Enfileira( &pessoas[ContadorAlunos+1], (&FilaFicha));
		
		//SAIDA DA FILA DE FICHA E ENTRADA FILA BANDEJA/////////////
		//Se tem alguem no caixa vai para bandeja , caso nao , nada ocorre. Depois sai alguem da ficha e vai para o caixa.
		//se for -1 e considerado nulo e nao ocorre nada
		Enfileira( (caixa) , (&FilaBandeja) );
		caixa = Desenfileira((&FilaFicha));
		
		Enfileira( (Scaixa) , (&FilaBandeja) );
		Scaixa = Desenfileira((&FilaFicha));	
		
		///////////////////////////////////CASOS DOS ALIMENTOS SERVINDO//////////////////////////////////////////////
		//LEMBRANDO QUE O CASO DO ALIMENTOS SERVIDOS ACONTECE MESMO QUE A DE BANDEJA PARE .
			
			
		
		//caso que serve arroz e conta mais um minuto
		/*Termina = Arroz;
		
		if(Termina != NULL){
			Termina->ultima = 1;
			TmpTotalAcabaram = TmpTotalAcabaram + Termina->tempo;
		}
		*/
		//caso que sai da de feijao e vai de arroz
		Arroz = Feijao;
		if( Arroz != NULL){
			Arroz->ultima = 1;
			TmpTotalAcabaram = TmpTotalAcabaram + Arroz->tempo;
		}
			
		//caso em que sai da de guarnicao  e entra na de feijao
		Feijao = Guarnicao;
			
		//caso em que sai da de salada e entra na de guarnicao
		Guarnicao = Salada;
		Salada = Desenfileira( (&FilaSalada) );
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Segunda Parte de comidas///////////////////////////////////////////////////////////////////////////////////////
		
		SArroz = SFeijao;
		if( SArroz != NULL){
			SArroz->ultima = 1;
			TmpTotalAcabaram = TmpTotalAcabaram + SArroz->tempo;
		}
			
		//caso em que sai da de guarnicao  e entra na de feijao
		SFeijao = SGuarnicao;
			
		//caso em que sai da de salada e entra na de guarnicao
		SGuarnicao = SSalada;
		SSalada = Desenfileira( (&FilaSalada) );
			
			
		
		
		//SE A PILHA DE BANDEJAS NAO TIVER VAZIA OCORRE O DESENFILERAMENTO DAS BANDEJAS E ENTRADA DE TALHER NA FILA DE COMIDA
		
		Enfileira( (talher) , (&FilaSalada) );
		if(Tamanho(PilhaBandejas) != 0) {
			//reduz a quantidade de bandejas disponiveis
			Desempilha((&PilhaBandejas) , (&bandejaAux));
			Empilha( bandejaAux , (&PilhaBandejasUsadas));
			
			
			//CASO BANDEJA//
			//caso em que sai da fila de bandeja e entra na de salada
			//no caso da bandeja é 1
			talher = Desenfileira( (&FilaBandeja));
		}
	
		Enfileira( (Stalher) , (&FilaSalada) );
		if(Tamanho(SPilhaBandejas) != 0) {
			//reduz a quantidade de bandejas disponiveis
			Desempilha((&SPilhaBandejas) , (&SbandejaAuxA));
			Empilha( SbandejaAuxA , (&SPilhaBandejasUsadas));
			
			
			//CASO BANDEJA//
			//caso em que sai da fila de bandeja e entra na de salada
			//no caso da bandeja é 1
			Stalher = Desenfileira( (&FilaBandeja));
		}	
		
		
		//FINAL DO MINUTO//////////////////////////////////////////////////////
		//incremento de mais duas pessoas no total de pessoas que estao no vetor
		ContadorAlunos = ContadorAlunos + 2;
		
		//aumentando o tempo em minutos de cada um que fica na fila caso esse nao tenha saido da mesma
		for(i = 0; i < ContadorAlunos; i++){
			if( pessoas[i].ultima != 1){
				pessoas[i].tempo = pessoas[i].tempo + 1;
			}
			else{
				//nota-se que quando ultima = 1 , indica que o mesmo pessoas[i] ja saiu da fila e nao esta mais tempo.
			
			}
		}
	}
	
	int Acabaram = 0;
	float ContadorDTempo = 0;
	for(i = 0; i < QuantidadeMaximaPessoas ; i++){
		ContadorDTempo = pessoas[i].tempo + ContadorDTempo;
		//printf("\npessoas[%d].tempo= %d" , i, pessoas[i].tempo );
		if( pessoas[i].ultima == 1){
			Acabaram = Acabaram + 1;
		}
	}
	printf("\nQuantidade Total = %d \nQuantidade que se serviu = %d" , ContadorAlunos , Acabaram );
	float AlunoTotal = ContadorAlunos;
	printf("\ntempo total = %d\ntempo medio = %f" , TempoMaxMinutos , (ContadorDTempo / AlunoTotal));
	
	free(bandejas);
	free(pessoas);
	free(Sbandejas);
}