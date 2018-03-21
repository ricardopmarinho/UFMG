#include<stdlib.h>
#include<stdio.h>

int main (){

int N;
int dd, jj, ii;
int da, ja;
int cm_imp; //constante magica impar
int aa, bb;

printf("Informe o valor inteiro entre 3 e 5 do lado do quadrado:\n");
scanf("%d", &N);

int quadrado[N][N];
cm_imp= (N*((N*N)+1))/2;

	if (N%2==1) { //vai fazer so para os numeros impares
	
	//	printf("n= %d, Soma = %d\n", N, cm_imp);
	
			for (dd=0; dd<N; dd++) { //vai zerar todas as posicoes
				for (jj=0; jj<N; jj++) {
					
					quadrado[dd][jj] = 0;
				//	printf("%d ", quadrado[dd][jj]);				
				}
				//printf("\n");	
			}// printf("\n");
		
		jj=(N/2); //vai calcular a posicao do meio da primeira linha
		dd=0;
	
		quadrado[dd][jj]=1;
		
				
	
	
		for(ii=2; ii<(N*N)+1; ii++) { //vai colocar os numeros nas posicoes
			da=dd; //salvando a posicao dd atual para quando for necessario voltar a ela
			ja=jj; //salvando a posicao jj atual para quando for necessario voltar a ela
			dd=dd-1; //vai "andar" pra posicao de cima
			jj=jj+1; // vai "andar" pra posicao da direita
			
			if (dd==(-1)) { //se dd ficar negativo, estara indo pra uma linha acima da primeira
				dd=(N-1); //entao na verdade tem q ir para ultima linha = N-1
			}
			
			if (jj==N) { //se jj for igual a N, estara indo pra uma coluna a direita da ultima, que nao existe
				jj=0; //entao na vdd devera ir para a primeira coluna = 0;
			}
			
			if (quadrado[dd][jj]==0) { //se a posicao for 0, quer dizer que ainda nao foi preenchida, entao o numero pode ser colocado la
				quadrado[dd][jj]=ii;
					
			} 
			
			else if (quadrado[dd][jj]!=0) { //se a posicao for diferente de 0, ela ja foi preenchida
			     dd=da+1; //o numero ficara em baixo do numero anterior, cuja posicao estava salva em da e ja
			     jj=ja;
			     if (dd==N) { //se dd for igual a N, estara indo pra uma linha abaixo da ultima
					dd=0; //entao na verdade tem q ir para a primeira linha N=0
				}
				
				 quadrado[dd][jj]=ii;
			}
			
			    	
		}
	printf("Soma= %d\n", cm_imp);
		for (aa=0; aa<N; aa++) { //teste do print
					for (bb=0; bb<N; bb++) {

						printf("%d ", quadrado[aa][bb]);				
					}
				printf("\n");	
		}printf("\n");
		
	}  //fim do if impar
	
	
	
	else if (N%4==0) { //vai fazer para os quadrados pares duplos (lados divisiveis por quatro)
	
	
			for (dd=0; dd<N; dd++) { //vai zerar todas as posicoes
				for (jj=0; jj<N; jj++) {
					
					quadrado[dd][jj] = 0;
				//	printf("%d ", quadrado[dd][jj]);				
				}
			//	printf("\n");	
			} //printf("\n");
		
	
		//criar os realces a,b,c,d;
		//int a[N/4][N/4];
			
			//preencher o realce central a com o valor: -1
		for (dd=0; dd<N/4; dd++) { //colocando -1 no realce a (canto superior esquerdo)
			for (jj=0; jj<N/4; jj++) {
				quadrado[dd][jj] = -1;
			}
		}	
		
		for (dd=0; dd<N/4; dd++) { //colocando -1 no realce b (canto superior direito)
			for (jj=3*(N/4); jj<N; jj++) {
				quadrado[dd][jj] = -1;
			}
		}
		
		for (dd=3*(N/4); dd<N; dd++) { //colocando -1 no realce c (canto inferior esquerdo)
			for (jj=0; jj<N/4; jj++) {
				quadrado[dd][jj] = -1;
			}
		}
		
		for(dd=3*(N/4); dd<N; dd++) { //colocando -1 no realce d (canto inferior direito)
			for (jj=3*(N/4); jj<N; jj++) {
				quadrado[dd][jj] = -1;
			}
		}
		
		//criar o realce central
		
		for(dd=N/4; dd<(N-(N/4)); dd++) { //colocando -1 no realce central
			for(jj=N/4; jj<(N-(N/4)); jj++) {
				quadrado[dd][jj] = -1;
			}
		}
		
		
	
	
		ii=1;
			for(dd=0; dd<N; dd++) {
				for(jj=0; jj<N; jj++) {
					if (quadrado[dd][jj]==-1) {
						quadrado[dd][jj]=ii;
					}
					
					ii++;
					
				}
			}
			
		ii=1;
			for(dd=N-1; dd>-1; dd--) {
				for(jj=N-1; jj>-1; jj--) {
					if (quadrado[dd][jj]==0) {
						quadrado[dd][jj]=ii;
					}
					
					ii++;
					
				}
			}	

		
		printf("Soma= %d\n", cm_imp);
			for (aa=0; aa<N; aa++) { //teste do print
					for (bb=0; bb<N; bb++) {

						printf("%d ", quadrado[aa][bb]);				
					}
				printf("\n");	
		}printf("\n");

	
	
	}  //fim do if quadrado duplo
		
		
		
	
	





return 0;
}