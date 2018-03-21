#ifndef TAD_FILA
#define TAD_FILA

#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

typedef struct NodeFila * ApontadorFila;

typedef struct NodeFila{
    Usuario usuario;
    ApontadorFila proximo;
} NodeFila;

typedef struct Fila{
    ApontadorFila primeiro;
    ApontadorFila ultimo;
} Fila;

// Cria uma nova fila
void FilaNova(Fila *fila);
int FilaVazia(Fila fila);

// Adiciona um novo usuario
void FilaAddUsuario(Fila *fila, Usuario x);

// Remove o primeiro da fila e retorna ele
void FilaRemoveUsuario(Fila *fila, Usuario *x);


#endif // TAD_FILA
