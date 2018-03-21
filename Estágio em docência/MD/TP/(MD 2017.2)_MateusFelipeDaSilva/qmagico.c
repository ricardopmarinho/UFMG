#include<stdlib.h>
#include<stdio.h>



int main (int argc, char *argv[]){

            int LIN = 0;
            int COL = 0;
            int N,i,j;
            int contador;

            scanf("%d",  & N);
            int pausa = N*N;


            int matrix[N][N];

    for (COL = 0; COL < N; COL++) {
                for (LIN = 0; LIN < N; LIN++)
                    matrix[COL][LIN] = 0;

            }

            if (N % 2 == 0) {
                /// MATRIX PAR

                contador = 0;
                int contador2 = 17;

                for (COL = 0; COL < N; COL++) {
                    for (LIN = 0; LIN < N; LIN++) {

                        contador++;
                        contador2--;

                        if (COL == LIN) {

                            matrix[COL][LIN] = contador;

                        } else if (COL == (N - 1 - LIN)) {

                            matrix[COL][LIN] = contador;

                        } else if (matrix[COL][LIN] == 0) {

                            matrix[COL][LIN] = contador2;

                        }
                    }
                }
                printf("n = %d,",N);
                printf(" soma = %d\n",((N*N*N)+N)/2);
                for (COL = 0; COL < N; COL++) {
                    for (LIN = 0; LIN < N; LIN++) {
                        printf("%3d ", matrix[COL][LIN]);
                    }
                    printf("\n");
                }

            } else {

                /// MATRIX IMPAR


                int meio = (N / 2);
                contador = 1;
                matrix[0][meio] = contador;

                LIN = 0;
                COL = meio;

                int a = 1;
                int LINanterior, COLanterior;

                while (pausa > 1) {
                    pausa--;


                    contador++;

                    LINanterior = LIN;
                    COLanterior = COL;

                    LIN--;
                    COL++;

                    if (LIN < 0) {
                        LIN = N-1;
                    }

                    if (COL > (N - 1)) {
                        COL = 0;
                    }


                    if (matrix[LIN][COL] == 0) {

                        matrix[LIN][COL] = contador;

                    } else {

                        LIN = LINanterior;
                        COL = COLanterior;
                        LIN++;

                        if (LIN >= N) {
                            LIN = 0;
                        }

                        matrix[LIN][COL] = contador;

                    }



                }

                printf("n = %d,",N);
                printf(" soma = %d\n",((N*N*N)+N)/2);
                    for (i = 0; i < N; i++) {
                        for (j= 0; j < N; j++) {
                            printf("%-5d ", matrix[i][j]);
                        }
                        printf("\n");

                    }
            }

			system("PAUSE");
            return 0;
}
