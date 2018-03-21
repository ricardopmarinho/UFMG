#include <stdio.h>
#include <stdlib.h>
#include "TP_AEDS2.h"
void Imprime(TFila *filaFichas) {//imprime o conteúdo da fila
    Apontador p;
    p = filaFichas->Frente->Prox;
    while (p != NULL) {
        printf("%d\n", p->Item.n_aluno);
        p = p->Prox;
    }
}
void FPVazia(TPilha *Pilha) {//cria uma pilha vazia
    Pilha->Topo = malloc(sizeof(TCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}
int Vazia(TPilha Pilha) {//verifica se a pilha está vazia
    return (Pilha.Topo == Pilha.Fundo);
}
void Empilha(conteudo aluno, TPilha *Pilha) {//coloca itens no topo da pilha
    Apontador Aux = malloc(sizeof(TCelula));
    Pilha->Topo->Item = aluno;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}
void Desempilha(TPilha *Pilha, conteudo *Item) {//tira itens do topo da pilha
    if (Vazia(*Pilha)) {
        printf("Erro lista vazia\n");
        return;
    }
    Apontador q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}
int Tamanho(TPilha *Pilha) {//retorna o tamanho da pilha
    return Pilha->Tamanho;
}

void FVazia(TFila *filaFichas){//cria uma fila vazia
    filaFichas->Frente=malloc(sizeof(TCelula));
    filaFichas->Tras=filaFichas->Frente;
    filaFichas->Frente->Prox=NULL;
}
int Vaziaf(TFila filaFichas){//verifica se a fila está vazia
    return(filaFichas.Frente==filaFichas.Tras);
}
void Enfileira(conteudo aluno, TFila *filaFichas){//coloca itens no final da fila
    filaFichas->Tras->Prox=malloc(sizeof(TCelula));
    filaFichas->Tras=filaFichas->Tras->Prox;
    filaFichas->Tras->Item=aluno;
    filaFichas->Tras->Prox=NULL;
}
void Desenfileira(TFila *filaFichas, conteudo *Item) {//retira itens do começo da fila
    if (Vaziaf(*filaFichas)) {
        printf("Erro: filaFichas vazia\n");
        return;
    }
    Apontador q = filaFichas->Frente;
    filaFichas->Frente = filaFichas->Frente->Prox;
    *Item = filaFichas->Frente->Item;
    free(q);
}

int main(){
    int tempo,j,m,contaalunos=0, aux, soma=0,acrescimo, alunosatendidos;
    int tempoindividual[480], tempo_saida[480];
    TFila *filaFichas=(TFila*)malloc(sizeof(TFila));//alocando as structs
    TFila *Fbandejas=(TFila*)malloc(sizeof(TFila));
    conteudo *Item=(conteudo*)malloc(sizeof(conteudo));
    conteudo *pile=(conteudo*)malloc(sizeof(conteudo));
    TPilha *Pilha=(TPilha*)malloc(sizeof(TPilha));
    conteudo aluno;
    conteudo auxiliar;
    conteudo bandeja;
    FVazia(filaFichas);//cria uma fila vazia de fichas
    FVazia(Fbandejas);//cria uma fila vazia de bandejas
    FPVazia(Pilha);//cria uma pilha vazia para bandejas
    for(j=1;j<=30;j++){//preenche a pilha de bandejas
        bandeja.n_bandeja=j;
        Empilha(bandeja,Pilha);
    }

    for(tempo=0;tempo<240;tempo++){
        acrescimo=0;
        aluno.n_aluno=contaalunos;
        Enfileira(aluno,filaFichas);//preenche a fila para fichas
        tempoindividual[aluno.n_aluno]=tempo;//tempo de entrada de cada aulno
        aluno.n_aluno++;
        Enfileira(aluno,filaFichas);
        tempoindividual[aluno.n_aluno]=tempo;

        Desenfileira(filaFichas, Item);//cada aluno pega uma ficha
        acrescimo++;// 1 min sendo atendido

        auxiliar=*Item;
        Enfileira(auxiliar, Fbandejas);//aluno entra na fila para bandejas
        acrescimo++;//1 min pegando bandeja
        if(Tamanho(Pilha)>0){
            Desenfileira(Fbandejas, Item);//aluno sai da fila de bandejas
            Desempilha(Pilha, pile);//aluno retira uma bandeja da pilha
            tempo_saida[Item->n_aluno]=tempo+4+acrescimo;//tempo de saída= tempo atual+4 min servindo o alimento + acrescimo sendo atendido
            if(tempo_saida[Item->n_aluno]==240)
                alunosatendidos=Item->n_aluno+1;
            }
        if(tempo%12==0){
            for(m=0;m<10;m++){
                if(Tamanho(Pilha)<30){
                Empilha(bandeja,Pilha);//10 bandejas são repostas na fila
                }
            }
        }
        contaalunos+=2;//2 alunos chegam a cada minuto
    }
    for(tempo=0;tempo<alunosatendidos;tempo++){//217 alunos atendidos
        soma=soma+(tempo_saida[tempo]-tempoindividual[tempo]);
    }
    printf("media %d para %d alunos atendidos", soma/alunosatendidos, alunosatendidos);//media do tempo de atendimento


    return 0;
}
