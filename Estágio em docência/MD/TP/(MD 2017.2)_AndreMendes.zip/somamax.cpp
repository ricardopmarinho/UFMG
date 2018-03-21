#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int tamanho; //quantidade de numeros
	int numero; //numero a ser lido
	int soma_atual = 0; 
	int soma_max = 0;
	
	scanf("%d", &tamanho); 
	int ind_atual = 1;
	int ind_inicial = 0;
	int ind_final = 0;
	int ind_inicial_atual = 0;
	
	//laço que irá computar uma quantidade de numeros igual ao valor da variavel "tamanho"
	while(ind_atual<=tamanho){
		scanf("%d", &numero);
		if(numero>0){
			soma_atual+=numero;
			if(ind_inicial_atual==0)
				ind_inicial_atual=ind_atual;
		}
		else{
			
				if (soma_atual>soma_max){
				soma_max = soma_atual;
				ind_inicial = ind_inicial_atual;
				ind_final = ind_atual - 1;
				}
			//garante que a soma (soma_atual + numero) nao sera negativa
				if(soma_atual>abs(numero))
					soma_atual+=numero;
			
			//caso a soma (soma_atual + numero ) seja negativa, resetamos a soma e o indice, para comecarmos uma nova soma a partir do indice seguinte
				else{
				soma_atual = 0;
				ind_inicial_atual = 0;
				}
		}
	ind_atual++;
	}
	
		if (soma_atual>soma_max){
				soma_max = soma_atual;
				ind_inicial = ind_inicial_atual;
				ind_final = ind_atual - 1;
		}
				
        	printf("Soma:%d\nIndices:%d a %d\n", soma_max, ind_inicial, ind_final);
	}
	
