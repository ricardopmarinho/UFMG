#include <stdio.h>
#include <string.h>

void geraQuadrados(int n); 

int main(){
	int n, soma;
	printf("Digite o tamanho da matriz quadrada: ");
	scanf("%d", &n); //tamanho da matriz quadrada
	soma = n *((n*n)+1)/2; //formula da soma do quadrado mágico
	printf("n = %d, Soma = %d\n", n, soma);
	geraQuadrados(n);
	return 0;
}

void geraQuadrados(int n){
	int matriz[n][n];
	if(n % 2 != 0){ //solucao para matrizes impares
		memset(matriz, 0, sizeof(matriz)); //zera todas as posições
		int i = n/2; //posicao inicial de i
		int j = n-1;
		for(int num = 1; num <= n*n;){
			if(i == -1 && j == n){ //condiçao 3
				i = 0;
				j = n-2;
			}
			else{ //condiçao 1
				if(j == n) j = 0;
				if(i < 0) i = n-1;
			}
			if(matriz[i][j]){ //condiçao 2
				i++;
				j -= 2;
				continue;
			}
			else{
				matriz[i][j] = num++; //coloca o valor na matriz
			}
			i--; //condiçao 1
			j++;
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++) printf("%3d ", matriz[i][j]);
			printf("\n");
		}
	}
	else{ //para resolver uma matriz de par duplo(e.g. 4, 8, 12..), dividir a matriz em quadrados de lado n/4 nos cantos,
	      //depois dividir o centro num quadrado maior de lado n/2.
	      //mudar os valores dos quadrados no canto, com a regra (n*n+1)-matriz[i][j]. 
		int i, j, k = 1;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++, k++) matriz[i][j] = k; //preenche a matriz com numeros de 1 a n^2 nessa ordem
		//canto superior esquerdo ordem (n/4)
		for(i = 0; i < n/4; i++){
			for(j = 0; j < n/4; j++) matriz[i][j] = (n*n+1)-matriz[i][j];
		}
		//canto superior direito ordem (n/4)
		for(i = 0; i < n/4; i++){
			for(j = 3*(n/4); j < n; j++) matriz[i][j] = (n*n+1) - matriz[i][j];
		}
		//canto inferior esquerdo ordem (n/4)
		for(i = 3*(n/4); i < n; i++){
			for(j = 0; j < n/4; j++) matriz[i][j] = (n*n+1) - matriz[i][j];
		}
		//canto inferior direito ordem (n/4)
		for(i = 3*(n/4); i < n; i++){
			for(j = 3*(n/4); j < n; j++) matriz[i][j] = (n*n+1) - matriz[i][j];
		}
		//centro da matriz ordem (n/2)
		for(i = n/4; i < 3* n/4; i++){
			for(j = n/4; j < 3* n/4; j++) matriz[i][j] = (n*n+1) - matriz[i][j];
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++) printf("%3d ", matriz[i][j]);
			printf("\n");
		}

	}

}
