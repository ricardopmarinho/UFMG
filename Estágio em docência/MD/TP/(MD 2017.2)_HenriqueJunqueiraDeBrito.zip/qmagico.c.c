#include <stdio.h>
#include <stdlib.h>

troca( int *p1, int *p2 ){
	int aux;
	aux = *p2;
	*p2 = *p1;
	*p1 = aux;
	return;
}

void Ordem_Impar(int n){
	
	int c1, c2;
	int num = 1;
	int quadrado[n][n];
	
	for( c1=0; c1<n; c1++) {
		for( c2=0; c2<n; c2++ ){
			quadrado[c1][c2] = 0;
		}
	}
	
	int l, c;
	
	l = n/2;
	c = n-1;
	
	while( num <= (n*n) ){
		
		if( l == -1 && c == n ){
			l = 0;
			c = n-2;
	    }
		if( c == n ){
			c = 0;
		}  
		if( l < 0 ){
			l = n-1;
		}
		if( quadrado[l][c] ){
			c = c-2;
			l++;
			continue;
		}
		
		quadrado[l][c] = num;
		num++;
		c++;
		l--;
	}
	
	for( c1=0; c1<n; c1++) {
		for( c2=0; c2<n; c2++ ){
			if( quadrado[c1][c2] < 10 ){
				printf("%d  ", quadrado[c1][c2]);
			}else{
				printf("%d ", quadrado[c1][c2]);
			}
	    }
		printf("\n");
	}
	
	return;
}

void Ordem_Par(int n){
	
	int c1, c2;
	int num = 1;
	int quadrado[n][n];
	int a = 1;
	int aux;
	
	for( c1=0; c1<n; c1++) {
		for( c2=0; c2<n; c2++ ){
			quadrado[c1][c2] = a;
			a++;
		}
	}
	
	troca(&quadrado[0][0], &quadrado[3][3]);
	troca(&quadrado[0][3], &quadrado[3][0]);
	
	troca(&quadrado[1][1], &quadrado[2][2]);
	troca(&quadrado[2][1], &quadrado[1][2]);
	
	for( c1=0; c1<n; c1++) {
		for( c2=0; c2<n; c2++ ){
			if( quadrado[c1][c2] < 10 ){
				printf("%d  ", quadrado[c1][c2]);
			}else{
				printf("%d ", quadrado[c1][c2]);
			}
		}
		printf("\n");
	}
	
	return;
}


int main() {
	
	int n;
	
	scanf("%d", &n);
	int soma = ( n*((n*n)+1) )/2;
	
	switch (n%2){
		case 0:
			printf("n = %d, Soma = %d\n", n, soma);
			Ordem_Par(n);
			break;
		case 1:
			printf("n = %d, Soma = %d\n", n, soma);
			Ordem_Impar(n);
			break;
	}

	
	return 0;
}
