#ifndef pilha
#define pilha
#include "../Cliente/cliente.h"
#include "../Fila/filas.h"
#define MAX 30

//DEFINICAO DE TIPOS E ESTRUTURAS
typedef int Ponteiro;
typedef int TUtilizadas;

typedef struct Bandejao{
    TUtilizadas Quantidade;
}TBandeja;

typedef struct Pilha{
    TBandeja Bandeja[MAX];
    Ponteiro Topo;
}TPilha;

//PROTOTIPOS
void cria_pilha_cheia(TPilha *Pilha);
int pilha_vazia(TPilha Pilha);
void bandejas_utilizadas(TBandeja *Bandejas);
TCliente pilha_bandejas(TFila *Fila, TCliente *Cliente, TCliente Aguarde, TPilha *Pilha, TBandeja *Bandejas);
void retorna_bandejas(TPilha *Pilha, int Novas);

#endif // pilha
