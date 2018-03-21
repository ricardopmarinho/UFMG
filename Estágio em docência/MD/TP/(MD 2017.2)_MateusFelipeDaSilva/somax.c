#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


int main(int argc, char *argv[]){


    int tamanho;
    scanf("%d",&tamanho);
    int sequencia[tamanho];
    int b;



    for(b = 0 ; b < tamanho; b++){
       scanf("%d",&sequencia[b]);
    }

    int verifica = 0;

    for(b = 0 ; b < tamanho; b++){
       if(sequencia[b] < 0)
       verifica++;
    }


    if(verifica == tamanho){
        printf("Soma: 0\n");
        printf("Todos os %cndices sao negativos\n",214);


    }else{

    int i,j,k,a;
    int somaP = 0;
    int inicioSequencia = 0;
    int fimSequencia = 0;
    int soma = INT_MIN;



for(j = 0; j < tamanho; j++){
	for(k = 0; k < tamanho; k++){
        somaP =0;
		for(i = j; i < tamanho-k; i++){

			somaP = somaP + sequencia[i];

		}

	if(somaP > soma){
		soma = somaP;
		inicioSequencia = j;
		fimSequencia = (i-1);

		}
	}
}

printf("Soma: %d\n",soma);
printf("%cndices: %d a %d\n",214,inicioSequencia+1 , fimSequencia+1);
    }
system("PAUSE");
return 0;
}
