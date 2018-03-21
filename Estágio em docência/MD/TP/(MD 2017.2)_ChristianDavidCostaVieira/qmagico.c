#include <stdio.h>
#include <stdlib.h>

int qmagico3x3[3][3] = {{2, 7, 6},
                        {9, 5, 1},
                        {4, 3, 8}};

int qmagico4x4[4][4] = {{12,  1, 14,  7},
                        {13,  8, 11,  2},
                        { 3, 10,  5, 16},
                        { 6, 15,  4,  9}};

int qmagico5x5[5][5] = {{17, 24,  1,  8, 15},
                        {23,  5,  7, 14, 16},
                        { 4,  6, 13, 20, 22},
                        {10, 12, 19, 21,  3},
                        {11, 18, 25,  2,  9}};

//-----------------------------------------------------------------------------
// Função verificaQMagico: 
//    Verifica se quadrado mágico é válido. Caso válido  retorna 1. Inválido, 
//    retorna 0. Um quadrado mágico para ser válido, deverá ter a soma dos 
//    elementos de todas as linhas, colunas, diagonal principal e diagnonal 
//    secundária iguais. Há de se observar que não é permitida a duplicação 
//    dos elementos.
//-----------------------------------------------------------------------------
int verificaQMagico (int n, int q[n][n]) {
  int i, j, acum, cm = n*(n*n+1)/2;

  // Arranjo temporário para verificar a unicidade dos elementos:
  int *arr = (int *)malloc(n*n*sizeof(int));

  // Verifica a unicidade dos elementos:
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      arr[i + j] = q[i][j];

  for(i = 0; i < n; i++)
    for(j = i + 1; j < n; j++)
      if(arr[i] == arr[j]) {
        free(arr);
        return 0;
      }

  for(i = 0; i < n; i++) {
    // Verifica linhas:
    acum = 0;
    for(j = 0; j < n; j++)
      acum += q[i][j];
    if(acum != cm) {
      free(arr);
      return 0;
    } 

    // Verifica colunas:
    acum = 0;
    for(j = 0; j < n; j++) acum += q[j][i];
    if(acum != cm) {
      free(arr);
      return 0;
    } 
  }

  // Verifica diagonal principal:
  acum = 0;
  for(i = 0; i < n; i++)
    acum += q[i][i];
  if(acum != cm) {
    free(arr);
    return 0;
  } 


  // Verifica diagonal secundária:
  acum = 0;
  for(i = 0; i < n; i++)
    acum += q[i][n - 1 - i];
  if(acum != cm) {
    free(arr);
    return 0;
  } 

  free(arr);
  return cm;
}

//-----------------------------------------------------------------------------
// Função exibeQMagico: 
//    Exibe quadrado mágico na saída padrão
//-----------------------------------------------------------------------------
void exibeQMagico (int n, int q[n][n]) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(j == n-1) fprintf(stdout, "%2d", q[i][j]);
      else fprintf(stdout, "%2d ", q[i][j]);
    }
    fprintf(stdout, "\n");
  }
}

//-----------------------------------------------------------------------------
// Função principal:
//-----------------------------------------------------------------------------
int main (int argc, char *argv[]) {
  int n, ans;

  n = (int)strtoul(argv[1], NULL, 0);
  if(n <= 2 || n > 5 || argc != 2) exit(EXIT_FAILURE);

  if(n == 3) {
    ans = verificaQMagico(n, qmagico3x3);
    fprintf(stdout, "n = %d, Soma = %d\n", n, ans);
    exibeQMagico(n, qmagico3x3);
  }else if(n == 4) {
    ans = verificaQMagico(n, qmagico4x4);
    fprintf(stdout, "n = %d, Soma = %d\n", n, ans);
    exibeQMagico(n, qmagico4x4);
  }else {
    ans = verificaQMagico(n, qmagico5x5);
    fprintf(stdout, "n = %d, Soma = %d\n", n, ans);
    exibeQMagico(n, qmagico5x5);
  }
  
  exit(EXIT_SUCCESS);
}
