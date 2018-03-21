#include<stdlib.h>
#include<stdio.h>



int main (int argc, char *argv[]){

            int linha = 0;
            int coluna = 0;
            int N,i,j;
            int contador;

            scanf("%d",  & N);
            int stop = N*N;


            int quadrado[N][N];

    for (coluna = 0; coluna < N; coluna++) {
                for (linha = 0; linha < N; linha++)
                    quadrado[coluna][linha] = 0;

            }
///Para quadrado par.
            if (N % 2 == 0) {
                

                contador = 0;
                int contador2 = 17;
                for (coluna = 0; coluna < N; coluna++) {
                    for (linha = 0; linha < N; linha++) {
/**acrescentar os valores no quadrado, preenchendo primeiro a diagonal principal e secundaria, depois colocando os outros
valores em ordem decrescente.**/
                        contador++;
                        contador2--;

                        if (coluna == linha) {
///diagonal principal
                            quadrado[coluna][linha] = contador;
/// diagonal secundaria
                        } else if (coluna == (N - 1 - linha)) {

                            quadrado[coluna][linha] = contador;

                        } else if (quadrado[coluna][linha] == 0) {

                            quadrado[coluna][linha] = contador2;

                        }
                    }
                }
                for (coluna = 0; coluna < N; coluna++) {
                    for (linha = 0; linha < N; linha++) {
                        printf("%4d ", quadrado[coluna][linha]);
                    }
                    printf("\n");
                }
                printf("N = %d\n", N);
                printf("Soma = %d\n", (N*(N*N+1))/2 );

            } else {

///Para quadrado impares.
                int meio = (N / 2);
                contador = 1;
                quadrado[0][meio] = contador;

                linha = 0;
                coluna = meio;
/*Para preencher o quadrado magico de matriz impar, defini que o for vai colocar o 1 sempre na primeira coluna,segundalinha.
O resto do preenchimento é feito pelo for que vai ir para baixo e para esquerda, se nao tiver numero onde ele parar ele coloca um numero la, caso tenha, ele volta
de onde saiu, e vai para a direita e preenche o espaço com um numero na ordem crescente.*/
                int a = 1;
                int linhaanterior, colunaanterior;

                while (stop > 1) {
                    stop--;
					contador++;

                    linhaanterior = linha;
                    colunaanterior = coluna;

                    linha--;
                    coluna++;


                    if (linha < 0) {
                        linha = N-1;
                    }

                    if (coluna > (N - 1)) {
                        coluna = 0;
                    }

                    if (quadrado[linha][coluna] == 0) {

                        quadrado[linha][coluna] = contador;

                    } else {
                        coluna = colunaanterior;
                        linha = linhaanterior;
                        linha++;

                        if (linha >= N) {
                            linha = 0;
                        }

                        quadrado[linha][coluna] = contador;

                    }



                }
                	
                    
					for (j= 0; j < N; j++)	{
						printf("\n");
						for (i = 0; i < N; i++)
						{
                        	
                            printf("%4d ", quadrado[i][j]);
                        	}

                    }           printf("\n");

                    printf("N = %d\n", N);
                   printf("Soma = %d\n", (N*(N*N+1))/2 );
            }
        

            return 0;

}


