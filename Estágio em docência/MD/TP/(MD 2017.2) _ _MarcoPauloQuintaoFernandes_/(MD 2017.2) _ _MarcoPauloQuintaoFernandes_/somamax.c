#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include<math.h>
int v[100];
long long p[100];
int main()
{
  memset(v, 0 , sizeof(v));
  memset(p, 0 , sizeof(p));

  int n;
  scanf("%d", &n);
  long long int resp = 0;

  for(int i=1;i<=n;i++){
    scanf("%d", &v[i]);
    p[i] = v[i] + p[i-1];
  }

  int idxi = -1;
  int idxj = -1;
  for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
      if( resp <= p[j] - p[i-1] )
        resp = p[j] - p[i-1], idxi=i, idxj=j;
    
  printf("Soma: %lld\n", resp);
  if(idxi>-1)
    printf("Indices: %d a %d\n", idxi, idxj);
  else 
    printf("Indices: nenhum intervalo\n");
  
  return 0;
}
