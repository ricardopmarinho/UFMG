//PILHAS --------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


typedef struct TBandeja{ //Estrutura que define as caracteristicas das bandejas.
    int Chave;
} TBandeja;

typedef struct TCelulaPilha 	*ApontadorPilha;

typedef struct TCelulaPilha {  //Estrutura que define as caracteristicas da Celula (Variavel que auxiliará no momento de desempilhar).
    TBandeja CopiaBandeja;
    ApontadorPilha Prox;
} TCelulaPilha;

typedef struct { //Estrutura que define as caracteristicas das Pilhas. (Armazena o tamanho e indica o inicio e o fim da pilha)
    ApontadorPilha Fundo;
    ApontadorPilha Topo;
    int Tamanho;
} TPilha;

// Abaixo são feitas as declarações das funções a serem utilizadas.
void FPVazia(TPilha *Pilha);
int PilhaVazia(TPilha Pilha);
void Empilha(TBandeja x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TBandeja *CopiaBandeja);
int Tamanho(TPilha Pilha);
