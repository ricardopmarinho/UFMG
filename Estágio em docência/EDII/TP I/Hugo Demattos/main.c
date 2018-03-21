#include <stdio.h>
#include <stdlib.h>
#include "DecFuncPilha.h"
#include "DecFuncFila.h"

int main()
{
    //CASO 1 - CASO INICIAL SUGERIDO
    printf("\n\nCaso 1: 1 FilaFicha, 1 Caixa, 1 FilaBand, 1 PilhaBand\n");
    printf("\n");

    TFila FilaFicha;
    FFVazia(&FilaFicha);

    TFila FilaBandeja;
    FFVazia(&FilaBandeja);

    TPilha PilhaBandeja;
    FPVazia(&PilhaBandeja);
    TBandeja Band=1; //variavel auxiliar para recarregar bandejas
    //Consideraremos que inicialmente a pilha ja esta com 30 bandejas
    int j;
    for(j=0;j<30;j++){
        Empilha(Band, &PilhaBandeja);
    }

    int ficha=0; //variavel que guarda o instante de tempo em que a pessoa entrou
    int pegaBand=0; //variavel que guarda o instante de tempo em que a pessoa entrou

    int n=0; //conta quantas pessoas ja se serviram
    int recBand=0; //conta quantos instantes de tempo se passaram desde a ultima recarga de bandejas

    int i; //conta instantes de tempo
    int tmax = 240; //tempo de funcionamento da cantina, 60 minutos vezes 4 horas

    int entraNaFila=1;

    int somaTempos=0; //soma do tempo que todas as pessoas que se serviram gastaram
    int tempoDessaPessoa=0; //tempo que a pessoa que acabou de se servir nesta iteracao gastou

    int aux;

    for(i=1; i<=tmax; i++){
        //pega a bandeja:
        if(pegaBand!=0 && (!VaziaPilha(PilhaBandeja))){
            aux=pegaBand;
            pegaBand=0;
            Desempilha(&Band, &PilhaBandeja);
            n++;
            tempoDessaPessoa=i-aux+4; //o "+4" eh o tempo que a pessoa demora para servir os alimentos
            somaTempos=somaTempos+tempoDessaPessoa;
        }


        //sai da fila de bandeja
        if(pegaBand==0 && (!VaziaFila(FilaBandeja))){
            Desenfileira(&pegaBand, &FilaBandeja);
         }

        //entra na fila da bandeja
        if(ficha!=0){
            if(TamanhoFila(FilaBandeja)<=1){
                ficha++;
            }
            Enfileira(ficha, &FilaBandeja);
            ficha=0;
        }

        //entra no caixa
        if(ficha==0 && (!VaziaFila(FilaFicha))){
            Desenfileira(&ficha, &FilaFicha);
        }

        //entra na fila do caixa - entram duas pessoas por instante de tempo
        entraNaFila=i;
        if(VaziaFila(FilaFicha)){
            Enfileira(entraNaFila+1, &FilaFicha);
            Enfileira(entraNaFila, &FilaFicha);
        }
        else {
            Enfileira(entraNaFila, &FilaFicha);
            Enfileira(entraNaFila, &FilaFicha);
        }

        //recarrega bandejas
        recBand++;
        if(recBand>=12 && TamanhoPilha(PilhaBandeja)<21){
            recBand = 0;
            for(j=0; j<10; j++){
                Empilha(Band, &PilhaBandeja);
            }
        }

    }//fim do for

    int media;
    media = somaTempos/n;
    printf("Numero de pessoas atendidas: %d\n", n);
    printf("Media de tempo: %d minutos por pessoa\n", media);

    //esvaziando as filas e pilhas para liberar memoria
    while(!VaziaFila(FilaFicha)){
        Desenfileira(&aux, &FilaFicha);
    }
    while(!VaziaFila(FilaBandeja)){
        Desenfileira(&aux, &FilaBandeja);
    }
    while(!VaziaPilha(PilhaBandeja)){
        Desempilha(&Band, &PilhaBandeja);
    }


    /*CASO 2 - Uma fila de ficha, dois caixas, uma fila de bandeja, duas pilhas de bandejas com 30
    bandejas cada e duas pessoas servem o mesmo alimento ao mesmo tempo*/
    printf("\n\nCaso 2: 1 FilaFicha, 2 Caixas, 1 FilaBand, 2 PilhasBand\n");
    printf("\n");

    TPilha PilhaBandeja2;
    FPVazia(&PilhaBandeja2);

    for(j=0;j<30;j++){
        Empilha(Band, &PilhaBandeja);
        Empilha(Band, &PilhaBandeja2);
    }

    int ficha2=0; //variavel que guarda o instante de tempo em que a pessoa entrou
    int pegaBand2=0;

    n=0;
    recBand=0;

    entraNaFila=1;

    somaTempos=0; //soma do tempo que todas as pessoas que se serviram gastaram
    tempoDessaPessoa=0;

    for(i=1;i<=tmax;i++){
        //pega a bandeja 1:
        if(pegaBand!=0 && (!VaziaPilha(PilhaBandeja))){
            aux=pegaBand;
            pegaBand=0;
            Desempilha(&Band, &PilhaBandeja);
            n++;

            tempoDessaPessoa=i-aux+4; //o "+4" eh o tempo que a pessoa demora para servir os alimentos
            somaTempos=somaTempos+tempoDessaPessoa;
        }
        //pega a bandeja 2:
        if(pegaBand2!=0 && (!VaziaPilha(PilhaBandeja2))){
            aux=pegaBand2;
            pegaBand2=0;
            Desempilha(&Band, &PilhaBandeja2);
            n++;

            tempoDessaPessoa=i-aux+4; //o "+4" eh o tempo que a pessoa demora para servir os alimentos
            somaTempos=somaTempos+tempoDessaPessoa;
        }
        //sai da fila de bandeja para pegar bandeja 1:
        if(pegaBand==0 && (!VaziaFila(FilaBandeja))){
            Desenfileira(&pegaBand, &FilaBandeja);
         }
         //sai da fila de bandeja para pegar bandeja 2:
        if(pegaBand2==0 && (!VaziaFila(FilaBandeja))){
            Desenfileira(&pegaBand2, &FilaBandeja);
         }
        //entra na fila da bandeja saindo do caixa 1:
        if(ficha!=0){
            if(VaziaFila(FilaBandeja)){
                ficha++;
            }
            Enfileira(ficha, &FilaBandeja);
            ficha=0;
        }
        //entra na fila da bandeja saindo do caixa 2:
        if(ficha2!=0){
            if(VaziaFila(FilaBandeja)){
                ficha2++;
            }
            Enfileira(ficha2, &FilaBandeja);
            ficha=0;
        }
        //entra no caixa 1
        if(ficha==0 && (!VaziaFila(FilaFicha))){
            Desenfileira(&ficha, &FilaFicha);
        }
        //entra no caixa 2
        if(ficha2==0 && (!VaziaFila(FilaFicha))){
            Desenfileira(&ficha2, &FilaFicha);
        }
        //entra na fila do caixa - entram duas pessoas por instante de tempo
        entraNaFila=i;
        if(VaziaFila(FilaFicha)){
            Enfileira(entraNaFila+1, &FilaFicha);
            Enfileira(entraNaFila, &FilaFicha);
        }
        else {
            Enfileira(entraNaFila, &FilaFicha);
            Enfileira(entraNaFila, &FilaFicha);
        }
        //recarrega bandejas - as duas ao mesmo tempo
        recBand++;
        if(recBand>=12 && TamanhoPilha(PilhaBandeja)<21 && TamanhoPilha(PilhaBandeja2)<21){
            recBand = 0;
            for(j=0; j<10; j++){
                Empilha(Band, &PilhaBandeja);
                Empilha(Band, &PilhaBandeja2);
            }
        }

    }//fim do for

    media = somaTempos/n;
    printf("Numero de pessoas atendidas: %d\n", n);
    printf("Media de tempo: %d minutos por pessoa\n", media);

    //esvaziando as filas e pilhas para liberar memoria
    while(!VaziaFila(FilaFicha)){
        Desenfileira(&aux, &FilaFicha);
    }
    while(!VaziaFila(FilaBandeja)){
        Desenfileira(&aux, &FilaBandeja);
    }
    while(!VaziaPilha(PilhaBandeja)){
        Desempilha(&Band, &PilhaBandeja);
    }
    while(!VaziaPilha(PilhaBandeja2)){
        Desempilha(&Band, &PilhaBandeja2);
    }


    /*CASO 3 - Uma fila de ficha, um caixa, uma fila de bandeja, pilhas de bandejas com 20
    bandejas que demora mais a recarregar e uma pessoa serve o alimento de cada vez, porem
    com duas pessoas entrando na fila por iteracao nas primeiras duas horas e um pessoa por
    iteracao nas outras duas horas  */

    printf("\n\nCaso 3: 1 FilaFicha, 1 Caixas, 1 FilaBand, 1 PilhasBand\n");
    printf("\n");


    for(j=0;j<20;j++){
        Empilha(Band, &PilhaBandeja);
    }
    ficha=0;
    pegaBand=0;

    n=0;
    recBand=0;

    entraNaFila=1;

    somaTempos=0; //soma do tempo que todas as pessoas que se serviram gastaram
    tempoDessaPessoa=0;
    aux=0;

    for(i=1; i<=tmax; i++){

        //pega a bandeja:
        if(pegaBand!=0 && (!VaziaPilha(PilhaBandeja))){
            aux=pegaBand;
            pegaBand=0;
            Desempilha(&Band, &PilhaBandeja);
            n++;

            tempoDessaPessoa=i-aux+4; //o "+4" eh o tempo que a pessoa demora para servir os alimentos
            somaTempos=somaTempos+tempoDessaPessoa;
        }


        //sai da fila de bandeja
        if(pegaBand==0 && (!VaziaFila(FilaBandeja))){
            Desenfileira(&pegaBand, &FilaBandeja);
         }

        //entra na fila da bandeja
        if(ficha!=0){
            if(TamanhoFila(FilaBandeja)<=1){
                ficha++;
            }
            Enfileira(ficha, &FilaBandeja);
            ficha=0;
        }

        //entra no caixa
        if(ficha==0 && (!VaziaFila(FilaFicha))){
            Desenfileira(&ficha, &FilaFicha);
        }

        //entra na fila do caixa - entram duas pessoas por instante de tempo
        entraNaFila=i;
        if(i>60 && i<120){
            if(VaziaFila(FilaFicha)){
            Enfileira(entraNaFila+1, &FilaFicha);
            Enfileira(entraNaFila, &FilaFicha);
        }
            else {
            Enfileira(entraNaFila, &FilaFicha);
            Enfileira(entraNaFila, &FilaFicha);
        }
        }
        else{
            if(VaziaFila(FilaFicha)){
            Enfileira(entraNaFila+1, &FilaFicha);
        }
            else {
            Enfileira(entraNaFila, &FilaFicha);
        }
        }

        //recarrega bandejas
        recBand++;
        if(recBand>=12 && TamanhoPilha(PilhaBandeja)<11){
            recBand = 0;
            for(j=0; j<10; j++){
                Empilha(Band, &PilhaBandeja);
            }
        }

    }//fim do for

    media = somaTempos/n;
    printf("Numero de pessoas atendidas: %d\n", n);
    printf("Media de tempo: %d minutos por pessoa\n", media);

    //esvaziando as filas e pilhas para liberar memoria
    while(!VaziaFila(FilaFicha)){
        Desenfileira(&aux, &FilaFicha);
    }
    while(!VaziaFila(FilaBandeja)){
        Desenfileira(&aux, &FilaBandeja);
    }
    while(!VaziaPilha(PilhaBandeja)){
        Desempilha(&Band, &PilhaBandeja);
    }


    return 0;
}
