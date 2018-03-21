#ifndef TAD_PILHA
#define TAD_PILHA

#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

typedef struct NodePilha * ApontadorPilha;

typedef int Bandeja;

typedef struct NodePilha{
    Bandeja bandeja;
    ApontadorPilha proximo;
} NodePilha;

typedef struct Pilha{
    ApontadorPilha fundo;
    ApontadorPilha topo;
    int tamanho;
} Pilha;

// Cria uma nova pilha
void PilhaNova(Pilha *pilha);
int PilhaVazia(Pilha pilha);

// Adiciona uma nova bandeja
void PilhaAddBandeja(Pilha *pilha, Bandeja x);

// Remove uma bandeja da pilha
void PilhaRemoveBandeja(Pilha *pilha, Bandeja *x);

int PilhaTamanho(Pilha pilha);

#endif // TAD_PILHA
