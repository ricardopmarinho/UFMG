#include <stdio.h>
#include <stdlib.h>
#include "TADs.h"

double tempoMedioCantina( int, int, int, int, int, int, int, int, int, int);

void PegarBandejas( int, TFila* [], TPilha* [], TFila*, int*, int);

void ReporBandejas( int, int, int, TPilha* [], int, int);


int main()
{
    int numFilasDeCompraDeFicha;
    int numFilasDeBandejas;
    int numPilhasDeBandejas;
    int reposicaoDeBandejas;
    int tempoDeReposicao;
    int limiteDeBandejasPorPilha;
    int numDeAlimentos;
    int baiasDeAlimentos;
    int clientesEntrandoPorMinuto;
    int tempoDeSimulacao;

    scanf("%d %d %d %d %d %d %d %d %d %d",&numFilasDeCompraDeFicha, &numFilasDeBandejas, &numPilhasDeBandejas, &reposicaoDeBandejas, &tempoDeReposicao,
          &limiteDeBandejasPorPilha, &numDeAlimentos, &baiasDeAlimentos, &clientesEntrandoPorMinuto, &tempoDeSimulacao);

    double teste = tempoMedioCantina( numFilasDeCompraDeFicha, numFilasDeBandejas, numPilhasDeBandejas, reposicaoDeBandejas, tempoDeReposicao,
                                     limiteDeBandejasPorPilha, numDeAlimentos, baiasDeAlimentos, clientesEntrandoPorMinuto, tempoDeSimulacao);
    printf("Tempo medio dos clientes baseados nos parametros dados: %f minutos\n",teste);


    return 0;
}




double tempoMedioCantina(
int numFilasDeCompraDeFicha, //Isso seria o número de filas para a compra de fichas, também associadas a um caixa cada.
int numFilasDeBandejas, //Isso seria o número de filas para pegar as bandejas, o primeiro de cada fila pode pegar uma bandeja, independente do número de pilhas de bandejas.
int numPilhasDeBandejas, //Isso seria o número de pilhas de bandejas, influenciando no total disponível de bandejas
int reposicaoDeBandejas, //A quantidade de bandejas repostas em cada pilha de bandejas.
int tempoDeReposicao, //O tempo necessário para repor as bandejas nas pilhas.
int limiteDeBandejasPorPilha, //O máximo que uma pilha de bandejas pode suportar.
int numDeAlimentos, //Número de alimentos disponíveis que devem ser servidos.
int baiasDeAlimentos, //Número de baias de alimentos que existem, como filas de alimentos.
int clientesEntrandoPorMinuto, //Número de clientes que entram nas filas de ficha por minuto.
int tempoDeSimulacao) //Tempo total de simulação expresso em minutos
{
    int contador, contador2;

    //Array de apontadores para as filas de fichas, afim de permitir um número variável de filas.
    TFila* filasDeCompraDeFicha[numFilasDeCompraDeFicha];
    for (contador = 0; contador < numFilasDeCompraDeFicha; contador++)
    {
        filasDeCompraDeFicha[contador] = malloc(sizeof(TFila));
        FFVazia(filasDeCompraDeFicha[contador]);
    }

    //Array de apontadores para as filas de bandejas, afim de permitir um número variável de filas.
    TFila* filasDeBandejas[numFilasDeBandejas];
    for (contador = 0; contador < numFilasDeBandejas; contador++)
    {
        filasDeBandejas[contador] = malloc(sizeof(TFila));
        FFVazia(filasDeBandejas[contador]);
    }

    //Array de apontadores para as pilhas de bandejas, afim de permitir um número variável de pilhas.
    TPilha* pilhasDeBandejas[numPilhasDeBandejas];
    for (contador = 0; contador < numPilhasDeBandejas; contador++)
    {
        pilhasDeBandejas[contador] = malloc(sizeof(TPilha));
        FPVazia(pilhasDeBandejas[contador]);
        for (contador2 = 0; contador2 < limiteDeBandejasPorPilha; contador2++)
        {
            Empilha(pilhasDeBandejas[contador]);
        }
    }

    //Fila adicional para pessoas logo antes de serem servidas, já com as bandejas em mãos. Percebi durante a implementação que seria necessário para números não compatíveis.
    TFila* filaComBandejas;
    filaComBandejas = malloc(sizeof(TFila));
    FFVazia(filaComBandejas);

    /*Um array de duas dimensões para representar as pessoas na posição de servir os alimentos.
    A primeira dimensão se refere as baias de alimentos, e a segunda, à quantidade de alimentos diferentes.
    Optei por um array por ter um tamanho fixo, dessa forma cada fila representa uma baia e cada coluna um alimento. (Além de ser valores pequenos.)*/
    int alimentos[baiasDeAlimentos][numDeAlimentos];
    for (contador = 0; contador < baiasDeAlimentos; contador++)
        for (contador2 = 0; contador2 < numDeAlimentos; contador2++)
            alimentos[contador][contador2] = 0;

    int tempoTotalDosClientes = 0, clientesServidos = 0, pessoaASerServida = 0;
    int filaDeCompraDeFichaEntrar = 0, filaDeBandejasEntrar = 0, pilhaDeBandejasAtiva = 0;

    int tempoAtual;
    for (tempoAtual = 1; tempoAtual <= tempoDeSimulacao; tempoAtual++)
    {
        //Atualização das filas onde é servido o almoço.
        for (contador = 0; contador < baiasDeAlimentos; contador++)
        {
            //Tratando das pessoas que já pegaram uma bandeja.
            if (!FVazia(*filaComBandejas)) pessoaASerServida = Desenfileira(filaComBandejas);

            //Tratando das pessoas que estão sendo servindas de comida, e aquelas que foram servidas.
            if (alimentos[contador][0]!=0)
            {
                tempoTotalDosClientes += tempoAtual - alimentos[contador][0];
                clientesServidos++;
            }
            for (contador2 = 0; contador2 <numDeAlimentos-1;contador2++)
            {
                alimentos[contador][contador2] = alimentos[contador][contador2 + 1];
            }
            alimentos[contador][numDeAlimentos - 1] = pessoaASerServida;
            pessoaASerServida = 0;
        }

        //Tratando das pessoas que estão a pegar uma bandeja.

        PegarBandejas(numFilasDeBandejas, filasDeBandejas, pilhasDeBandejas, filaComBandejas, &pilhaDeBandejasAtiva, numPilhasDeBandejas);

        //Tratando das pessoas que entram na fila de compra de fichas.
        for(contador = 0; contador < clientesEntrandoPorMinuto; contador++)
        {
            Enfileira(tempoAtual, filasDeCompraDeFicha[filaDeCompraDeFichaEntrar]);
            filaDeCompraDeFichaEntrar = (filaDeCompraDeFichaEntrar + 1) % numFilasDeCompraDeFicha;

        }


        //Tratando das pessoas que estão a ser atendidas nos caixas.
        for (contador = 0; contador < numFilasDeCompraDeFicha; contador++)
        {
            if (FVazia(*filasDeCompraDeFicha[contador]))
                continue;
            Enfileira(Desenfileira(filasDeCompraDeFicha[contador]), filasDeBandejas[filaDeBandejasEntrar]);
            filaDeBandejasEntrar = (filaDeBandejasEntrar + 1) % numFilasDeBandejas;
        }

        //Tratando da reposição de bandejas.
        ReporBandejas(tempoAtual, tempoDeReposicao, numPilhasDeBandejas, pilhasDeBandejas, reposicaoDeBandejas, limiteDeBandejasPorPilha);
    }

    //Desalocação de memória.
    for (contador = 0; contador<numFilasDeCompraDeFicha; contador++)
    {
        DesalocaFila(filasDeCompraDeFicha[contador]);
    }


    for (contador = 0; contador<numFilasDeBandejas; contador++)
    {
        DesalocaFila(filasDeBandejas[contador]);
    }


    for (contador = 0; contador<numPilhasDeBandejas; contador++)
    {
        DesalocaPilha(pilhasDeBandejas[contador]);
    }


    DesalocaFila(filaComBandejas);


    //Cálculo do tempo médio e retorno do resultado.
    return ((double)tempoTotalDosClientes)/((double)clientesServidos);
}

void PegarBandejas(
int numFilasDeBandejas,
TFila* filasDeBandejas[],
TPilha* pilhasDeBandejas[],
TFila* filaComBandejas,
int* pilhaDeBandejasAtiva,
int numPilhasDeBandejas)
{
    int contador;
    for (contador = 0; contador < numFilasDeBandejas; contador++)
    {
        if (!FVazia(*filasDeBandejas[contador])&&!PVazia(*pilhasDeBandejas[*pilhaDeBandejasAtiva]))
        {
            Enfileira(Desenfileira(filasDeBandejas[contador]), filaComBandejas);
            Desempilha(pilhasDeBandejas[*pilhaDeBandejasAtiva]);
            *pilhaDeBandejasAtiva = (*pilhaDeBandejasAtiva + 1) % numPilhasDeBandejas;
        }
    }
}

void ReporBandejas(
int tempoAtual,
int tempoDeReposicao,
int numPilhasDeBandejas,
TPilha* pilhasDeBandejas[],
int reposicaoDeBandejas,
int limiteDeBandejasPorPilha)
{
    int contador, contador2;
    //Tratando da reposição de bandejas.
    if ( (tempoAtual % tempoDeReposicao) == 1)
    {
        for (contador = 0; contador<numPilhasDeBandejas; contador++)
        {
            if (Tamanho(*pilhasDeBandejas[contador]) + reposicaoDeBandejas > limiteDeBandejasPorPilha)
            {
                for(contador2 = Tamanho(*pilhasDeBandejas[contador]); contador2 <limiteDeBandejasPorPilha; contador2++)
                {
                    Empilha(pilhasDeBandejas[contador]);
                }
            }
            else
            {
                for (contador2 = 0; contador2 <reposicaoDeBandejas; contador2++)
                {
                    Empilha(pilhasDeBandejas[contador]);
                }
            }
        }
    }
}
