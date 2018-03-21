#ifndef PILHA_H
#define PILHA_H

typedef struct{
	int Topo;
}Tpilha;


void InitPilha(Tpilha *Pilha);
int PilhaVazia(Tpilha Pilha);
void Empilha(Tpilha *Pilha);
void Desempilha(Tpilha *Pilha);
void AcrescentaBandeja(Tpilha *Pilha);

#endif