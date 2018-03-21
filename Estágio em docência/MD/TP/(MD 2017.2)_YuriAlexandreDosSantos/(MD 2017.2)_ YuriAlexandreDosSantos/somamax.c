#include <stdio.h>
#include <stdlib.h>

int main()

{
    int N, i, somaMax=0, indiceMenor=0, indiceMaior=0, indiceMenorAux=0, soma=0;

    // Lê o número N de números que comporão o vetor

    scanf("%d", &N);

    if ((N<3)||(N>20)){printf("Entrada invalida!\n");}

    else {

        // Cria um espaço na memória correspondente a um vetor com N números do tipo int (inteiros).

        int vetor[N];

        // Lê as entradas de cada um dos números que comporão o vetor, guardando-os nas posições que variam de vetor[0] a vetor[N-1].

        for(i=0;i<N;i++){scanf("%d", &vetor[i]);}

        // Calcula a sequência de maior soma possível em números adjacentes do vetor[N], guardando seus respectivos índices (que variam de i = 0 a i = N-1).

        for (i=0; i<N; i++){

            if ((soma + vetor[i]) < 0){


                indiceMenorAux = i+1; soma = 0;

            } else {soma = soma + vetor[i];}

            if (soma > somaMax) { somaMax=soma; indiceMenor=indiceMenorAux; indiceMaior=i;}

        }

        // Imprime na tela o valorda soma máxima e dos índices a ela relacionados.

            printf("Soma: %d\nÍndices: %d a %d\n", somaMax, indiceMenor+1, indiceMaior+1);

    }

    return 0;
}
