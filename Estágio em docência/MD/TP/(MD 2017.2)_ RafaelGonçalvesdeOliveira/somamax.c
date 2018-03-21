#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, cont, cont2, soma = 0, aux = 0, indice1 = 0, indice2 = 0;
    scanf("%d", &n);

    //laço que verifica se o programa deve ser encerrado
    while(n != 0){
        while(n < 0){
            printf("Valor invalido, por favor entre com um numero positivo.\n");
            scanf("%d",&n);
        }
        int a[n];

        //laço que lê os valores do vetor
        for(cont = 0; cont < n; cont++)
        {
                   scanf("%d", &a[cont]);
        }

        //laço mais externo que controla o índice referente ao inicio da soma
        for(cont = 0; cont < n; cont++)
        {

            //laço mais interno que faz a soma do índice inicial com todos seguintes verificando a soma e guardando os valores necessários
            for(cont2 = cont; cont2 < n; cont2++)
            {
                aux += a[cont2];
                if(soma < aux)
                    {
                        soma = aux;
                        indice1 = cont + 1;
                        indice2 = cont2 + 1;
                    }
            }

            aux = 0;
        }
        printf("Soma: %d\nIndices: %d a %d\n", soma, indice1, indice2);
        scanf("%d", &n);
        soma = indice1 = indice2 = 0;
    }
    return 0;
}
