#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, j, k, N, maior=0, ii=0, soma=0, aux;
	scanf("%d", &N);
	if(N<3 || N>20){
		printf("ERRO\n");
		return 0;
	}
	int vet[N];
	for(i=0; i<N; i++)
		scanf("%d", &vet[i]);
	for(i=0; i<N-1; i++){
		if(vet[i]>0){
			aux=vet[i];
			if(aux>soma){
				soma=aux;
				maior=i; ii=i;
			}
			for(j=i+1; j<N; j++){
				aux+=vet[j];
				if(aux>soma){
					soma=aux;
					maior=i; ii=j;
				}
				if(aux<=0)
					j=N;
			}
		}
	}
	printf("Soma: %d\n", soma);
	if(soma==0)
		printf("Indices 0 a 0\n");
	else
		printf("Indices: %d a %d\n", ++maior, ++ii);
	return 0;
}