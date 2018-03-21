#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int n, i, j;
	int max_parcial = 0, max_soma = 0; 
	int indice_menor, indice_maior;

	scanf("%d", &n); //define o valor de n;
	int vetor[n];

	for(i = 0; i < n; i++) //lê as n posições do vetor;
	{
		scanf("%d", &vetor[i]);
	}

	for(i = 0; i < n; i++) //percorre o vetor a partir de cada posição;
	{
		if(max_soma < vetor[i]) //se o valor armazenado em vetor[i] for maior do que a soma máxima, ele passa a ser a soma máxima;
		{
			max_soma = vetor[i];
			indice_menor = indice_maior = i + 1;
		}

		max_parcial = vetor[i]; //antes de percorrer o vetor, é definido o máximo parcial como o valor de vetor[i], a partir do qual serão somados os valores seguintes do vetor;

		for(j = i + 1; j < n; j++) //percorre as posições restantes do vetor a partir da posição definida pela soma parcial;
		{
			max_parcial += vetor[j]; //a soma parcial é acrescida do valor de vetor[j];

			if(max_soma < max_parcial)
			{
				max_soma = max_parcial;
				indice_menor = i + 1;
				indice_maior = j + 1;
			}
		}
	}

	printf ("Soma: %d\n", max_soma);
	printf ("Índices: %d a %d\n", indice_menor, indice_maior);

	return 0;
}
