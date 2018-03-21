//MAIN TP --------------------------------------------------------

#include "TAD_PILHA.h"
#include "TAD_FILA.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAXBANDEJA 40

void main(){
	
	int a, b;
	int CodAluno=0, CodBandeja=0;
	int ContIteracao=0;
	int AlunosAtendidos=0, AlunosEmFila=0;
	int TempoTotalAtendimento=0;
	
	TFila FilaFicha;
	TFila FilaBandeja;
	TFila FilaFicha2;
	TFila FilaBandeja2;
	TFila FilaAlimentos;
	TFila FilaAlimentos2;
	TPilha PilhaBandeja;
	TPilha PilhaBandeja2;
	
	FFVazia(&FilaFicha);
	FFVazia(&FilaBandeja);
	FFVazia(&FilaFicha2);
	FFVazia(&FilaBandeja2);
	FFVazia(&FilaAlimentos);
	FFVazia(&FilaAlimentos2);
	FPVazia(&PilhaBandeja);
	FPVazia(&PilhaBandeja2);
	
	TAluno *pessoas = (TAluno*)(malloc((480)*sizeof(TAluno)));
	
	TCelulaFila Clone;
	TCelulaFila Clone2;
	
	TBandeja Quantidade[MAXBANDEJA];
	TBandeja Quantidade2[MAXBANDEJA];
		
	TCelulaPilha CloneBandeija;
	TCelulaPilha CloneBandeija2;
	
	
	for(a=0; a<MAXBANDEJA; a++){
		Empilha(Quantidade[a], &PilhaBandeja); 
		Empilha(Quantidade2[a], &PilhaBandeja2);
		//printf("\n%d", Quantidade[a]);
	}//Após esse FOR as bandejas estão empilhadas.
	
	
	do{	
	
		if(ContIteracao == 0){
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha);
			CodAluno++;
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha2);
			CodAluno++;
			//printf("\n%d", pessoas[CodAluno]); //print que testa se esta enfileirando na FilaFicha.    
			
			AlunosEmFila+=2;
			//Após esse FOR duas pessoas entram na Fila
			ContIteracao++;
		}
		
		if(ContIteracao == 1){
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha);
			CodAluno++;
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha2);
			CodAluno++;
			//printf("\n%d", pessoas[CodAluno]); //print que testa se esta enfileirando na FilaFicha.    
			
			AlunosEmFila+=2;
			
			Desenfileira(&FilaFicha, &Clone.CopiaAluno);
			Desenfileira(&FilaFicha2, &Clone2.CopiaAluno);
			//printf("\n%d", Clone.CopiaAluno);   //print que testa se esta criando o Clone.
			Enfileira(Clone.CopiaAluno , &FilaBandeja);
			Enfileira(Clone2.CopiaAluno , &FilaBandeja2);
		
			ContIteracao++;
		}
		
		if(ContIteracao == 2){
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha);
			CodAluno++;
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha2);
			CodAluno++;
			//printf("\n%d", pessoas[CodAluno]); //print que testa se esta enfileirando na FilaFicha.    
			
			AlunosEmFila+=2;
			
			Desenfileira(&FilaFicha, &Clone.CopiaAluno);
			Desenfileira(&FilaFicha2, &Clone2.CopiaAluno);
			//printf("\n%d", Clone.CopiaAluno);   //print que testa se esta criando o Clone.
			Enfileira(Clone.CopiaAluno , &FilaBandeja);
			Enfileira(Clone2.CopiaAluno , &FilaBandeja2);
		
			Desenfileira(&FilaBandeja, &Clone.CopiaAluno);
		    Desenfileira(&FilaBandeja2, &Clone2.CopiaAluno);
			
			if(PilhaVazia(PilhaBandeja) && PilhaVazia(PilhaBandeja2)){ // testa se pode desempilhar uma bandeja.
				printf("\nNão há bandejas no momento.");    
			}else{
				Desempilha(&PilhaBandeja, &CloneBandeija.CopiaBandeja);
				Desempilha(&PilhaBandeja2, &CloneBandeija2.CopiaBandeja);
			}
		
			ContIteracao++;
		}
		
		if(ContIteracao == 3 || ContIteracao == 4 || ContIteracao == 5 || ContIteracao == 6){
			
			Enfileira(Clone.CopiaAluno , &FilaAlimentos);
			Enfileira(Clone2.CopiaAluno , &FilaAlimentos2);
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha);
			CodAluno++;
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha2);
			CodAluno++;
			//printf("\n%d", pessoas[CodAluno]); //print que testa se esta enfileirando na FilaFicha.    
			
			AlunosEmFila+=2;
			
			Desenfileira(&FilaFicha, &Clone.CopiaAluno);
			Desenfileira(&FilaFicha2, &Clone2.CopiaAluno);
			//printf("\n%d", Clone.CopiaAluno);   //print que testa se esta criando o Clone.
			Enfileira(Clone.CopiaAluno , &FilaBandeja);
			Enfileira(Clone2.CopiaAluno , &FilaBandeja2);
		
			Desenfileira(&FilaBandeja, &Clone.CopiaAluno);
		    Desenfileira(&FilaBandeja2, &Clone2.CopiaAluno);
			
			if(PilhaVazia(PilhaBandeja) && PilhaVazia(PilhaBandeja2)){ // testa se pode desempilhar uma bandeja.
				printf("\nNão há bandejas no momento.");    
			}else{
				Desempilha(&PilhaBandeja, &CloneBandeija.CopiaBandeja);
				Desempilha(&PilhaBandeja2, &CloneBandeija2.CopiaBandeja);
			}
			
			ContIteracao++;
		}
		
	
		
		if(ContIteracao > 6){
			
			Enfileira(Clone.CopiaAluno , &FilaAlimentos);
			Enfileira(Clone2.CopiaAluno , &FilaAlimentos2);
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha);
			CodAluno++;
			
			pessoas[CodAluno].NumCarteirinha = CodAluno;
			pessoas[CodAluno].TempoAtendimento = ContIteracao;
			Enfileira(pessoas[CodAluno], &FilaFicha2);
			CodAluno++;
			//printf("\n%d", pessoas[CodAluno]); //print que testa se esta enfileirando na FilaFicha.    
			
			AlunosEmFila+=2;
			
			Desenfileira(&FilaFicha, &Clone.CopiaAluno);
			Desenfileira(&FilaFicha2, &Clone2.CopiaAluno);
			//printf("\n%d", Clone.CopiaAluno);   //print que testa se esta criando o Clone.
			Enfileira(Clone.CopiaAluno , &FilaBandeja);
			Enfileira(Clone2.CopiaAluno , &FilaBandeja2);
		
			
			if(ContIteracao%40 == 0 && ContIteracao >= 40){ //testa se chegou a hora de empilhar 10 bandejas
				for(a=0; a<40; a++){
					Empilha(Quantidade[a], &PilhaBandeja);
					Empilha(Quantidade[a], &PilhaBandeja2);
					//printf("\n%d", Quantidade[a]); Testa se empilhou 10 bandejas.
				}
			}//Após esse FOR as bandejas estão empilhadas.
			
			if(PilhaVazia(PilhaBandeja) && PilhaVazia(PilhaBandeja2)){ // testa se pode desempilhar uma bandeja.
				printf("\nNao ha bandejas no momento.");    
			}else{
				Desenfileira(&FilaBandeja, &Clone.CopiaAluno);
				Desenfileira(&FilaBandeja2, &Clone2.CopiaAluno);
				
				Desempilha(&PilhaBandeja, &CloneBandeija.CopiaBandeja);
				Desempilha(&PilhaBandeja2, &CloneBandeija2.CopiaBandeja);
				
				Desenfileira(&FilaAlimentos, &Clone.CopiaAluno);
				Desenfileira(&FilaAlimentos2, &Clone2.CopiaAluno);
				
				Clone.CopiaAluno.TempoAtendimento = ContIteracao - Clone.CopiaAluno.TempoAtendimento;
				Clone2.CopiaAluno.TempoAtendimento = ContIteracao - Clone2.CopiaAluno.TempoAtendimento;
				printf("\n%d", Clone.CopiaAluno.TempoAtendimento);
				printf("\n%d", Clone2.CopiaAluno.TempoAtendimento);
				TempoTotalAtendimento = TempoTotalAtendimento + (Clone.CopiaAluno.TempoAtendimento + Clone2.CopiaAluno.TempoAtendimento);
				AlunosAtendidos+=2;
			}
			
			ContIteracao++;
		} 
		
	}while(ContIteracao < 240);
	
	TempoTotalAtendimento = TempoTotalAtendimento / AlunosAtendidos; //Tempo médio de atendimento dos alunos que foram completamente servidos.
	AlunosEmFila = AlunosEmFila - AlunosAtendidos;
	printf("\nO tempo medio de atendimento dos alunos completamente servidos foi de: %d minutos", TempoTotalAtendimento);
	printf("\nO numero de alunos completamente servidos foi de: %d", AlunosAtendidos);
	printf("\nO numero de alunos remanescentes nas filas foi de: %d", AlunosEmFila);
}
