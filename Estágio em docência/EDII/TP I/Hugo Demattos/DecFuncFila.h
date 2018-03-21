#ifndef DECFUNCFILA_H_INCLUDED
#define DECFUNCFILA_H_INCLUDED

//definicao do tipo

typedef struct FCelula *FApontador;

typedef struct FCelula {
    int Pessoa;
    FApontador FProx;
    } FTCelula;

typedef struct {
    FApontador Frente;
    FApontador Tras;
    int FTamanho;
    } TFila;

//cabecalhos das funcoes

void FFVazia(TFila *Fila);
int VaziaFila(TFila Fila);
void Enfileira(int x, TFila *Fila);
void Desenfileira(int *x, TFila *Fila);
int TamanhoFila(TFila Fila);

#endif // DECFUNCFILA_H_INCLUDED
