#include "pilhaEstatica.h"
#include <stdlib.h>

struct pilhaEstatica {
    int max_bandejas;
    int num_bandejas;
    int reposicao_bandejas;
};

PILHA* cria_pilha(int max_bandejas, int reposicao_bandejas){
    PILHA *pe;
    pe = (PILHA *)malloc(sizeof(PILHA));
    if(pe != NULL){
        pe->max_bandejas = max_bandejas;
        pe->num_bandejas = max_bandejas;
        pe->reposicao_bandejas = reposicao_bandejas;
    }
    return pe;
}

void destroi_pilha(PILHA *pe){
    free(pe);
}

int pilha_vazia(PILHA *pe){
    if(pe->num_bandejas > 0){
        return 0;
    }
    return 1;
}

void repoe_pilha(PILHA *pe){
    pe->num_bandejas += pe->reposicao_bandejas;
    if(pe->num_bandejas > pe->max_bandejas){
        pe->num_bandejas = pe->max_bandejas;
    }
}

void retira_bandeja(PILHA *pe){
    pe->num_bandejas--;
}

