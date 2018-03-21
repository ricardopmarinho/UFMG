#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  int n, i, ii;
  int soma=0, somamax=0;
  int indiceAtual=0, indiceInicio, indiceFim;
  int vetor[20];

  printf("Insira o tamanho do vetor:\n");
  scanf("%d", &n);
  printf("Insira o vetor:\n");
  for (i = 0; i < n; i++)
    {
      scanf("%d", &vetor[i]);
    }

  for (ii = 0; ii < n; ii++)
    {
     soma += vetor[ii];
     if (soma <= 0)
      {
        indiceAtual = ii + 1;
        soma = 0;
      }
     else if (somamax < soma)
      {
        somamax = soma;
        indiceInicio = indiceAtual;
        indiceFim = ii;
      }
    }
  printf("Soma: %d\n", somamax);
  printf("Índices: %d a %d\n", indiceInicio+1, indiceFim+1);
  return 0;
}
