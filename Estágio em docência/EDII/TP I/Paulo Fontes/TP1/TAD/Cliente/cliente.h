#ifndef cliente
#define cliente

//DEFINICAO DE TIPOS E ESTRUTURA
typedef int TTempo;
typedef int TId;
typedef struct Cliente{
    TId ID;
    TTempo Chegada;
    TTempo Saida;
    TTempo TempoTotal;
}TCliente;

//PROTOTIPOS
void define_atraso(TCliente *Aguarde);
void chega_cliente (TCliente *Cliente, TTempo Chegada, TId ID);
void finaliza_atendimento(TCliente *Alimento, TCliente *Saida, int *TotalTempo, int *TotalClientes, int Cronometro);

#endif // cliente
