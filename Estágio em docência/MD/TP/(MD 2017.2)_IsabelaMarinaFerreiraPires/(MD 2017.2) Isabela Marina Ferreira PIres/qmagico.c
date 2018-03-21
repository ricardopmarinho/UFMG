// Este programa gera um quadrado mágico a partir de um número maior ou igual a 3 e menor ou igual a 5 digitado no console, dando em seguida a disposição 
// dos números nele e a soma correspondente.

#include <stdio.h>
#include <stdlib.h>

int func_walk(int *lin, int *col)
{

  (*lin)--;
  (*col)++;
}

int cubo_impar(int N, int matriz[N][N])
{
  int magic;
  magic=(N * (N*N + 1)) / 2;

  int seq=1;
  int lin = 0;
  int col = N/2;
  int cont, cont2;
  int antlin, antcol;

   for(cont=0;cont<N;cont++)
    {
      for(cont2=0;cont2<N;cont2++)
      {
        antlin=lin;
        antcol=col;
       if(matriz[lin][col]==0) // insere os numeros
       {
         matriz[lin][col]=seq; seq++;
         func_walk(&lin, &col);

         if(lin<0)
         {
          lin=N-1;
         }
         if(col==N)
         {
          col=0;
         }
       }
       if(matriz[lin][col]!=0)  //checa posiçao
       {
         lin=antlin+1;
         col=antcol;
       }
      }
    }

    for(lin=0;lin<N;lin++)          // Exibir quadrado
    {
      for(col=0;col<N;col++)
      {
       printf("%-5d", matriz[lin][col]);
      }
      printf("\n");
    }
    printf("n=%d  soma=%d\n", N, magic);
  return 0;
}

int cubo_par(int N, int matriz[N][N])
{
  int magic;
  magic=(N * (N*N + 1)) / 2;

  int ida=1;
  int volta=N*N;

	int lin;
  int col;
  int cont;

  
for(lin=0;lin<N;lin++)    //linha
    {
      for(col=0;col<N;col++) //coluna
      {
         if(col==lin || lin==N-1-col)
         {
          matriz[lin][col]=ida;
          ida++;
         }
         else ida++;
      }
    }

for(lin=0;lin<N;lin++)    //linha
    {
      for(col=0;col<N;col++) //coluna
      {
         if(matriz[lin][col]==0)
         {
          matriz[lin][col]=volta;
          volta--;
         }
         else volta--;
      }
    }

  for(lin=0;lin<N;lin++)          // Exibir quadrado
    {
      for(col=0;col<N;col++)
      {
       printf("%-5d", matriz[lin][col]);
      }
      printf("\n");
    }
    printf("n=%d  soma=%d\n", N, magic);
  return 0;
}



int main() 
{
	int N;
	int cont, cont2;
	scanf("%d", &N);
    int m[N][N];

    for(cont=0;cont<N;cont++)
    {
    	for(cont2=0;cont2<N;cont2++)
    	{
    	 m[cont][cont2]=0;
    	}
    }
	
	if(N%2==0)
	{
		cubo_par(N, m);
	}
	else
		cubo_impar(N, m);
  
	
	return 0;
}
