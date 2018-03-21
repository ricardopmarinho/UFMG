#ifndef TADs_h

#define TADs_h



typedef struct CelulaFila *Apontador;

typedef struct CelulaFila
{
    int TempoQuandoEntrou;
    Apontador Prox;
} TCelulaFila;

typedef struct
{
    Apontador Frente;
    Apontador Tras;
} TFila;


void FFVazia(TFila*);

int FVazia(TFila);

void Enfileira(int, TFila*);

int Desenfileira(TFila*);

void DesalocaFila(TFila*);

typedef struct Celula 	*ApontadorP;

typedef struct Celula
{
    ApontadorP Prox;
} TCelula;

typedef struct
{
    ApontadorP Fundo;
    ApontadorP Topo;
    int Tamanho;
} TPilha;


void FPVazia(TPilha*);

int PVazia(TPilha);

void Empilha(TPilha*);

void Desempilha(TPilha*);

int Tamanho(TPilha);

void DesalocaPilha(TPilha*);


#endif // TADs_h
