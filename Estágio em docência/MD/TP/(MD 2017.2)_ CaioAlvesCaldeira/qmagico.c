#include <stdio.h>
#include <stdlib.h>

int tam; //Tamanho da matriz

/* A logica que vale pro quadrado de 3 lados vale pro de 5*/
void quad_imp(int soma){
    int matriz[tam][tam]; //Matriz
    int maior_tamanho=tam*tam; //Variavel de parada
    int cnt=1; //Numero a ser colocado na matriz
    int ii, jj; //Variaveis auxiliares
    int col=tam/2; //Coluna inicial
    int lin=0; //Linha inicial
    /*Garantindo com que nao haja lixo que comprometa o programa*/
        for(ii=0; ii<tam; ii++)
            for(jj=0; jj<tam; jj++)
                matriz[ii][jj]=0;
    /*Altero o ponto inicial, somo um a contagem e estabeleco um valor a minhas variaveis auxiliares*/
        matriz[0][col]=cnt;
        cnt++;
        jj=col;
        ii=0;
        while(cnt<=maior_tamanho){
    /*Verifico se ha uma linha acima da que vou examinar, caso haja prossegue, caso nao eu retorno para
            primeira linha da minha matriz*/
            lin=(lin-1<0)?tam-1:lin-1;
    /*Verifico se ha uma coluna a direita da que vou examinar, caso haja prossegue, caso nao eu retorno para
            primeira coluna da minha matriz*/        
            col=(col+1>tam-1)?0:col+1;
    /*Caso o elemento da matriz na posicao examinada ainda nao possua valor atribuo 
    as minhas variaveis auxiliares 'ii' e 'jj' os valores de linha e coluna, respectivamente*/
            if(matriz[lin][col]==0){
                ii=lin;
                jj=col;
            }
    /*Caso contrario eu incremento o valor de 'ii' e igualo minhas variaveis de linha e coluna as
            variaveis ii e jj*/
            else{
                ii++;
                lin=ii;
                col=jj;
            }
    /*Atribuo o valor da contagem ao elemento encontrado e incremento o valor da contagem*/ 
        matriz[lin][col]=cnt;
        cnt++;
        } //Processo repetido ate minha contagem ser igual ao tamanho da matriz ao quadrado
    /*Impressao do que e requisitado*/
        printf("n = %d Soma = %d\n", tam, soma);
        for(ii=0; ii<tam; ii++){
            for(jj=0; jj<tam; jj++)
                printf("%3d", matriz[ii][jj]);
            printf("\n");
        }
}
 
void quad_4(int soma){
    int matriz[tam][tam]; //Matriz    
    int cnt=1; //Numero a ser colocado na matriz
    int ii, jj; //Variaveis auxiliares

        for(ii=0;ii<tam;ii++)
            for(jj=0;jj<tam;jj++){
    /*Caso o elemento esteja na posicao da diagonal principal da matriz este if espelha a posicao
        a ser alterada*/
                if(ii==jj)
                    matriz[3-ii][3-jj]=cnt;
                else if(ii+jj==tam-1)
    /*Caso o elemento esteja na posicao da diagonal secundaria da matriz este else if espelha a posicao
        a ser alterada*/
                    matriz[jj][ii]=cnt;
    /*Nos outros casos a matriz e completada crescentemente da esquerda pra direita*/            
                 else
                    matriz[ii][jj]=cnt;
                cnt++; //Incrementacao de variavel
            }
    /*Impressao do que e requisitado*/
        printf("n = %d Soma = %d\n", tam, soma);
        for(ii=0;ii<tam;ii++){
            for(jj=0;jj<tam;jj++)
                printf("%3d", matriz[ii][jj]);
            printf("\n");
        }
        
}



int main(){
    int soma; //Soma encontrada a partir de qualquer linha, coluna ou diagona da matriz
        scanf("%d", &tam); 
    soma=tam*(tam*tam+1)/2;
        if(tam%2) //Caso o tamanho seja impar chama a funcao quad_imp
            quad_imp(soma);
        else //Caso contrario chama a funcao quad_4
            quad_4(soma);
}
