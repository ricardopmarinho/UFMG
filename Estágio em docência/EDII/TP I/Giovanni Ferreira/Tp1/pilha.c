#include "pilha.h"

Bandeja * cria_bandeja(int id) {
    Bandeja * novaBandeja = (Bandeja*) malloc(sizeof(Bandeja));
    if (novaBandeja == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(0);
    }
    novaBandeja->id = id;
    novaBandeja->proximo = NULL;
    return novaBandeja;
}

Pilha * pilha_vazia()
{
    Pilha * pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(0);
    }
    pilha->tamanho = 0;
    pilha->Topo = NULL;
    return pilha;
}

void mostrar_pilha(Pilha * pilha)
{
    Bandeja * atual = pilha->Topo;
    if (pilha->Topo == NULL)
        return;
    while (atual->proximo != NULL)
    {
        printf("%d,", atual->id);
        atual = atual->proximo;
    }
    printf("%d\n", atual->id);
}

void push(Pilha * pilha)
{
    int id = 1;
    Bandeja * atual = NULL;
    if (pilha->Topo == NULL)
    {
        pilha->Topo = cria_bandeja(id);
        pilha->tamanho += 1;
    }
    else
    {
        atual = cria_bandeja(id);
        atual->proximo = pilha->Topo;
        pilha->Topo = atual;
        pilha->tamanho += 1;
    }
}

void pop(Pilha * pilha)
{
    if (pilha->Topo == NULL)
    {
        printf("Pilha vazia\n");
        exit(0);
    }

    Bandeja * old_Topo = pilha->Topo;
    pilha->Topo = pilha->Topo->proximo;
    pilha->tamanho -= 1;
    free(old_Topo);
}

void destruir_pilha(Pilha * pilha)
{
    Bandeja * atual = pilha->Topo;
    Bandeja * proximo = atual;
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(pilha);
}