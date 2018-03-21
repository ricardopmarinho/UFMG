#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Generica.h"

Generica* CriaGenericaVazia(){
	Generica *new = (Generica *) malloc(sizeof(Generica)); //Criou a Generica
	new->primeiro = (Node *) malloc(sizeof(Node)); //Criou a celula sentinela, que é o primeiro node da lista, que não guarda nenhuma pessoa.

	new->ultimo = new->primeiro;
	new->primeiro->next = new->primeiro;
	new->primeiro->prev = new->primeiro;
	new->tam = 0;

	return new;
}



void setEntrou(Pessoa *p, int tempo){
	p->entrouCantina = tempo;
}
void setSaiu(Pessoa *p, int tempo){
	p->saiuCantina = tempo;
}

Pessoa* criaPessoa(int id){
	Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
	p->id = id;
	return p;
	
}

void insereElemento(Generica *l, Pessoa *p){
	Node *novo = (Node *) malloc(sizeof(Node));
	novo->p = p;
	novo->next = l->primeiro;
	novo->prev = l->ultimo;
	l->ultimo->next = novo;
	l->ultimo = novo;
	l->primeiro->prev = l->ultimo;
	l->tam++;

}

void removeElemento(Generica *l, int id){
	Node *ptr = l->primeiro->next;
	while(ptr != l->primeiro && ptr->p->id != id){
		ptr = ptr->next;
	}
	if(ptr != l->primeiro){
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		if(ptr == l->ultimo){
			l->ultimo = ptr->prev;
		}
		ptr->next = NULL;
		ptr->prev = NULL;
		free(ptr->p);
		free(ptr);
		l->tam--;
	}
}


Pessoa* desempilha(Generica *l){
	Node *ptr = l->ultimo;
	Pessoa *aux = ptr->p;
	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	l->ultimo = ptr->prev;
	l->tam--;
	free(ptr);

	return aux;

}

void tiraBandeja(Generica *pilha){
	(pilha->primeiro->next->p->id)--;	
}

void colocaBandeja(Generica *pilha, int qtd){
	(pilha->primeiro->next->p->id)+=qtd;	
}

int temBandeja(Generica *pilha){
	return 	pilha->primeiro->next->p->id > 0;
}

int temGente(Generica *fila){
	return fila->primeiro != fila->ultimo;
}

int tamGenerica(Generica *g){
	return g->tam;
}

Pessoa* desenfileira(Generica *l){
	Node *ptr = l->primeiro->next;
	Pessoa *aux = ptr->p;
	ptr->next->prev = ptr->prev;
	ptr->prev->next = ptr->next;
	if(ptr == l->ultimo)
		l->ultimo = ptr->prev;

	l->tam--;
	free(ptr);

	return aux;

}

void imprimeGenerica(Generica *l){
	Node *ptr = l->primeiro->next; //primeiro elemento
	while(ptr != l->primeiro){
		printf("%d\n", ptr->p->id);
		ptr = ptr->next;
	}
}


void liberaGenerica(Generica *l){
	while(l->primeiro != l->ultimo){
		removeElemento(l, l->primeiro->next->p->id);
	}
	free(l->primeiro);
	free(l);
}


int calculaTempoMedio(Generica *l){
	Node *ptr = l->primeiro->next;
	int soma = 0;
	while(ptr != l->primeiro){
		soma += (ptr->p->saiuCantina - ptr->p->entrouCantina);
		
		ptr = ptr->next;
	}

	return (soma/l->tam);
}
