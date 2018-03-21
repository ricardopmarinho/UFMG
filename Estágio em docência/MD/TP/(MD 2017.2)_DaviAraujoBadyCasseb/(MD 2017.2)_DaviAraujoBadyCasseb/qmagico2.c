#include <stdio.h>

void qmagico(int, int [][10]);

int main( )
{
    int tamanho;
    int a[10][10];

    printf("Digite o tamanho do quadrado: ");
    scanf("%d", &tamanho);

    if (tamanho % 2 == 0)
    {
        printf("O quadrado magico funciona apenas com numeros impares!\n");
    }
    else
    {
        qddmagico(tamanho, a);
    }
    return 0;
}

void qmagico(int tamanho, int a[][10])
{
    int sqr = tamanho * tamanho;
    int i = 0, j = tamanho / 2, k;

    for (k = 1; k <= sqr; ++k)
    {

        a[i][j] = k;
        i--;
        j++;

        if (k % tamanho == 0)
        {
            i += 2;
            --j;
        }
        else
        {
            if (j == tamanho)
            {
                j -= tamanho;
            }
            else if (i < 0)
            {
                i += tamanho;
            }
        }
    }

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
