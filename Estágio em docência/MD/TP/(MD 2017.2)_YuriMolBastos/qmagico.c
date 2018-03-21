# include <stdio.h>  
#include <stdlib.h>  

int main(int argc, char *argv[]){  

 int n;
 int i, j;
 int aux;
 int mat[5][5];  

 scanf("%d", &n) ;

 	if (n % 2 == 0){  
  		aux = 1;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++, aux++)
				mat[i][j] = aux; 
				
		for(i = 0, j = (n-1); i < n/2; i++, j--){
			aux = mat[i][i];
			mat[i][i] = mat[j][j];
			mat[j][j] = aux;
		}
		
		for(i = 0, j = (n-1); i < n/2; i++, j--){
			aux = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = aux;
		}
		
		printf("\n");
		printf("n = %d, Soma = %d\n\n", n, n*(n*n+1)/2);
		
		for (i = 0 ; i < n ; i++){ 
   			for (j = 0 ; j < n ; j++){  
   				printf("%d\t", mat[i][j]);  
   			} 
  			printf("\n\n");  
  		}   
   	}else{  
 		j = (n + 1) / 2 - 1;
 		i = 0;  
  		for(aux = 1 ; aux <= n * n ; aux++){  
  		
  			mat[i][j] = aux ;

   			if(aux % n == 0){  
   				i = i + 1;  
   			}else{
    			if(i == 0)i = n-1;  
    			else{i = i - 1;} 

    			if(j == n - 1)j = 0;  
    			else{j = j + 1;}  
   			}
  		} 
  		printf("\n");
  		printf("n = %d, Soma = %d\n\n", n, n*(n*n+1)/2);
  		
  		for (i = 0 ; i < n ; i++){  
   			for (j = 0 ; j < n ; j++){  
   				printf("%d\t", mat[i][j]);  
   			} 
   			printf("\n\n");  
  		}  
 
 	}  

	return 0;
}   
