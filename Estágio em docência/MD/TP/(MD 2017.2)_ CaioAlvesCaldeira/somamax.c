#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; //Numero de numeros a serem lidos
    int numat; //Numero lido
    int somat=0; //Soma atual
    int somax=0; //Soma maxima
    //Indices iniciais, finais, atual, e inicial da soma atual, respectivamente
    int indi=0, indf=0, indat=1, indiat=0; 
        scanf("%d", &n);
        while(indat<=n){
            scanf("%d", &numat);
        /*Caso o numero atual seja maior que zero soma-se a soma atual*/
            if(numat>0){
                somat+=numat;
            /*Caso o indice da soma atual ainda nao tenha sido atribuido
                ele recebe o valor do indice atual*/
                if(indiat==0)
                    indiat=indat;
            }
        /*Caso seja menor que zero*/
            else{
                /*Verificamos se a soma atual e maior que a soma maxima
                    caso seja atualizamos o valor da soma maxima e seus indices
                        caso contrario prosseguimos*/
                    if(somat>somax){
                        somax=somat;
                        indi=indiat;
                        indf=indat-1;
                    }
                /*Caso a soma atual seja maior que o valor absoluto do numero atual
                    soma este a soma atual*/
                    if(somat>abs(numat))
                        somat+=numat;
                /*Caso contrario resetamos a soma atual e seu indice*/
                    else{
                    somat=0;
                    indiat=0;
                    }
                }
            }
        indat++;
        }//Repetir N vezes
/*Verificamos se a soma atual e maior que a soma maxima
            caso seja atualizamos o valor da soma maxima e seus indices
                caso contrario prosseguimos*/
        if(somat>somax){
            somax=somat;
            indi=indiat;
            indf=indat-1;
        }
    /*Impressao do requisitado*/
        printf("Soma: %d\nIndices: %d a %d\n", somax, indi, indf);

}