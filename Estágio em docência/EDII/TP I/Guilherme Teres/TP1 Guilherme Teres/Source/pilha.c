#include "pilha.h"


void PilhaNova(Pilha *pilha){
    pilha->topo = malloc(sizeof(NodePilha));
    pilha->fundo = pilha->topo;
    pilha->topo->proximo = NULL;
    pilha->tamanho = 0;
}

int PilhaVazia(Pilha pilha){
    return (pilha.topo == pilha.fundo);
}

void PilhaAddBandeja(Pilha *pilha, Bandeja x){
    ApontadorPilha tmp = malloc(sizeof(NodePilha));
    pilha->topo->bandeja = x;
    tmp->proximo = pilha->topo;
    pilha->topo = tmp;
    pilha->tamanho++;
}

void PilhaRemoveBandeja(Pilha *pilha, Bandeja *x){
    if (PilhaVazia(*pilha)){
        printf("Pilha vazia!");
        return;
    }
    ApontadorPilha tmp = pilha->topo;
    pilha->topo = tmp->proximo;
    *x = tmp->proximo->bandeja;
    free(tmp);
    pilha->tamanho--;
}

int PilhaTamanho(Pilha pilha){
    return pilha.tamanho;
}

