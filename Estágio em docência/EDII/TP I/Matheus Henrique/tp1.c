#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "pessoa.h"
#include "fila1.h"
#include "fila2.h"
#include "pilha.h"
#define COUNT 240

/*MAIN*/
	
int main(int argc, char *argv[]){
	
	int CountTotal, CountMedia = 0;
	int Media, Flag, Atendidos = 0;
	ApontadorCaixa Caixa1 = NULL;
	ApontadorBandejas BandejaDisponivel = NULL;

	Tfila1 Fila1;
	Tfila2 Fila2;
	Tpilha Pilha;
	Tpessoa Pessoa1, Pessoa2, PessoaArroz, PessoaFeijao, PessoaGuarnicao, PessoaSalada;
	
	InitFila1(&Fila1);
	InitFila2(&Fila2);
	InitPilha(&Pilha);
	
	for(CountTotal = 1; CountTotal <= COUNT; CountTotal++){
		InitPessoas(&Pessoa1, &Pessoa2, CountTotal);
		Enfileira1(Pessoa1, &Fila1);
		Enfileira1(Pessoa2, &Fila1);
		
		Desenfileira1(&Pessoa1, &Fila1);
		Caixa1 = &Pessoa1;
		Pessoa1.Count++;
		Enfileira2(Pessoa1, &Fila2);
	
		if(CountTotal % 12 == 0){
			AcrescentaBandeja(&Pilha);
		}
		
		if(PilhaVazia(Pilha)){
			BandejaDisponivel = NULL;
			Atendidos--;
		}
		else{
			Desempilha(&Pilha);
			Desenfileira2(&Pessoa2, &Fila2);
			Pessoa2.Count++;
			BandejaDisponivel = &Pessoa2;
		}
		
		
		if(PessoaGuarnicao.JaGuarnicao == 1 && PessoaGuarnicao.JaSalada == 0 && PessoaGuarnicao.Count > Flag){
			PessoaSalada = PessoaGuarnicao;
			PessoaSalada.JaSalada = 1;
		}
		if(PessoaFeijao.JaFeijao == 1 && PessoaFeijao.JaGuarnicao == 0){
			PessoaGuarnicao = PessoaFeijao;
			PessoaGuarnicao.JaGuarnicao = 1;
		}
		if(PessoaArroz.JaArroz == 1 && PessoaArroz.JaFeijao == 0){
			PessoaFeijao = PessoaArroz;
			PessoaFeijao.JaFeijao = 1;
		}
		if(BandejaDisponivel != NULL && BandejaDisponivel->JaArroz == 0){
			PessoaArroz = *BandejaDisponivel;
			PessoaArroz.JaArroz = 1;
			Flag = PessoaArroz.Count;
			PessoaArroz.Count++;
		}
		
		if(PessoaSalada.JaSalada == 1){
			Atendidos++;
			PessoaSalada.Count += (CountTotal - PessoaSalada.Ident);
			printf("%d\n", PessoaSalada.Count);
			CountMedia += PessoaSalada.Count;
		}
	}
	
	Media = CountMedia / Atendidos;
	printf("Atendidos: %d\n", Atendidos);
	printf("Media: %d\n", Media);
	return 1;
}


