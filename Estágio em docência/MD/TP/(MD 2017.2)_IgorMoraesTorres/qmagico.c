#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void gerador_quad_imp(int );
void gerador_quad_o(int );

int main () {
    int n;
    printf("Entre com o valor de n\n");
    scanf("%d", &n);
    if( n % 2 != 0)
        gerador_quad_imp(n);
    else
        if( n % 4 == 0)
        gerador_quad_o(n);
        else
            printf("n do formato 4*n + 2.Nao possivel neste progama\n");

    return 0;
}

void gerador_quad_imp(int N)
{
    int numb;
    int quadrado_magico[N][N];


    memset(quadrado_magico, 0, sizeof(quadrado_magico));


    int i = N/2;
    int j = N-1;


    for ( numb=1; numb <= N*N; )
    {
        if (i==-1 && j==N)
        {
            j = N-2;
            i = 0;
        }
        else
        {
            if (j == N)
                j = 0;

            if (i < 0)
                i=N-1;
        }
        if (quadrado_magico[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            quadrado_magico[i][j] = numb++;

        j++; i--;
    }


    printf("n=%d, Soma = %d\n", N, N*(N*N+1)/2);
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%3d", quadrado_magico[i][j]);
        printf("\n");
    }
}

void gerador_quad_o( int N )
{
    int arr[N][N], i, j;

    for ( i = 0; i < N; i++)
        for ( j = 0; j < N; j++)
            arr[i][j] = (N*i) + j + 1;


    for ( i = 0; i < N/4; i++)
        for ( j = 0; j < N/4; j++)
            arr[i][j] = (N*N + 1) - arr[i][j];


    for ( i = 0; i < N/4; i++)
        for ( j = 3 * (N/4); j < N; j++)
            arr[i][j] = (N*N + 1) - arr[i][j];


    for ( i = 3 * N/4; i < N; i++)
        for ( j = 0; j < N/4; j++)
            arr[i][j] = (N*N+1) - arr[i][j];


    for ( i = 3 * N/4; i < N; i++)
        for ( j = 3 * N/4; j < N; j++)
            arr[i][j] = (N*N + 1) - arr[i][j];


    for ( i = N/4; i < 3 * N/4; i++)
        for ( j = N/4; j < 3 * N/4; j++)
            arr[i][j] = (N*N + 1) - arr[i][j];

    printf("n=%d, Soma = %d\n", N, N*(N*N+1)/2);

    for (i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
            printf("%3d", arr[i][j]);

        printf("\n");
    }
}
