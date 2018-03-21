#include<stdio.h>
#include<stdlib.h>

main(){
int i,j;
	int maior;
	int qtd;
	int contNeg = 0;
	int ind1, ind2;
	
	scanf("%d",&qtd);
	int vetor[qtd];
	
	for(i=0; i<qtd; i++){
		scanf("%d",&vetor[i]);
		
		if(vetor[i] < 0){
			contNeg++;
		}
		
		if(i == 0){
			maior = vetor[i];
			ind1 = i; ind2 = i;
		}else{
			if(vetor[i] > maior){
				maior = vetor[i];
				ind1 = i; ind2 = i;
			}
		}
	}
	
	//Criando duas variáveis para o controle de posição das verificações
	int x=0,y=1;
	//Ponto de parada: Quando a verificação ter sido feita em todo o vetor
	while(y<qtd){
		
		//Duas variáveis para o controle de posição das verificações internas
		int aux1=x, aux2=y;
		
		//Ponto de parada: Quando a verificação interna ter sido feita em todo o vetor
		while(aux2<qtd){
			//Contador i irá variar dentro do proximo while 
			i = aux1;
			int soma = 0;
			
			//Ponto de parada: Quando o contador I for menor ou igual ao ponto de verificação
			while(i<=aux2){
				soma += vetor[i];
				i++;
			}
		
			if(soma > maior){
				maior = soma;
				ind1 = aux1;
				ind2 = aux2;
			}
			
			aux1++; aux2++;
		}
		y++;
	}
	
	if(contNeg == qtd){
		printf("Soma: 0");
	}else{
		printf("Soma: %d\nIndices: %d a %d\n",maior,ind1+1,ind2+1);
	}
	
	system("pause");
}
