#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int chave;
	int chegada;
	int saida;
	int tempo_gasto;
}TPessoa;


struct Tcelula;
typedef struct t_celula_pessoa celula_pessoa;

typedef struct t_fila_pessoas {
	celula_pessoa *inicio;
	celula_pessoa *final;
} fila_pessoas;


fila_pessoas cria_fila_pessoas(void);
void libera_fila_pessoas(fila_pessoas*);
void insere_fila_pessoas(fila_pessoas*, TPessoa*);
TPessoa* remove_fila_pessoas(fila_pessoas*);
bool fpessoas_ta_vazia(fila_pessoas);



