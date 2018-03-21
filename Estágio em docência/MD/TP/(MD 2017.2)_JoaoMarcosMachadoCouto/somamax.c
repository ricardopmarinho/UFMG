#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0; //quantidade de numeros do vetor
    int i = 0, j = 0 ; //auxilares de loop
    int somaatual = 0 ; //Armazena a soma sendo avaliada 
    int maiordassomas = 0 ; //Recebe a maior soma entre todos os tamanhos
    int inicialmaior = 0 , finalmaior = 0 ; //Recebe os indices de comeco e fim do subvetor com maior soma
    int tamanho = 0 ; //Tamanho do subvetor sob avaliacao
    scanf ("%d", &n) ; //Le o numero de elementos do vetor
    int d = n+1 ;
    int indinicial[d] , indfinal[d] ; //Indices de comeco e fim para a maior soma de subvetores tamanho [x]
    int vetor[n] ; //O vetor principal
    int maiorsoma[d] ; //Armazena em [x] a maior soma para subvetores de tamanho x 
    for (i = 0 ; i <= n ; i++){ //Inicializacao dos indices em comecos
        indinicial[i] = 0 ;
        indfinal[i] = 0 ;
        maiorsoma[i] = 0 ;
    }
    for (i = 0 ; i < n ; i++){ //Le os valores presentes no vetor
        scanf ("%d", &vetor[i]);
    }
        i = 0 ;
        while (vetor[i] < 0 && i < n){ // Avalia se todos os numeros no vetor sao negativos
            if (i >= (n-1)){ //Caso sim, imprime o valor da soma, no caso, 0 
                printf ("Soma: 0\n") ;
                printf ("Indices: 1 a %d", n ) ;
                return 0 ;
            }
            i++ ;
        }
    for (i = 0 ; i < n ; i++){  //Loop principal do programa que determina a maior soma para cada tamanho de sub vetor
        somaatual = vetor[i] ;
        if (somaatual > maiorsoma[1]){ //Avalia a maior soma para o caso de subvetor tamanho 1
            maiorsoma[1] = somaatual ;
            indinicial[1] = i ;
            indfinal[1] = i ;
        }
        for (j = i+1 ; j < n ; j++){ //Avalia qual a maior soma para subvetores de tamanho maior que 1
            somaatual += vetor[j] ;
            tamanho = j-1+i ;
            if (somaatual > maiorsoma[tamanho]){ //Realiza o swap caso a somaatual seja maior que a maiorsoma para determinado tamanho
                maiorsoma[tamanho] = somaatual ;
                indinicial[tamanho] = i ;
                indfinal[tamanho] = j ;
            }
        }
    }
    maiordassomas = 0 ;
    for (i = 1 ; i < n ; i++){ //Avalia qual o subvetor com a maior das somas
        if (maiorsoma[i] > maiordassomas){
            maiordassomas = maiorsoma[i] ;
            inicialmaior = indinicial[i] ;
            finalmaior = indfinal[i] ;
        }
    }
    printf ("Soma: %d\n", maiordassomas); //Imprime o valor da soma do subvetor com maior soma
    printf ("Indices: %d a %d", inicialmaior+1 , finalmaior+1 ) ;//Imprime os indices do subvetor com a maior soma de todas
return 0 ;
}
