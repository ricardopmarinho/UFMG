#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    int n=0,i,j,k,soma,maior=-1000,a,b;
    while(n<3 || n>20)
    {
            scanf("%i",&n);
    }
    int vetor[n];
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        //vetor[i] = (rand()%100-rand()%100);
        scanf("%i",&vetor[i]);
        //printf("%i ",vetor[i]);
    }
    for(j=0;j<(n-1);j++)
    {
            for(k=j;k<n;k++)
            {
                //printf("\n%i\n",vetor[k]);
                if(k==j)
                {
                    soma = 0;
                }
                soma = vetor[k]+soma;
                if(soma>maior)
                    {
                        maior = soma;
                        a=j+1;
                        b=k+1;
                    }
            }

    }
    printf("\nSoma:%i\nIndices:%i a %i",maior,a,b);
    return(0);
}
