#include "Pilha.h"
#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include "PILHA_VETOR.h"
#include "FILA_VETOR.h"
#define MAX 30                             //MUDA O TAMANHO DA PILHA DE BANDEJA
#define FUNCIONAMENTO 240                  //MUDA A QUANTIDADE DE MINUTOS QUE O RESTAURANTE FICA ATENDENDO
#define QCAIXAS 2                          //MUDA A QUANTIDADE DE CAIXAS PARA ATENDIMENTO. SE 1 OU 2.



//===================================================================================================== INICIO DAS FUNÇÕES DA TAD PILHA ARRANJO
void FPVaziaV(TPilha *Pilha) {
    Pilha->Topo = 0;
}

int VaziaV(TPilha Pilha) {
    if(Pilha.Topo == 0){
        return 1;
    }else{
        return 0;
    }
}

void EmpilhaV(TBANDEJA x, TPilha *Pilha) {
    if (Pilha->Topo == MAX)
        printf("Erro: pilha cheia\n");
    else {
        Pilha->BANDEJA[Pilha->Topo] = x;
        Pilha->Topo++;
    }
}

int DesempilhaV(TPilha *Pilha, TBANDEJA *BANDEJA) {
    if (VaziaV(*Pilha)){
        return 1;
    }else {
        *BANDEJA = Pilha->BANDEJA[Pilha->Topo - 1];
        Pilha->Topo--;
        return 0;
    }

}

int TamanhoV(TPilha Pilha) {
    return Pilha.Topo;
}

//===================================================================================================== FIM DAS FUNÇÕES DA TAD PILHA ARRANJO

//===================================================================================================== INICIO DAS FUNÇÕES DA TAD PILHA PONTEIRO
void FPVazia(TipoPilha *Pilha) {
    Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia_pilha(TipoPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoItem x, TipoPilha *Pilha) {
    TipoApontador Aux = (TipoApontador)malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item) {
    TipoApontador q;
    if (Vazia_pilha(*Pilha)) {
        printf("Erro: Pilha vazia\n");
        return;
    }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha) {
    return Pilha.Tamanho;
}

void Imprime_pilha(TipoPilha *Pilha){
    TipoPilha P_aux;
    TipoItem x;
    FPVazia(&P_aux);
    while(!Vazia_pilha(*Pilha)){
        Desempilha(Pilha, &x);
        Empilha(x, &P_aux);
    }
    while(!Vazia_pilha(P_aux)){
        Desempilha(Pilha, &x);
        printf("%d\n", x.Chave);
    }

}

//============================================================================================================ FIM DAS FUNÇÕES TAD PILHA

//=========================================================================================================== INICIO DAS FUNÇÕES DA TAD LISTA
void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int Vazia_fila(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TItem x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
}

void Desenfileira(TFila *Fila, TItem *Item) {
    if (Vazia_fila(*Fila)) {
        printf("Erro: fila vazia\n");
        return;
    }
    Apontador q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->Item;
    free(q);
}

//============================================================================================================ FIM DAS FUNÇÕES TAD FILA


int main(){

    TFila Fila_ficha;           //FILA DO CAIXA
    FFVazia(&Fila_ficha);

    TFila Fila_bandeja;         //FILA DA BANDEJA
    FFVazia(&Fila_bandeja);

    TPilha Pilha_bandeja;       //PILHA DE BANDEJAS
    FPVaziaV(&Pilha_bandeja);
    TBANDEJA Bandeja;
    Bandeja.Chave = 0;

    TFila Fila_comida;         //FILA DA COMIDA
    FFVazia(&Fila_comida);

    TItem Matricula;
    TItem Aluno;
    TItem Aluno2;
    Matricula.Chave = 2017010000;


    int i = 0, j = 0, CAIXA_1 = 0, N_CAIXA_1 = 0, CAIXA_2 = 0, N_CAIXA_2 = 0, contador = 1, Q_alunos = 0, QuantCaixas = 0;
    float tempo = 0;

    FILE *LOG;
    LOG = fopen("LOG.txt", "wt");



    tempo = FUNCIONAMENTO;
    Bandeja.Chave = MAX;
    QuantCaixas = QCAIXAS;



    if((QuantCaixas%2) == 0){

            printf("%d CAIXAS ATENDENDO.\n\n", QuantCaixas);
            //------------------------------------ 1º minuto-------------------------------------------------------------------------------------------------------------------

            for(i = MAX; i > 0; i--){                                           //Enchenndo a Pilha de bandeja pela primeira vez.
                EmpilhaV(Bandeja, &Pilha_bandeja);
            }

            printf("tamanho da pilha: %d\n\n", TamanhoV(Pilha_bandeja));




            while(tempo > 0){
                    for(i = 0; i < 2; i++){
                        Matricula.Chave = Matricula.Chave + 1;                  //ENTRADA DE DOIS ALUNOS NA FILA
                        Enfileira(Matricula, &Fila_ficha);
                    }


                    Desenfileira(&Fila_ficha, &Aluno);
                    CAIXA_1 = Aluno.Chave;                                      //ENTRADA DO ALUNO NO CAIXA 1
                    N_CAIXA_1 = N_CAIXA_1 + 1;
                    fprintf(LOG,"Aluno atendido no CAIXA 1: %d\n", CAIXA_1);

                    Desenfileira(&Fila_ficha, &Aluno2);
                    CAIXA_2 = Aluno2.Chave;                                      //ENTRADA DO ALUNO NO CAIXA 2
                    N_CAIXA_2 = N_CAIXA_2 + 1;
                    fprintf(LOG,"Aluno atendido no CAIXA 2: %d\n", CAIXA_2);


                    Enfileira(Aluno, &Fila_bandeja);                            //ENTRADA DO ALUNO 1 NA FILA DA BANDEJA
                    Enfileira(Aluno2, &Fila_bandeja);                           //ENTRADA DO ALUNO 2 NA FILA DA BANDEJA



                    if((contador%12) == 0 ){                                    //Se contador for multiplo de 12, carrega mais 10 bandejas na pilha de bandeja
                        for(j = 10; j > 0; j--)
                            EmpilhaV(Bandeja, &Pilha_bandeja);
                    }



                    if(VaziaV(Pilha_bandeja) == 0){                             //Se tiver bandeja na pilha, o aluno sai da fila da bandeja
                        Desenfileira(&Fila_bandeja, &Aluno);
                        DesempilhaV(&Pilha_bandeja, &Bandeja);
                    }


                    if((contador%4) == 0 ){
                        Q_alunos = Q_alunos + 1;
                    }

                    tempo = tempo - 1;
                    contador = contador + 1;

            }
            tempo = contador;
            fprintf(LOG,"QUANTIDADE DE ALUNOS COM REFEICAO PRONTA: %d\n", Q_alunos);
            fprintf(LOG,"TEMPO CORRIDO DE ATENDIMENTO: %d HORAS\n", contador/60);
            fprintf(LOG,"Tempo Medio de atendimento: %d.\n", contador/Q_alunos);
            printf("Quantidade de alunos com refeicao pronta: %d\n", Q_alunos);
            printf("Quantidade de alunos que compraram fichas: %d\n", N_CAIXA_1+N_CAIXA_2);
            printf("Tempo corrido: %d horas\n", contador/60);
            printf("Tempo Medio de atendimento para cada aluno.\nDesde a entrada na fila ate a saida com os alimentos: %d minutos por pessoa.\n", contador/Q_alunos);


    }else{
            printf("%d CAIXAS ATENDENDO.\n\n", QuantCaixas);
            //------------------------------------ 1º minuto-------------------------------------------------------------------------------------------------------------------

            for(i = MAX; i > 0; i--){                                           //Enchenndo a Pilha de bandeja pela primeira vez.
                EmpilhaV(Bandeja, &Pilha_bandeja);
            }

            printf("tamanho da pilha: %d\n\n", TamanhoV(Pilha_bandeja));




            while(tempo > 0){
                    for(i = 0; i < 2; i++){
                        Matricula.Chave = Matricula.Chave + 1;                  //ENTRADA DE DOIS ALUNOS NA FILA
                        Enfileira(Matricula, &Fila_ficha);
                    }


                    Desenfileira(&Fila_ficha, &Aluno);
                    CAIXA_1 = Aluno.Chave;                                      //ENTRADA DO ALUNO NO CAIXA
                    N_CAIXA_1 = N_CAIXA_1 + 1;
                    fprintf(LOG,"Aluno atendido: %d\n", CAIXA_1);


                    Enfileira(Aluno, &Fila_bandeja);                            //ENTRADA NA FILA DA BANDEJA



                    if((contador%12) == 0 ){                                    //Se contador for multiplo de 12, carrega mais 10 bandejas na pilha de bandeja
                        for(j = 10; j > 0; j--)
                            EmpilhaV(Bandeja, &Pilha_bandeja);
                    }



                    if(VaziaV(Pilha_bandeja) == 0){                             //Se tiver bandeja na pilha, o aluno sai da fila da bandeja
                        Desenfileira(&Fila_bandeja, &Aluno);
                        DesempilhaV(&Pilha_bandeja, &Bandeja);
                    }


                    if((contador%4) == 0 ){
                        Q_alunos = Q_alunos + 1;
                    }

                    tempo = tempo - 1;
                    contador = contador + 1;

            }
            tempo = contador;
            fprintf(LOG,"QUANTIDADE DE ALUNOS COM REFEICAO PRONTA: %d\n", Q_alunos);
            fprintf(LOG,"TEMPO CORRIDO DE ATENDIMENTO: %f HORAS\n", tempo/60);
            fprintf(LOG,"Tempo Medio de atendimento: %d.\n", contador/Q_alunos);
            printf("Quantidade de alunos com refeicao pronta: %d\n", Q_alunos);
            printf("Quantidade de alunos que compraram fichas: %d\n", N_CAIXA_1);
            printf("Tempo corrido: %f horas\n", tempo/60);
            printf("Tempo Medio de atendimento para cada aluno.\nDesde a entrada na fila ate a saida com os alimentos: %d minutos por pessoa.\n", contador/Q_alunos);
    }

    return 0;


}
