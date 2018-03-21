#include "function.c"

int main() {
  TFila *ficha;
  ficha = (TFila*) malloc(sizeof(TFila));
  FFVazia(ficha);

  TFila *bet;//fila bandejas e talheres
  bet = (TFila*) malloc(sizeof(TFila));
  FFVazia(bet);

  TPilha *pilha_bandejas;
  pilha_bandejas = (TPilha*) malloc(sizeof(TPilha));
  FPVazia(pilha_bandejas);

  int tempo;
  int inicio = 0;
  int atraso = 0;
  int tempo_gasto = 0;
  int atendidos = 0;
  int cte = 6;
  //printf("Digite o tempo (em horas) a ser analisado" );
  //scanf("%d",&tempo);
  tempo = 4;
  tempo = (tempo*60) - 4;

  for(inicio; inicio < tempo; inicio++){
    if(inicio%12 == 0){
      Empilha10(pilha_bandejas);
    }

    Enfileira2(ficha,inicio);

    if(PegarBandeja(pilha_bandejas,bet)){
      tempo_gasto += inicio + cte + atraso;
      atendidos++;
    }else if (!VaziaF(*bet)) {
      atraso++;
    }

    DesenfileiraEnfileira(ficha,bet);
    DesenfileiraEnfileira(ficha,bet);

    if(inicio%2 == 0){
      cte-=1;
    }
  }

  printf("ATENDIDOS %d pessoas\n",atendidos);
  printf("MEDIA TEMPO GASTO POR PESSOA %d min\n",tempo_gasto/atendidos);



}
