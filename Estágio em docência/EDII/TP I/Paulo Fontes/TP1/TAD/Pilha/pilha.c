#include <stdlib.h>
#include "pilha.h"
#include "../Cliente/cliente.h"

// Cria uma pilha cheia por arranjo
void cria_pilha_cheia(TPilha *Pilha){
    Pilha->Topo = MAX;
}
// Retorna 1 se a pilha estiver vazia ou 0, caso contrario
int pilha_vazia(TPilha Pilha){
    return (Pilha.Topo == 0);
}
// Atribui a uma variavel do programa a quantidade de bandejas utilizadas
void bandejas_utilizadas(TBandeja *Bandejas){
    Bandejas->Quantidade = 0;
}
// Retorna um cliente valido que sai da fila para ser encaminhado para a proxima etapa, caso a fila e pilha nao estejam vazias
// ou uma flag para aguardar o proximo ciclo, caso contrario
TCliente pilha_bandejas(TFila *Fila, TCliente *Cliente, TCliente Aguarde, TPilha *Pilha, TBandeja *Bandejas){
    if(!fila_vazia(*Fila) && !pilha_vazia(*Pilha)){
    Apontador Aux = Fila->Frente;
    Fila->Frente = Fila->Frente->Proximo;
    *Cliente = Fila->Frente->Cliente;
    Bandejas->Quantidade += 1;
    Pilha->Topo--;
    free(Aux);
    return *Cliente;
    }
    else
        return Aguarde;
}
// Empilha um numero pre determinado de bandejas na pilha (menor ou igual ao maximo definido)
void retorna_bandejas(TPilha *Pilha, int Novas){
    if (Pilha->Topo >= (MAX - Novas))
        Pilha->Topo = MAX;
    else {
         Pilha->Topo += Novas;
    }
}


