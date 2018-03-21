
#include "fila.h"
//#include "usuario.h"

void FilaNova(Fila *fila){
    fila->primeiro = malloc(sizeof(NodeFila));
    fila->ultimo = fila->primeiro;
    fila->primeiro->proximo = NULL;
}

int FilaVazia(Fila fila){
    return (fila.primeiro == fila.ultimo);
}

void FilaAddUsuario(Fila *fila, Usuario x){
    fila->ultimo->proximo = malloc(sizeof(NodeFila));
    fila->ultimo = fila->ultimo->proximo;
    fila->ultimo->usuario = x;
    fila->ultimo->proximo = NULL;
}

void FilaRemoveUsuario(Fila *fila, Usuario *x){
    if (FilaVazia(*fila)){
        printf("Fila vazia!");
        return;
    }
    ApontadorFila p = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    *x = fila->primeiro->usuario;
    free(p);
}





