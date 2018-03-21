#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//Variaveis globais

int vetor[25], n;
int usados[26];
int lim;
int grid[26][26];
int soma;
int japrintou;


//Funcoes

int testa_coluna(){ // retorna 0 se a solucao nao e valida, 
					// ou a soma de uma coluna
	int i, j;
	int s = -1; //soma da coluna
	for(i = 0; i < n; i++){
		int aux = 0;
		for(j = 0; j < n; j++){
			aux += grid[j][i];
		}
		if(s == -1) 
			s = aux;
		if(aux != s) 
			return 0;
	}
	return s;
}

int testa_linha(){
	int i, j;
	int s = -1;
	for(i = 0; i < n; i++){
		int aux = 0;
		for(j = 0; j < n; j++){
			aux += grid[i][j];
		}
		if(s == -1) 
			s = aux;
		if(aux != s) 
			return 0;
	}
	return s;
}

int testa_diag(){
	int i, j;
	int soma_pri = 0;
	for(i = 0; i < n; i++) 
		soma_pri +=  grid[i][i];

	int soma_sec = 0;
	for(i = 0; i < n; i++) 
		soma_sec += grid[i][n-1-i];

	if(soma_pri != soma_sec) 
		return 0;
	return soma_pri;
}

void printa(){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d\t", grid[i][j]);
		}
		puts("");
	}
	puts("");
	japrintou = 1;
}

void testa(){
	int x = testa_coluna();
	int y = testa_diag();
	int z = testa_linha();
	if(x + y + z > 0  && x == y && x == z)
		printa();
}

void forca_bruta(int i){
	int j;
	if(japrintou) 
		return;

	if(i > 0){ //para nao sair da matriz
		int aux = 0;
		for(j = 0; j <= (i - 1) % n; j++) 
			aux += vetor[i - j - 1];
		if(aux > soma) 
			return;
	}

	if(i == lim){
		int i;
		for(i = 0; i < lim; i++) {
			grid[i/3][i%3] = vetor[i];
		}
		testa();
		return;
	}

	for(j = 1; j <= lim; j++){
		if(!usados[j]){
			vetor[i] = j;
			usados[j] = 1;
			forca_bruta(i + 1);
			usados[j] = 0;
		}
	}
}

int dx = -1; //vetor de deslocamento
int dy = 1;

void q_sequencial(){
	int i;
	int x0 = 0, y0 = n/2;
	for(i = 1; i <= lim; i++){
		if(grid[x0][y0]){
			x0 -= dx;
			y0 -= dy;
			x0++;
			x0 = (x0+n)%n;
			y0 = (y0+n)%n;
			grid[x0][y0] = i;
		}
		else
			grid[x0][y0] = i;
		
		x0 = x0 + dx;
		y0 = y0 + dy;
		x0 = (x0+n)%n;
		y0 = (y0+n)%n;
	}
	testa();
}


int main(){

	if(scanf("%d", &n) == 0) {
		printf("Erro: nao foi possivel ler o valor de N\n");
	}
	lim = n*n;
	soma = (n + n*n*n)/2;
	if(n % 2 == 0){
		forca_bruta(0);
	}
	else{
		q_sequencial();
	}

	return 0;
}
