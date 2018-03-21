#include <stdio.h>
#include <stdlib.h>
#include "pilha_fila.h"

#define MAX 30

int main (){
//--------variáveis gerais------------------------------
	int i, clock, repor, usuarios, restantes;
	float tempo;
	
//-------variáveis do TAD------------------------------
	t_fila pegarFicha, pegarBandeja, Atendidos;
	t_pilha usarBandeja;
	t_item itemFila, bandejas, atendidos;
	
//-------cria filas e pilhas----------------------------	
	fila_FazVazia(&pegarFicha);
	fila_FazVazia(&pegarBandeja);
	fila_FazVazia(&Atendidos);
	pilha_FazVazia(&usarBandeja);
	
//======================= CASO INICIAL ======================================

	//zera o clock que irá contar o tempo
	clock = 0;
	//empilha as 30 bandejas iniciais
	for(i=0;i<30;i++)
		pilha_empilha(bandejas, &usarBandeja);
		
	while(clock<240){
		
		//chegam as duas pessoas na fila
		fila_enfileira(itemFila, &pegarFicha);
		fila_enfileira(itemFila, &pegarFicha);
		
		//uma pessoa é atendida
		fila_desenfileira(&pegarFicha, &itemFila);
		itemFila.ficha = 1;
		
		//conta as iterações/tempo
		repor++;	
		clock++;
		
		//a pessoa chega na fila para pegar a bandeja
		fila_enfileira(itemFila, &pegarBandeja);
		
		//testa se a pessoa pode pegar a bandeja
		if(!pilha_TestaVazia(&usarBandeja)){
			fila_desenfileira(&pegarBandeja, &itemFila);
			
			//pegou a bandeja e contou o tempo
			clock++;
			repor++;
			
			//desempilhou uma bandeja
			pilha_desempilha(&usarBandeja, &bandejas);
			itemFila.bandeja = 1;
			 
			 //pegou a comida e contou 4 tempos
			itemFila.comida=1;
			clock = clock+4;
			repor = repor+4;
			
			//pegou a comida e terminou o atendimento
			fila_enfileira(itemFila, &Atendidos);
			
			if(repor == 12){//testa para saber se pode repor as bandejas
				if(pilha_tamanho(&usarBandeja) < 20){	
					for(i=0;i<10;i++)
						pilha_empilha(bandejas, &usarBandeja);
				}
				repor = 0;
			}
			
		}
		
	}
	
	usuarios = 0;
	restantes = 0;
	
	while(!fila_TestaVazia(&Atendidos)){
		fila_desenfileira(&Atendidos, &itemFila);
		usuarios++;
	}
	while(!fila_TestaVazia(&pegarBandeja)){
		fila_desenfileira(&pegarBandeja, &itemFila);
		restantes++;
	}
	while(!fila_TestaVazia(&pegarFicha)){
		fila_desenfileira(&pegarFicha, &itemFila);
		restantes++;
	}
	
	printf("CASO INICIAL:\n");
	
	printf("\nForam atendidas %d pessoas em 4h\n", usuarios);
	printf("Restaram %d pessoas na fila\n", restantes);
	
	//calcula o tempo médio
	tempo =(float) 240/usuarios;
	printf("\nTempo medio por usuario: %.2f minutos\n\n\n", tempo);
	
//========== 2 FILAS ======================================================
	
	while(!pilha_TestaVazia(&usarBandeja)){
		pilha_desempilha(&usarBandeja, &bandejas);
	}

	//zera o clock que irá contar o tempo
	clock = 0;
	//empilha as 30 bandejas iniciais
	for(i=0;i<30;i++){
		pilha_empilha(bandejas, &usarBandeja);
		pilha_empilha(bandejas, &usarBandeja);
	}
	
	while(clock<240){
		
		//chegam as duas pessoas na fila
		fila_enfileira(itemFila, &pegarFicha);
		fila_enfileira(itemFila, &pegarFicha);
		
		//uma pessoa é atendida
		fila_desenfileira(&pegarFicha, &itemFila);
		itemFila.ficha = 1;
		
		//conta as iterações/tempo
		repor++;	
		clock++;
		
		//a pessoa chega na fila para pegar a bandeja
		fila_enfileira(itemFila, &pegarBandeja);
		fila_enfileira(itemFila, &pegarBandeja);
		
		//testa se a pessoa pode pegar a bandeja
		if(!pilha_TestaVazia(&usarBandeja)){
			fila_desenfileira(&pegarBandeja, &itemFila);
			fila_desenfileira(&pegarBandeja, &itemFila);
			
			//pegou a bandeja e contou o tempo
			clock++;
			repor++;
			
			//desempilhou uma bandeja
			pilha_desempilha(&usarBandeja, &bandejas);
			pilha_desempilha(&usarBandeja, &bandejas);
			
			itemFila.bandeja = 1;
			 
			 //pegou a comida e contou 4 tempos
			itemFila.comida=1;
			clock = clock+4;
			repor = repor+4;
			
			//pegou 
			fila_enfileira(itemFila, &Atendidos);
			fila_enfileira(itemFila, &Atendidos);
			
			if(repor == 12){
				if(pilha_tamanho(&usarBandeja) < 20){	
					for(i=0;i<10;i++)
						pilha_empilha(bandejas, &usarBandeja);
				}
				repor = 0;
			}
			
		}
		
	}
	
	usuarios = 0;
	restantes = 0;
	
	while(!fila_TestaVazia(&Atendidos)){
		fila_desenfileira(&Atendidos, &itemFila);
		usuarios++;
	}
	while(!fila_TestaVazia(&pegarBandeja)){
		fila_desenfileira(&pegarBandeja, &itemFila);
		restantes++;
	}
	while(!fila_TestaVazia(&pegarFicha)){
		fila_desenfileira(&pegarFicha, &itemFila);
		restantes++;
	}
	
	printf("DUAS PILHAS DE BANDEJAS:\n");
	
	printf("\nForam atendidas %d pessoas em 4h\n", usuarios);
	printf("Restaram %d pessoas na fila\n", restantes);
	
	//calcula o tempo médio
	tempo =(float) 240/usuarios;
	printf("\nTempo medio por usuario: %.2f minutos\n\n\n", tempo);	
	
	
//=============== 45 BANDEJAS =====================================

	while(!pilha_TestaVazia(&usarBandeja)){
		pilha_desempilha(&usarBandeja, &bandejas);
	}
	//zera o clock que irá contar o tempo
	clock = 0;
	//empilha as 45 bandejas iniciais
	for(i=0;i<45;i++)
		pilha_empilha(bandejas, &usarBandeja);
		
	while(clock<240){
		
		//chegam as duas pessoas na fila
		fila_enfileira(itemFila, &pegarFicha);
		fila_enfileira(itemFila, &pegarFicha);
		
		//uma pessoa é atendida
		fila_desenfileira(&pegarFicha, &itemFila);
		itemFila.ficha = 1;
		
		//conta as iterações/tempo
		repor++;	
		clock++;
		
		//a pessoa chega na fila para pegar a bandeja
		fila_enfileira(itemFila, &pegarBandeja);
		
		//testa se a pessoa pode pegar a bandeja
		if(!pilha_TestaVazia(&usarBandeja)){
			fila_desenfileira(&pegarBandeja, &itemFila);
			
			//pegou a bandeja e contou o tempo
			clock++;
			repor++;
			
			//desempilhou uma bandeja
			pilha_desempilha(&usarBandeja, &bandejas);
			itemFila.bandeja = 1;
			 
			 //pegou a comida e contou 4 tempos
			itemFila.comida=1;
			clock = clock+4;
			repor = repor+4;
			
			//pegou 
			fila_enfileira(itemFila, &Atendidos);
			
			if(repor == 12){
				if(pilha_tamanho(&usarBandeja) < 35){	
					for(i=0;i<10;i++)
						pilha_empilha(bandejas, &usarBandeja);
				}
				repor = 0;
			}
			
		}
		
	}
	
	usuarios = 0;
	restantes = 0;
	
	while(!fila_TestaVazia(&Atendidos)){
		fila_desenfileira(&Atendidos, &itemFila);
		usuarios++;
	}
	while(!fila_TestaVazia(&pegarBandeja)){
		fila_desenfileira(&pegarBandeja, &itemFila);
		restantes++;
	}
	while(!fila_TestaVazia(&pegarFicha)){
		fila_desenfileira(&pegarFicha, &itemFila);
		restantes++;
	}
	
	printf("45 BANDEJAS:\n");
	
	printf("\nForam atendidas %d pessoas em 4h\n", usuarios);
	printf("Restaram %d pessoas na fila\n", restantes);
	
	//calcula o tempo médio
	tempo =(float) 240/usuarios;
	printf("\nTempo medio por usuario: %.2f minutos\n\n\n", tempo);
	

	
//================= TEMPO DE REPOSIÇÃO DAS BANDEJAS VARIANDO ============

	while(!pilha_TestaVazia(&usarBandeja)){
		pilha_desempilha(&usarBandeja, &bandejas);
	}
	
	//zera o clock que irá contar o tempo
	clock = 0;
	//empilha as 30 bandejas iniciais
	for(i=0;i<30;i++)
		pilha_empilha(bandejas, &usarBandeja);
		
	while(clock<240){
		
		//chegam as duas pessoas na fila
		fila_enfileira(itemFila, &pegarFicha);
		fila_enfileira(itemFila, &pegarFicha);
		
		//uma pessoa é atendida
		fila_desenfileira(&pegarFicha, &itemFila);
		itemFila.ficha = 1;
		
		//conta as iterações/tempo
		repor++;	
		clock++;
		
		//a pessoa chega na fila para pegar a bandeja
		fila_enfileira(itemFila, &pegarBandeja);
		
		//testa se a pessoa pode pegar a bandeja
		if(!pilha_TestaVazia(&usarBandeja)){
			fila_desenfileira(&pegarBandeja, &itemFila);
			
			//pegou a bandeja e contou o tempo
			clock++;
			repor++;
			
			//desempilhou uma bandeja
			pilha_desempilha(&usarBandeja, &bandejas);
			itemFila.bandeja = 1;
			 
			 //pegou a comida e contou 4 tempos
			itemFila.comida=1;
			clock = clock+4;
			repor = repor+4;
			
			if(repor == 6){
				for(i=0;i<10;i++)
					pilha_empilha(bandejas, &usarBandeja);
				
				repor = 0;
			
			//pegou 
			fila_enfileira(itemFila, &Atendidos);
		
			}
			
		}
		
	}
	
	usuarios = 0;
	restantes = 0;
	
	while(!fila_TestaVazia(&Atendidos)){
		fila_desenfileira(&Atendidos, &itemFila);
		usuarios++;
	}
	while(!fila_TestaVazia(&pegarBandeja)){
		fila_desenfileira(&pegarBandeja, &itemFila);
		restantes++;
	}
	while(!fila_TestaVazia(&pegarFicha)){
		fila_desenfileira(&pegarFicha, &itemFila);
		restantes++;
	}
	
	printf("REPONDO A CADA 6 MINUTOS, SEM LIMITE DE BANDEJAS:\n");
	
	printf("\nForam atendidas %d pessoas em 4h\n", usuarios);
	printf("Restaram %d pessoas na fila\n", restantes);
	
	//calcula o tempo médio
	tempo =(float) 240/usuarios;
	printf("\nTempo medio por usuario: %.2f minutos\n\n\n", tempo);
	
//libera a memoria---------------------------------------------------------------------------
	while(!pilha_TestaVazia(&usarBandeja)){
		pilha_desempilha(&usarBandeja, &bandejas);
	}
	
	free(usarBandeja.topo);
	free(pegarBandeja.frente);
	free(pegarFicha.frente);
	free(Atendidos.frente);

}
	

