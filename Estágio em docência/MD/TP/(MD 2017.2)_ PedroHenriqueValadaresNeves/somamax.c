#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, N, soma, somaM, iM, jM;
    int vetor[20];
    scanf("%i", &N);
    //printf("N:%i\n", N);
    for(i = 0; i < N; i++)
    {
        scanf("%i ", &vetor[i]);
        //printf("%i ", vetor[i]);
    }
    //printf("\n");
    somaM = -1;
    for(i = 0; i < N; i++)
    {
        for(j = N-1; j >= i; j--)
        {
            soma = 0;
            for(k = i; k <= j; k++)
                soma += vetor[k];
            //printf("soma %i %i: %i", i, j, soma);
            if(soma < 0)
                soma = 0;
            if(soma > somaM)
            {
                iM = i;
                jM = j;
                somaM = soma;
            }
        }
    }
    printf("Soma: %i\n", somaM);
    printf("Indices: %i a %i", iM+1, jM+1);
    return 0;
}