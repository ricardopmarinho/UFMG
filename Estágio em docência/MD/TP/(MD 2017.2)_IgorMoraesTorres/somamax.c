#include <stdio.h>
#include <stdlib.h>

int v[3];   //variavel global
void sMax(int r[], int N){

    int maxsoma,entrada,saida,aux,soma,cont;
    maxsoma = soma = 0;
    entrada = 0;
    aux = 1;
    saida = -1;
    for(cont=1; cont<N; cont++)
    {
        if( (soma + r[cont]) < 0 ){
            aux = cont +1;
            soma = 0;
        }
        else {
            soma = soma + r[cont];
        }
            if( soma > maxsoma) {
                maxsoma = soma;
                entrada = aux;
                saida = cont;
        }
    }

        v[0] = maxsoma;
        v[1] = entrada + 1;
        v[2] = saida +1;

}

int main (){
    int ii;
    int n;
    int s[25];
    scanf("%d", &n);
    for(ii=0; ii<n; ii++){
        scanf("%d", &s[ii]);
    }
    sMax(s,n);
    printf("Soma: %d\n", v[0]);
    printf("Indices: %d a %d\n", v[1], v[2]);

    return 0;
}
