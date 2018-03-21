#include<stdio.h>
#include<stdlib.h>

void GeraImpar(int n);
void GeraParSimples(int n1); 
void GeraParDuplo(int n1);

main(){
	//Toda explicação das partes do código estão contidas na documentação
	GeraImpar(3);
	GeraParDuplo(4);
	GeraImpar(5);
	GeraParSimples(6);
	GeraImpar(7);
	GeraParDuplo(8);
	GeraImpar(9);
	GeraParSimples(10);
	
	system("pause");
	
}

void GeraImpar(int n){
	int matriz[n][n];
	int i,j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matriz[i][j] = 0;
		}
	}
	
	matriz[0][n/2] = 1;
	int auxl = 0, auxc = n/2;
	
	for(i=2; i<=(n*n);){
		
		auxl--;
		auxc++;
		
		if(auxl < 0){
			auxl = n-1;
		}
		
		if(auxc >= n){
			auxc = 0;
		}
		
		if(matriz[auxl][auxc] == 0){
			matriz[auxl][auxc] = i;
			i++;
		}
		else{
			auxl++;
			auxc--;	
			if(auxl >= n){
				auxl = 0;
			}
		
			if(auxc < 0){
				auxc = n-1;
			}
			
			auxl++;
			if(auxl >= n){
				auxl = 0;
			}
			
			if(matriz[auxl][auxc] == 0){
				matriz[auxl][auxc] = i;
				i++;	
			}
			
		}
	}
	
	printf(" n = %d, Soma = %d\n",n, (n*(n*n + 1)/2));
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %2d",matriz[i][j]);
		}
		
		printf("\n");
	}
	printf("\n");
}

void GeraParSimples(int n1){
	int n = n1/2;
	
	int matriz1[n][n], matriz2[n][n], matriz3[n][n], matriz4[n][n];
	int aux2, aux3, aux4;
	aux2 = n * n + 1;
	aux3 = aux2 + n*n;
	aux4 = aux3 + n*n;;
	int i,j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matriz1[i][j] = 0;
			matriz2[i][j] = 0;
			matriz3[i][j] = 0;
			matriz4[i][j] = 0;
		}
	}
	
	matriz1[0][n/2] = 1;
	matriz2[0][n/2] = aux2;
	matriz3[0][n/2] = aux3;
	matriz4[0][n/2] = aux4;
	aux2++; aux3++; aux4++;

	int auxl = 0, auxc = n/2;
	
	for(i=2; i<=(n*n);){
		
		auxl--;
		auxc++;
		
		if(auxl < 0){
			auxl = n-1;
		}
		
		if(auxc >= n){
			auxc = 0;
		}
		
		if(matriz1[auxl][auxc] == 0){
			matriz1[auxl][auxc] = i;
			matriz2[auxl][auxc] = aux2;
			matriz3[auxl][auxc] = aux3;
			matriz4[auxl][auxc] = aux4;
			aux2++; aux3++; aux4++; i++;
		}
		else{
			auxl++;
			auxc--;	
			if(auxl >= n){
				auxl = 0;
			}
		
			if(auxc < 0){
				auxc = n-1;
			}
			
			auxl++;
			if(auxl >= n){
				auxl = 0;
			}
			
			if(matriz1[auxl][auxc] == 0){
				matriz1[auxl][auxc] = i;
				matriz2[auxl][auxc] = aux2;
				matriz3[auxl][auxc] = aux3;
				matriz4[auxl][auxc] = aux4;
				aux2++; aux3++; aux4++; i++;
					
			}
		}
	
	
	}
	
	if(n1 == 6){
		int seguro = matriz1[0][0];
		matriz1[0][0] = matriz4[0][0]; matriz4[0][0] = seguro;
		
		seguro = matriz1[1][1];
		matriz1[1][1] = matriz4[1][1]; matriz4[1][1] = seguro;
		
		seguro = matriz1[2][0];
		matriz1[2][0] = matriz4[2][0]; matriz4[2][0] = seguro;
	}
	
	else{
		int aa = n1/4;
		int x1, x2;
		
		//Mudança das colunas finais da matriz
		for(x1 = 0; x1<n1/2; x1++){
			for(x2 =(n1/2) - (aa-1); x2<n1/2; x2++){
				int seguro = matriz3[x1][x2];
				matriz3[x1][x2] = matriz2[x1][x2];
				matriz2[x1][x2] = seguro;
			}
		}
		
		//Troca de valores entre duas matrizes antes da linha/coluna média 
		for(x1=0; x1<aa; x1++){
			for(x2=0; x2<aa; x2++){
				int seguro = matriz1[x1][x2];
				matriz1[x1][x2] = matriz4[x1][x2];
				matriz4[x1][x2] = seguro;
			}
		}
		
		//Troca de valores entre duas matrizes, linha/coluna média
		for(x1 = 1; x1<=aa; x1++){
			int seguro = matriz1[aa][x1];
			matriz1[aa][x1] = matriz4[aa][x1];
			matriz4[aa][x1] = seguro;
		}
		
		//Troca de valores entre duas matrizes depois da linha/coluna média 
		int bb = aa*2 + 1;
		for(x1 = aa+1; x1<bb; x1++){
			for(x2=0; x2<aa; x2++){
				int seguro = matriz1[x1][x2];
				matriz1[x1][x2] = matriz4[x1][x2];
				matriz4[x1][x2] = seguro;
				
			}
		}
		
		
	}

	printf(" n = %d, Soma = %d\n",n1, (n1*(n1*n1 + 1)/2));
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %2d",matriz1[i][j]);
		}
		
		for(j=0; j<n; j++){
			printf(" %2d",matriz3[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %2d",matriz4[i][j]);
		}
		
		for(j=0; j<n; j++){
			printf(" %2d",matriz2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void GeraParDuplo(int n1){
	int vet[n1*n1];
	int i,j,cont=0;
	int lado = n1/4;
	int matriz[n1][n1];
	
	for(i=0; i<n1*n1; i++){
		vet[i] = i+1;
	}
	
	for(i=0; i<n1; i++){
		for(j=0; j<n1; j++){
			matriz[i][j] = 0;
		}
	}
	
	for(i=0; i<n1; i++){
		for(j=0; j<n1; j++){
			if( (i<lado )|| (((n1-1) - i) < lado)) {
				if( (j<lado )|| (((n1-1) - j) < lado)) {
					matriz[i][j] = vet[cont];
				}	
			}
			
			if((i>=lado) && (j>=lado)){
				if((i< (n1-lado)) && (j<(n1-lado))){
					matriz[i][j] = vet[cont];
				}
			}
			cont++;
		}
	}
	
	cont--;
	for(i=0; i<n1; i++){
		for(j=0; j<n1; j++){
			if(matriz[i][j] == 0){
				matriz[i][j] = vet[cont];
			}
			
			cont--;
		}
	}
	
	printf(" n = %d, Soma = %d\n",n1, (n1*(n1*n1 + 1)/2));
	for(i=0; i<n1; i++){
		for(j=0; j<n1; j++){
			printf(" %2d",matriz[i][j]);
		}
		
		printf("\n");
	}
	printf("\n");
}
