#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int n, n2, aux, aux2;
	do{
    scanf("%d", &n);
    if (n<3||n>5) printf("Valor invalido para n, entre com um numero entre 3 e 5\n");}
	while (n<3||n>5);
    int i=0, j=n/2, k=0;
    int SomaMagica=n*((n*n+1)/2), soma=0;
    int quadrado[n][n];
    int organizado[n][n];
    int comparacao[4][4]={1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1};
    for (aux=0; aux<n; aux++)
        for (aux2=0; aux2<n; aux2++)
            quadrado[aux][aux2]=n*aux+1+aux2;
    for (aux=0; aux<n; aux++){
        for (aux2=0; aux2<n; aux2++)
            organizado [aux][aux2]=0;
        }
    if(n%2){
    	for(aux=0; aux<n; aux++){
    		for(aux2=0; aux2<n; aux2++){
    			if (organizado[i][j])i++;
                organizado[i][j]=quadrado[aux][aux2];
                i--;
				j++;
                if (i<0) i=n-1;
                if (j==n) j=0;
            }
        }
	}
	else { 
	    for (aux=0; aux<n; aux++){
		    for (aux2=0; aux2<n; aux2++){
		    	if (comparacao[aux][aux2])organizado[aux][aux2]=quadrado[aux][aux2];
		    	else organizado[aux][aux2]=organizado[aux][aux2]=quadrado[n-1-aux][n-1-aux2];
			}
	    }
	}
	for (aux=0; aux<n; aux++) soma+=organizado[0][aux];
	//if (soma==SomaMagica)printf("Ok");
	printf("n = %d, Soma = %d\n", n, soma);
	for (aux=0; aux<n; aux++){
        for (aux2=0; aux2<n; aux2++)
            printf("%d ", organizado[aux][aux2]);
        printf ("\n");}
	
	return 0;
}
