#include <stdio.h>
#include <stdlib.h>

void kadane(int *v, int n, int &x, int &y , int &max_total)
{
 int max_atual;
 int xtemp;
 int i;

 max_atual = 0;
 max_total = -1;
 xtemp = 0;

 for(i=0;i<n;i++)
  {
    max_atual = max_atual + v[i];
    if(max_atual < 0)
     {
     max_atual = 0;
     xtemp = i+1;
     }

  if(max_atual > max_total)
  {
   max_total = max_atual;
   x = xtemp;
   y = i;
  }
 }
}

int main()
{
 int x,y,max;
 int v[] = {-2,1,-3,4,-1,2,1,-5,4};

 kadane(v,9,x,y,max);
 printf("segmento de soma maxima [%d-%d] com soma %d\n", x,y,max);
}
