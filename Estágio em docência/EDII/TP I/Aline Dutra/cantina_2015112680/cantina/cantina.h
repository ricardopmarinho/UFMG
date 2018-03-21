#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	struct Node* prox;
	int tempo;
}Node;

void inicia(Node *FILA);
Node *aloca(int x);
void insere(Node *FILA, int tempo);
int vazia(Node *FILA);
void percorreFILA(Node *Fila);
int retira(Node *FILA);
void imprimeTempo(Node *FILA);
void iniciaPilha(Node *PILHA);
int vaziaPilha(Node *PILHA);
Node *alocaPilha();
void push(Node *PILHA);
void *pop(Node *PILHA);