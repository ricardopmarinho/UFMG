#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


int main(int argc, char *argv[]){


    
    
int D;
int quantidade;
    scanf("%d",&quantidade);
    int sequencia[quantidade];
    	for(D = 0 ; D < quantidade; D++)
		{
       		scanf("%d",&sequencia[D]);
    	}
	int AUXj = 0;
    int AUXi = 0;
    int i,j,k;
    int TOTAL = 0;
    int soma = INT_MIN;

/* Com esse for, estou fazendo a soma de cada termo , e guardando a maior soma dentro da variavel TOTAL.
A interação vai ser realizada primeiramente de termo por termo depois, 
de dois em dois, depois três, e assim ate n termos.Achando assim a maior soma entre um determinado intervalo*/

for(j = 0; j < quantidade; j++){
	for(k = 0; k < quantidade; k++){
        TOTAL =0;
for(i = j; i < quantidade-k; i++){

    TOTAL = TOTAL + sequencia[i];
  
}
  /*Esta condição serve para pegar o maior valor da soma e guardar em TOTAL e qual intervalo meu for achou a maior soma*/
if(TOTAL > soma){
    soma = TOTAL;
    AUXj = j;
    AUXi = (i-1);

}

}
}if(soma==0){
printf("Soma: %-2d\n",soma);}
else{
printf("Soma: %-2d\n",soma);
printf("Indices: %-2d a %-2d\n",AUXj+1 , AUXi+1);}

return 0;
}
