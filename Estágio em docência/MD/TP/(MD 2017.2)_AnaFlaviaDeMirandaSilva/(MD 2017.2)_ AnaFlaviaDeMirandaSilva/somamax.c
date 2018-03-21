#include <stdio.h>
#include <stdlib.h>
int main(){
	int i, j, n, soma, indice1, indice2;
	int somamax=0;
	int count=0;

//Lê o valor n (quantos números existem no vetor)
	scanf("%i", &n);

	int vetor[n];

//Lê os n números do vetor
	for(i=0;i<n;i++){
		scanf("%i", &vetor[i]);
	}

//Conta quais valores do vetor são negativos, se todos forem negativos, define a soma maxima como zero
	for(i=0; i<n; i++){
		if(vetor[i]<0){
			count++;
		}
	}
	if(count==n){
			somamax=0;
		}

/*Loop que realiza as somas e verifica qual é a soma máxima, quando a encontra, guarda o seu valor e os indices inicial e final
de seu subvetor. Este loop soma um primeiro valor n e os valores seguintes no vetor*/
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			if (i==j){
				soma=0;
			}
			soma+=vetor[j];
			if (soma>somamax){
				somamax=soma;
				indice1=(i+1);
				indice2=(j+1);
			}
		}
	} 

	if(somamax==0){
		printf("Soma: %i\n", somamax);
	}
	else{
		printf("Soma: %i\n", somamax);
		printf("Índices: %i a %i\n", indice1, indice2);
	}

/*	for(i=0;i<n;i++){
		printf("%i ", vetor[i]);
	}
*/
	return 0;
}