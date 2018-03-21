#include<stdio.h>
#include<stdlib.h>

main(){
  int soma,auxsoma,n,i,j,indfinal,indinicial;
  soma=0;
  scanf("%d ",&n);
  int vet[n];
  for(i=0;i<n;i++)
  scanf("%d",&vet[i]);
  for(j=0;j<n;j++){
    auxsoma=0;
    for(i=0;(i+j)<n;i++){
      auxsoma+=vet[i+j];
      if(soma<auxsoma){
      soma=auxsoma;
      indinicial=j;
      indfinal=i+j;
      }
    }
  }
  if(soma==0) printf("Soma: %d",soma);
  else printf("Soma: %d\nIndices: %d a %d",soma,indinicial+1,indfinal+1);
}
