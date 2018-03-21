//TAD FILA -------------------------------------------


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


typedef struct TAluno {   //Estrutura que define as caracteristicas dos Alunos.
    int NumCarteirinha;
	int TempoAtendimento;
} TAluno;

typedef struct TCelulaFila *ApontadorFila;

typedef struct TCelulaFila {  //Estrutura que define as caracteristicas da Celula (Variavel que auxiliará no momento de desefileirar).
    TAluno CopiaAluno;
    ApontadorFila Prox;
} TCelulaFila;

typedef struct {  //Estrutura que define as caracteristicas das Filas. (indica o inicio e o fim da fila)
    ApontadorFila Frente;
    ApontadorFila Tras;
} TFila;

// Abaixo são feitas as declarações das funções a serem utilizadas.
void FFVazia(TFila *Fila);
int FilaVazia(TFila Fila);
void Enfileira(TAluno x, TFila *Fila);
void Desenfileira(TFila *Fila, TAluno *CopiaAluno);

