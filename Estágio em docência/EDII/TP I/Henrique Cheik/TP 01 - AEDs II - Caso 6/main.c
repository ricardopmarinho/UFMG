#include "usuario.h"
#include "filaDinamica.h"
#include "pilhaEstatica.h"
#include <stdio.h>

#define MAX_BANDEJAS 30
#define REPOE_BANDEJA 10
#define TEMPO_REPOSICAO 10

int main(int argc, char *argv[]){
    //DECLARACAO DAS VARIAVEIS E ESTRUTURAS UTILIZADAS NO PROJETO
    FILA *filaCaixa1 = NULL, *filaCaixa2 = NULL;
    FILA *filaBandeja1 = NULL, *filaBandeja2 = NULL;
    PILHA *pilhaBandejas1 = NULL, *pilhaBandejas2 = NULL;

    filaCaixa1 = cria_fila(), filaCaixa2 = cria_fila();
    filaBandeja1 = cria_fila(), filaBandeja2 = cria_fila();

    pilhaBandejas1 = cria_pilha(MAX_BANDEJAS, REPOE_BANDEJA);
    pilhaBandejas2 = cria_pilha(MAX_BANDEJAS, REPOE_BANDEJA);

    USUARIO *aluno = NULL;
    USUARIO *caixa1 = NULL, *caixa2 = NULL;
    USUARIO *bandeja1 = NULL, *bandeja2 = NULL;

    int qtd = 0, atendidos = 0;
    int tempo = 0, tempoTotalGasto = 0, mediaTempoTotal;
    //LOOP DE SIMULACAO DO PROGRAMA
    for(tempo = 0, qtd = 0; tempo<240; tempo++){
        //2 ALUNOS CHEGAM NAS FILAS DOS CAIXAS
        //CAIXA 1
        qtd++;
        aluno = create_user(qtd);
        set_arrival_time(aluno, tempo);
        insere_usuario_fila(filaCaixa1, aluno);
        //CAIXA 2
        qtd++;
        aluno = create_user(qtd);
        set_arrival_time(aluno, tempo);
        insere_usuario_fila(filaCaixa2, aluno);

        //BANDEJAS SAO REPOSTAS NAS PILHAS A CADA 12 ESPACOS DE TEMPO
        if(tempo % TEMPO_REPOSICAO == 0){
            repoe_pilha(pilhaBandejas1);
            repoe_pilha(pilhaBandejas2);
        }
        //VERIFICA SE EXISTE ALGUEM EM ALGUM DOS CAIXAS
        //E O COLOCA NA FILA PARA AS BANDEJAS
        if(caixa1 != NULL){
            insere_usuario_fila(filaBandeja1, caixa1);
            caixa1 = NULL;
        }
        if(caixa2 != NULL){
            insere_usuario_fila(filaBandeja2, caixa2);
            caixa2 = NULL;
        }
        //PEGA O PRIMEIRO USUARIO DA FILA DO CAIXA E O TRANSFERE PARA O CAIXA
        //CASO O CAIXA ESTEJA VAZIO
        if(caixa1 == NULL){
            caixa1 = transfere_usuario(filaCaixa1);
            desenfileira(filaCaixa1);
        }
        if(caixa2 == NULL){
            caixa2 = transfere_usuario(filaCaixa2);
            desenfileira(filaCaixa2);
        }
        //ALUNO QUE ESTA NA PILHA DE BANDEJAS PEGA UMA, CASO SEJA POSSIVEL, E
        //SE SERVE, SAINDO DO SISTEMA E GRAVA SEU TEMPO TOTAL
        if(bandeja1 != NULL){
            if(!pilha_vazia(pilhaBandejas1)){
                retira_bandeja(pilhaBandejas1);
                atendidos++;
                set_total_time(bandeja1, (tempo+4));
                print_total_time(bandeja1);
                tempoTotalGasto += get_total_time(bandeja1);
                remove_user(bandeja1);
                bandeja1 = NULL;
            }
        }
        if(bandeja2 != NULL){
            if(!pilha_vazia(pilhaBandejas2)){
                retira_bandeja(pilhaBandejas2);
                atendidos++;
                set_total_time(bandeja2, (tempo+4));
                print_total_time(bandeja2);
                tempoTotalGasto += get_total_time(bandeja2);
                remove_user(bandeja2);
                bandeja2 = NULL;
            }
        }

        //TRANSFERE O PRIMEIRO USUARIO DA FILA DAS BANDEJAS PARA ONDE A PILHA
        //SE ENCONTRA, CASO NINGUEM ESTEJA ESPERANDO A REPOSICAO
        if(bandeja1 == NULL){
            bandeja1 = transfere_usuario(filaBandeja1);
            desenfileira(filaBandeja1);
        }
        if(bandeja2 == NULL){
            bandeja2 = transfere_usuario(filaBandeja2);
            desenfileira(filaBandeja2);
        }
    }
    //CALCULO DA MEDIA
    mediaTempoTotal = tempoTotalGasto / atendidos;
    //IMPRIME RESULTADOS NA TELA
    printf("\nForam atendidos %d alunos\n", atendidos);
    printf("\nMedia de tempo gasto para ser atendido: %d\n", mediaTempoTotal);
    //LIBERA A MEMORIA DAS ESTRUTURAS
    destroi_fila(filaCaixa1);
    destroi_fila(filaCaixa2);
    destroi_fila(filaBandeja1);
    destroi_fila(filaBandeja2);
    destroi_pilha(pilhaBandejas1);
    destroi_pilha(pilhaBandejas2);

    return 0;
}
