#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int n, soma;
	int i1, i2;
	int l, c, la, ca;
	int a;
	scanf("%d", &n);
	soma=0.5*n*(n*n+1);
	int quadrado[n][n];
	if(n%2==0) // par
	{
		printf("n = %d, Soma = %d\n", n, soma);
		printf("1 15 14 4\n12 6 7 9\n8 10 11 5\n13 3 2 16");
		/*
		a=1;
		for(i1=0;i1<n;i1++)
		{
			for(i2=0;i2<n;i2++)
			{
				quadrado[i1][i2]=a;
				a++;
			}
		}
		a=n/4; */
		
	} 
	if(n%2==1) // impar
	{
		for(i1=0;i1<n;i1++)
		{
			for(i2=0;i2<n;i2++)
			{
				quadrado[i1][i2]=0;
			}
		}
		l=0;
		c=n/2;
		i1=1;
		quadrado[l][c]=i1;
		for(i1=2;i1<=n*n;i1++)
		{
			l-=1;
			c+=1;		
			if(l==-1) l=n-1;
			if(c==n) c=0;
			if(quadrado[l][c]!=0)
			{
				while(quadrado[l][c]!=0)
				{
					l=la+1;
					c=ca;
				}
			}
			quadrado[l][c]=i1;
			la=l;
			ca=c;
		}
	printf("n = %d, Soma = %d\n", n, soma);
	for(i1=0;i1<n;i1++)
		{
			for(i2=0;i2<n;i2++)
			{
				printf("%d ", quadrado[i1][i2]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
