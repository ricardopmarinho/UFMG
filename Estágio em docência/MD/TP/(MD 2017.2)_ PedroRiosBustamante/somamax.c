#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){


	int numeros;
	scanf ("%d", &numeros);
	int vetor[numeros], total, i, ii, aux, somatotal=0, indice1=0, indice2=0, a;
	for (a=0; a<numeros; a++){
		scanf ("%d", &vetor[a]);
	}
	for (i=0; i<numeros; i++){
		for (ii=0; ii<numeros; ii++){
			total=0;
			for (aux=i; aux<numeros-ii; aux++){
				total+=vetor[aux];
				if(total>somatotal){
					somatotal=total;
					indice1=(i+1);
					indice2=(aux+1);
				}
			}
		}	
	}
	if (somatotal<0) somatotal=0;
	printf("Soma: %d\n", somatotal);
	printf("Indices: %d a %d\n", indice1, indice2); 


return 0;
}
