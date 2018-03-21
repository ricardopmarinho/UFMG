#include <stdlib.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
  
    int N, linhas, colunas, i, j;
    int contador;
    printf(">> DIGITE O TAMANHO DA SUA MATRIZ <<\n");
    scanf("%d",&N);
    printf("\n");
    int MATRIZ[N][N];
    int somaMagica = N*((N*N) + 1)/2; // fórmula do quadrado mágico
    int temp = 0;
    int acertos = 0;

    for(colunas = 0; colunas < N; colunas++)
    {
        for(linhas = 0; linhas < N; linhas++)
        {
             MATRIZ[colunas][linhas] = 0;
             MATRIZ[colunas][linhas] = 0;
        }
    }
                    /// Quadrado Mágico Par 4x4

    if(N%2 == 0)  //condição para matrizes pares
    { 
            
    contador = 0;
    int contador2 = 17;
    
        for(colunas = 0; colunas < N; colunas++) 
        {
            for(linhas = 0; linhas < N; linhas++) // laço que realiza o preenchimento da matriz de acordo com as condições abaixo.
            {
                contador++;
                contador2--;
                    if(linhas == colunas) // preenche diagonal principal 
                    {
                        MATRIZ[linhas][colunas] = contador;
                    }
                        else if(linhas == (N-1-colunas)) // preenche diagonal secundária 
                        {
                            MATRIZ[linhas][colunas] = contador;
                        }
                            else if(MATRIZ[linhas][colunas] == 0) // preenche o restante das prosições
                            {
                                MATRIZ[linhas][colunas] = contador2;
                            }   
            }

        }

    }
    
    else // condição matrizes impares
{

    /// Quadrado Mágico Ímpar

    int k;
    int linha_ant, coluna_ant; // variáveis que controlam a condicão do Passo 3 do algoritimo
    int num = 1;   
    
    i = N-1; j = N/2; // inicializando as variáveis (i) e (j) para começar a matriz com o (1) na posição correta.
    
    for(k = 0; k < N*N; k++) // passo 4, inserir os N números, repetir até que toda a matriz esteja completa
    {  
        MATRIZ[i][j] = num; // passo 1, insere o número 1 na posiãção correta da matriz 1 na linha 3 coluna 2
        linha_ant = i; coluna_ant = j; // a cada iteração a posição anterior é guardada.
        j--; i++; // passo 2, percorrer a matriz uma posição a esquerda e uma para baixo
        if(i > N-1)
        {
            i = 0;
        } 
        if(j < 0)
        {
            j = N-1;
        } 
        if(MATRIZ[i][j] != 0) //laço: passo 3, se for encontrada uma posição com número diferente de 0, voltar a posição anterior (antes da realização do passo 2) e subir uma posição.
        {
            i = linha_ant;
            j = coluna_ant;
            i--;
        }
        num++; // adiciona os números na matriz
    }
}
    /*                   >>Verificação de Resultados<<
        Esta parte do programa apenas realiza comparações para efeito
         de confirmação de que todas linhas, colunas e diagonais possuem 
         o mesmo resultado quando somadas as componentes de cada 
         posição (i)(j) da matriz. 
    */

    printf("Matriz: %d x %d \n\n",N, N);

    for(i = 0; i < N; i++)  // imprime a matriz preenchida
    {
        for(j = 0; j < N; j++)
            printf("%3d", MATRIZ[i][j]);
            printf("\n");
    }
    printf("\n");

    for(i = 0; i < N; i++) // verifica linhas
    {
        for(j = 0; j < N; j++)
        {
            temp += MATRIZ[i][j];
        }
        if(temp == somaMagica)
        {
            acertos++;
        } 
        temp = 0;
    }

    for(i = 0; i < N; i++) // verifica colunas
    {
        for(j = 0; j < N; j++)
        {
            temp += MATRIZ[j][i];
        }

        if(temp == somaMagica)
        {
             acertos++;
        }
        temp = 0;
    }

    for(i = 0; i < N; i++)  // verifica diagonal principal
    {
        temp += MATRIZ[i][i];
    }
    if(temp == somaMagica)
    {
         acertos++;
    }
    temp = 0;
    for(i = 0; i < N; i++) // verifica diagonal secundária
    {
        for(j = 0; j < N; j++)
        {
            if(i == N-1-j)
            {
                temp += MATRIZ[i][j];
            }              
        }
            if(temp == somaMagica)
            {
                acertos++;
            }
    }

    if(acertos == (N*2)+2) // Mostra o resultado da Soma
    {
        printf("Soma: %d\n", somaMagica);
    }else printf("ERRO!\n");

        printf("\n");

    system("pause");
    return 0;
}

