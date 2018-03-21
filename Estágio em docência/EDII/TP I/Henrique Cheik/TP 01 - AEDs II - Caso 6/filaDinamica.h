#ifndef FILADINAMICA_H
#define FILADINAMICA_H

typedef struct fila_dinamica FILA;

FILA* cria_fila();

void destroi_fila(FILA *fd);

int tamanho_fila(FILA *fd);

int fila_vazia(FILA *fd);

void insere_usuario_fila(FILA *fd, USUARIO *al);

void desenfileira(FILA *fd);

USUARIO* transfere_usuario(FILA *fd);

#endif // FILADINAMICA_H
