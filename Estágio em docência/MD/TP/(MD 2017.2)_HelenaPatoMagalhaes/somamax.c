#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int av[50];
	int sv[500];
	int i1, i2, i3, negativo, inicio, fim;
	inicio=0;
	fim=0;
	int n, s;
	for(i1=0;i1<50;i1++) av[i1]=0;
	for(i1=0;i1<500;i1++) sv[i1]=0;
	scanf ("%d", &n);
	if(n<3||n>20) exit(0);
	for(i1=0;i1<n;i1++) scanf ("%d", &av[i1]);
	negativo=0;
	for(i1=0;i1<n;i1++) if(av[i1]<0) negativo++;
	if(negativo==n)
	{
		printf("Soma: 0\nIndices: 1 a %d", n);
		exit(0);
	}
	i3=0;
	for(i1=0;i1<n;i1++)
	{
		for(i2=(i1+1);i2<(n+1);i2++)
		{
			if(i2==(i1+1)) sv[i3]=(av[i1]+av[i2]);
			else sv[i3]=(sv[i3-1]+av[i2]);
			if(i3==0)
			{
				inicio=i1;
				fim=i2;
				s=sv[i3];
			}
			else if(s<sv[i3])
			{
				inicio=i1+1;
				fim=i2+1;
				s=sv[i3];
			}
			i3++;
		}
	}
	printf("Soma: %d\nIndices: %d a %d", s, inicio, fim);
	return 0;
}
