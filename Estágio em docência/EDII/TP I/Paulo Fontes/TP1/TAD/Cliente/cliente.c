#include "cliente.h"
#include "../Fila/filas.h"
#include "../Pilha/pilha.h"

// Define 'Atraso' como um tipo cliente especial (flag) para o qual nao havera desenfileiramento
void define_atraso(TCliente *Aguarde){
    Aguarde->ID = -1;
    Aguarde->Chegada = -1;
    Aguarde->Saida = -1;
    Aguarde->TempoTotal = -1;
}

// Define parametros de um cliente valido que sera enfileirado e desenfileirado durante a simulacao
void chega_cliente (TCliente *Cliente, TTempo Chegada, TId ID){
    Cliente->ID = 2*Chegada + ID; // O 'ID' de cada cliente que entrar na fila sera crescente e sequencial
    Cliente->Chegada = Chegada; // O valor do cronometro quando o cliente entra na fila eh atribuido a 'Chegada'
    Cliente->Saida = 0; // O valor do cronometro quando o cliente finalizar o atendimento eh atribuido a 'Saida'
    Cliente->TempoTotal = 0; // 'TempoTotal' indicara o tempo necessario para o atendimento do cliente
}
// Define os valores de 'Saida' e 'TempoTotal' do cliente ao fim do atendimento, soma seu 'TempoTotal' ao tempo total de atendimento
// e informa o numero total de clientes atendidos até determinado momento (através da ultima 'ID' atendida)
void finaliza_atendimento(TCliente *Alimento, TCliente *Saida, int *TotalTempo, int *TotalClientes, int Cronometro){
    if(Alimento->ID != -1){
        *Saida = *Alimento;
        Saida->Saida = Cronometro;
        Saida->TempoTotal = Saida->Saida - Saida->Chegada;
        *TotalTempo += Saida->TempoTotal;
        *TotalClientes = Saida->ID;
        }
        else{
        *TotalTempo += 0;
        *TotalClientes += 0;
        }
}
