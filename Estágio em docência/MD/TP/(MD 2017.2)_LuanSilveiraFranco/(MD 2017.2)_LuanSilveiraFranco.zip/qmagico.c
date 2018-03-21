
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int magicnum , lado , linprev , colprev , numero = 1 ;
	int i , j ;
	int errolin , errocol ;

	int quadrado[5][5] = {0} ;
	scanf("%d" , &lado) ;
	if(lado % 2 == 1){
		magicnum = ( lado * ( (lado * lado) + 1) ) / 2 ;
		quadrado[0][lado / 2] = numero ;
		linprev = ( lado - 1);
		colprev = ( (lado / 2) + 1 ) ;
		for(numero = 2 ; numero <= (lado * lado) ; numero++){
			if(linprev < 0 ) linprev = (lado - 1) ;
			if(colprev > ( lado - 1) ) colprev = 0;
			if(quadrado[linprev][colprev] != 0){
				linprev = (errolin + 1) ;
				if(linprev > (lado - 1) ) linprev = 0 ;
				colprev = errocol ;
				quadrado[linprev][colprev] = numero ;
			}else quadrado[linprev][colprev] = numero ;
			errolin = linprev ;
			errocol = colprev ;
			linprev-- ;
			colprev++ ;
		}
		printf("n = %d, Soma = %d\n" , lado , magicnum) ;
		for(i = 0 ; i < lado ; i++){
			for(j = 0 ; j < lado ; j++){
				printf("%d ", quadrado[i][j] ) ;
			}
		printf("\n") ;
	}
	}else{
		int cntcres = 0 , cntdecres = 17 ;
		magicnum = ( lado * ( (lado * lado) + 1) ) / 2 ;
		for (i = 0; i < lado ; ++i){
			for (j = 0; j < lado  ; ++j){
				cntcres++ ;
				cntdecres-- ;
				if(i == j) quadrado[i][j] = cntcres;
				else if(i==(lado-1-j)) quadrado[i][j] = cntcres ;
				else if(quadrado[i][j] == 0) quadrado[i][j] = cntdecres ;
			}
		}
		printf("n = %d, Soma = %d\n" , lado , magicnum) ;
		for(i = 0 ; i < lado ; i++){
			for(j = 0 ; j < lado ; j++){
				printf("%d ", quadrado[i][j] ) ;
			}
			printf("\n") ;
		}
	}	
	return 0;
}

