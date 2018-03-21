#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"


int main(){
	
	int soma=0;
	float media;
	Apontador aux;
	int TEMPO=1;
	TFila Fcaixa;
	TPilha bandeija;
	TFila Fbandeija;
	TFila Falimento;
	TFila fim;
	TItem caixa;
	TItem band;
	TItem lixo;
	TItem inicio;
	
	inicio.tempo=0;
	inicio.alim=0;
	band.tempo=0;
	band.alim=0;	
	caixa.tempo=0;
	caixa.alim=0;	
	
	FFilaVazia(&Fbandeija);
	FFilaVazia(&Fcaixa);
	FFilaVazia(&Falimento);
	FFilaVazia(&fim);
	FPilhaVazia(&bandeija);	
	
	CriaBandeija (&bandeija);
	EncheBandeija (&bandeija);
	Enfileira(caixa,&Fcaixa);	
	
	while (TEMPO<240){
		PassaTempo (&Fbandeija,&Fcaixa, &Falimento, &caixa, &band);
		ClienteEmbora (&Falimento,&fim);
		AndaAlimento (&Falimento);
		if(TEMPO%12==0)
			EncheBandeija (&bandeija);
		if(band.tempo!=0){
			band.alim++;
			Enfileira(band,&Falimento);
			Desempilha(&bandeija,&lixo);
			band.tempo=0;
			band.alim=0;
		}
		if(bandeija.tamanho==0){
			Enfileira(caixa,&Fbandeija);
			caixa.tempo=0;
			caixa.alim=0;
		}			
		else{
			if(!FVazia(Fbandeija)){
				Enfileira(caixa,&Fbandeija);
				Desenfileira(&Fbandeija,&band);				
			}
			else{
				band=caixa;
				caixa.tempo=-1;
				caixa.alim=-1;					
			}			
		}		
		Enfileira(inicio,&Fcaixa);		
		Enfileira(inicio,&Fcaixa);
		Desenfileira(&Fcaixa,&caixa);
		TEMPO++;		
	}
	
	aux=fim.frente->prox;
	while(aux!=NULL){
		soma+=aux->item.tempo;
		aux=aux->prox;			
	}		
	media=soma/fim.tamanho;	
	printf("\n\n%f\n",media);
	
	liberaP (&bandeija);
	liberaF (&Fbandeija);
	liberaF (&Fcaixa);
	liberaF (&Falimento);
	liberaF (&fim);
	
	return 0;
}
