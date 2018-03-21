#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas

typedef struct{ 	// Estrutura que armazena o valor do somatorio do intervalo
	int sum;  
} T;


//Funcoes

T** AlocaMatriz(int N){ //Aloca a memoria para a matriz
 	
 	int i, j;

 	T** matriz;
	matriz = (T**) calloc(N, sizeof(T*)); // Aloca o numero de colunas
	
	if(matriz == NULL){
		printf("Erro: memoria insuficiente\n");
	}

	for(i = 0; i < N; i++){
		matriz[i] = (T*) calloc(N, sizeof(T)); // Aloca as linhas
		if(matriz[i] == NULL){
			printf("Erro: memoria insuficiente\n");
		}
	}

	return matriz;
}

void PreencheMatriz(T** matriz, int* vetor, int N){
	int i, j;

	for (i = 0; i < N; i++){
		for(j = i; j < N; j++){
			if(i == j){ //Preenche a diagonal principal, onde os valores sao iguais
				matriz[i][j].sum = vetor[i];
			}
			else{ //Preenche a parte acima da diagonal principal e espelha para
				  //a parte de baixo
				matriz[i][j].sum = vetor[j] + matriz[i][j-1].sum;

				matriz[j][i].sum = vetor[j] + matriz[i][j-1].sum;
			}
		}
	}
}

void LiberaMemoria(T** matriz, int N){ //Desaloca a memoria ocupada pela matriz
	int i;

	for (i = 0; i < N; i++){
		free(matriz[i]);
	}
	free(matriz);
}


int main(){

	int N; // Numero de elementos do vetor
	int i, j;
	int somamax, i_final, j_final;

	if(scanf("%d", &N) == 0) {
		printf("Erro: nao foi possivel ler o valor de N\n");
	}

	int* vetor;
	vetor = (int*) calloc(N, sizeof(int)); // Alocacao do vetor de numeros

	T** matriz; // Instanciacao da matriz


	for (int i = 0; i < N; i++){ // Leitura das posicoes do vetor
		if (scanf("%d", &vetor[i]) == 0) {
			printf("Erro: Nao foi possivel ler a posicao %d do vetor\n", i+1);
		}
	}

	matriz = AlocaMatriz(N); // Alocacao da matriz

	PreencheMatriz(matriz, vetor, N); // Preenchimento da matriz com os valores
									  // lidos do vetor

	somamax = 0;
	i_final = 0;
	j_final = 0;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(somamax <= matriz[i][j].sum){
				somamax = matriz[i][j].sum;
				i_final = i + 1;
				j_final = j + 1;
			}
		}
	}


	if(i_final != 0 && j_final != 0){
		printf("Soma: %d\n", somamax);
		if(i_final > j_final)
			printf("Índices de: %d a %d\n", j_final, i_final);
		else
			printf("Índices de: %d a %d\n", i_final, j_final);
	}
	else
		printf("Soma: %d\n", somamax);

	LiberaMemoria(matriz, N);

	free(vetor);
		
	return 0;
}