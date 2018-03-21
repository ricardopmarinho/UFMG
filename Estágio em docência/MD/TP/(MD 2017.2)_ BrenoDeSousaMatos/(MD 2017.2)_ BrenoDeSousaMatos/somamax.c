#include "stdlib.h"
#include "stdio.h"


int Sum(int i,int j,int *v){
	int auxSum = 0,k,max,min;

	if (i < j)
	{
		max = j;
		min = i;
	}else {
		max = i;
		min = j;
	}
	for (k = min; k <= max; k++)
	{
		auxSum+=v[k];
	}

	return auxSum;
}

int main(int argc, char const *argv[])
{
	int n,i,*v,j;
	int Max = 0,posI,posJ;//usados para
	int **M;
	scanf("%d",&n);

	v = (int*) malloc(sizeof(int)*n*4);

	for (i = 0; i < n; i++) //loop de leitura dos valores do vetor
	{
		scanf("%d",&v[i]);
	}

	M = (int**)malloc(sizeof(int*)*n);

	for (i = 0; i < n; i++)
	{
		M[i] = (int*)malloc(sizeof(int)*n);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			M[i][j] = Sum(i,j,v);
			if (M[i][j] > Max)
			{
				Max = M[i][j];
				if (i > j)
				{
					posI = j;
					posJ = i;
				}
				else
				{
					posI = i;
					posJ = j;					
				}
			}
		}
	}

	printf("Soma: %d\n",Max );
	printf("Indices: %d a %d\n",posI+1,posJ+1 );


	return 0;
}