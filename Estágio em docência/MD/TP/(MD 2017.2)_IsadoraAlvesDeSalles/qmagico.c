#include <stdio.h>
#include <stdlib.h>

int main () {
	int N, L=0, C=0, i, j, soma, AuxTroca;
	printf ("n= ");
	scanf("%d", &N);			//Entrada do numero de lados do quadrado magico
	while ((N>5)||(N<3)){		//Se o numero digitado for imcompativel com os 3, 4 ou 5, esta mensagem sera gerada
		printf("Este programa gera quadrados magicos de lados 3, 4 ou 5.\nInsira o digito novamente.\n");
		printf ("n= ");
		scanf("%d", &N);
	}
	int matriz[N][N];			//Define uma matriz NxN
	soma=(N*(N*N+1))/2;			//Formula usada para o calculo da constante magica
	printf("Soma= %d\n", soma); //Imprime o valor da soma
	if ((N%2)!=0){				//Se o numero de lados for impar
		for (i=0; i<N; i++)		//Escreve 0 em cada posicao da matriz
			for (j=0; j<N; j++)
				matriz[i][j]=0;
		C=N/2;					//C, que representa as colunas, receve N/2 ou seja, trata-se da coluna do meio 
		matriz[0][C]=1;			//Inicialmente inserir 1 na posicao da coluna do meio da primeira linha
		for(i=2; i<=(N*N); i++){	//Loop em que i representa os proximos numeros a serem inseridos na matriz
			//Os proximos numeros serao sempre inseridos uma linha acima e uma coluna para frente, salvo algumas excecoes
			C++;				
			L--;
			if(C<=(N-1)){		//Se C não ultrapassar o numero de colunas 
				if (L<0) L=N-1; //e se L passa em -1 o numero de linhas, inserir o numero na ultima linha da coluna,
				else if ((L<(N-1))&&(matriz[L][C]!=0)) {C--; L+=2;} //ou se já tiver um numero no lugar, 
				//inserir o proximo uma linha abaixo do numero anterior
				matriz[L][C]=i;
			}
			else {				//Se C ultrapassa o numero de colunas
				if (L<0) {C--; L+=2;} 	//e L passa em -1 o numero de linhas, inserir o proximo uma linha abaixo do numero anterior,
				else if (L<(N-1)) C=0;	//ou se l estiver entre 0 e N-1, escrever o numero na primeira coluna
				matriz[L][C]=i;
			}
		}
	}
	else {						//Se o numero de lados for igual a 4
		for (i=0; i<N; i++)		//Escrever os numeros de 1 a 16 na matriz, em ordem crescente, da esquerda para a direita
			for (j=0; j<N; j++){
				if ((i==0)&&(j==0)) matriz[i][j]=1;
				else matriz[i][j]=matriz[i][j-1]+1;
			}
		j=N; C=N; L=N;			//Condicoes iniciais usadas para andar sobre a matriz no loop abaixo
		for (i=0; i<4; i++){	//8 numeros serao trocados de posicao
			//Em i=0 2 trocara com 15, i=1 5 trocara com 12, i=2 9 trocara com 8 e em i=3 14 trocara com 3
			if (i==1) {j--; C++;} 
			else if (i==3) {j++; C--;}
			AuxTroca=matriz[i][j-3];	//Variavel auxiliar utilizada para armazenar um valor durante a troca
			matriz[i][j-3]=matriz[L-1][C-2];
			matriz[L-1][C-2]=AuxTroca;
			L--;				//L referencia as linhas de 4 dos numeros, sendo esta decrescente da ultima a primeira linha
		}	
	}
	for (i=0; i<N; i++){		//Loop para imprimir os valores da matriz
		for (j=0; j<N; j++)
			//Se os numeros tiverem apenas um algarismo imprimir com um espaco na frente, apenas para formatacao do quadrado ficar mais legivel
			if (matriz[i][j]<10) printf(" %d ", matriz[i][j]);	
			else printf("%d ", matriz[i][j]);
		printf ("\n");			//Mudanca de linha para imprimir na saida a proxima linha do quadrado
	}
	return 0;
}
