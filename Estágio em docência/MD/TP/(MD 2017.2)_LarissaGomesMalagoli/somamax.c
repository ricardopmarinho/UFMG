/* 
* somamax.c
* Autora: Larissa Gomes Malagoli
* Bacharelado de Ciencia da Computacao
* UFMG. 
* 
* Este software foi desenvolvido com o objetivo de cumprir a primeira questao proposta no trabalho pratico da disciplina de Matematica Discreta.
* 
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	// Variaveis utilizadas
    int *vetor;
    int tamanho, n, i=0, x=0, negativos=0, soma=0, j=0, somamax=0, a=0, b=0, segmento;  
    
	// Define o tamanho do vetor a ser tratado por uma entrada do usuario (So aceita valores entre 3 e 20)      
    printf("Digite um valor para n (Sendo 3<=n<=20): \n");
    scanf ("%d",&n);
    while(n<3 || n>20) {
      	printf("ERRO! Valor invalido, digite novamente. \n");
     	printf("Digite um valor para n (Sendo 3<=n<=20): \n");
     	scanf ("%d",&n);
    }
    // Aloca espaco na memoria para armazenar os valores
    vetor = malloc (n * sizeof (int));
    
    // Armazena cada numero fornecido pelo usuario no vetor 
    printf("Digite os n numeros inteiros, cada um separado por um espaco em branco: \n");
    for(i = 0; i < n; i++) {
    	scanf("%d", &(vetor[i]));
	}
	printf("\n\n");
	
	// Define a primeira soma como o primeiro elemento para ter um valor de comparacao
    somamax=vetor[0];
    
    // Verifica se todos os valores do vetor são negativos
	for(i=0; i<n; i++){
	    if (vetor[i]>0){
			negativos++;
	    }
	}
	// Caso não sejam, procura a maior soma
	if (negativos>0){
		// Percorre o vetor dividindo o mesmo em segmentos e compara cada segmento até encontrar a maior soma
		for ( segmento=1; segmento <= n; segmento++ )
		{
			for(i=0; i<=n-segmento; i++){
				soma=0;
				for(j=i; j<i+segmento; j++){
					soma=soma+vetor[j];
				}
			
				if (soma>somamax){
					somamax=soma;
					a=i;
					b=j;
				}
			
			}	
				
		}
		// Mostra o resultado final
		printf("Segmento de soma maxima [%d-%d] com soma %d\n", a,b,somamax);
	}
	// Caso sejam apenas valores negativos, define a soma maxima como 0 segundo as intrucoes
	else{
		somamax=0;
		printf("Todos os numeros sao negativos. Soma maxima = %d \n", somamax);
	}
  	// Libera o espaco de memoria utilizado e finaliza o programa
    free(vetor);
    system("PAUSE"); 
   	return 0;
    
    
} //end somamax.c
