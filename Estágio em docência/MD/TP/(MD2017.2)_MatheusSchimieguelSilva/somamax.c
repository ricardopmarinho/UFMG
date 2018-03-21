
#include <stdio.h>
#include <stdlib.h>
int main (void){



int tamanho;
int i,j;
int soma,somatotal;
int posinicial,posfinal;

	scanf("%d",&tamanho);
	int vetor[tamanho];

	for (i=0;i<tamanho;i++){
		scanf("%d",&vetor[i]);
	}
	
	soma = 0;
	somatotal = 0;


	for (i=0;i<tamanho-1;i++){

		if( somatotal < vetor[i] ){
			somatotal = vetor[i];
			posinicial=i;
			posfinal=i;
		}
	

		soma=vetor[i];



		for (j=i+1;j<tamanho;j++){
			soma=soma + vetor[j];

			if (soma>somatotal){
				somatotal=soma;
				posinicial=i;
				posfinal=j;
              
			}


		}
	}
		
		if( vetor[tamanho-1] > somatotal )
			somatotal = vetor[tamanho-1];


		printf("soma total :%d\n",somatotal);

		printf("posicao inicial %d posicao final %d\n", posinicial+1, posfinal+1); 
		


	

	



return 0;
}

