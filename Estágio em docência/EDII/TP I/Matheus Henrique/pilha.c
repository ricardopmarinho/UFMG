#include <stdlib.h>
#include "pilha.h"

void InitPilha(Tpilha *Pilha){
	Pilha->Topo = 30;
}

int PilhaVazia(Tpilha Pilha){
	return (Pilha.Topo == 0);
}

void Empilha(Tpilha *Pilha){
	Pilha->Topo++;
}

void Desempilha(Tpilha *Pilha){
	Pilha->Topo--;
}

void AcrescentaBandeja(Tpilha *Pilha){
	int i;
	for(i = 1; i <= 10; i++){
		if(Pilha->Topo == 30){
			break;
		}
		Pilha->Topo++;
	}	
}