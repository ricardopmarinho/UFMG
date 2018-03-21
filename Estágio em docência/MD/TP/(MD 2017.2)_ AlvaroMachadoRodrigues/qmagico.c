#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  int N;
  printf("Insira o tamanho do lado do quadrado:\n");
  scanf("%d", &N);

  int qmagico[N][N];
  int i, aux;
  int lin, col;

  if (N%2 != 0)
  {

    for(lin = 0;lin < N; lin++)
     {
         for(col = 0;col < N; col ++)
         {
            qmagico[lin][col] = 0;
         }
     }

    lin = N/2;
    col = N-1;

     for(i = 1; i <= N*N;)
     {
       if (lin==-1 && col==N)
       {
           col = N-2;
           lin = 0;
       }
       else
       {
           if (col == N)
               col = 0;

           if (lin < 0)
               lin=N-1;
       }
       if (qmagico[lin][col])
       {
           col -= 2;
           lin++;
           continue;
       }
       else
           qmagico[lin][col] = i++;
           col++; lin--;
     }
     printf("n = %d, Soma = %d\n", N, N*(N*N+1)/2);
     for(lin = 0;lin<N;lin++)
     {
         for(col = 0;col <N; col ++)
         {
             printf("%4d",qmagico[lin][col]);
         }
         printf("\n");
     }
  }

  if (N%4 == 0)
  {
    i = 1;
     for(lin = 0;lin <N; lin++)
     {
         for(col = 0;col <N; col ++)
         {
             qmagico[lin][col] = i;
             i++;
         }
     }

     for(lin = 0; lin <N/2; lin ++)
     {
         for(col = N/4;col <N/4*3;col ++)
         {
             aux = qmagico[lin][col];
             qmagico[lin][col] = qmagico[N-lin-1][col];
             qmagico[N-lin-1][col] = aux;
         }
     }

     for(col = 0; col <N/2; col ++)
     {
         for(lin = N/4;lin <N/4 * 3;lin ++)
         {
             aux = qmagico[lin][col];
             qmagico[lin][col] = qmagico[lin][N-col-1];
             qmagico[lin][N-col-1] = aux;
         }
     }
     printf("n = %d, Soma = %d\n", N, N*(N*N+1)/2);
     for(lin = 0;lin <N; lin++)
     {
         for(col = 0;col <N; col ++)
         {
             printf("%4d",qmagico[lin][col]);
         }
         printf("\n");
     }
  }

  if (N%2 == 0 && N%4 != 0 ) {printf("O programa não suporta esse tamanho de quadrado.\n");}
  return 0;
}
