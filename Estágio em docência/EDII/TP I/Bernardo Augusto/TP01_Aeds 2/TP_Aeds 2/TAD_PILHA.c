//PILHAS --------------------------------------------------------------------------------

#include "TAD_PILHA.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


void FPVazia(TPilha *Pilha) {   // Cria uma pilha dinâmica vazia e prepara o primeiro elemento sendo NULL.
    Pilha->Topo = malloc(sizeof(TCelulaPilha));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int PilhaVazia(TPilha Pilha) { // Função que retorna verdadeiro ao comparar o topo com o final de uma pilha e ver se são iguais. (Testa se a pilha esta vazia).
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TBandeja x, TPilha *Pilha) {   // Função que empilha uma bandeja no topo da pilha e prepara o proximo espaço de alocação deixando-o NULL.
    ApontadorPilha Aux = malloc(sizeof(TCelulaPilha));
    Pilha->Topo->CopiaBandeja = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha, TBandeja *CopiaBandeja) {  // Função que primeiramente testa se há algum elemento na pilha. Caso haja algum elemento na pilha,
    if (PilhaVazia(*Pilha)) {                             // remove o elemento mais do topo e o armazena numa variavel auxilar. Após isso desaloca o espaço 
        printf("Erro lista vazia\n");                     // anteriormente ocupado por esse elemento.
        return;
    }
    ApontadorPilha q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *CopiaBandeja = q->Prox->CopiaBandeja;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha) { // Função que retorna o valor da variavel presente no interior do struct TPilha. (Retorna o tamanho da pilha).
    return Pilha.Tamanho;
}
