#ifndef DECFUNCPILHA_H_INCLUDED
#define DECFUNCPILHA_H_INCLUDED

//definicao do tipo
typedef int TBandeja;

typedef struct PCelula *PApontador;

typedef struct PCelula {
    TBandeja Bandeja;
    PApontador PProx;
    } PTCelula;

typedef struct {
    PApontador Fundo;
    PApontador Topo;
    int PTamanho;
    } TPilha;

//cabecalho das funcoes

void FPVazia(TPilha *Pilha);
int VaziaPilha(TPilha Pilha);
void Empilha(TBandeja x, TPilha *Pilha);
void Desempilha(TBandeja *x, TPilha *Pilha);
int TamanhoPilha(TPilha Pilha);

#endif // DECFUNCPILHA_H_INCLUDED
