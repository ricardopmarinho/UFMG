#ifndef _PILHA_H_
#define _PILHA_H_

 // DEFINIÇÃO DO TIPO
typedef int TChave;
typedef struct {
    TChave ChavePilha;
    // outros componentes
} TipoItem;
typedef struct CelulaPilha 	*ApontadorPilha;
typedef struct CelulaPilha {
    TipoItem Item;
    ApontadorPilha Prox;
} TipoCelula;
typedef struct {
    ApontadorPilha Fundo;
    ApontadorPilha Topo;
    int Tamanho;
} TPilha;

// CABEÇALHO DAS FUNÇOES
void FPVazia(TPilha *Pilha);
int Vvazia(TPilha *Pilha);
void Empilha(TipoItem Item, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TipoItem *Item);
int Tamanho(TPilha Pilha);
#endif
