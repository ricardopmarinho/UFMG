/* 
* qmagico.c
* Autora: Larissa Gomes Malagoli
* Bacharelado de Ciencia da Computacao
* UFMG. 
* 
* Este software foi desenvolvido com o objetivo de cumprir a segunda questao proposta no trabalho pratico da disciplina de Matematica Discreta.
* 
*/

#include <stdio.h>
#include <stdlib.h>

// Funcao que calcula quadrados magicos para Matrizes da forma nxn sendo n ímpar.
void matrizimpar(int l, int c) {
    // Variaveis
    int matriz[l][c];
    int aux, n, i=0, j=0, kmagica, coluna, linha, lantiga, cantiga;  
    // Em todo Quadrado Mágico Elementar do tipo n×n o resultado constante das somas de cada linha, cada coluna ou de cada diagonal é sempre (n*(n^2+1))/2. -> n=numero de lados
    //Elemento central: n^2+1/2
        
        
    // Preenche a matriz com 0
    for (i=0; i<l; i++){
			for(j=0; j<c; j++){
		
				matriz[i][j]=0;
			}
		
	}
    n=l;
    // Calcula a constante magica pela formula
    kmagica=((n)*((n*n)+1))/2;  
    // Define a posicao do primeiro valor
	matriz[0][n/2]=1; 
	linha=0;
	coluna=n/2;
	// Guarda as posicoes
	lantiga=linha;
    cantiga=coluna;
    
	// Percorre a matriz preenchendo-a com valores de 2 a n^2		
	for (aux=2; aux<((n*n)+1); aux++) {
		// Usa o padrao de preenchimento subindo uma linha e depois se movendo uma coluna a direita
		linha=linha-1;
		coluna=coluna+1;
		// Reseta as colunas e linhas se elas ultrapassarem os valores limites da matriz
		if (linha<0) {
				linha=l-1;
		}
		if (coluna>c-1) {
				coluna=0;
		}
		// Confere se a posicao já não foi ocupada
		if (matriz[linha][coluna]==0){
			// Reseta as colunas e linhas se elas ultrapassarem os valores limites da matriz
			if (linha<0) {
				linha=l-1;
			}
			if (coluna>c-1) {
				coluna=0;
			}
		    // Preenche a posicao com um dos valores de 2 a n^2
			matriz[linha][coluna]=aux;
			// Guarda as posicoes
			lantiga=linha;
			cantiga=coluna;
			
		}
		else{
			
			// Passa para a proxima posicao valida e preenche com um dos valores de 2 a n^2
		    linha=lantiga+1;
		    coluna=cantiga;
		     
			if (linha<0) {
				linha=l-1;
			}
			matriz[linha][coluna]=aux;
		}
		
	} // end for
	
	// Mostra a matriz (Quadrado Magico) na tela e sua constante magica
	printf ("\n\n");
	printf ("n=  %d      Constante magica = %d   ", n, kmagica);
	printf ("\n");
	for (i=0; i<l; i++){
			for(j=0; j<c; j++){
		
				printf ("%2d   ", matriz[i][j]);
				//printf ("  ");
			}
			printf ("\n");
	}
	printf ("\n");
	printf ("\n");
} // end matrizimpar

// Funcao que calcula quadrados magicos para Matrizes da forma nxn sendo n da forma multiplo de 4x4 (Ex: 4x4, 8x8, 12x12).
void matrizpardupla(int l, int c) {
    // Variaveis
    int matriz[l][c];
    int vetor[100];
    int aux, n, i=0, x=0, j=0, kmagica, coluna, linha, lantiga, cantiga, realce, realcecentral;  
    // Em todo Quadrado Mágico Elementar do tipo n×n o resultado constante das somas de cada linha, cada coluna ou de cada diagonal é sempre (n*(n^2+1))/2. -> n=numero de lados
    //Elemento central: n^2+1/2
        
        
    // Preenche a matriz com 0
    for (i=0; i<l; i++){
			for(j=0; j<c; j++){
		
				matriz[i][j]=0;
			}
		
	}
    n=l;
    // Calcula a constante magica pela formula
    kmagica=((n)*((n*n)+1))/2;  

    // Define os realces laterais do quadrado
	realce=c/4;
	// Define o realce central do quadrado
	realcecentral=c/2;
	aux=1;

	// Preenche cada realce com os valores em ordem crescente a partir da posicao [0][0]
	for (linha=0; linha<l; linha++){
		for(coluna=0; coluna<c; coluna++){	
		
		// Realce A
		if (linha<realce && coluna<realce){
			matriz[linha][coluna]=aux;
		
			
		}
		else{
			// Realce B
			if (linha<(realce) && coluna>(realce+realcecentral-1)){
				matriz[linha][coluna]=aux;
					
			}
			else{
				// Realce C
				if (linha>(realce+realcecentral-1) && coluna<(realce)){
					matriz[linha][coluna]=aux;	
					
				}
				else{
					// Realce D
					if (linha>(realce+realcecentral-1) && coluna>(realce+realcecentral-1)){
						matriz[linha][coluna]=aux;	
						
					}
					else{
						//Realce Central
						if (linha>(realce-1) && coluna>(realce-1) && linha<(realce+realcecentral) && coluna<(realce+realcecentral)){
							matriz[linha][coluna]=aux;	
							
						}
						else{
							// Salva os valores não utilizados para preencher o restante do quadrado
							vetor[x]=aux;
							x++;
						}
							
					}
				}
			}
			
		}
		
		aux++;
		}
	} 
	// Preencher o restante das casas (Fora dos realces)
	// Volta para a última posicao do vetor
	x--;
	// Preenche apenas as casas que ainda não foram utilizadas (Possuem valor 0)
	for (linha=0; linha<l; linha++){
		
		for(coluna=0; coluna<c; coluna++){	
		    	
			if(matriz[linha][coluna]==0){
				matriz[linha][coluna]=vetor[x];
				x--;
			}
		
		}
	}
	

	// Mostra a matriz (Quadrado Magico) na tela e sua constante magica
	printf ("\n\n");
	printf ("n=  %d      Constante magica = %d   ", n, kmagica);
	printf ("\n");
	for (i=0; i<l; i++){
			for(j=0; j<c; j++){
		
				printf ("%2d   ", matriz[i][j]);
			}
			printf ("\n");
	}
	printf ("\n");
	printf ("\n");
	
} // end matrizpardupla


// Funcao que calcula quadrados magicos para Matrizes da forma nxn sendo n os pares restantes
void matrizpar(int l, int c) {
    // Variáveis    
    int matriz[l][c];
    int aux, n, i=0, j=0, kmagica, coluna, linha, lantiga, cantiga, lquadrante, quarto, limite, limiteanterior, x;  
    // Em todo Quadrado Mágico Elementar do tipo n×n o resultado constante das somas de cada linha, cada coluna ou de cada diagonal é sempre (n*(n^2+1))/2. -> n=numero de lados
    //Elemento central: n^2+1/2
       
    // Preenche a matriz com 0    
    for (i=0; i<l; i++){
			for(j=0; j<c; j++){
		
				matriz[i][j]=0;
			}
		
	}
	

    n=l;
    // Calcula a constante magica pela formula
    kmagica=((n)*((n*n)+1))/2;  

	// Divide a matriz em 4 partes com lado n/2 cada
	lquadrante=n/2;
	quarto=(n*n)/4;

	// Primeiro quarto
	// Resolucao de quadrado magico impar nas posicoes 0 a 4 (linhas) e 0 a 4 (colunas)
		limite=quarto+1;
		matriz[0][lquadrante/2]=1; 
		linha=0;
		coluna=lquadrante/2;
		lantiga=linha;
		cantiga=coluna;
		
		for (aux=2; aux<(limite); aux++) {
		
		linha=linha-1;
		coluna=coluna+1;
		if (linha<0) {
				linha=lquadrante-1;
		}
		if (coluna>lquadrante-1) {
				coluna=0;
		}
		
		if (matriz[linha][coluna]==0){
			
			if (linha<0) {
				linha=lquadrante-1;
			}
			if (coluna>lquadrante-1) {
				coluna=0;
			}
		    
			matriz[linha][coluna]=aux;
			lantiga=linha;
			cantiga=coluna;
			
		}
		else{
			
			
		    linha=lantiga+1;
		    coluna=cantiga;
		     
			if (linha<0) {
				linha=lquadrante-1;
			}
			matriz[linha][coluna]=aux;
		}
		
	}
		// Segundo quarto
		// Resolucao de quadrado magico impar nas posicoes 5 a 9 (linhas) e 5 a 9 (colunas)
	    limiteanterior=limite;
		limite=(quarto*2)+1;

		linha=0+lquadrante;
		coluna=(lquadrante/2)+lquadrante;
	    matriz[linha][coluna]=limiteanterior; 
		lantiga=linha;
		cantiga=coluna;
		
		for (aux=limiteanterior+1; aux<(limite); aux++) {
		
		linha=linha-1;
		coluna=coluna+1;
		if (linha<0+lquadrante) {
				linha=lquadrante-1+lquadrante;
		}
		if (coluna>lquadrante-1+lquadrante) {
				coluna=0+lquadrante;
		}
		
		if (matriz[linha][coluna]==0){
			
			if (linha<0+lquadrante) {
				linha=lquadrante-1+lquadrante;
			}
			if (coluna>lquadrante-1+lquadrante) {
				coluna=0+lquadrante;
			}
		    
			matriz[linha][coluna]=aux;
			lantiga=linha;
			cantiga=coluna;
			
		}
		else{
			
			
		    linha=lantiga+1;
		    coluna=cantiga;
		     
			if (linha<0+lquadrante) {
				linha=lquadrante-1+lquadrante;
			}
			matriz[linha][coluna]=aux;
		}
		
	}


	// Terceiro quarto
	// Resolucao de quadrado magico impar nas posicoes 0 a 4 (linhas) e 5 a 9 (colunas)
	    limiteanterior=limite;
		limite=(quarto*3)+1;

		linha=0;
		coluna=(lquadrante/2)+lquadrante;
	    matriz[linha][coluna]=limiteanterior; 
		lantiga=linha;
		cantiga=coluna;
		
		for (aux=limiteanterior+1; aux<(limite); aux++) {
		
		linha=linha-1;
		coluna=coluna+1;
		if (linha<0) {
				linha=lquadrante-1;
		}
		if (coluna>lquadrante-1+lquadrante) {
				coluna=0+lquadrante;
		}
		
		if (matriz[linha][coluna]==0){
			
			if (linha<0) {
				linha=lquadrante-1;
			}
			if (coluna>lquadrante-1+lquadrante) {
				coluna=0+lquadrante;
			}
		    
			matriz[linha][coluna]=aux;
			lantiga=linha;
			cantiga=coluna;
			
		}
		else{
			
			
		    linha=lantiga+1;
		    coluna=cantiga;
		     
			if (linha<0) {
				linha=lquadrante-1;
			}
			matriz[linha][coluna]=aux;
		}
		
	}

    
	
    // Quarto quarto
	// Resolucao de quadrado magico impar nas posicoes 5 a 9 (linhas) e 0 a 4 (colunas)		
	    limiteanterior=limite;
		limite=(quarto*4)+1;
		
		linha=0+lquadrante;
		coluna=lquadrante/2; 
	    matriz[linha][coluna]=limiteanterior; 
		lantiga=linha;
		cantiga=coluna;
		
		for (aux=limiteanterior+1; aux<(limite); aux++) {
		
		linha=linha-1;
		coluna=coluna+1;
		if (linha<0+lquadrante) {
				linha=lquadrante-1+lquadrante;
		}
		if (coluna>lquadrante-1) {
				coluna=0;
		}
		
		if (matriz[linha][coluna]==0){
			
			if (linha<0+lquadrante) {
				linha=lquadrante-1+lquadrante;
			}
			if (coluna>lquadrante-1) {
				coluna=0;
			}
		    
			matriz[linha][coluna]=aux;
			lantiga=linha;
			cantiga=coluna;
			
		}
		else{
			
			
		    linha=lantiga+1;
		    coluna=cantiga;
		     
			if (linha<0+lquadrante) {
				linha=lquadrante-1+lquadrante;
			}
			matriz[linha][coluna]=aux;
		}
		
	}


    // Resolvendo os Realces
    // Usando a troca de realces para matriz 6x6
  	// Cada realce em uma matriz 6x6 é apenas uma posição, logo é só executar as trocas
    if (l==6) {
    	
    	// Trocando o Realce A1 com D1
    	aux=matriz[0][0];
    	matriz[0][0]=matriz[3][0];
    	matriz[3][0]=aux;
    	
    	// Trocando o Realce A2 com D2
    	aux=matriz[1][1];
    	matriz[1][1]=matriz[4][1];
    	matriz[4][1]=aux;
    	
    	// Trocando o Realce A3 com D3
    	aux=matriz[2][0];
    	matriz[2][0]=matriz[5][0];
    	matriz[5][0]=aux;
    	
	}

	// Usando a troca de realces para matriz 10x10
	/* Em uma matriz 10x10 existem 4 realces, sendo os realces A e D localizados nas primeiras duas colunas e os realces B e C na ultima coluna. 
	   Assim, troca-se as posições do realce A (Até a linha 4, excluindo a posição [2][0]) com as posiçoes de D (de 5 a 9). O mesmo ocorre para B e C. 
	*/
    if (l==10) {
    	
    	for (aux=0; aux<5; aux++){
    	
    		// Trocando o Realce A com D
    		if (aux!=2){
			
    			x=matriz[aux][0];
    			matriz[aux][0]=matriz[aux+5][0];
    			matriz[aux+5][0]=x;
    		}
    		else{
    			// Trocando as posições [2][2] do realce A com [7][2] do realce D
    			x=matriz[aux][2];
    			matriz[aux][2]=matriz[aux+5][2];
    			matriz[aux+5][2]=x;
			}
    		x=matriz[aux][1];
    		matriz[aux][1]=matriz[aux+5][1];
    		matriz[aux+5][1]=x;
    		
    		// Trocando o Realce B com C
    		
    		x=matriz[aux][9];
    		matriz[aux][9]=matriz[aux+5][9];
    		matriz[aux+5][9]=x;
		}
    	
	} 



    // Imprimir a matriz final	
	printf ("\n\n");	
	printf ("n=%d     Constante magica = %d   ", n, kmagica);
	printf ("\n");
	for (i=0; i<l; i++){
			for(j=0; j<c; j++){
		
				printf ("%3d     ", matriz[i][j]);
			}
			printf ("\n");
	}

	printf ("\n");
	printf ("\n");
} //end matrizpar()


int main(int argc, char *argv[]) {
	
        // Executa as funcoes apropriadas para gerar quadrados magicos de 3 a 10
		
        matrizimpar(3,3);
     	printf ("\n");
	    matrizpardupla(4,4);
        printf ("\n");
        matrizimpar(5,5);
        printf ("\n");
        matrizpar(6,6);
        printf ("\n");
        matrizimpar(7,7);
        printf ("\n");
        matrizpardupla(8,8);
        printf ("\n");
        matrizimpar(9,9);
        printf ("\n");
        matrizpar(10,10);
       
       //
	// Finaliza o programa
    system("PAUSE"); 
   	return 0;
    
    
}
