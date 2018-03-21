#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

/**************************************FILA********************/
//Definição do tipo Fila
struct elemento{
    struct clientes dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *fim;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

/*int consulta_Fila(Fila* fi, struct cliente *cl){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}*/

int insere_Fila(Fila* fi, struct clientes cl){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = cl;
    no->prox = NULL;
    if(fi->fim == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->fim->prox = no;
    fi->fim = no;
    fi->qtd++;

    return 1;
}

    int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    /*fi *temp = f -> prox;* //dados para retornar o elemento removido*/
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->fim = NULL;
    free(no);
    fi->qtd--;
    return fi;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

/*void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

//Pilha* AbasteçaAPilha (){
//Função responsável por reabastecer a pilha de bandejas
}*/

//Funcoes da pilha

/*void ExibirPilha(int topo){
     printf("\n");
        for(int temp=topo-1;temp >=0 ;temp--)
    {
      printf("Na posicao %d temos %d\n",temp,Pilha[temp]);
    }
     printf("\n");
     system("PAUSE");
}*/


/***********************************PILHA************************/
int InserirNaPilha(int topo, int max){
    if (topo==max){
          return 1;
      }
      else {
           topo++;
           }
}

int RemoverDaPilha(int topo){
    if (topo==0){
           return 0;
                }
    else {
         topo--;
         return 1;
         }

}
// Enquanto a pilha não estiver cheia insere bandejas respeitando o limite de 12 bandejas inseridas por vez
int EnchePilhaBandeja (int topo, int max){
    int tmp=0;
    while (InserirNaPilha(topo, max)!=1 && tmp < 12){
        InserirNaPilha(topo, max);
        tmp++;
    }
}
