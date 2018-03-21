#ifndef filas
#define filas
#include "../Cliente/cliente.h"

//DEFINICAO DE TIPOS E ESTRUTURAS
typedef struct Posicao *Apontador;

typedef struct Posicao{ // Estrutura da celula individual da fila
    TCliente Cliente;
    Apontador Proximo;
}TPosicao;

typedef struct Fila{ // Estrutura da fila
    Apontador Frente;
    Apontador Tras;
}TFila;

//PROTOTIPOS
void cria_fila(TFila *Fila);
int fila_vazia(TFila Fila);
void aumenta_fila(TFila *Fila, TCliente Cliente);
void destroi_fila(TFila *Fila);
TCliente atendimento(TFila *Fila, TCliente *Cliente, TCliente Aguarde);
void self_service(TCliente Aguarde, TCliente *Arroz, TCliente *Feijao, TCliente *Guarnicao, TCliente *Salada, TCliente *Saida);
void serve_prato (TCliente *Cliente, TCliente *Alimento, TCliente Aguarde);
void atrasa_fila(TCliente Aguarde, TCliente *Bandejas);

#endif // filas
