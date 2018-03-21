#ifndef PESSOA_H
#define PESSOA_H

typedef struct{
	int Ident;
	int Count;
	int JaArroz;
	int JaFeijao;
	int JaGuarnicao;
	int JaSalada;
	int JaServiu;
}Tpessoa;

typedef Tpessoa *ApontadorCaixa;
typedef Tpessoa *ApontadorBandejas;

void InitPessoas(Tpessoa *Pessoa, Tpessoa *Pessoa1, int CountTotal);

#endif