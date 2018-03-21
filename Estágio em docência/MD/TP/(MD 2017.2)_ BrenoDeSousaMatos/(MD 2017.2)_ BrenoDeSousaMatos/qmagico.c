#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int busca(int tamVetor, int *v, int k){
	int i;
	int resposta;
	for ( i = 0; i < tamVetor; i++) {
		if (v[i] == k) {//se o numero esta presente no vetor
		  resposta = 1;
      break;
    }
	}
  if (i == tamVetor) {//se nao esta no vetor
    resposta = 0;
  }
	return resposta;
}

void resolveImpar(int n, int constMagica,int** matriz,int i, int j, int sequencia) {

  if (sequencia == constMagica || sequencia > pow(n,2))
  {
  	return;
  }
  else if (i == -1 && j == n)
  {
  	return resolveImpar(n,constMagica,matriz,0,n-2,sequencia);
  }
  else if (j == n)
  {
  	return resolveImpar(n,constMagica,matriz,i,0,sequencia);
  }
  else if (i == -1)
  {
  	return resolveImpar(n,constMagica,matriz,n-1,j,sequencia);
  }

  else if (matriz[i][j] != 0)
  {
  	return resolveImpar(n,constMagica,matriz,i+1,j-2,sequencia);
  }
  else{
  	matriz[i][j] = sequencia++;
  }

  return resolveImpar(n,constMagica,matriz,i-1,j+1,sequencia);
}

void resolvePar(int n, int constMagica,int** matriz){
	int i,j,k,l,m = 0,contadorAux,*v;
	v = (int *) calloc(n*n,sizeof(int));

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i==j || i+j + 1== n)
				{
					matriz[i][j] = ((i)*n) + j+1;
					v[k] = ((i)*n) + j+1;
					k++;
				}
			}
		}


	contadorAux = matriz[n-1][n-1] - 1;//segunda ida na matriz, completando o quadrado magico

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (!(i==j || i+j + 1== n))
			{
				if (busca(n*n,v,contadorAux) == 0) {//se o valor atual do contador nao esta no vetor
					matriz[i][j] = contadorAux;
					contadorAux--;
				}
				else{ //CONTADOR ESTA NO VETOR
					while (busca(n*n,v,contadorAux) == 1) {
						contadorAux--;
					}
					matriz[i][j] = contadorAux;
					contadorAux--;
				}
			}

		}
	}
	free(v);
}

int main(int argc, char const *argv[]) {
  int n,i,j;
  int constMagica;
  int **matriz;

  scanf("%d",&n );
  constMagica = n *(pow(n,2) + 1)/2 ;
  matriz = (int **) calloc(n,sizeof(int*));
  for ( i = 0; i < n; i++) {
    matriz[i] = (int *) calloc(n,sizeof(int));
  }

  if (n%2 == 0) {//se o numero eh par
  	resolvePar(n,constMagica,matriz);
  } else {
    resolveImpar(n,constMagica,matriz,n/2,n-1,1);
  }

  for (i = 0; i < n; i++)
  {
  	for (j = 0; j < n; j++)
  	{
  		printf("%3d ",matriz[i][j] );
  	}
  	printf("\n");
  }
  return 0;
}
