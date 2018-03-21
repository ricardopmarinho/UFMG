#include<stdlib.h>
#include<stdio.h>


int main (int argc, char *argv[]){
	int i;
	scanf ("%d", &i);
	int quadrado[i][i], aux, aux2, col, lin, n, linanterior, colanterior, soma=0;
	for (lin=0; lin<i; lin++){
		for (col=0; col<i; col++){
			quadrado[lin][col]=0;
		}
	}

	
	if (!(i%2)){	
		for (lin=0; lin<i; lin++){
			for (col=0; col<i; col++){
				if ((col!=lin) && (lin!=(3-lin))) {
					quadrado[lin][col]=(i*lin+col+1);
				}
				else{
					quadrado[lin][col]=(i*(4-lin)-(col));
				}
			}
		}	
	}
	else{
		for(n=1; n<=(i*i); n++){
			if (n==1){
				lin=0;
				col=((i-1)/2);
				quadrado[lin][col]=1;
			}
			else{
				linanterior=lin;
				colanterior=col;
				lin--;
				col++;
				if(lin<0) lin=i-1;
				if(col>(i-1)) col=0;
				if((quadrado[lin][col])==(0)){
					quadrado[lin][col]=(n);
				}
				else {
					lin=linanterior;
					col=colanterior;
					lin++;
					if(lin>(i-1)) lin=0;
					quadrado[lin][col]=(n);										
					}	
			}
			}
		}
		for (lin=0; lin<i; lin++){
			for (col=0; col<i; col++){
				if (col==lin) soma=(soma+quadrado[lin][col]);
			}
		}
		printf ("n = %d, Soma = %d", i, soma);
	for (lin=0; lin<i; lin++){
		printf ("\n");
		for (col=0; col<i; col++){
			printf("%d ", quadrado[lin][col]);
		}
	}
}


