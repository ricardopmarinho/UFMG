#include "fila.h"


Cliente * cria_cliente(int id, bool status) 
{
    Cliente * novoCliente = (Cliente*) malloc(sizeof(Cliente));
    if (novoCliente == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(0);
    }
    novoCliente->id = id;
    novoCliente->status = status;
    novoCliente->proximo = NULL;
    return novoCliente;
}


Fila * fila_vazia()
{
    Fila * fila = (Fila*) malloc(sizeof(Fila));
    if (fila == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(0);
    }
    fila->tamanho = 0;
    fila->inicio = NULL;
    return fila;
}


void mostrar_fila(Fila * fila)
{
    Cliente * atual = fila->inicio;
    if (fila->inicio == NULL)
        return;
    while (atual->proximo != NULL)
    {
        if(atual->status == true) 
            printf("A");
        else 
            printf("D");
        printf("%d,", atual->id);
        atual = atual->proximo;
    }
    if(atual->status == true) 
            printf("A");
        else 
            printf("D");
    printf("%d\n", atual->id);
}

void reiniciar_atividade(Fila * fila)
{
    Cliente * atual = fila->inicio;
    if (fila->inicio == NULL)
        return;
    while (atual->proximo != NULL)
    {
        atual->status = true; //pode se mover
        atual = atual->proximo;
    }
    atual->status = true; //o ultimo tbm pode se mover
}


void adicionar(int id, bool status, Fila * fila)
{
    Cliente * atual = NULL;
    if (fila->inicio == NULL)
    {
        fila->inicio = cria_cliente(id, status);
        fila->tamanho += 1;
    }
    else
    {
        atual = fila->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = cria_cliente(id, status);
        fila->tamanho += 1;
    }
}


void deletar(int id, Fila * fila)
{
    Cliente * atual = fila->inicio;
    Cliente * previous = atual;
    while (atual != NULL) {
        if (atual->id == id)
        {
            previous->proximo = atual->proximo;
            if (atual == fila->inicio)
                fila->inicio = atual->proximo;
            free(atual);
            return;
        }
        previous = atual;
        atual = atual->proximo;
    }
}


void destruir_fila(Fila * fila)
{
    Cliente * atual = fila->inicio;
    Cliente * proximo = atual;
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(fila);
}


int retirar_da_fila(Fila * fila)
{
    if (fila->inicio == NULL)
    {
        printf("Filaa vazia\n");
        exit(0);
    }

    Cliente * antiga_inicio = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    int id_antiga_inicio = antiga_inicio->id;
    free(antiga_inicio);
    return id_antiga_inicio;
}
