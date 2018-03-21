#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------
// Função sumMax: calcula soma máxima, retornando o valor da soma máxima 
//                obtida; sobre-escreve as variáveis startPos e endPos passadas
//                como referência.
//                Esta função tem custo computacional de O(n)
//-----------------------------------------------------------------------------
long long int sumMax (long long int *S, int n, int *startPos, int *endPos) {
  int tStart = 0;
  *startPos = 0;
  *endPos = 0;
  long long int somaAtual = S[0];
  long long int maxSum = S[0];

  for(int i = 1; i < n; i++) {
    somaAtual += S[i];
    if(S[i] > somaAtual) {
      somaAtual = S[i];
      tStart = i;
    }
    if(somaAtual > maxSum) {
      maxSum = somaAtual;
      *startPos = tStart;
      *endPos = i;
    }
  }
  return maxSum;
}

//-----------------------------------------------------------------------------
// Função principal
//-----------------------------------------------------------------------------
int main (int argc, char *argv[]) {
  if(argc < 3) exit(EXIT_FAILURE);

  int i, n;
  n = (int)strtoul(argv[1], NULL, 0);

  long long int *arr = (long long int *)malloc(n*sizeof(long long int));
  for(i = 0; i < n; ++i)
    //fscanf(stdin, "%d", &arr[i]);
    arr[i] = (int)strtoul(argv[i + 2], NULL, 0);

  int startPos, endPos;
  long long int MaxSoFar = 0;

  MaxSoFar = sumMax(arr, n, &startPos, &endPos);
  fprintf(stdout, "Soma: %lld\nIndices: %d a %d\n", MaxSoFar, startPos + 1, endPos + 1);

  free(arr);
  exit(EXIT_SUCCESS);
}
