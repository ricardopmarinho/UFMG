#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char * string;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 void troca(int *qm, int *a1, int *a2){
  char temporario;
  temporario = qm[*a1]; 
  qm[*a1] = qm[*a2]; 
  qm[*a2] = temporario;
}




void quadradomagicotm3(void){
	
	srand(time(0));
    int a,b,random1;
    


int q[]={2,1,4,3,5,9,6,7,8};





    while (q[0]+q[1]+q[2]!=15 || q[3]+q[4]+q[5]!=15|| q[6]+q[7]+q[ 8]!=15 || q[0]+q[4]+q[8] !=15 
        || q[0]+q[3]+q[6]!=15 || q[1]+q[4]+q[7]!=15|| q[2]+q[5]+q[8]!=15|| q[0]+q[4]+q[8]!=15 || q[2]+q[4]+q[6]!=15){
    
        while (q[4] > 5 ){
            a=4;
            b=(((rand()%4)+1)*2) -1;
            troca(q,&a,&b);
        }
            a=(((rand()%4)+1)*2) -1;
            b=(((rand()%4)+1)*2) -1;
               troca(q,&a,&b);

        
    
    }
   
    printf("%d %d %d\n%d %d %d\n%d %d %d\n",q[0],q[1],q[2],q[3],q[4],q[5],q[6],q[7],q[8]);
    
    }
	
	void quadradomagicotm4(void){
		int q[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
		int mudar[16]={0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
		int cont;
		for(cont=0;cont <16;cont++){
			if (mudar[cont]==1)
				q[cont]=16-cont +1;
		printf(" %d ",q[cont]);
		if((cont+1)%4==0)
			printf("\n");
		}
	 
		
		
	}
	void quadradomagicotm5(void){
		int q[]={11,24,7,20,3,4,12,25,8,16,17,5,13,21,9,10,18,1,14,22,23,6,19,2,15};
		
		int aux;
		for(aux=0;aux <25;aux++){
		printf(" %d ",q[aux]);
		if((aux+1)%5==0)
			printf("\n");
		
		}
	 
	 
		
		
	}
	
	
int main(void) {
		int n,soma;
		scanf("%d",&n);
				
		printf("n = %d, soma = %d\n",n,soma);
		if (n==3)
			quadradomagicotm3();
		if (n==4)
			quadradomagicotm4();
    	if(n==5)
    		quadradomagicotm5();
    
    return 0;
}
