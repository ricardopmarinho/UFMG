//TAD FILA -------------------------------------------

#include "TAD_FILA.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


void FFVazia(TFila *Fila){ // Cria uma fila dinâmica vazia e prepara o primeiro elemento sendo NULL. 
    Fila->Frente = malloc(sizeof(TCelulaFila));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int FilaVazia(TFila Fila){ // Função que retorna verdadeiro ao comparar o final com o inicio de uma fila e ver se são iguais. (Testa se a fila esta vazia).
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TAluno x, TFila *Fila){ // Função que enfileira o aluno na fila e prepara o proximo espaço de alocação deixando-o NULL.
    Fila->Tras->Prox = malloc(sizeof(TCelulaFila));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->CopiaAluno = x;
    Fila->Tras->Prox = NULL;
}

void Desenfileira(TFila *Fila, TAluno *CopiaAluno){ // Função que primeiramente testa se há algum elemento na fila. Caso haja algum elemento na fila,
    if (FilaVazia(*Fila)) {                         // remove o elemento mais "antigo"e o armazena numa variavel auxilar. Após isso desaloca o espaço 
        printf("Erro: fila vazia\n");               // anteriormente ocupado por esse elemento.
        return;
    }
    ApontadorFila q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *CopiaAluno = Fila->Frente->CopiaAluno;
    free(q);
}

