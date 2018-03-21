#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#define ban 30 //NUMERO DE BANDEJAS
#define rep 10 //NUMERO DE BANDEJAS REPOSTAS
#define temp 12 //TEMPO PARA REPOR "rep" BANDEJAS
int main ()
{
    int i=1, k, m, t, p, soma=0, MediaPorCliente;
    //FILAS DE CAIXA E BANDEJA
    TipoFila FilaCaixa, FilaBandeja;
    TItem Cliente;
    FFVazia(&FilaCaixa);
    FFVazia(&FilaBandeja);
//PILHA DE BANDEJA
    TPilha PilhaBandeja;
    TipoItem Bandeja;
    Bandeja.ChavePilha=1;
    FPVazia(&PilhaBandeja);
    //EMPILHANDO TODAS AS BANDEJAS/TALHERES ANTES DE ABRIR O RESTAURANTE
    for(k=1; k<=ban; k++)
        {
            Bandeja.ChavePilha=k;
            Empilha(Bandeja, &PilhaBandeja);
            //  printf("\nBandeja: %d", Bandeja.ChavePilha);
        }
    //printf("\nTamanho pilha Bandeja: %d", Tamanho(PilhaBandeja));
    // CHEGADA DOS DOIS PRIMEIROS CLIENTES
                    Cliente.ChaveFila=0;
                    Enfileira(Cliente, &FilaCaixa);
                    Enfileira(Cliente, &FilaCaixa);

    do
        {
            //DEPOIS DE 4 HORAS NÃO ENTRA CLIENTE NA FILA
            if(i<240)
                {
                    Cliente.ChaveFila=i;
                    Enfileira(Cliente, &FilaCaixa);
                    Enfileira(Cliente, &FilaCaixa);

                }

            if(Vazia(&FilaCaixa)==0)
                {
                    Desenfileira(&FilaCaixa, &Cliente);
                    Enfileira(Cliente, &FilaBandeja);
                }


            if(Vvazia(&PilhaBandeja)==0)
                {
                    Desenfileira(&FilaBandeja, &Cliente);
                    Desempilha(&PilhaBandeja, &Bandeja);
                    //printf("\nCliente numero: %d", Cliente.ChaveFila);
                   //printf("\nBandeja: %d", Bandeja.ChavePilha);
                    MediaPorCliente = (i - Cliente.ChaveFila) +5;
                    soma = soma + MediaPorCliente;
                }

            if(i%temp==0) // REPÕE 10 BANDEJAS A CADA 12 MINUTOS.
                {
                    for(m=1; m<=rep; m++)
                        {
                            Bandeja.ChavePilha=m;
                            Empilha(Bandeja, &PilhaBandeja);
                        }
                }
            //printf("\nTamanho pilha: %d", Tamanho(PilhaBandeja));
            //printf("\nSoma: %d", soma);
            i++;
            t = Vazia(&FilaBandeja);
            p = Vazia(&FilaCaixa);
        }
    while((i<=240)||(t==0)||(p==0));

    //printf("\n Tamanho caixa: %d", TamanhoFila(&FilaCaixa));
   // printf("\n Tamanho bandeja: %d", TamanhoFila(&FilaBandeja));
    printf("\n Media: %d", soma/480);
   // printf("\nBanana: %d ", i-1);
    free(&FilaCaixa);
    free(&FilaBandeja);
    free(&PilhaBandeja);
    return 0;
}

