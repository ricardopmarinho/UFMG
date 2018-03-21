#include "usuario.h"
#include "filaDinamica.h"
#include <stdlib.h>
#include <stdio.h>

struct fila_dinamica{
    struct elemento *inicio;
    struct elemento *fim;
};

struct elemento{
    USUARIO *aluno;
    struct elemento *prox;
};

typedef struct elemento Elem;


//FUNÇÕES DA FILA DINAMICA

//CRIAÇÃO
FILA* cria_fila(){
    FILA *fd = (FILA*)malloc(sizeof(FILA));
    if(fd != NULL){
        fd->fim = NULL;
        fd->inicio = NULL;
    }
    //printf("Fila Criada com Sucesso!\n\n");
    return fd;
}

//DESTRUIÇÃO

void destroi_fila(FILA *fd){
    if (fd != NULL){
        Elem *aux;
        while(fd->inicio != NULL){
            aux = fd->inicio;
            fd->inicio = fd->inicio->prox;
            remove_user(aux->aluno);
            free(aux);
        }
        free(fd);
        //printf("Fila destruida com sucesso!\n\n");
    }
}

//NUMERO DE PESSOAS NA FILA

int tamanho_fila(FILA *fd){
    if (fd == NULL){
        return 0;
    }
    int i = 0;
    Elem *aux = fd->inicio;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}
//CHECA SE A FILA ESTÁ VAZIA (retorna 1 caso vazia e 0 caso contrario)
//OBS NAO FAZ SENTIDO IMPLMENTAR ALGO PARA CHECAR SE A FILA ESTÁ CHEIA
//POIS ELA AUMENTA A MEDIDA QUE O USUARIO DESEJA
int fila_vazia(FILA *fd){
    if (fd == NULL){
        return 1;
    }
    if(fd->inicio == NULL){
        return 1;
    }
    return 0;
}

//INSERÇÃO DE USUARIO NA FILA (feita no final)

void insere_usuario_fila (FILA *fd, USUARIO *al){
    if(fd == NULL){
        printf("Falha na insercao do usuario!\n Fila inexistente!\n");
        return;
    }
    Elem *aux = (Elem*)malloc(sizeof(Elem));
    if(aux == NULL){
        printf("Falha na insercao do usuario!\n\n");
        return;
    }
    aux->aluno = al;
    aux->prox= NULL;

    if(fd->fim == NULL){
        fd->inicio = aux;
    }
    else{
        fd->fim->prox = aux;
    }
    fd->fim = aux;

}

//REMOÇÃO DE USUARIO NA FILA (feita no inicio)

void desenfileira(FILA *fd){
    if(fd == NULL){
        printf("Falha na operacao desenfileira!\n Fila inexistente!\n");
        return;
    }
    if(fd->inicio == NULL){ //FILA VAZIA
        return;
    }
    Elem *aux = fd->inicio;
    fd->inicio = fd->inicio->prox;
    if(fd->inicio == NULL){ //FILA FICOU VAZIA APÓS DESENFILEIRAR
        fd->fim = NULL;
    }
    free(aux);
}

//ESSA FUNCAO PERMITE GUADAR OS DADOS DO USUARIO QUANDO ESTE SAI DE ALGUMA FILA
//EXEMPLO: FILADOCAIXA -> CAIXA, FILADABANDEJA -> PILHA DE BANDEJAS
USUARIO* transfere_usuario(FILA *fd){
    if(fd == NULL){
        printf("Falha na consulta!\n Fila inexistente!\n");
        return NULL;
    }
    if(fd->inicio == NULL){ //FILA VAZIA
        return NULL;
    }
    Elem *aux = fd->inicio;

    return aux->aluno;
}
