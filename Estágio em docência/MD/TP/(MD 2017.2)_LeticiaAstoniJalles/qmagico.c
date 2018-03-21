#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
    int n, soma;

    printf("Insira o valor de n (Numero de lados do quadrado, sendo que n deve ser maior ou igual a 3 e menor ou igual a 10). \n");
    scanf("%d", &n);

    if (n==3)
    {
        printf ("n = 3, Soma = 15 \n"); //achar quadrado mágico
        printf (" 02 07 06 \n 09 05 01 \n 04 03 08");
    }

    if (n==4)
    {
        printf ("n = 4, Soma = 34 \n");
        printf (" 16 02 03 13 \n 05 11 10 08 \n 09 07 06 12 \n 04 14 15 01 \n");
    }

    if (n==5)
    {
        printf ("n = 5, Soma = 65 \n");
        printf (" 17 24 01 08 15 \n 23 05 07 14 16 \n 04 06 13 20 22 \n 10 12 19 21 03 \n 11 18 25 02 09 \n");

    }

    if (n==6)
    {
        printf ("n = 6, Soma = 111 \n");
        printf (" 28 22 34 15 05 07 \n 08 25 06 12 33 27 \n 23 36 04 14 03 31 \n 02 10 24 29 35 11 \n 18 01 30 20 16 26 \n 32 17 13 21 19 09 \n");
    }

    if (n==7)
    {
        printf ("n = 7, Soma = 175 \n");
        printf (" 19 49 39 40 20 01 07 \n 11 23 32 44 38 18 09 \n 06 22 21 04 35 41 46 \n 48 13 17 25 12 36 24 \n 47 08 29 05 31 10 45 \n 16 33 34 15 37 26 14 \n 28 27 03 42 02 43 30 \n");
    }

    if (n==8)
    {
        printf ("n = 8, Soma = 260 \n");
        printf (" 64 42 32 47 27 08 28 02 \n 35 43 14 21 55 06 24 62 \n 34 33 39 09 37 23 54 31 \n 03 53 26 13 44 07 63 52 \n 15 48 28 36 41 50 17 25 \n 49 01 57 58 11 45 19 20 \n 04 18 52 46 16 60 05 59 \n 56 22 12 30 29 61 40 10");
    }

    if (n==9)
    {
        printf ("n = 9, Soma = 369 \n");
        printf (" 01 73 47 04 76 69 09 80 10 \n 15 17 46 75 70 54 61 12 18 \n 72 56 48 32 43 22 24 08 64 \n 36 28 35 33 68 30 31 29 79 \n 38 55 41 15 45 50 60 26 39 \n 53 40 63 51 21 13 34 42 52 \n 57 27 49 23 25 59 65 44 20 \n 19 71 37 78 14 67 11 66 06 \n 77 02 03 58 07 05 74 62 81 \n ");
    }

    if (n==10)
    {
        printf ("n = 10, Soma = 505 \n");
        printf (" 01 99 93 04 96 05 97 08 92 10 \n 90 12 88 14 86 85 17 83 19 11 \n 71 79 23 77 25 26 74 28 72 30 \n 61 62 38 34 65 36 37 33 69 70 \n 60 42 58 47 45 46 44 53 59 51 \n 50 52 43 57 55 56 54 48 49 41 \n 40 39 68 64 35 66 67 63 32 31 \n 21 29 73 27 76 75 24 78 22 80 \n 20 82 18 87 16 15 84 13 89 81 \n 91 09 03 94 06 95 07 98 02 100 \n ");
    }

    else
    {
        printf ("Erro! O valor de n informado nao esta dentro das regras pre-estabelecidas (n>=3 e n<=10)");
    }

    return 0;
}
