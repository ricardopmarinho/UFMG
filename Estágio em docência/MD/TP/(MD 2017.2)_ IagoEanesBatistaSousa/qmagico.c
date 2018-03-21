// Trabalho prático de Matemática Discreta
// Escrito por Iago Eanes
// Santa Luzia, 30 de Outubro de 2017 (rev 1.1)

//Inclusão de bibliotecas de funções
#include <stdio.h>
#include <math.h>

//Declaração e inicialização de algumas variáveis utilizadas pelo programa
int n;//armazena o tamanho do lado do quadrado
int i;//utilizado para linhas
int j;//utlizado para colunaunas
int quadrado_magico[5][5];//arranjo bidimensional que armazena o quadrado
int maximo; // O número máximo que pode ser armazenado no quadrado
int const_mag;// armazena a constante mágica do quadrado(valor das somas entre linhas, colunaunas e diagonais)
int a;//variável utilizada para realizar trocas e inserções

//Como o único quadrado mágico aceito tem tamanho de lados = 4, essa rotina é construída especificamente para tratamento dele
void quad_par (int l){
  const_mag=((l * ((pow(l,2)) + 1)) / 2);//Calcula a constante mágica do quadrado

  //Escreve os números no quadrado de maneira sequencial e em ordem crescente
  a=0;
  for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        a=a+1;
        quadrado_magico[i][j]=a;
      }
    }

  //Sucessivas manipulações de números para obter a combinação desejada
  //Troca de posição os números 5 e 12

    a=quadrado_magico[1][0];
    quadrado_magico[1][0]=quadrado_magico[2][3];
    quadrado_magico[2][3]=a;

  //Troca de posição os números 8 e 9
    a=quadrado_magico[1][3];
    quadrado_magico[1][3]=quadrado_magico[2][0];
    quadrado_magico[2][0]=a;

  //Troca de posição os números 15 e 2
    a=quadrado_magico[3][2];
    quadrado_magico[3][2]=quadrado_magico[0][1];
    quadrado_magico[0][1]=a;

  //Troca de posição os números 14 e 3
    a=quadrado_magico[3][1];
    quadrado_magico[3][1]=quadrado_magico[0][2];
    quadrado_magico[0][2]=a;

  return;
}

//Essa função é aplicável a qualquer quadrado mágico ímpar, haja vista que a forma de resolvê-los é análoga
void quad_impar(int a){
  int referencia = (n / 2); // Identifica a coluna do meio
  quadrado_magico[0][referencia] = 1; // Insere o número 1 no meio da primeira coluna

  // Laço para inserção dos números no quadrado mágico
  int linha;
  int coluna;
  int proxima_linha;
  int proxima_coluna;
 //Calculo da constante mágica
 const_mag=(n * (pow(n,2) + 1)) / 2;
  for (i = 2, linha = 0, coluna = referencia; i < maximo + 1; i++) {
    if ((linha - 1) < 0) { // Se for um, sai do topo do quadrado
      proxima_linha = n - 1; // Vá para a fileira de baixo
    }
    else { proxima_linha = linha - 1; } // Senão sobe uma fileira

    if ((coluna + 1) > (n - 1)) { // Se for o fim das colunaunas
      proxima_coluna = 0; // retorna à primeira colunauna
    }
    else { proxima_coluna = coluna + 1; } // Senão, move para a próxima

    if (quadrado_magico[proxima_linha][proxima_coluna] > 0) { // Se a posição estiver ocupada
      if (linha > (n - 1)) { // Se estiver na última fileira
          proxima_linha = 0; // Retorna ao topo
        }
      else {
        proxima_linha = linha + 1; // Senão, vá para a fileira de baixo
        proxima_coluna = coluna; // Se mantendo na mesma colunauna
      }
    }
    linha = proxima_linha;
    coluna = proxima_coluna;
    quadrado_magico[linha][coluna] = i; // Insere o valor de i na posição atual
  }
  return;
}

//Rotina que realiza a leitura e determina a paridade do quadrado
int main() {
    scanf("%d", &n);//Lê o tamanho do lado do quadradro
    if (n==3 || n==4 || n==5) { //verifica se a entrada é válida
      maximo = n * n; //Determina o valor máximo que pode ser colocado no quadrado mágico
      if (n%2==0){//verifica se o quadrado é ímpar ou par
        quad_par(n);//chama a função para quadrados pares
      }
      else quad_impar(n);//chama a função para quadrados ímpares
    }
    else return (0);//caso a entrada seja inválida, encerra o programa

  //Exibe o resultado final após as devidas manipulações de valores
    printf ("n = %d, Soma = %d\n",n, const_mag);
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", quadrado_magico[i][j]);
      }
      printf("\n");
    }
    return (0);
  }
