#include <stdio.h>
#include <stdlib.h>
#include "TAD/Cliente/cliente.h"
#include "TAD/Fila/filas.h"
#include "TAD/Pilha/pilha.h"
#define HORA 60
#define PERIODO 240
#define TEMP_REP 12
#define NOVAS_BAND 10

//PROTOTIPO DO PROCEDIMENTO DE IMPRESSAO
void imprime_resultado(int TotalClientes, int TotalTempo, TBandeja Utilizadas, int Cronometro);

int main(int argc, char *argv[]){

    int Cronometro = 0;
    int TotalTempo = 0;
    int TotalClientes = 0;
    TCliente ClienteFila1, ClienteFila2, ClienteFila3;
    TCliente Arroz, Feijao, Guarnicao, Salada;
    TCliente Caixa, Bandejas, Aguarde, Saida;
    TBandeja Utilizadas;
    TFila Fila1, Fila2, Fila3;
    TPilha Pilha1;

// INICIALIZAÇÃO DE PILHA CHEIA E FILAS VAZIAS
    cria_fila(&Fila1);
    cria_fila(&Fila2);
    cria_fila(&Fila3);
    cria_pilha_cheia(&Pilha1);

// ATRIBUICAO DE VALORES (FLAGS) PARA CONDICIONAR O DESENFILEIRAMENTO
    bandejas_utilizadas(&Utilizadas);
    define_atraso(&Aguarde);
    atrasa_fila(Aguarde, &Bandejas);
    self_service(Aguarde, &Arroz, &Feijao, &Guarnicao, &Salada, &Saida);

// SIMULAÇÃO DA PASSAGEM DE TEMPO
        for(Cronometro=0; Cronometro<PERIODO; Cronometro++){

        //PRIMEIRO MOMENTO DA TRAJETORIA DO CLIENTE: ENTRA NA FILA DO CAIXA E COMPRA UMA FICHA
                if (Cronometro == 0){
                        chega_cliente(&ClienteFila1, Cronometro, 1); // Chega o primeiro cliente na Cantina
                        aumenta_fila(&Fila1, ClienteFila1); // O primeiro cliente inicia a fila do Caixa
                        chega_cliente(&ClienteFila1, Cronometro, 2); // Chega o segundo cliente na Cantina
                        aumenta_fila(&Fila1, ClienteFila1); // O segundo cliente vai para a segunda posicao na fila do Caixa
                        Caixa = atendimento(&Fila1, &ClienteFila1, Aguarde); // O primeiro cliente da fila do Caixa vai para o Caixa
                }
                else{
                        if(Cronometro%TEMP_REP == 0) // Retorna 10 bandejas a cada 12 minutos
                            retorna_bandejas(&Pilha1, NOVAS_BAND);

                // TERCEIRO MOMENTO DA TRAJETORIA DO CLIENTE: COM A BANDEJA EM MAOS, SE SERVE E SAI
                        aumenta_fila(&Fila3, Bandejas); // Cliente que já tenha pegado bandeja vai para a fila de alimentos
                        finaliza_atendimento(&Salada, &Saida, &TotalTempo, &TotalClientes, Cronometro); // Apos servir-se de salada, o cliente completa o atendimento
                        serve_prato(&Guarnicao, &Salada, Aguarde); // Apos servir-se de Guarnição, o cliente se serve de Salada
                        serve_prato(&Feijao, &Guarnicao, Aguarde); // Apos servir-se de Feijao, o cliente se serve de Guarnicao
                        serve_prato(&Arroz, &Feijao, Aguarde); //Apos servir-se de Arroz, o cliente se serve de feijao
                        Arroz = atendimento(&Fila3, &ClienteFila3, Aguarde); // O primeiro cliente da fila de alimentos se serve de Arroz

                // SEGUNDO MOMENTO DA TRAJETORIA DO CLIENTE: COM A FICHA EM MAOS, SEGUE PARA A SEGUNDA FILA E PEGA UMA BANDEJA.
                        aumenta_fila(&Fila2, Caixa); // Apos comprar a ficha no caixa, o cliente vai para o final da fila de Bandejas
                        chega_cliente(&ClienteFila1, Cronometro, 1); // Chega um novo cliente na Cantina
                        aumenta_fila(&Fila1, ClienteFila1); // O Cliente entra na ultima posicao da fila do Caixa
                        chega_cliente(&ClienteFila1, Cronometro, 2); // Chega um novo cliente na Cantina
                        aumenta_fila(&Fila1, ClienteFila1); // O cliente entra na ultima posicao da fila do Caixa
                        Caixa = atendimento(&Fila1, &ClienteFila1, Aguarde); // O primeiro Cliente da fila do caixa vai para o caixa
                        Bandejas = pilha_bandejas(&Fila2, &ClienteFila2, Aguarde, &Pilha1, &Utilizadas); // O primeiro cliente da fila de bandejas pega uma Bandeja
                }
        }
    imprime_resultado(TotalClientes, TotalTempo, Utilizadas, Cronometro);
    destroi_fila(&Fila1);
    destroi_fila(&Fila2);
    destroi_fila(&Fila3);
return 777976;
}

//PROCEDIMENTO DE IMPRESSAO
void imprime_resultado(int TotalClientes, int TotalTempo, TBandeja Utilizadas, int Cronometro){
        int Media;
        if (TotalClientes !=0)
            Media = TotalTempo/ TotalClientes;
        else
            Media = 0;
        int MediaHoras = Media/HORA;
        int MediaMinutos = Media%HORA;
        int HorasTotais = Cronometro/HORA;
        int MinutosTotais = Cronometro%HORA;
        int TotalTempoHoras = TotalTempo/HORA;
        int TotalTempoMinutos = TotalTempo%HORA;
        printf("\nPARAMETROS:\n Numero de filas: 3 [Caixa: 1 | Bandejas: 1 | Self Service: 1]\n Novos usuarios por minuto: 2\n Pilhas de bandejas: 1\n Bandejas por pilha: %d\n Tempo para reposicao de bandejas: %d Minutos\n Bandejas adicionadas por reposicao: %d\n Numero de mesas de servico: 1\n Tipos de alimentos: 4\n", MAX, TEMP_REP, NOVAS_BAND);
        printf(" Unidades de tempo consumidas no atendimento: 6 [Caixa: 1 | Bandejas: 1 | Arroz: 1 | Feijao: 1 | Guarnicao: 1 | Salada: 1]\n");
        printf("\nRESULTADOS:\n Periodo considerado: %d Minutos (%d Horas e %d Minutos)\n Numero de clientes atendidos: %d\n Quantidade de bandejas utilizadas: %d\n Soma dos tempos de atendimento: %d Minutos (%d Horas e %d Minutos)\n Tempo medio de atendimento: %d Minutos (%d Horas e %d Minutos)\n", Cronometro, HorasTotais, MinutosTotais, TotalClientes, Utilizadas.Quantidade, TotalTempo, TotalTempoHoras, TotalTempoMinutos, Media, MediaHoras, MediaMinutos);
}
