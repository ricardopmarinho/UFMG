#ifndef GENERICA_H_
#define GENERICA_H_

typedef struct Pessoa{
	int id;
	int entrouCantina;
	int saiuCantina;
}Pessoa;

typedef struct Node{
	Pessoa *p;
	struct Node *next, *prev;
}Node;

typedef struct Generica{
	Node *primeiro, *ultimo;
	int tam;
}Generica;




Pessoa* criaPessoa(int id);
Generica* CriaGenericaVazia();
void insereElemento(Generica *l, Pessoa *p);
Pessoa* desempilha(Generica *l);
Pessoa* desenfileira(Generica *l);
void imprimeGenerica(Generica *l);
void liberaGenerica(Generica *l);

void setEntrou(Pessoa *p, int tempo);
void setSaiu(Pessoa *p, int tempo);
int tamGenerica(Generica *g);
void tiraBandeja(Generica *pilha);
void colocaBandeja(Generica *pilha, int qtd);
int temBandeja(Generica *pilha);
int temGente(Generica *fila);


void removeElemento(Generica *l, int id);

int calculaTempoMedio(Generica *l);

#endif
