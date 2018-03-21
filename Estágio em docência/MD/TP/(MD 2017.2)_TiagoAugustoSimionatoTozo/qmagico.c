#include<stdio.h>
#include<stdlib.h>
void QuadradoMagicoImpar(int n){
/*QUADRADO IMPAR*/
int i,j,k,l,x;
  int vet[n][n];
  for(i=0;i<n;i++)for(j=0;j<n;j++)vet[i][j]=0;
  j=0;i=n/2;k=j;l=i;
  vet[j][i]=1;
  for(x=2;x<=(n*n);x++){
    k-=1;l+=1;
    if(k==-1)k=(n-1);
    if(l==n)l=0;
    if(vet[k][l]!=0){k=j+1;l=i;}
    vet[k][l]=x;
    j=k;i=l;
  }
  printf(" n = %d, Soma = %d\n",n,(n*(n*n+1)/2));
  for(j=0;j<n;j++){
    for(i=0;i<n;i++)
      printf(" %d ",vet[j][i]);
    printf("\n");
  }
}/*FIM DO QUADRADO IMPAR*/


void main(){


  QuadradoMagicoImpar(3);printf("\n");
  /*QUADRADO MAGICO N=4*/
  int i,j,k,l,n,x,y;
  n=4;
  x=1;y=n*n;
  int vet[n][n];
  for(i=0;i<n;i++)for(j=0;j<n;j++)vet[i][j]=0;
  for(i=0;i<n;i++)for(j=0;j<n;j++)if((i+j==(n-1))||(i==j))vet[i][j]=17;
    for(j=0;j<n;j++)
      for(i=0;i<n;i++){
        if(vet[j][i]==17)vet[j][i]=x;
          x+=1;
    }
  for(j=0;j<n;j++)
      for(i=0;i<n;i++){
        if(vet[j][i]==0)vet[j][i]=y;
        y-=1;}
  printf("n = %d, Soma = %d\n",n,(n*(n*n+1)/2));
  for(j=0;j<n;j++){
      for(i=0;i<n;i++)
        printf(" %d ",vet[j][i]);
        printf("\n");}
/*FIM DO QUADRADO N=4*/
  printf("\n");
  QuadradoMagicoImpar(5);
}
