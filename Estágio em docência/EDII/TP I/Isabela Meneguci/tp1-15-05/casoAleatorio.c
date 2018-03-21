#include<stdlib.h>
#include<stdio.h>
#include"tad.h" 
#include <time.h>

int casoAleatorio(int num){
int filasfichas=1 , filasbandejas=1,  bandeijas=30, pilhasbandejas;
int i,k,l,j=0,tempo=0,count=0,repor=0,cronometro=0,reporRand=0,filaatendidos;
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

	srand(time(NULL));
	pilhasbandejas=rand()%240;
	while(tempo<240){
	
	reporRand=rand()%240;
		i=0;
		while(i<filasfichas){
			Enfileira(qtdFila,&FilaFicha);//Entrou 1 pessoas
			filaatendidos++;
			Enfileira(qtdFila,&FilaFicha);//Entrou 1 pessoas
			filaatendidos++;
			Desenfileira (&FilaFicha,&qtdFila);			
			cronometro++;
			
			Enfileira(qtdFila,&FilaBandeja);
			
			i++;
		}
		 k=0;
		while(k<filasbandejas){
			if (!VerificaPVazia(PilhaBandeja)){
				Desenfileira (&FilaBandeja,&qtdFila);
				Desempilha(&PilhaBandeja,&qtdPBandeja);
				cronometro++;
				
		
				if (repor==reporRand){
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
					//printf("\n%d\n",count);
					
			k++;		
		}
		tempo++;
	}

	printf("Quantidade de pessoas que entraram na fila: %d \n",filaatendidos);
	int usuarios=filaatendidos;
	float  media= (float)(count/usuarios);
	printf("Media de tempo que cada usuario leva para completar seu atendimento: %.2f minutos \n",media);
	

}
