#include "pilha.h"
#include "fila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BANDEJAS 30

void main(int argc, char *argv[]){

int i=0;
int j;
int tempo = 1;
int fim = 0;
int Pessoas = 2;
int countPessoas = 2;
int tempoTotal = 240; //Tempo de 4 horas
int nFilaC = atoi(argv[1]);
int nFilaB = atoi(argv[2]);
int nPilha = atoi(argv[3]);
int countFinal = 0;
int teste = 0;
int mediaInd = 0;
int media = 0;

TFila *filaCaixa = (TFila*)malloc(nFilaC*sizeof(TFila)); //Alocação para Fila do caixa
TFila *filaBandeja = (TFila*)malloc(nFilaB*sizeof(TFila)); //Alocação para Fila da Bandeja
PilhaPratos *pilha = (PilhaPratos*)malloc(nPilha*sizeof(PilhaPratos));
TItem x; //Item da fila
TItemPilha y; //Item da pilha

FazArranjoFila(filaCaixa, nFilaC); //Cria um arranjo de filas do caixa
FazArranjoFila(filaBandeja, nFilaB); //Cria um arranjo de filas da bandeja
FazArranjoPilha(pilha, nPilha); //Cria um arranjo de pilhas de pratos

for (j = 0; j < nPilha; j++) {
  for(i=0;i<BANDEJAS;i++){ //Empilha o numero de pratos na pilha
    EmpilhaPratos(y, &pilha[j]);
  }
}

for(i=0;i<Pessoas-1;i++){ //Enfileira as primeiras duas pessoas no caixa
  x.Tempo = 0;
  Enfileira(x, &filaCaixa[EscolheFila(&filaCaixa, nFilaC)]);
  Enfileira(x, &filaBandeja[EscolheFila(&filaBandeja, nFilaB)]);
}

while(fim == 0){ //Loop principal do programa
  if(!Vazia(filaCaixa[EscolheFilaMaior(&filaCaixa, nFilaC)])){ //Verifica se as filas dos caixas estão vazias
    for (i = 0; i < nFilaC; i++) {
      if(!Vazia(filaCaixa[i])){
        Desenfileira(&filaCaixa[EscolheFilaMaior(&filaCaixa, nFilaC)], &x); //Desenfileira do caixa de maior fila
        Enfileira(x,&filaBandeja[EscolheFila(&filaBandeja, nFilaB)]); //Enfileira no caixa de menor fila
    }
  }
}
if(tempo<tempoTotal){ //Enquanto tempo for menor do que tempo total, vão enfileirar pessoas na fila do caixa
    for(i=0;i<Pessoas;i++){
      x.Tempo = tempo; //Guarda o tempo atual no TAD
      Enfileira(x,&filaCaixa[EscolheFila(&filaCaixa, nFilaC)]); //Enfileira no caixa de menor fila
      countPessoas++; //Quantidade de pessoas que entram na cantina
    }
  }

  if(!PilhaVazia(pilha[EscolhePilha(&pilha, nPilha)])){ // Verifica se a MAIOR pilha está vazia
    for(i=0; i < nFilaB; i++){ //Loop para acessar todas as filas da bandeja
      if(!Vazia(filaBandeja[i]) && !PilhaVazia(pilha[EscolhePilha(&pilha, nPilha)])) { //Verifica se a fila acessada e a pilha nao estão vazias
        Desenfileira(&filaBandeja[EscolheFilaMaior(&filaBandeja, nFilaB)], &x); //Desenfileira a maior fila
        mediaInd = (tempo - x.Tempo) + 5; //Media individual é o tempo que a pessoa entrou, menos o tempo que ela saiu + tempos constantes
        media += mediaInd; //Soma a media Ind a media total
        DesempilhaPratos(&pilha[EscolhePilha(&pilha, nPilha)], &y); //Desempilha 1 prato da pilha
        countFinal++; //Incrementa ao contador total de pessoas que foram atendidas
      }
    }
  }

  if(tempo%12==0){ //Condição para entrar de 12 em 12 minutos
    for (j = 0; j < nPilha; j++) {
      for(i=0;i<10;i++){ //10 bandejas serão repostas
        if(pilha[j].Tamanho < 29){ //Verifica se está obedencendo o tamanho total das pilhas
          EmpilhaPratos(y, &pilha[j]);
        }
      }
    }
  }
  tempo++;
  if(Vazia(filaBandeja[EscolheFilaMaior(&filaBandeja, nFilaB)]) && Vazia(filaCaixa[EscolheFilaMaior(&filaCaixa, nFilaC)])){
        fim = 1; //Verifica se existe algúem na fila da bandeja e na fila do caixa
    }
  }
media = media/countFinal;
printf("Pessoas que entraram: %d \n", countPessoas );
printf("Pessoas que sairam: %d \n", countFinal );
printf("Media de atendimento: %d minutos \n", media  );

free(filaCaixa);
free(filaBandeja);
free(pilha);
}
