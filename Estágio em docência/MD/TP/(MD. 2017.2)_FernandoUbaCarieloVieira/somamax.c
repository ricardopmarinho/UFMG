#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, ii;
    int i, j, Ind1, Ind2;
    int SomaSeg= 0; 
    int SomaMax= -1; //definicao das variaveis que serao utilizadas no programa
    
    scanf("%d", &n); //scanf da quantidade de elementos do Vetor 
    int Vetor[n];
    
    for(ii=1; ii<=n; ii++){
              scanf("%d", &Vetor[ii]);} //Laco para atribuicao dos valores de cada elemento do Vetor
    
    for(i=1; i<=n; i++){
               SomaSeg= 0;
                  for(j=i; j<=n; j++){ 
                           SomaSeg= SomaSeg + Vetor[j]; 
                           if(SomaSeg > SomaMax){ //Comparacao entre a Soma Maxima de Segmento ate agora, com a atual Soma de Segmento. 
                           SomaMax= SomaSeg;
                           Ind1= i;
                           Ind2= j;}
                  }
    //Laco "for" dentro de outro laco "for" com o objetivo de calcular a Soma de cada Segmento, comecando pelo segmento de 1 ate 2,3,...n,
    //guardando em SomaMax a Soma do Segmento (SomaSeg) com maior valor, apos 1 ate n, inicia-se 2 ate 3,4,...n, e assim sucessivamente...
    //Sao guardados em Ind1 e Ind2, o numero de comeco do Segmento(i) e o numero do encerramento do Segmento(j), respectivamente.
        }
    if(SomaMax<=0)SomaMax= 0; //Se a Soma Maxima de Segmento for negativa, entao SomaMax= 0.
    
    printf("Soma: %d\n", SomaMax);
    printf("Indices %d a %d\n", Ind1, Ind2);
    
  system("PAUSE");	
  return 0;
}
