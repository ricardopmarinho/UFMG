#include <stdio.h>
struct conteudo{
    int n_aluno;
    int n_bandeja;
};
typedef struct conteudo conteudo;
typedef struct Celula *Apontador;
typedef struct Celula{
    conteudo Item;
    Apontador Prox;
}TCelula;
typedef struct{
    Apontador Frente;
    Apontador Tras;
}TFila;
typedef struct {
    Apontador Fundo;
    Apontador Topo;
    int Tamanho;
} TPilha;

