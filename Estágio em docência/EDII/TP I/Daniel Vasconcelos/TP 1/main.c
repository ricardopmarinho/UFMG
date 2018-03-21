#include <stdio.h>
#include <stdlib.h>
#include "tadpilha.h"
#include "tadfila.h"

#define MAXBAND 30 //numero máximo de bandejas
#define MAXCLI 500 //numero máximo de clientes

void CresceFila (TFila *Fila, TFila *Fila2, TPilha *Pilha);
void Caixa (TFila *PrFila, TFila *SgFila, int *temp);
void ReporBandeja (TPilha *Pilha);
void PegarBandeja (TFila *Fila, TPilha *Pilha, int *temp, TipItem *b, TItem *a);
void Servir (TItem *a, int *temp);

void main (){
	TFila Ficha, Espera;
	TPilha Bandeja;
	FFVazia (&Ficha);
	FFVazia (&Espera);
	FPVazia (&Bandeja);
	CresceFila (&Ficha, &Espera, &Bandeja);
}

void CresceFila (TFila *Fila, TFila *Fila2, TPilha *Pilha){
	TItem x, y, z;
	TipItem b;
	int n = 0, i=0;
	int tempC=0 , tempB = 0, tempS = 0, tempI = 0,tempT = 0;
	float tempM = 0;
	for (i=0; i<3; i++){ //enche a pilha com 30 bandeijas
		ReporBandeja (Pilha);
	}
	while (n < MAXCLI){ //enquanto ainda tiver clientes para chegar
		//coloca duas pessoas na fila para fichas
		x.Chave = n + 1;
		y.Chave = n+2;
		x.Tempo = 0, y.Tempo = 0;
		x.Bandeja = 0, y.Bandeja = 0;
		Enfilera (x, Fila);
		if(n+1 <= MAXCLI) {
			Enfilera (y, Fila);
		}
		tempI ++;
		//atende uma pessoa no caixa
		Caixa (Fila, Fila2, &tempC);
		if (!(tempI%12)){ //conta 12 espaços de tempo desde o início
			ReporBandeja (Pilha);
		}
		//pessoas da segunda fila pegam a bandeija
		PegarBandeja (Fila2, Pilha, &tempB, &b, &z);		
		if (z.Bandeja){ //soma dos tempos finais
			Servir (&z, &tempS);
			if (!(tempS%4)) tempT = tempT + z.Tempo; 
		}
		if (tempI >=240) break;//o processo começou a um tempo maior ou igual a 4 horas
		n = n+2;
	}
	
	while ((!Vazia(*Fila2)) || (!Vazia(*Fila))){//enquanto todo mundo ainda não serviu
		
		if (tempI>=240) break; //o processo começou a um tempo maior ou igual a 4 horas
		tempI ++;

		if (!Vazia(*Fila)){
			Caixa (Fila, Fila2, &tempC);	
			if (!(tempI%12)){ //conta 12 espaços de tempo desde o início
				ReporBandeja (Pilha);
			}
		}
		else{//depois que esvaziou a primeira fila mas ainda falta a segunda
			tempC = tempC + 1;
			if (!(tempC%12)){ //conta 12 espaços de tempo desde o início
				ReporBandeja (Pilha);
			}
		}
		PegarBandeja (Fila2, Pilha, &tempB, &b, &z);		
		if (z.Bandeja){ //soma dos tempos finais
			Servir (&z, &tempS);
			if (!(tempS%4)) tempT = tempT + z.Tempo; 
		}	
		
	}
	tempM = (tempT*1.0)/z.Chave;
	printf("media: %f\n", tempM);
}

void Caixa (TFila *PrFila, TFila *SgFila, int *temp){
	TItem a;
	Desenfilera (PrFila, &a);//sai da fila da ficha
	if (!(a.Chave%2)){
		*temp = *temp + 1; //tempo de espera
	}
	a.Tempo = *temp;
	Enfilera (a, SgFila); //entra na fila da bandeija
}

void ReporBandeja (TPilha *Pilha){
	TipItem x; //item qualquer só para empilhar
	x.Chave = 1;
	int i, aux;
	aux = Tamanho (*Pilha);
	if ((aux - MAXBAND) >= 10){
		for (i = 0; i<10; i++){
			Empilha (x, Pilha);
		}
	}
	else if ((aux - MAXBAND) < 10){
		for (i = MAXBAND; i> aux; i--){
			Empilha (x, Pilha);
		}
	}
}

void PegarBandeja (TFila *Fila, TPilha *Pilha, int *temp, TipItem *b, TItem *a){
	*temp = *temp + 1;
	
	if (!PVazia(*Pilha)){
		Desenfilera (Fila, a);
		a->Tempo = a->Tempo + *temp;
		a->Bandeja = 1;
		Desempilha (Pilha, b);
	} 
}

void Servir (TItem *a, int *temp){
	*temp = *temp +1;//conta o tempo de servir um ingrediente
	if (!(*temp%4)){//se acabou de servir
		a->Tempo = a->Tempo + 4;
	}
}