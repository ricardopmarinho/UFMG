#include<stdlib.h>
#include<stdio.h>
#include"tad.h" 

int caso3(int num){
int filasfichas=1 , filasbandejas=2,  pilhasbandejas=1,  bandeijas=40;
int i,k,l,j=0,temposervir=0,tempo=0,count=0,repor=0,cronometro=0,filaatendidos=0;
	TFila FilaFicha,  FilaBandeja,FilaAtendidos;
	TItemFila qtdFila;
	TPilha PilhaBandeja ;
	TItemPilha qtdPBandeja;
	
	//inicializa filas
	FFVazia(&FilaFicha); 
	FFVazia(&FilaBandeja);
	FFVazia(&FilaAtendidos);
	FPVazia(&PilhaBandeja);
	
	//colocar numeros de bandejas 
	while(j<bandeijas){
		Empilha(qtdPBandeja,&PilhaBandeja);
		j++;
	}

	while(tempo<240){
		i=0;
		while(i<filasfichas){
			Enfileira(qtdFila,&FilaFicha);//Entrou 1 pessoas
			filaatendidos++;
			Enfileira(qtdFila,&FilaFicha);//Entrou 1 pessoas
			filaatendidos++;
			Desenfileira (&FilaFicha,&qtdFila);			
			cronometro++;
			repor++;
			Enfileira(qtdFila,&FilaBandeja);
			Enfileira(qtdFila,&FilaBandeja);
			i++;
		}
		 
			if (!VerificaPVazia(PilhaBandeja)){
				Desenfileira (&FilaBandeja,&qtdFila);
				Desenfileira (&FilaBandeja,&qtdFila);
				Desempilha(&PilhaBandeja,&qtdPBandeja);
				Desempilha(&PilhaBandeja,&qtdPBandeja);
				cronometro++;
				repor++;
				cronometro++;
				repor++;
				
				if (repor==12){
					repor=0;
					if (TamanhoPilha(PilhaBandeja)<20){
						j=0;
						while(j<10){
							l=0;
							while(l<pilhasbandejas){
								Empilha(qtdPBandeja,&PilhaBandeja);
								l++;
								//printf("Entrou");
							}										
							j++;
						}
						cronometro++;// tempo a mais para esperar a repoicao
					}	
				}		
			}
					cronometro=cronometro+4 ;
					count=count+cronometro;
		tempo++;
	}


	printf("Quantidade de pessoas que entraram na fila: %d \n",filaatendidos);
	int usuarios=filaatendidos;
	float  media= (float)(count/usuarios);
	printf("Media de tempo que cada usuario leva para completar seu atendimento: %.2f minutos \n",media);
	
}
