#include <stdio.h>
#include <stdlib.h>

void quadrado_impar(int n)
{
	int i, j, k;
	int auxi = 0, auxj = n/2;
	int contagem;
	int quadrado[n][n];

	for(i = 0; i < n; i++) //laço para definir todas as posições do quadrado como zero;
	{
		for(j = 0; j < n; j++)
		{
			quadrado[i][j] = 0;
		}
	}

	i = 0;
	j = 1;

	quadrado[0][n/2] = 1; //o percurso começa na posição central da primeira linha;

	if(n == 3) //define quantos números serão colocados no quadrado, variando conforme o tamanho do lado;
		k = 10;
	else
		k = 26;

	for(contagem = 2; contagem < k; contagem++)
	{
		auxi -= 1; //sempre uma linha para cima, e uma coluna para a direita;
		auxj += 1;

		if(auxi < 0) //caso extrapole o limite das linhas;
			auxi = n - 1;

		if(auxj > n - 1) //caso extrapole o limite das colunas;
			auxj = 0;

		if(quadrado[auxi][auxj]) //caso a posição já esteja ocupada;
		{
			i += 1;
			auxi = i;
			auxj = j;
		}

		i = auxi;
		j = auxj;

		quadrado[i][j] = contagem;
	}

	if(n == 3)
		printf(
			"n = 3, Soma = %d\n",
			quadrado[0][0] + quadrado[0][1] + quadrado[0][2]
		);
	else
		printf("n = 5, Soma = %d\n",
			quadrado[0][0] + quadrado[0][1] + quadrado[0][2] + quadrado[0][3] + quadrado[0][4]
		);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%2d ", quadrado[i][j]);
		}

		putchar('\n');
	}
}

void quadrado_par()
{
	int i, j;
	int contagem = 1;
	int quadrado[4][4];

	while(contagem < 17) //laço mais externo incrementa o valor a ser colocado em cada posição;
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				if(i == j || i == 3 - j) //somentes as posições referentes às diagonais recebem valores da contagem; o resto recebe zero;
					quadrado[i][j] = contagem;
				else
					quadrado[i][j] = 0;

				contagem++;
			}
		}
	}

	contagem = 16;

	while(contagem > 0) //contagem em ordem decrescente;
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				if(quadrado[i][j] == 0) //se a posição possui zero, recebe um novo valor na contagem;
					quadrado[i][j] = contagem;

				contagem--;
			}
		}
	}

	printf(
		"n = 4, Soma = %d\n",
		quadrado[0][0] + quadrado[0][1] + quadrado[0][2] + quadrado[0][3]
	);

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%2d ", quadrado[i][j]);
		}

		putchar('\n');
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	if(n == 4)
		quadrado_par();
	else
		quadrado_impar(n);

	return 0;
}
