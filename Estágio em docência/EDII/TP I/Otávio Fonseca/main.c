#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
#define max 30
#define tmax 30
int main(){

int Pilha[max];//
int topo=0;

    struct clientes cliente;

    int tempo=0; //Tempo geral de an�lise
    int tbandejas=0;//Tempo entre uma reposi�ao e outra das bandejas
    int tmedio=0;//Tempo m�dio
    int somadostempos=0;//Soma de todos os tempos gastos
    int nclientes=0;//Marca o n�mero de clientes atendidos
    Fila* filaDoCaixa = cria_Fila();
    Fila* filaDaBandeja = cria_Fila();


    while(tempo<tmax){
        cliente.tempodechegada=tempo;
        insere_Fila(filaDoCaixa, cliente);//Insere cliente na fila e informa o tempo no qual ele chegou
        //filaDoCaixa->fim->dados.tempodechegada = tempo;//Seta o tempo de chegada do �ltimo cliente na fila
        cliente.tempodechegada=tempo;
        insere_Fila(filaDoCaixa, cliente);//Insere um segundo cliente na fila e informa o tempo no qual ele chegou
        //filaDoCaixa->fim->dados.tempodechegada = tempo;//Seta o tempo de chegada do �ltimo cliente na fila
        insere_Fila(filaDaBandeja, &(filaDoCaixa->inicio));//Insere na fila da bandeja o primeiro da fila do caixa
        remove_Fila(filaDoCaixa);//Remove da fila do caixa

        if(topo!= 0){//Se a pilha das bandejas n�o estiver vazia retira uma bandeja e remove um cliente da fila
           somadostempos+=(tempo - filaDaBandeja->inicio.dados.tempodechegada)+4;//Soma o tempo gasto pelo usu�rio que acabou de ser servido aos demais tempos
            remove_Fila(filaDaBandeja);
            RemoverDaPilha (topo);
        }
        tbandejas++;
        if(tbandejas==12){//Quando o tempo das badejas alcan�a 12 repoe as bandejas
            EnchePilhaBandeja (topo, max);//fun��o para repor 12 bandejas ou at� encher a pilha com no m�ximo 30 bandejas
            tbandejas=0;
        }
        tempo++;
    }
    tmedio= somadostempos/(tmax*2);
}


