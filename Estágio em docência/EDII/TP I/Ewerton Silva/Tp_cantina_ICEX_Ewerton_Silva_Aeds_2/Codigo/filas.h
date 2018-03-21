#include <stdio.h>
#include <stdlib.h>

typedef int TCh;

typedef struct TIt {
    TCh tempo_entrada;
} USUARIO;

typedef struct Cel  *Apont;

typedef struct Cel {
    USUARIO Itemm;
    Apont Prox;
} TCel;

typedef struct {
    Apont Frente;
    Apont Tras;
} TFila;


void Desenfileira(TFila *Fila, USUARIO *Itemm);
void Enfileira(USUARIO x, TFila *Fila);
void Enfileira_caixa(USUARIO x, TFila *Fila);
int FVazia(TFila Fila);
void FFVazia(TFila *Fila);
USUARIO insere_val_users(USUARIO comida, int x);
int retorna_entrada(USUARIO comida);
int destroi_fila (TFila *Fila);
