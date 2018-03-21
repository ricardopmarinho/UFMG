#include <stdio.h>
#include <stdlib.h>

//Função que gera e imprime o quadrado mágico de n ímpar
void qmagico_impar (int n){ 
	int qmagico[n][n];
	int i, j, k, auxi, auxj;

//Zera o quadrado mágico
	for(i=0; i<n; i++){ 
		for(j=0; j<n; j++){
			qmagico[i][j]=0;
		}
	}
//Definição da linha e da coluna onde o numero 1 será inserido
	i=n-1;
	j=n/2;

//Define count igual a 1 para que comece a posicionar os números na matriz a partir do 1
	int count=1;

//Loop que insere os valores nas posições
	for(k=0; k<(n*n); k++){
	 	auxi=i;
	 	auxj=j;
	 	qmagico[i][j]=count;

/*Depois de determinar a posição do número 1, os números seguintes serão posicionados andando-se para a esquerda e para baixo,
ou seja, diminuindo 1 da coluna e aumentando 1 nas linhas */
	 	j--;
	 	i++;

/*Condições de saida da matriz, se o índice da linha aumentar a ponto de sair da matriz, o índice deve ser igualado a 0, isto é,
retorna à 1a linha, se o índice da coluna diminuir a ponto de sair da matriz, o indice deve ser igualado a n-1, isto é,
retorna à última coluna*/
	 	if(i>n-1){
	 		i=0;
	 	}
	 	if(j<0){
	 		j=n-1;
	 	}
/*Se na inserção dos números a posição já estiver ocupada por um valor diferente de 0, o número deverá ser inserido na mesma 
coluna, porém na linha abaixo, do número anterior*/	 	
	 	if(qmagico[i][j]!=0){
	 		i=auxi;
	 		j=auxj;
	 		i--;
	 	}
	 	count++;
	}
//Loop que imprime o quadrado mágico
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(qmagico[i][j]<10){
				printf("0%i ", qmagico[i][j]);
			}
			else{
				printf("%i ", qmagico[i][j]);
			}
		}
		printf("\n");
	}
}

//Loop que gera e imprime o quadrado mágico de n=4
void qmagico_par (int n){
	int qmagico[n][n];
	int i, j, count;

//Zera a matriz
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			qmagico[i][j]=0;
		}
	}

//Começando do número 1, insere, sequencialmente, os valores nas diagonais principal e secundária
	count=1;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==j){ //diagonal principal
				qmagico[i][j]=count;
			}
				
			if((i+j)==(n-1)){ //diagonal secundária
				qmagico[i][j]=count;
			}
						
			count++;
		}	
	}

//Começando do número 16 (n²), insere, de forma decrescente, os números onde as posicoes tem o valor 0 
	count=16;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(qmagico[i][j]==0){
				qmagico[i][j]=count;
			}
			count--;
//Imprime o quadrado mágico			
			if(qmagico[i][j]<10){
				printf("0%i ", qmagico[i][j]);
			}
			else{
				printf("%i ", qmagico[i][j]);
			}
		}
		printf("\n");
	}
}

int main(){
	int n, par_imp;

//O programa pede que seja inserido um valor entre 3 e 5
	printf("Digite um número n entre 3 e 5: ");
	scanf("%i", &n);

//Confere se o número é par, isto é, divisível por 2
	par_imp=n%2;

//Se for par, imprime o valor de n, da soma e chama a função que gera e imprime o quadrado mágico de lado 4
	if(par_imp==0){
		printf("n = %i, Soma = 34\n", n);
		qmagico_par(n);
	}
/*Se for impar, imprime o valor de n e da soma para cada caso específico (n=3 ou n=5) e chama a função que gera e imprime o quadrado 
mágico de lado ímpar*/	
	else{
		printf("n = %i, ", n);
		if(n==3){
			printf("Soma = 15\n");
		}
		else if(n==5){
			printf("Soma = 65\n");
		}
		qmagico_impar(n);
	}
	
	return 0;
}