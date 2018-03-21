#include <stdio.h>

void quadImpar(int n, int q[10][10])
{
    int i, j, num;
    i = n/2;
    j = n - 1;
    for(num = 1; num <= n*n; )
    {
        //caso os índices saiam da matriz
        if (i == -1 && j == n)
        {
            j = n-2;
            i = 0;
        }
        else
        {
            if(j == n)
            {
                j = 0;
            }
            if(i < 0)
            {
                i = n-1;
            }
        }
        //caso encontre um número na posição
        if(q[i][j] != 0)
        {
            i++;
            j -= 2; 
            continue; //continue para pular o resto da iteração do for
        }
        else //coloca o numero
        {
            q[i][j] = num++;
        }
        j++;
        i--;
    }
}

void quadParDuplo(int n, int q[10][10])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            q[i][j] = (n * i) + j + 1;        
    }
    //muda os valores de acordo com a regra (n * n + 1)- q[i][j]
    //começando pelo canto superior esquerdo com índices menores que n/4
    for (i = 0; i < n/4; i++)
    {
        for (j = 0; j < n/4; j++)
            q[i][j] = (n * n + 1) - q[i][j];
    }

    // canto superior direito
    for (i = 0; i< n/4; i++)
    {
        for (j = 3 * (n/4); j < n; j++)
            q[i][j] = (n * n + 1) - q[i][j];
    }

    // inferior esquerdo
    for (i = 3 * n/4; i < n; i++)
    {
       for (j = 0; j < n/4; j++)
            q[i][j] = (n * n + 1) - q[i][j];
    }    

    // inferior direito
    for (i = 3 * n/4; i < n; i++)
    {
        for (j = 3 * n/4; j < n; j++)
            q[i][j] = (n * n + 1) - q[i][j];
    }

    // centro do quadrado
    for (i = n/4; i < 3 * n/4; i++)
    {
        for (j = n/4; j<3 * n/4; j++)
            q[i][j] = (n * n + 1) - q[i][j];
    } 
}

void quadPar(int N, int q[10][10])
{
    int i, j, num, n;
    if(N == 6)
    {
        n = 3;
        //superior esquerdo
        i = 1;
        j = 2;
        for(num = 1; num <= 9; )
        {
            //caso os índices saiam da matriz
            if (i == -1 && j == n)
            {
                j = n-2;
                i = 0;
            }
            else
            {
                if(j == n)
                {
                    j = 0;
                }
                if(i < 0)
                {
                    i = n-1;
                }
            }
            //caso encontre um número na posição
            if(q[i][j] != 0)
            {
                i++;
                j -= 2; 
                continue; //continue para pular o resto da iteração do for
            }
            else //coloca o numero
            {
                q[i][j] = num++;
            }
            j++;
            i--;
        }
        //superior direito
        i = 1;
        j = 5;
        for(num = 19; num <= 27; )
        {
            //caso os índices saiam da matriz
            if (i == -1 && j == 6)
            {
                j = 4;
                i = 0;
            }
            else
            {
                if(j == 6)
                {
                    j = 3;
                }
                if(i < 0)
                {
                    i = n-1;
                }
            }
            //caso encontre um número na posição
            if(q[i][j] != 0)
            {
                i++;
                j -= 2; 
                continue; //continue para pular o resto da iteração do for
            }
            else //coloca o numero
            {
                q[i][j] = num++;
            }
            j++;
            i--;
        }
        //inferior esquerdo
        i = 3;
        j = 2;
        for(num = 28 ; num <= 36; )
        {
            //caso os índices saiam da matriz
            if (i == 2 && j == n)
            {
                j = 1;
                i = 3;
            }
            else
            {
                if(j == n)
                {
                    j = 0;
                }
                if(i < 3)
                {
                    i = 5;
                }
            }
            //caso encontre um número na posição
            if(q[i][j] != 0)
            {
                i++;
                j -= 2; 
                continue; //continue para pular o resto da iteração do for
            }
            else //coloca o numero
            {
                q[i][j] = num++;
            }
            j++;
            i--;
        }
        //inferior direito
        i = 3;
        j = 5;
        for(num = 10 ; num <= 18; )
        {
            //caso os índices saiam da matriz
            if (i == 2 && j == 6)
            {
                j = 4;
                i = 3;
            }
            else
            {
                if(j == 6)
                {
                    j = 3;
                }
                if(i < 3)
                {
                    i = 5;
                }
            }
            //caso encontre um número na posição
            if(q[i][j] != 0)
            {
                i++;
                j -= 2; 
                continue; //continue para pular o resto da iteração do for
            }
            else //coloca o numero
            {
                q[i][j] = num++;
            }
            j++;
            i--;
        }
    }
}

int main()
{
    int quadrado[10][10];
    int i, j, n, constMagica;
    //incializa o quadrado
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            quadrado[i][j] = 0;
        }
    }
    scanf("%i", &n);
    constMagica = n *(n * n+1)/2;
    if(n % 2 == 1)
    {
        quadImpar(n, quadrado);
    }
    else if(n % 4 == 0)
    {
        quadParDuplo(n, quadrado);
    }
    else
    {
        quadPar(n, quadrado);
    }
    printf("n = %i, Soma = %i\n", n, constMagica);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%i ", quadrado[i][j]);
        }
        printf("\n");
    }
    return 0;
}