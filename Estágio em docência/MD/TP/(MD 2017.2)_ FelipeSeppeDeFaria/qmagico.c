#include <stdio.h>
#include <stdlib.h>

void quad_impar(int N){
	int i, ii, j, jj, k;
	int quad[N][N];
	int valor[N*N];
	for(i=0; i<N*N; i++)
		valor[i]=i+1;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			quad[i][j]=0;
	i=0; j=N/2;
	for(k=0; k<N*N; k++){
		if(!quad[i][j]){
			quad[i][j]=valor[k];
			ii=i; jj=j;
		}
		else{
			i=ii; j=jj;
			i++;
			if(i>=N)
				i=0;
			quad[i][j]=valor[k];
		}
		i--; j++;
		if(i<0)
			i=N-1;
		if(j>=N)
			j=0;
	}
	printf("n = %d, Soma = %d\n", N, (N*(N*N+1))/2);
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(quad[i][j]<10)
				printf(" %d ", quad[i][j]);
			else
				printf("%d ", quad[i][j]);
		}
		printf("\n");
	}
	return;
}

void quad_4(int N){
	int quad[N][N];
	int valor[N*N];
	int i, j, k, kk;
	for(i=0; i<N*N; i++)
		valor[i]=i+1;
	k=0; kk=(N*N)-1;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++){
			quad[i][j]=0;
			if(i==j)
				quad[i][j]=valor[k];
			else if(i==N-j-1)
				quad[i][j]=valor[k];
			else
				quad[i][j]=valor[kk];
			k++; kk--;
		}
	printf("n = %d, Soma = %d\n", N, (N*(N*N+1))/2);
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(quad[i][j]<10)
				printf(" %d ", quad[i][j]);
			else
				printf("%d ", quad[i][j]);
		}
		printf("\n");
	}
	return;
}

int main(void){
	int N, i, j, k;
	scanf("%d", &N);
	if(N%2)
		quad_impar(N);
	else
		quad_4(N);
	return 0;
}