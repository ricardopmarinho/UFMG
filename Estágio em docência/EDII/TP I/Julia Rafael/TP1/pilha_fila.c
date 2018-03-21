#include <stdio.h>
#include <stdlib.h>
#include "pilha_fila.h"

//PILHA-------------------------------------
void pilha_FazVazia(t_pilha *pilha){
    pilha->topo = malloc(sizeof(t_celula));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

int pilha_TestaVazia(t_pilha *pilha){
    return (pilha->topo == pilha->fundo);
}

void pilha_empilha(t_item x, t_pilha *pilha){
    t_apontador aux = malloc(sizeof(t_celula));
    pilha->topo->item = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void pilha_desempilha(t_pilha *pilha, t_item *item){
    if (pilha_TestaVazia(pilha)) {
        fprintf(stderr,"Erro lista vazia\n");
        exit(-1);
    }
    t_apontador q = pilha->topo;
    pilha->topo = q->prox;
    *item = q->prox->item;
    free(q);
    pilha->tamanho--;
}

int pilha_tamanho(t_pilha *pilha){
    return pilha->tamanho;
}




//FILA--------------------------------------
void fila_FazVazia(t_fila *fila){
    fila->frente = malloc(sizeof(t_celula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL; 

}

int fila_TestaVazia(t_fila *fila){
    return (fila->frente == fila->tras); 
}

void fila_enfileira(t_item x, t_fila *fila){
    fila->tras->prox = malloc(sizeof(t_celula));
    fila->tras = fila->tras->prox;
    fila->tras->item = x;
    fila->tras->prox = NULL; 
}

void fila_desenfileira(t_fila *fila, t_item *item){
    if (fila_TestaVazia(fila)) {
        fprintf(stderr,"Erro: fila vazia\n");
    exit(-1);
    }
    t_apontador q = fila->frente;
    fila->frente = fila->frente->prox;
    *item = fila->frente->item;
    free(q);
}


