#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include<math.h>
int n;
int g[100][100];
int dx = -1, dy = 1;
int slin(int lin){
  int ret=0;
  for(int j=0;j<n;j++) ret+=g[lin][j];
  return ret;
}

int scol(int col){
  int ret=0;
  for(int j=0;j<n;j++) ret+=g[j][col];
  return ret;
}

int sdiag_p(){
  int ret =0 ;
  for(int i=0;i<n;i++) ret+= g[i][i];
  return ret;
}

int sdiag_s(){
  int ret =0 ;
  for(int i=0;i<n;i++) ret+= g[i][n-i-1];
  return ret;
}

int confere()
{
  int Sl = slin(0);
  for(int i=0;i<n;i++) if(Sl != slin(i) ) return 0;
  for(int i=0;i<n;i++) if(Sl != scol(i) ) return 0;
  if(Sl!= sdiag_p()) return 0;
  if(Sl!= sdiag_s()) return 0;
  return 1;
}
void imprime()
{
  printf("n = %d, Soma = %d\n", n, slin(0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ", g[i][j]);
    }
    printf("\n");
  }
}
void nimpar()
{
  int x = 0, y= n/2;
  for(int i=1;i<=n*n;i++){
    if(g[x][y]){
      x -=dx;
      y -=dy;
      x++;
      y= (y+n)%n;
      x= (x+n)%n;
      g[x][y] = i;
    }else{
      g[x][y] = i;
    }
    x+=dx;
    y+=dy;
    y= (y+n)%n;
    x= (x+n)%n;
  }
}
int jafoi;
int usados[100];
int tam,nxt;
int SOMA_MAGICA;
void npar(int i, int somalinha)
{
  if(i==tam) {
    if(confere()) {
      imprime(), jafoi=1;
    }
    return;
  }
  for(int j=1;j<=tam;j++){
    if(jafoi) return;
    if(!usados[j]) {
      usados[j] = 1;
      g[i/n][i%n] = j;
      nxt = somalinha + j;
      if(i%n== 0) nxt = j;
      if(nxt <= SOMA_MAGICA) 
        npar(i+1,nxt); 
      usados[j] = 0;
    }
  }
}
int main()
{
  memset(g, 0 , sizeof(g));
  memset(usados, 0, sizeof(usados));
  scanf("%d", &n);
  tam = n*n;
  SOMA_MAGICA = (n* (n*n + 1))/2;
  if(n%2){
    nimpar();
    if(confere()){
      imprime();
    }else{
      puts("FAIL ;(");
    }
  }else{
    npar(0, 0);
  }
  return 0;
}
