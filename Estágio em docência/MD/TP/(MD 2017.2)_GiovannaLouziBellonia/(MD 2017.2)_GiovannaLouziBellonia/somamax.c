#include <stdlib.h>
#include <stdio.h>


int main () {
	
	int N;
	
	printf("Digite o valor inteiro de n para a quantidade de elementos que serao colocados no vetor\n");
	scanf("%d", &N);
	int i[N+1]; //criacao do vetor com os n numeros + 1 para o /0
	int ii, aa, bb, cc;
	
	printf("Digite os numeros que serao colocados no vetor:\n");
	for(ii=0; ii<N; ii++) { //leitura dos valores que serao colocados no vetor
		scanf("%d", &i[ii]);
	//	printf("entrada %d: %d ", ii, i[ii]); //conferindo se esta funcionando
	}
	
	printf("\n");
	
	//soma pode ser menor se o numero negativo nao compensar a soma dos negativos
	//comecar a somar apenas apartir de um numero positivo, se os x primeiros forem negativos serao descartados
	//se todos forem positivos, a soma max é a soma de todos
	//se houver um negativo, ele so estara dendo da lista se a soma dos proxs n positivos forem maior do q eles 
	//se apos um negativo, vier outro negativo, o mesmo de cima vale para a soma dos negativos
	
	struct somaMax { int soma; 
	int indI; //indicador inicial
	int indF; //indicador final
	}; 
	
	struct somaMax somas[N]; 
	
	
	int indI, indA, indF; //indicador inicial, indicador atual, indicador final 
	int soma=0;
	int somaNeg=0;
	int somaPos=0;
		
	for (ii=0; ii<N; ii++) { //achar o primeiro numero positivo para comecar a somar
		if (i[ii]>0) {
			indI=ii;
			break;			
		}
		
	}
	
	if (ii==N) { //nao ha nenhum numero positivo
	 printf("Soma=0, ja que todos os numeros sao negativos\n");
	 return 0;
	}
	
	for (ii=indI; ii<N; ii++) { //vai ir somando ate encontrar um numero negativo
		
		if (i[ii]>0) {
			soma=soma+i[ii];
			indF=ii; 
		}
		
		if (i[ii]<0) {
			indA=ii;
			break;
		}

	}
	
	if (ii==N) { //nao ha depois do primeiro positivo, nenhum negativo
	 printf("Soma = %d,indice inicial = %d indice final = %d\n", soma, indI+1, indF+1);
	 return 0;
	}
	
	for (ii=indA; ii<N; ii++) { //vai ir somando dentro das somas dos negativos ate encontrar um positivo
		
		if (i[ii]<0) {
			somaNeg=somaNeg+i[ii];
		}
		
		if (i[ii]>0) {
			indA=ii;
			break;
		}
		
	}
	
	if (ii==N) { //nao ha nenhum numero positivo apos os numeros negativos
	 printf("Soma = %d,indice inicial = %d indice final = %d\n", soma, indI+1, indF+1);
	 return 0;
	}
	
	for (ii=indA; ii<N; ii++) { //vai ir somando dentro das somas dos positivos ate encontrar um negativo
		
		if (i[ii]>0) {
			somaPos=somaPos+i[ii];
		}
		
		if (i[ii]<0) {
			indA=ii;
			break;
		}
		
	}
	
	if (ii==N) { //nao ha nenhum numero negativo apos os numeros positivos que vem depois dos outros negativos
		if (somaNeg<somaPos) {
		soma=soma+somaNeg+somaPos;
		printf("Soma = %d,indice inicial = %d indice final = %d\n", soma, indI+1, ii+1);
	 	return 0;
		}
		
		else if (somaNeg>=somaPos) {
		printf("Soma = %d,indice inicial = %d indice final = %d\n", soma, indI+1, indF+1);
	 	return 0;	
		}
	 
	}
	
	
	
	return 0;
	
}