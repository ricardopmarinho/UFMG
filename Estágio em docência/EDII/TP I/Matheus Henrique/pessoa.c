#include "pessoa.h"

void InitPessoas(Tpessoa *Pessoa, Tpessoa *Pessoa1, int CountTotal){
	Pessoa->Ident = CountTotal;
	Pessoa->Count = 0;
	Pessoa->JaArroz = 0;
	Pessoa->JaFeijao = 0;
	Pessoa->JaGuarnicao = 0;
	Pessoa->JaSalada = 0;
	
	Pessoa1->Ident = CountTotal;
	Pessoa1->Count = 0;
	Pessoa1->JaArroz = 0;
	Pessoa1->JaFeijao = 0;
	Pessoa1->JaGuarnicao = 0;
	Pessoa1->JaSalada = 0;
}