// Trabalho prático de Matemática Discreta
// Escrito por Iago Eanes
// Santa Luzia, 30 de Outubro de 2017 (rev 1.4)

//Inclusão de bibliotecas de funções
#include <stdio.h>

//Declaração e inicialização de algumas variáveis utilizadas pelo programa
int n;//armazena o tamanho do arranjo
int i;//variável para índices


//função responsável por realizar a soma de todos os subconjuntos do arranjo
//ela recebe o arranjo como um ponteiro, de acordo com a linguagem C, além do tamanho do arranjo
void soma_maxima( int * a, int size){

//define a soma maxima inicial como o primeiro elemento do arranjo
  int soma_max = a[0];

//cria duas variáveis locais e as inicializa
  int inicio_soma = 0;//armazena o índice de início da soma
  int fim_soma = 0;//armazena o índice de final da soma

//inicializa a verificação em 1 até o final do arranjo
  for( int i = 1; i < size; i++)
  {
    //criação de duas variáveis locais auxiliares
    int soma_atual = 0;
    int j;

    //enquanto j for maior ou igual a zero a soma atual é incrementada de a índice j
      for(j = i; j >= 0; j--){
        soma_atual += a[j];

        //se a soma atual for maior que a soma máxima, atualizam-se as variáveis de posição e o valor da soma
        if (soma_atual > soma_max){
          soma_max = soma_atual;
          inicio_soma = j;
          fim_soma = i;
        }
      }
    }
    printf("Soma: %d\n", soma_max);//imprime o valor da soma maxima
    printf("Índices: %d a %d\n", inicio_soma+1, fim_soma+1 );//imprime os índices dos elementos extremos da soma maxima
}

//cria o arranjo e recebe o seu tamanho
int main() {
    scanf ("%d", &n);
    int arranjo[n];

    //verifica a validade da entrada
    if (n<3 || n > 20){
     return (0);
    }
    else{

      //recebe os valores do arranjo
      for ( i = 0; i < n; i++ ){
        scanf ("%d", &arranjo[i]);
      }
    }
    soma_maxima( arranjo, n);//passa o arranjo e o tamanho dele para a função
  return 0;
}
