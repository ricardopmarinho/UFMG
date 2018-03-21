#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) //implementa a macro que retorna o valor maximo entre a e b.

int somaMaxima(int n, int a[]);

int main(void){
	int n, max, i = 0;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int a[n];
	printf("Digite os valores do vetor: ");
	while(i < n){ //armazena os valores no vetor.
		scanf("%d", &a[i]);
		i++;
	}
	max = somaMaxima(n, a);
	return 0;
}

int somaMaxima(int n, int a[]){
	int maximo_global, maximo_atual, i = 1, j = 0;
	int test = 1, comeco, fim, c = 0;
	maximo_global = a[0];
	maximo_atual = a[0];
	for(; j < n; j++){ //verifica se todos os numeros sao negativos.
		if(a[j] > 0) test = 0;
	}
	if (test){
		printf("Soma: 0\n");
		printf("Indices: 1 a %d\n", n);
		return 0;
	}
	for(; i < n; i++ ){
		maximo_atual = MAX(a[i], maximo_atual + a[i]);
		if (maximo_atual > maximo_global){
			maximo_global = maximo_atual;
			comeco = c;
			fim = i;
		}
		if(maximo_atual < 0){
			maximo_atual = 0;
			c = i+1;
		}
	}
	printf("Soma: %d\n", maximo_global);
	printf("Indices: %d a %d\n", comeco+1, fim+1);
	return maximo_global;
}
