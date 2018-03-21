#include <stdio.h>

void inicializacao(int n, int quadrado[][n]); // função que inicializa todas as posições como 0
void mensagemError(); // função que apresenta um erro cometido pelo usuário
void procurar_quadradoMagico(int n, int quadrado[][n]); // função que constrói um quadrado mágico dado um 'n'
void imprimirResultado(const int soma, int n, int quadrado[][n]); // função que imprime o resultado obtido
int isComplete(int n, int quadrado[][n]); // função que verifica se o quadrado mágico já está completo
int somaMagica(int n); // função que acha a soma mágica dado um 'n'
int lerDimensao(); // função para ler a dimensão do usuário

int main()
{
	int n = lerDimensao(); // a variável 'n' guardará a dimensão n x n do nosso quadrado mágico
	int quadrado_magico[n][n]; // declaração do nosso quadrado mágico de tamanho n x n
	const int soma = somaMagica(n); // cálculo da soma mágica dado um 'n'

	inicializacao(n, quadrado_magico); // chamada da função para inicializar a matriz com 0's
	procurar_quadradoMagico(n, quadrado_magico); // chamada da função que gera um quadrado mágico dado um 'n'
	imprimirResultado(soma, n, quadrado_magico); // chamada da função que imprime os resultados obtidos

	return 0;
}

void inicializacao(int n, int quadrado[n][n])
{
	int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			quadrado[i][j] = 0; // a ideia aqui é falar que 0 significa que não temos nenhum número nessa posição
}

void mensagemError()
{
	setbuf(stdin, NULL);
	printf("Valor fora do intervalo proposto!\n");
	printf("Pressione Enter para tentar novamente.");
	getchar();
}

void procurar_quadradoMagico(int n, int quadrado[][n])
{
	int i, j, num; // variáveis de controle de laço (i e j) e variável para inserir os números de 1 a n²
	int iAnt, jAnt; // variáveis para guardar as posições anteriores da linha e coluna
	int aux[n]; // variável auxiliar para trocar as duas últimas linhas e colunas do quadrado 4x4, tornando-o um Panmagic Square

	if(n%2 != 0) // se o valor de 'n' for ímpar, execute esse algoritmo
	{
		num = 1; // inicialmente temos o nosso número valendo 1
		i = 0; j = (n/2); // começamos "setando" a variável i (linhas) com o valor 0 (primeira linha) e a j (colunas) para a coluna central (N/2)
		quadrado[i][j] = num; // inserimos o valor guardado na variável "num" nessa posição

		while(!isComplete(n, quadrado)) // enquanto o quadrado mágico não estiver completo (ainda possuir 0's), executaremos o preenchimento do quadrado através do Método Siamês (Siamese Method)
		{
			num++; // somamos 1 a variável "num"
			iAnt = i; jAnt = j; // guardamos a posição anterior de i (linha) e j (coluna)
			i--; j++; // subimos uma posição em relação as linhas e "andamos" uma posição para a direita em relação as colunas

			if(i < 0) i = (n-1); // se formos para uma "linha negativa", "setamos" a variável i para a última linha (n-1)
			if(j > (n-1)) j = 0; // se formos para uma coluna maior que n-1, "setamos" a variável j para a primeira coluna (0) 

			if(quadrado[i][j] != 0) // verificamos se essa posição possui um número, se sim, executamos essa condição
			{
				i = (iAnt+1); // atribuimos o valor da linha anterior para i e somamos 1 (descemos uma posição)
				j = jAnt; // atribuimos o valor da coluna anterior para j
			}

			quadrado[i][j] = num; // inserimos o valor guardado na variável "num" nessa posição
		}
	}

	else // caso contrário, execute esse. Não precisamos usar a condição de par duplo ou par normal visto que estamos trabalhando apenas com 3x3, 4x4 ou 5x5
	{
		num = 1;

		for(i = 0; i < n; i++) // laço para percorrer as linhas da matriz
			for(j = 0; j < n; j++) // laço para percorrer as colunas da matriz
			{	
				if((i == j) || (i == n-j-1)) // se essa posição for parte da diagonal primária (i == j) ou secundária (i == n-j-1), inserimos o número guardado na variável "num"
					quadrado[i][j] = num;
				num++; // incrementamos o valor de "num" em 1
			}

		num = 1; // atribuimos 1 para a variável "num"

		for(i = n-1; i >= 0; i--) // laço para percorrer as linhas da matriz de forma contrária
		{
			for(j = n-1; j >= 0; j--) // laço para percorrer as colunas da matriz de forma contrária
			{
				if(quadrado[i][j] != 0) num++; // se tivermos um número nessa posição, apenas incrementamos o valor de "num" em 1

				else // caso contrário, inserimos o número guardado em "num" nessa posição e incrementamos em 1 a variável "num"
				{
					quadrado[i][j] = num;
					num++;
				}
			}
		}

		for(j = 0; j < n; j++) // esse laço troca as duas últimas linhas entre si
		{
			aux[j] = quadrado[n-2][j];
			quadrado[n-2][j] = quadrado[n-1][j];
			quadrado[n-1][j] = aux[j];
		}

		for(i = 0; i < n; i++) // esse laço troca as duas últimas colunas entre si
		{
			aux[i] = quadrado[i][n-2];
			quadrado[i][n-2] = quadrado[i][n-1];
			quadrado[i][n-1] = aux[i];
		}

		// Após esses dois laços for, teremos um quadrado 4x4 chamado de Panmagic Square. Um quadrado com o número máximo de ocorrênciaas da constante mágica (52 formas distintas) 
	}
}

void imprimirResultado(const int soma, int n, int quadrado[][n])
{
	int i, j;

	printf("\nn = %d, Soma = %d\n\n", n, soma); // imprime a dimensão inserida e a constante mágica

	for(i = 0; i < n; i++) // imprime o quadrado mágico num formato específico para ficar mais legível
	{
		for(j = 0; j < n; j++)
			printf("%-5d", quadrado[i][j]);

		printf("\n\n");
	}
}

int isComplete(int n, int quadrado[][n])
{
	int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(quadrado[i][j] == 0) // se acharmos uma posição com o número 0, significa que o quadrado não está completo!
				return 0; // retorne falso
	return 1; // retorne verdadeiro
}

int somaMagica(int n)
{
	return ((n*(n*n + 1))/2); // cálculo da constante mágica
}

int lerDimensao()
{
	int n;

	printf("Insira a dimensão da matriz a ser criada (de 3 a 5): ");
	scanf("%d", &n);

	while(n < 3 || n > 5) // laço que fica rodando enquanto o usuário não digitar um número dentro do intervalo solicitado
	{
		mensagemError(); // chamada da função para mostrar o erro
		printf("\nInsira a dimensão da matriz a ser criada (de 3 a 5): ");
		scanf("%d", &n);
	}

	return n; // retorna a dimensão lida
}
