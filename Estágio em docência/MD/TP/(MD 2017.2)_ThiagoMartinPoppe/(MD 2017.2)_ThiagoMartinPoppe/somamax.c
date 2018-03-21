#include <stdio.h>

void mensagemErro(); // função que imprime uma mensagem de erro
void lerTamanho(int *tamanho); // função que lê o tamanho do nosso vetor
void lerNumeros(int tamanho, int array[], int *numPos, int *numNeg); // função que lê os números
int arrayTamanho(); // função que verifica se o tamanho é compatível
int somasMaximasPossiveis(int tamanho, int array[], int *inicio, int *final, int numPos, int numNeg);
// função que verifica todas as somas possíveis (subconjuntos) e acha a maior soma possível

int main()
{
	int tamanho = arrayTamanho(); // variável que guarda o tamanho do vetor
	int array[tamanho], soma_max; // respectivamente, o nosso vetor e a variável para soma máxima
	int inicio, final; // respectivamente, variáveis para guardar a posição inicial e final do nosso conjunto soma máxima
	int numPos, numNeg; // respectivamente, variáveis para guardar o número de números positivos e negativos

	lerNumeros(tamanho, array, &numPos, &numNeg); // chamada da função para ler os números

	soma_max = somasMaximasPossiveis(tamanho, array, &inicio, &final, numPos, numNeg); // chamada da função para achar as somas

	printf("Soma: %d\n", soma_max);
	printf("Índices: %d a %d\n", inicio, final);

	return 0;
}

void mensagemErro()
{
	setbuf(stdin, NULL); // limpeza do buffer para que o getchar() funcione como esperado
	printf("\nErro. Esse numero nao pertence ao intervalo dado!\n");
	printf("Por favor pressione Enter para tentar outro número.");
	getchar();
}

void lerTamanho(int *tamanho)
{
	printf("Informe o tamanho do array (de 3 e 20): ");
	scanf("%d", tamanho);
}

void lerNumeros(int tamanho, int array[], int *numPos, int *numNeg)
{
	int i;

	*numNeg = *numPos = 0; // inicialmente possuimos 0 números no nosso vetor

	for(i = 0; i < tamanho; i++)
	{
		printf("Insira o %dº número: ", i+1);
		scanf("%d", &array[i]);

		if(array[i] < 0) (*numNeg)++; // se o número for menor que 0, temos um incremento na quantia dos números negativos
		else (*numPos)++; // caso contrário, temos um incremento na quantia dos números positivos
	}

	printf("\n");
}

int somasMaximasPossiveis(int tamanho, int array[], int *inicio, int *final, int numPos, int numNeg)
{
	int i, j, ultimaPosicao; // variáveis de controle de laço e para guardar a última posição
	int somaTemporaria = 0; // variável para guardarmos a soma momentânea
	int somaMax = 0; // variável que guarda o valor da maior soma encontrada

	if(numPos == tamanho) // se só tivermos positivos, a soma máxima será a soma dos números
	{
		*inicio = 1; *final = tamanho;
		for(i = 0; i < tamanho; i++) somaMax += array[i];
	}

	else if(numNeg == tamanho) // se só tivermos negativos, a soma máxima será 0 (já inicializada assim) e as posições serão 0 (ou seja, inválidas)
	{
		*inicio = *final = 0;
	}

	else // caso contrário ele roda o algoritmo baseado em "força bruta" para achar a maior soma possível dentro do conjunto
	{
		// a ideia por trás desse algoritmo é percorrer o vetor inteiro e depois percorrer até n-1 posições, até lermos apenas o primeiro número

		for(i = 0; i < tamanho; ++i)
		{
			ultimaPosicao = tamanho; // a variável última posição funciona como uma auxiliar para mudarmos o tamanho a ser lido

			for(j = i; i < ultimaPosicao; ++j) // percorre da posição i até o último elemento do vetor
			{
				if(j < ultimaPosicao)  // enquanto não chegar na última posição, eu somo os elementos lidos
					somaTemporaria += array[j];

				else // chegando na última posição nós comparamos a somaTemporaria com a somaMax
				{
					if(somaTemporaria >= somaMax)
					{
						somaMax = somaTemporaria; // atualizamos a nossa soma máxima
						*inicio = i+1; // atribuimos a posição i+1 para o início do nosso intervalo
						*final = ultimaPosicao; // atribuimos a última posição para o final do nosso intervalo
					}

					somaTemporaria = 0; // zeramos a soma temporária
					--ultimaPosicao; // decrementamos a última posição para ler até n-1 números
					j = i-1; // essa linha é necessária devido ao ++j presente no for
				} 
			}
		}
	}

	return somaMax; // retorna a soma máxima possível
}

int arrayTamanho()
{
	int tamanho;

	lerTamanho(&tamanho); // chamada da função para ler o tamanho do nosso array

	while(tamanho < 3 || tamanho > 20) // esse laço fica rodando até que o usuário insira um número que pertença ao intervalo dado
	{
		mensagemErro(); printf("\n");
		lerTamanho(&tamanho);
	}

	return tamanho; // retorna o tamanho lido
}
