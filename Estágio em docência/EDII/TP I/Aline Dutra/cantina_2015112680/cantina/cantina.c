#include "cantina.h"

void inicia(Node *FILA)
{
	FILA->prox = NULL;
}

void iniciaPilha(Node *PILHA)
{
 PILHA->prox = NULL;
}


int vazia(Node *FILA)
{
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;	
}

int vaziaPilha(Node *PILHA)
{
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}

Node *alocaPilha()
{
 Node *novo=(Node *) malloc(sizeof(Node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  return novo;
 }
}

void push(Node *PILHA)
{
 Node *novo=alocaPilha();
 novo->prox = NULL;

 if(vaziaPilha(PILHA))
  PILHA->prox=novo;
 else{
  Node *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
}

void *pop(Node *PILHA)
{
 if(PILHA->prox == NULL){
  printf("PILHA ja vazia\n\n");
  return NULL;
 }else{
  Node *ultimo = PILHA->prox,
              *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
 }
}

Node *aloca(int x)
{
	Node *novo=(Node *) malloc(sizeof(Node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		novo->tempo = x;
		return novo;
	}
}

void insere(Node *FILA, int tempo)
{
	Node *novo=aloca(tempo);
	novo->prox = NULL;

	if(vazia(FILA))
		FILA->prox=novo;
	else{
		Node *tmp = FILA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void percorreFila(Node *FILA){
	if(vazia(FILA)){
		//fila vazia, não acrescenta nada
	}
	else{

		Node *tmp = FILA->prox;
		while(tmp != NULL){
			tmp->tempo++;
			tmp = tmp->prox;


		}
	}
}

int retira(Node *FILA)
{
	int tempo;
	if(FILA->prox == NULL){
		return 0;
	}else{
		Node *tmp = FILA->prox;
		tempo = tmp->tempo;
		FILA->prox = tmp->prox;
		free(tmp);
		return tempo;
	}

}

void imprimeTempo(Node *FILA){
	if(vazia(FILA)){
		//fila vazia, não acrescenta nada
	}
	else{

		Node *tmp = FILA->prox;
		do{
			printf("\n\ntempo:%d\n", tmp->tempo);
			tmp = tmp->prox;

		}while(tmp != NULL);
	}
}