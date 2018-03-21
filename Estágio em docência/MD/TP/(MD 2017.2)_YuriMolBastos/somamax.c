#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int N;
	int a[20];
	int somaMax = 0;
	int somaInd;
	int i, j, k;// auxiliares dos loops
	int aux1, aux2;// auxiliares para a impressão dos indices
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)//for para pegar todos os N numeros do array
		scanf("%d", &a[i]);
	
	
	for(i = 0; i < N; i++)
    	for(j = i; j < N; j++){
    		
			somaInd = 0;
    		
      		for(k = i; k < j; k++){
        		somaInd = somaInd + a[k];
      		}
      		if(somaInd > somaMax){
				somaMax = somaInd;
				aux1 = i + 1;
				aux2 = j;
    	}
   }

	printf("Soma: %d\n", somaMax);
	printf("Indices: %d a %d", aux1, aux2);

	return 0;
}
