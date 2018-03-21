#include <stdio.h>
#include <stdlib.h>


int main() {
	
	struct vetores{
		int soma;
		int idxMaior;
		int idxMenor;
	};
	int n;
	int cnt1, cnt2;
	int numVetores;
	
	scanf("%d", &n);
	
	numVetores = (n*(n+1))/2;
	
	int termo[n];
	struct vetores vetor[numVetores];
	struct vetores maxVetor;
	
	for( cnt1=0; cnt1<n; cnt1++){
		scanf("%d", &termo[cnt1]);	
	}

    for( cnt1=0; cnt1<numVetores; cnt1++){
    	vetor[cnt1].soma = 0;
	}
	
	int i=n, j=1;
	int b=0; 
	
	while( i!=0 && j!=n+1 ){
		for( cnt1=0; cnt1<i; cnt1++ ){
    	    for( cnt2=0; cnt2<j; cnt2++ ){
    	    	vetor[b].soma += termo[cnt1+cnt2];
            }
            vetor[b].idxMaior = cnt1+cnt2;
            vetor[b].idxMenor = cnt1+1;
			b++;
	    }
	    i--;
	    j++;
	}
    
    maxVetor = vetor[0];
	for ( cnt1=1; cnt1<numVetores; cnt1++ ){
		if( maxVetor.soma < vetor[cnt1].soma ){
			maxVetor = vetor[cnt1];
		}
	} 
	
	printf("Soma: %d\n", maxVetor.soma);
	printf("Índices: %d a %d\n", maxVetor.idxMenor, maxVetor.idxMaior);
    
	return 0;
}
