#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, j, SomaQM, N;
    int QuadradoMagico[5][5], AuxQuadradoMagico[5][5]; //Matriz do Quadrado Magico e Matriz Auxiliar.
    int x=1;
    int ii=0, jj=0, lin, col;
    int NumTotal;
    
    scanf("%d", &N); //Ler o valor da dimensao do quadrado Magico
    
    SomaQM= (N*((N*N)+1)) / (2); //Equacao da soma Minima de um quadrado Magico de Tamanho N. Guardando em SomaQM o valor.
    
    if(N==4){ //Se a dimensao for igual a 4.
             for(i=0; i<N; i++){
                      for(j=0; j<N; j++){
                               QuadradoMagico[i][j]= x;
                               AuxQuadradoMagico[i][j]= x;
                               x= x+1;}
                               }
             //Primeiro laco duplo for para preencher a Matriz do Quadrado Magico e o Aux. usando 1 ate 16.
             
             for(i=0; i<N; i++){
                      for(j=0; j<N; j++){
                               if((i==j) || ((j+i)==3)){
                                       QuadradoMagico[i][j] = AuxQuadradoMagico[abs(i-3)][abs(j-3)];}
                                       }
                               }
             //Segundo laco duplo for para substituir as diagonais e formar o Quadrado Magico com as somas dos lados, colunas e diagonais
             //se igualando a 34.
                               
             }

    if(N==3 || N==5){ //Condicao caso a dimensao seja 3 ou 5.
             NumTotal= N*N; //Numero Total de elementos do quadrado magico. 
             
             for(i=0; i<N; i++){ //Laco for com o objetivo de zerar todo o quadrado magico.
                      for(j=0; j<N; j++){
                                   QuadradoMagico[i][j]= 0;}}
             lin= 0;
             col= (N/2);
             
             QuadradoMagico[lin][col]= 1;
             //Atribuindo valor 1 a posicao de onde comeca-se a logica do Quadrado Magico: ocupar a posicao
             //acima e a direita da sua posicao inicial.
             ii= lin;
             jj= col;
             for(i=2; i<=NumTotal; i++){ //Laco for com o objetivo de ocupar cada posicao do quadrado magico, comecando por 2 ja que o numero 1 ja foi guardado na posicao anterior.
                      
                      ii= ii-1;         
                      jj= jj+1;
                      //Valores somados a ii e jj para se avancar acima e a direita dentro da matriz QuadradoMagico
                      
                      if(ii < 0)ii= N-1;
                      if(jj > N-1)jj= 0; //Condicoes "if" caso o numero exceda as dimensoes do Quadrado Magico.
                      
                      if(QuadradoMagico[ii][jj]== 0){ //Se a posicao esta vazia, ocupo-a
                      lin= ii;
                      col= jj;
                      QuadradoMagico[lin][col]= i;
                      } else{ //Se Nao:
                             ii= ii+1; //Ocupa a posicao abaixo dele.
                             lin= ii;
                             col= jj;
                             QuadradoMagico[lin][col]= i;}
                      }
    }
    
     printf("n = %d, Soma= %d\n", N, SomaQM);
             for(i=0; i<N; i++){
                      for(j=0; j<N; j++){
                               printf("%d ", QuadradoMagico[i][j]);}
                               printf("\n");}
             //printf do QuadradoMagico resolvido
           
  system("PAUSE");  
  return 0;
}
