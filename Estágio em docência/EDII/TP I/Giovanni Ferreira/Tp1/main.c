#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

#define MAX_BANDEJAS 30
//4 horas em segundos
#define MAX_HORAS 240
//Intervalo para repor bandeijas
#define REPOR_BANDEJAS 12
//Tempo para controle
int tempo = 0;


void chegam_clientes(int * Id_Cliente, Fila * fila_de_fichas)//Adiciona 2 clientes à fila
{
    for (int clientes = 0; clientes < 2; clientes += 1)
    {

        *Id_Cliente += 1;
        adicionar(*Id_Cliente, true, fila_de_fichas);
    }
}

void transfere_cliente(Fila * fila_1, Fila * fila_2 )//Muda de uma fila para outra e nao permite que o cliente ande ate a proxima iteracao
{
    int id_cliente = retirar_da_fila(fila_1);
    adicionar(id_cliente, false, fila_2);
}

void pega_bandeja(Fila * fila_de_bandejas, Fila * fila_de_alimentos, Pilha * pilha_de_bandejas)
{
    if(fila_de_bandejas->inicio->status == true) //Se o cliente ainda nao se mexeu na iteração
    {
        printf("O cliente pode pegar bandejas!\n");
        if (pilha_de_bandejas->tamanho > 0)
        {
            int id_cliente = retirar_da_fila(fila_de_bandejas);
            transfere_cliente(fila_de_bandejas, fila_de_alimentos);
            printf("O cliente %d entrou para a fila de alimentos\n", id_cliente);
            pop(pilha_de_bandejas); // retira uma bandeja da pilha
        }
    }
}


void repoe_bandejas(int quantidade, Pilha * pilha_de_bandejas)
{
    for (int i = 1; i <= quantidade && pilha_de_bandejas->tamanho < MAX_BANDEJAS; i += 1) //A pilha só pode ser reposta ate 30 idependente da quantidade passada
    {
        push(pilha_de_bandejas);
    }
    if (pilha_de_bandejas->tamanho > MAX_BANDEJAS) exit(0);
}


int main() {
    //Inicio das filas e pilhas a serem utilizadas
    Fila * fila_de_fichas = fila_vazia();
    Fila * fila_de_bandejas = fila_vazia();
    Fila * fila_de_alimentos = fila_vazia();
    Pilha * pilha_de_bandejas = pilha_vazia();

    //Contador de Clientes que serve como sua ID
    int Id_Cliente = 0;

    //Bandejas sao repostas antes do inicio do programa
    repoe_bandejas(30, pilha_de_bandejas);
    
    //Caso base
    chegam_clientes(&Id_Cliente, fila_de_fichas); //Chegam 2 Clientes
    printf("\nFila de fichas Inicial: ");
    mostrar_fila(fila_de_fichas);
    printf("\nQuantidade de bandejas: %d ", pilha_de_bandejas->tamanho);
    while (tempo < MAX_HORAS)
    {
        tempo += 1;
        reiniciar_atividade(fila_de_fichas);
        reiniciar_atividade(fila_de_bandejas);
        reiniciar_atividade(fila_de_alimentos);

        chegam_clientes(&Id_Cliente, fila_de_fichas);
        printf("\nTempo %d\n", tempo);

        transfere_cliente(fila_de_fichas, fila_de_bandejas);
        
        printf("\nFila de fichas: ");
        mostrar_fila(fila_de_fichas);

        printf("\nFila de bandejas: ");
        mostrar_fila(fila_de_bandejas);

        pega_bandeja(fila_de_bandejas, fila_de_alimentos, pilha_de_bandejas);
        printf("\nQuantidade de bandejas: %d ", pilha_de_bandejas->tamanho);
        
        //Condicional para repor a pilha de bandejas 
        if (tempo % REPOR_BANDEJAS == 0)
        {
            repoe_bandejas(10, pilha_de_bandejas);
            printf("As bandejas foram repostas!\n");
            printf("\nQuantidade de bandejas: %d\n", pilha_de_bandejas->tamanho);
        }
    }

    printf("Foram servidos %d Clientes no intervalo \n", Id_Cliente/2 - 5);

    destruir_fila(fila_de_fichas);
    destruir_fila(fila_de_bandejas);
    destruir_fila(fila_de_alimentos);
    destruir_pilha(pilha_de_bandejas);

    return 0;
}