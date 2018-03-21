#include "usuario.h"
#include "filaDinamica.h"
#include "pilhaEstatica.h"
#include <stdio.h>

#define MAX_BANDEJAS 30
#define REPOE_BANDEJA 10
#define TEMPO_REPOSICAO 12

int main(int argc, char *argv[]){
    //DECLARACAO DAS VARIAVEIS E ESTRUTURAS UTILIZADAS NO PROJETO
    FILA *filaCaixa = NULL, *filaBandeja = NULL;
    PILHA *pilhaBandejas = NULL;

    filaCaixa = cria_fila();
    filaBandeja = cria_fila();
    pilhaBandejas = cria_pilha(MAX_BANDEJAS, REPOE_BANDEJA);

    USUARIO *aluno = NULL, *caixa = NULL, *bandeja = NULL;

    int qtd = 0, atendidos = 0;
    int tempo = 0, tempoTotalGasto = 0, mediaTempoTotal;
    int i;
    //LOOP DE SIMULACAO DO PROGRAMA
    for(tempo = 0, qtd = 0; tempo<240; tempo++){
        //2 ALUNOS CHEGAM NA FILA DO CAIXA
        for(i=0; i<2; i++){
            qtd++;
            aluno = create_user(qtd);
            set_arrival_time(aluno, tempo);
            insere_usuario_fila(filaCaixa, aluno);
        }
        //BANDEJAS SAO REPOSTAS NA PILHA A CADA 12 ESPACOS DE TEMPO
        if(tempo % TEMPO_REPOSICAO == 0){
            repoe_pilha(pilhaBandejas);
        }
        //VERIFICA SE EXISTE ALGUEM NO CAIXA E O COLOCA NA FILA PARA AS BANDEJAS
        if(caixa != NULL){
            insere_usuario_fila(filaBandeja, caixa);
            caixa = NULL;
        }
        //PEGA O PRIMEIRO USUARIO DA FILA DO CAIXA E O TRANSFERE PARA O CAIXA
        //CASO O CAIXA ESTEJA VAZIO
        if(caixa == NULL){
            caixa = transfere_usuario(filaCaixa);
            desenfileira(filaCaixa);
        }
        //ALUNO QUE ESTA NA PILHA DE BANDEJAS PEGA UMA, CASO SEJA POSSIVEL, E
        //SE SERVE, SAINDO DO SISTEMA E GRAVA SEU TEMPO TOTAL
        if(bandeja != NULL){
            if(!pilha_vazia(pilhaBandejas)){
                retira_bandeja(pilhaBandejas);
                atendidos++;
                set_total_time(bandeja, (tempo+4));
                print_total_time(bandeja);
                tempoTotalGasto += get_total_time(bandeja);
                remove_user(bandeja);
                bandeja = NULL;
            }
        }

        //TRANSFERE O PRIMEIRO USUARIO DA FILA DAS BANDEJAS PARA ONDE A PILHA
        //SE ENCONTRA, CASO NINGUEM ESTEJA ESPERANDO A REPOSICAO
        if(bandeja == NULL){
            bandeja = transfere_usuario(filaBandeja);
            desenfileira(filaBandeja);
        }
    }
    //CALCULO DA MEDIA
    mediaTempoTotal = tempoTotalGasto / atendidos;
    //IMPRIME RESULTADOS NA TELA
    printf("\nForam atendidos %d alunos\n", atendidos);
    printf("\nMedia de tempo gasto para ser atendido: %d\n", mediaTempoTotal);
    //LIBERA A MEMORIA DAS ESTRUTURAS
    destroi_fila(filaCaixa);
    destroi_fila(filaBandeja);
    destroi_pilha(pilhaBandejas);

    return 0;
}
