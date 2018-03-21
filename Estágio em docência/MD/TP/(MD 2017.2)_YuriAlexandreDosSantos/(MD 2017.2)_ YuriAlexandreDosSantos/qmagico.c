#include <stdio.h>
#include <stdlib.h>

void geraMatriz_nImpar (int N) {

    int meio = ((N*N)/2)+1, i, k, soma=15;

    int matriz[N][N];

    for (i=0; i<N; i++){


        for(k=0;k<N;k++) {

            matriz[i][k] = (N*((i+k+1+(N/2))%N)+((i+1+(2*(k+1))-2)%N) + 1);

        }

    }

    for (i=0; i<N; i++){


        for(k=0;k<N;k++) {

            printf ("%.2d ", matriz[i][k]);

        }

        printf("\n");

    }

}

void geraMatriz_n4(int N) {

    int i, k, aux=1, soma=34;

int matriz[4][4];

int matrizAuxiliar[4][4];

for (i=0;i<4; i++){

    for (k=0;k<4;k++){

        if ((i == k) || ((i+k) == (N-1))) {matrizAuxiliar[i][k] = 1;

        } else {matrizAuxiliar[i][k] = 0;}

    }


}

for (i=0;i<4; i++){

    for (k=0;k<4;k++){

            if (matrizAuxiliar[i][k] == 1) {matriz[i][k] = i + k + aux;}
            if (matrizAuxiliar[i][k] == 0) {matriz[i][k] = (N*N) - (i+k+aux-1);}
    }

    aux = aux + (N-1);
}




for (i=0;i<4; i++){

    for (k=0;k<4;k++){

        printf("%.2d ", matriz[i][k]);

    }
printf("\n");

}

}



int main()
{

    int N, soma;

    // Chama a função que gera a o quadrado mágico com N = 3;

    N = 3;  soma = (((N*N)+1)/2)*N;

    printf("n = %d, Soma = %d\n", N, soma);

    geraMatriz_nImpar(N);

    printf("\n");

    // Chama a função que gera a o quadrado mágico com N = 4;

    N = 4; soma = (((N*N)+1)/2)*N;

    printf("n = %d, Soma = %d\n", N, soma);

    geraMatriz_n4(N);

    printf("\n");

    // Chama a função que gera a o quadrado mágico com N = 5;

    N = 5; soma = (((N*N)+1)/2)*N;

    printf("n = %d, Soma = %d\n", N, soma);

    geraMatriz_nImpar(N);

    printf("\n");

    return 0;
}
