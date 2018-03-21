#include <stdio.h>
#include <stdlib.h>

void imprimir(int n, int* pi);
void impar(int n, int* pi, int inicio);
void par_simples(int n, int* pi);
void par_duplo(int n, int* pi);

int main(int argc, char *argv[])
{
 	int n = 10, *p, j;

    //cria o laço para gerar os quadrados mágicos
 	for(j = 3; j <= n; j++){
        //matriz para armazenar temporariamente os quadrados
        int matriz[j][j];

        if( j%2 == 1){
            //utiliza a solução para quadrado ímpar
            impar( j, (int*)&matriz[0], 1);

        }else if( j%4 == 0){
            //utiliza a solução para quadrado divisivel por 4
            par_duplo( j, (int*)&matriz[0]);

        }else if(j%2 == 0){
            //utiliza a solução para quadrado divisivel por 2 mas não por 4
            par_simples( j, (int*)&matriz[0]);
        }

        //chama a função pra imprimir o quadrado mágico atual de lado j
        imprimir(j,(int*)&matriz[0]);

 	}


  return 0;
}

//função que imprimi os quadrados
void imprimir(int n, int* pi){

    int j, numero;
    numero = n*((float)(n*n+1)/2);

    //imprimi as informações sobre o quadrado mágico atual
    printf("n = %d, Soma = %d\n", n, numero);

    //imprimi o quadrado mágico solucionado com o auxílio de j para caminhar pelo ponteiro, quando j+1%n == 0 quer dizer que já foi impressa uma linha de tamanho n
    for(j = 0; j < n*n; j++){
        printf("%3d ",*(pi+j));
        if((j+1)%n == 0){
            printf("\n");
            }

 	}
 	printf("\n\n");
}

//função que resolve quadrado com lado ímpar
void impar(int n, int* pi, int inicio){
	 int numeroMagico = ((n*((n*n)+1))/2), linha = 0, coluna = (n)/2, i, j;
	 int quadrado[n][n];

	 //zera toda a matriz para evitar erros
	 for(i = 0; i < n; i++)
     {
         for(j = 0; j<n;j++){
	 	   quadrado[i][j] = 0;
         }
     }

     //preenche a matriz obedecendo as regras para solução ímpar descritas no doc.pdf
	 for(i = 0; i < (n*n); i++)
	 {
        if(quadrado[linha%n][coluna%n] == 0)
        {
	 	   quadrado[linha%n][coluna%n] = i+inicio;
        }else{
            linha+=2;
            coluna--;
            quadrado[linha%n][coluna%n] = i+inicio;
        }

        linha+=n-1;
        coluna++;
	 }

	 //transfere os valores da matriz na mesma ordem para o ponteiro na main
	 for(i = 0; i < n; i++)
     {   //j representando a coluna atual e i a linha, por isso é multiplicada por n
         for(j = 0; j<n;j++){
	 	   *(pi+(i*n+j)) = quadrado[i][j];
         }
     }

}

//função que resolve um quadrado com lado divisível por 2 mas não por 4
void par_simples(int n, int* pi){

    int control = n/2, i = 0, j, temp, *quadA, *quadB, *quadC, *quadD;
    int quads[4][control][control];
    quadA = &quads[0];
    quadB = &quads[1];
    quadC = &quads[2];
    quadD = &quads[3];

    //soluciona cada sub-matriz pelo método ímpar corrigindo o valor inicial de cada uma
    impar(control,quadA,1+(control*control)*i++);

    impar(control,quadB,1+(control*control)*i++);

    impar(control,quadC,1+(control*control)*i++);

    impar(control,quadD,1+(control*control)*i);

    //realiza a troca de realces A1 - D1 e A3 - D3 descrita no doc.pdf
    for(i = 0; i < control/2; i++){
        for(j = 0; j < control/2; j++){
            temp = *(quadA + j + i * control);
            *(quadA + j + i * control) = *(quadD + j + i * control);
            *(quadD + j + i * control) = temp;

            temp = *(quadA +((control/2+1)*control) + j + i * control);
            *(quadA +((control/2+1)*control) + j + i * control) = *(quadD +((control/2+1)*control) + j + i * control);
            *(quadD +((control/2+1)*control) + j + i * control) = temp;
        }
    }

    //realiza a troca de realces A2 - D2 descrita no doc.pdf
    for(i = 0; i < control/2; i++){
        temp = *(quadA + (control/2)*control + i + 1);
        *(quadA + (control/2)*control + i + 1) = *(quadD + (control/2)*control + i + 1);
        *(quadD + (control/2)*control + i + 1) = temp;
    }

    //para n > 6 faz a troca necessária das colunas das matrizes B e C, descrita no doc.pdf
    if(n > 6){
        for(i = 0; i < control; i++){
            for(j = control-1; j > (control/2)+1; j--){
                temp = *(quadB+j+(i*control));
                *(quadB+j+(i*control)) = *(quadC+j+(i*control));
                *(quadC+j+(i*control)) = temp;
            }
        }
    }

    //transfere os valores dos quadrados para um ponteiro na main
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < control; j++)
        {
            if(i < control)
                *(pi+j+n*i) = *(quadA+j+control*i);
            else
                *(pi+j+n*i) = *(quadD+j+control*(i - control));
        }
        for(j = 0; j < n; j++)
        {
            if(i < control)
                *(pi+j+control+n*i) = *(quadC+j+control*i);
            else
                *(pi+j+control+n*i) = *(quadB+j+control*(i - control));

        }
    }

}

//função que resolve um quadrado com lado divisível por 4
void par_duplo(int n, int* pi){
    int i, j, k, l = 1, temp;
    int quadrado[n][n];

    //preenche toda a matriz em ordem de 1 até n^2
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            quadrado[i][j] = l++;
        }
    }

    //realiza uma troca espelhada entre as linhas superiores e inferiores delimitadas pelas posições marcadas nas extremidades e central
    //equivalente ao método descrito no doc.pdf
    for(i = 0; i < n/4; i++){
        for(j = n/4; j < (n-n/4); j++){
            temp = quadrado[i][j];
            quadrado[i][j] = quadrado[n-1-i][n-1-j];
            quadrado[n-1-i][n-1-j] = temp;
        }
    }

    //realiza uma troca espelhada entre as colunas nas extremidades esquerda e direita delimitadas pelas posições marcadas nas extremidades e central
    //equivalente ao métodos descrito no doc.pdf
    for(i = n/4; i < n-n/4; i++){
        for(j = 0; j < n/4; j++){
            temp = quadrado[i][j];
            quadrado[i][j] = quadrado[n-i-1][n-j-1];
            quadrado[n-i-1][n-j-1] = temp;
        }
    }

    //transfere os valores do quadrado para um ponteiro na main
    for(i = 0; i < n; i++)
     {
         for(j = 0; j < n; j++){
	 	   *(pi + ((i*n)+j)) = quadrado[i][j];
         }
     }


}
