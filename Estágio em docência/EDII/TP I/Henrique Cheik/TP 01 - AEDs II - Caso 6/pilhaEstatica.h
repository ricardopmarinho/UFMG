#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

typedef struct pilhaEstatica PILHA;

PILHA* cria_pilha(int max_bandejas, int reposicao_bandejas);

void destroi_pilha(PILHA *pe);

int pilha_vazia(PILHA *pe);

void repoe_pilha(PILHA *pe);

void retira_bandeja(PILHA *pe);

#endif // PILHAESTATICA_H
