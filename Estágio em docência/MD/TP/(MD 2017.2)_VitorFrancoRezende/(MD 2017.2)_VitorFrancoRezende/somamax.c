#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{	
	int N, i, k, j, soma = 0, maior = 0, indices[2] = {0,0};
	printf("Digite o tamanho do seu vetor de 3 a 20 numeros:\n");
	do // laço que avalia se a entrada do programa e válida ou não no caso 3 =< N <=20
	{	
	scanf("%d", &N);
    	if(N < 3 || N > 20)
    	{
    		printf("Entrada Invalida!\n");
			printf("Digite o tamanho do seu vetor novamente:\n");		
    	}

	} while(!(N >= 3 && N <= 20));
		
	int quantNumeros[N];
	printf("Digite os componentes do seu vetor:\n");	
	for (i = 0; i < N; ++i) // Laço que insere os números da entrada dentro do arranjo quantNumeros.
	{
		scanf("%d", &quantNumeros[i]);
	}
	for (i = 0; i < N; ++i) // Laço principal que itera pelos n tamanhos diferentes de subvetores.
		{
			for (j = 0; j < (N-i); ++j) // Laço que identifica como será analisado um subvetor 1 em 1, 2 em 2. n em n, identifica a posição inicial do subvetor
			{	
				soma = 0; // zera a variável soma para não acumular os valores a cada iteração.
				for (k = 0; k < (i+1); ++k) //Laço que identifica a posição inicial do subvetor e realiza a soma de cada posição do subvetor.
				{
					soma += quantNumeros[j+k]; // soma dos elementos do subvetor.
					if (soma > maior) // condicional que analisa os resultados a cada iteração.
					{
						maior = soma;
						indices[0] = j;
						indices[1] = j+k;
					} 
				}
			}
		}
	printf("Soma: %d\n", maior);		
	if (maior > 0)
        {
            printf("Indices: %d a %d\n", indices[0]+1, indices[1]+1);
        }
        else printf("Indices: %d a %d\n", indices[0], indices[1]);

	system("pause");
	return 0;
}
