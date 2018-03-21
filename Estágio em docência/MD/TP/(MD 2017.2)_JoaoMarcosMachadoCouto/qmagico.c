#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
int soma ;
int Caminha(int ProxCoordenada, int PassoCoordenada ){
    int CoordenadaCandidata=ProxCoordenada+PassoCoordenada;
    if ( CoordenadaCandidata >= n ){
        CoordenadaCandidata-=n;
    }
    else if ( CoordenadaCandidata < 0 ){
        CoordenadaCandidata+=n;
    }
    return CoordenadaCandidata;
}
void Hindu( int Quadrado[] ){ //Metodo para quadrados de lado impar
    int InicioColuna=(n-1)/2; //Seleciona a coluna central 
    int InicioLinha, PassoLinha, PassoColuna=1; 
    if ( rand()%2 <= 0 ){ //Seleciona randomicamente: 
        InicioLinha=0;//Inciar na linha superior
        PassoLinha=-1;//Navegar "para cima"
    } else {
        InicioLinha=n-1; //Iniciar na linha infeior
        PassoLinha=1;//Navegar "para baixo"
    }
    int ProxNumero=1; //Numero a ser atribuido para a proxima celula
    int LimiteNumero=ProxNumero+(n*n)-1; //Ultimo numero atribuido a uma celula
    int ProxLinha=InicioLinha; 
    int ProxColuna=InicioColuna;
    int LinhaCandidata; //Coordenadas da celula canditada a receber o proximo numero
    int ColunaCandidata;
    int Continue=0;
    while ( ( ProxNumero <= LimiteNumero  ) && ( Continue == 0 ) ) { //Enquanto houverem numeros 
        Quadrado[(ProxLinha*n)+ProxColuna]=ProxNumero;
        ColunaCandidata=Caminha(ProxColuna,PassoColuna);
        LinhaCandidata=Caminha(ProxLinha,PassoLinha);
            if ( Quadrado[(LinhaCandidata*n)+ColunaCandidata]>0){ //Verifica se a celula candidata ja esta preenchida
                LinhaCandidata=Caminha(ProxLinha,-PassoLinha); //Caso sim, segue para a celula na mesma coluna na linha contraria aa direcao de navegacao
                ColunaCandidata=ProxColuna;
                if ( ProxLinha == InicioLinha && ProxColuna == InicioColuna ) { //Interrompe se encontrou a celula inicial (com valor 1) 
                    break ;
                }
                if ( Quadrado[(LinhaCandidata*n)+ColunaCandidata]>0){ //Interrompe se celula da linha contraria da navegacao ja esta preenchida
                    break  ;
                }
            }
        ProxLinha=LinhaCandidata;
        ProxColuna=ColunaCandidata;
        ProxNumero++;
    }
}
void QuadradoExibir( int Quadrado [] ){ //Funcao que imprime o quadrado resolvido
    int Linha,Coluna,NumeroMagico=0;
    for ( Linha=0 ;Linha<n ;Linha++ ){
        for ( Coluna=0 ; Coluna<n ; Coluna++ ){
            printf( "%d\t" , Quadrado[(Linha*n)+Coluna] );
        }
        printf("\n" );
    }
    printf("\n" );
}
void JacobMurugan( int Quadrado[] ){ //Funcao geradora de quadrado para lados multiplos de 4
    int QuadLinha,QuadColuna;
    for ( QuadLinha=0; QuadLinha<n; QuadLinha+=4 ){ //Posiciona na primeira celular de cada bloco 4x4
        for ( QuadColuna=0; QuadColuna<n; QuadColuna+=4 ){ 
            int BlocoLinha,BlocoColuna; //Indices das celulas dentro de cada bloco 4x4
            for ( BlocoLinha=0; BlocoLinha<4 ;BlocoLinha++ ){ //Navega em cada celula do bloco 4x4
                for ( BlocoColuna=0; BlocoColuna<4; BlocoColuna++){ 
                    int CoordenadaCelula=((QuadLinha+BlocoLinha)*n)+(QuadColuna+BlocoColuna); //Numero da celula no quadrado magico seguindo padrao de 1 a n*n
                    if (( BlocoLinha == BlocoColuna ) || (3==(BlocoLinha+BlocoColuna))) {//Avalia se e´ diagonal do bloco 4x4
Quadrado[CoordenadaCelula]=CoordenadaCelula+1;
                    } else {
Quadrado[CoordenadaCelula]=(n*n)-CoordenadaCelula;
                    }
                }
            }
        }
    }
}
int main()
{   srand((unsigned) time(NULL));
        scanf( "%d" , &n ) ;
        soma = ((n*(n*n+1))/2) ;
        printf ("n = %d, Soma = %d\n", n,soma );
        int Quadrado[n*n]; // Quadrado magico 
        int Linha, Coluna; 
        for ( Linha=0 ;Linha<n ;Linha++ ){ //Inicialia todas as celulas com 0
            for ( Coluna=0 ; Coluna<n ; Coluna++ ){
                Quadrado[(Linha*n)+Coluna]=0;
            }
        }

        if ( n%2 > 0 ) { //Avalia se quadrado tenha lado de tamanho impar
            Hindu(Quadrado);
        } else if ( 0 == n%4 ) { //Avalia se o quadrado tem lado multiplo de 4
            JacobMurugan(Quadrado);
        }
        QuadradoExibir(Quadrado);
    return 0;
}
