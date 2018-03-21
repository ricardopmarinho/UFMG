#include <stdlib.h>
#include "filas.h"
#include "../Cliente/cliente.h"

// Cria uma fila vazia
void cria_fila(TFila *Fila){
        Fila->Frente = malloc(sizeof(TPosicao));
        Fila->Tras = Fila->Frente;
        Fila->Tras->Proximo = NULL;
}
// Retorna 1 caso a fila esteja vazia
int fila_vazia(TFila Fila){
     return (Fila.Frente == Fila.Tras);
}
// Enfileira clientes conforme ordem de chegada
void aumenta_fila(TFila *Fila, TCliente Cliente){
    if(Cliente.ID != -1){
    Fila->Tras->Proximo = malloc(sizeof(TPosicao));
    Fila->Tras = Fila->Tras->Proximo;
    Fila->Tras->Cliente = Cliente;
    Fila->Tras->Proximo = NULL;
    }
}
// Libera a memoria alocada para a fila ao final da simulacao
void destroi_fila(TFila *Fila){
    while (!fila_vazia(*Fila)){
    Apontador Fechado = Fila->Frente;
    Fila->Frente = Fila->Frente->Proximo;
    free(Fechado);
    }
    free(Fila->Frente);
}
// Retorna um cliente valido que sai da fila para ser encaminhado para a proxima etapa, caso a fila nao esteja vazia
// ou uma flag para aguardar o proximo ciclo, caso contrario
TCliente atendimento(TFila *Fila, TCliente *Cliente, TCliente Aguarde){
    if(!fila_vazia(*Fila) && Cliente->ID != -1){
    Apontador Aux = Fila->Frente;
    Fila->Frente = Fila->Frente->Proximo;
    *Cliente = Fila->Frente->Cliente;
    free(Aux);
        return *Cliente;
    }
    else
        return Aguarde;
}
// Inicializa as posicoes dos alimentos no estado vazio (flag 'Aguarde')
void self_service(TCliente Aguarde, TCliente *Arroz, TCliente *Feijao, TCliente *Guarnicao, TCliente *Salada, TCliente *Saida){
    *Arroz = Aguarde;
    *Feijao = Aguarde;
    *Guarnicao = Aguarde;
    *Salada = Aguarde;
    *Saida = Aguarde;
}
// Ocupa a posicao do proximo alimento com um cliente valido, caso haja, ou mantem a posicao vazia (com a flag 'Aguarde')
void serve_prato(TCliente *Cliente, TCliente *Alimento, TCliente Aguarde){
    if(Cliente->ID != -1)
       *Alimento = *Cliente;
    else
       *Alimento = Aguarde;
}
// Atribui a flag 'Aguarde' na posicao das bandejas para atrasar o desenfileiramento
void atrasa_fila(TCliente Aguarde, TCliente *Bandejas){
    *Bandejas = Aguarde;
}
