#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

void VerificaParametro(char **argv, int *tam_caixa, int *tam_bandeja, 
	int *tam_prato, int *qtd_prato, int *tmp_prato, int *reposicao);
void IniciaFila(int tam_caixa, int tam_bandeja, t_fila ***caixa, t_fila ***bandeja);
void PreenchePilha(t_pilha *prato, t_conteudo *talher, int qtd_prato);
void IniciaPilha(int tam_prato, int qtd_prato, t_conteudo *talher, t_pilha ***prato);
void InserePessoa(t_item *pessoa, t_fila ***fila, int *id_pessoa, int tempo, int tam_fila,
	int qtd);
int Parametro(int tam_fila, int qtd);
void TrocaFila(t_item *pessoa, t_fila ***fila1, t_fila ***fila2, int tam_fila1, 
	int tam_fila2, int qtd, int tempo);
void ReporPrato(t_pilha ***pilha, t_conteudo *talher, int tam_prato, int tmp_prato, 
	int reposicao, int qtd_prato, int tempo);
int RemovePessoa(t_fila ***fila, t_pilha ***pilha, t_item *pessoa, t_conteudo *talher, 
	int tam_fila, int tam_pilha, int tempo);
int Funcionamento(t_fila ***bandeja, int tam_bandeja, int tempo, int maxtempo);
void LimpaPonteiros(t_fila ***fila1, t_fila ***fila2, t_pilha ***pilha, int tam_fila1, 
	int tam_fila2, int tam_pilha);
