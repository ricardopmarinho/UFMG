#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Generica.h"

#define HORA_ALMOCO 240


int main(int argc, char *argv[]){

	int tempo, id_pessoa = 1;
	Generica *filaFicha = CriaGenericaVazia();
	Generica *filaFicha2 = CriaGenericaVazia();
	Generica *filaAlmoco = CriaGenericaVazia();
	Generica *pilhaBandeja = CriaGenericaVazia();
	Generica *pilhaBandeja2 = CriaGenericaVazia();
	Generica *filaAlimentos = CriaGenericaVazia();
	Generica *filaAlimentos2 = CriaGenericaVazia();
	Generica *usuarios = CriaGenericaVazia();
	Pessoa *bandejas = criaPessoa(30);
	Pessoa *bandejas2 = criaPessoa(30);
	insereElemento(pilhaBandeja, bandejas);
	insereElemento(pilhaBandeja2, bandejas2);
	Pessoa *caixa, *caixa2, *bandeja, *bandeja2, *servida, *servida2;
	bandeja = NULL;
	bandeja2 = NULL;
	for(tempo = 1; tempo <= HORA_ALMOCO; tempo++){

		//Chegam duas pessoas
		
		Pessoa *p1 = criaPessoa(id_pessoa++);

		insereElemento(filaFicha, p1);
		setEntrou(p1, tempo);
		Pessoa *p2 = criaPessoa(id_pessoa++);
		insereElemento(filaFicha2, p2);
		setEntrou(p2, tempo);
		caixa = NULL;
		//Uma pessoa vai pra fila comprar
		if(temGente(filaFicha)){
			caixa = desenfileira(filaFicha);

		}
		
		caixa2 = NULL;
		if(temGente(filaFicha2)){
			caixa2 = desenfileira(filaFicha2);

		}

		//Se tiver gente na fila de bandeja, e tiver bandeja disponível, usuario sai da fila de almoco
		if(bandeja == NULL && temGente(filaAlmoco) && temBandeja(pilhaBandeja)){
			tiraBandeja(pilhaBandeja);
			bandeja = desenfileira(filaAlmoco);
		}

		if(bandeja2 == NULL && temGente(filaAlmoco) && temBandeja(pilhaBandeja2)){
			tiraBandeja(pilhaBandeja2);
			bandeja2 = desenfileira(filaAlmoco);
		}
		

		//Se tiver quatro pessoas na fila de servir, a pessoa que entrou primeiro sai, pq foi servida
		servida = NULL;
		if(tamGenerica(filaAlimentos) == 4){
			servida = desenfileira(filaAlimentos);
		}

		servida2 = NULL;
		if(tamGenerica(filaAlimentos2) == 4){
			servida2 = desenfileira(filaAlimentos2);
		}

		//Se existe gente servida imprime a pessoa e em qual slot de tempo foi servida
		if(servida){
			setSaiu(servida, tempo);
			printf("Pessoa id: %d foi servida no tempo: %d Entrou %d Saiu %d Tempo Atendimento %d\n", servida->id, tempo, servida->entrouCantina, servida->saiuCantina, servida->saiuCantina - servida->entrouCantina);
			insereElemento(usuarios, servida);
		}

		if(servida2){
			setSaiu(servida2, tempo);
			printf("Pessoa id: %d foi servida no tempo: %d Entrou %d Saiu %d Tempo Atendimento %d\n", servida2->id, tempo, servida2->entrouCantina, servida2->saiuCantina, servida2->saiuCantina - servida2->entrouCantina);
			insereElemento(usuarios, servida2);
		}

		//Quando temos um tempo multiplo de 12, sao colocadas mais 10 bandejas na pilha
		if(tempo%12 == 0){
			colocaBandeja(pilhaBandeja, 10);
			colocaBandeja(pilhaBandeja2, 10);
		}

//////////////////////////Preparar para o proximo tempo


		//Pessoa que comprou vai pra fila de bandeja
		if(caixa){
			insereElemento(filaAlmoco, caixa);
		}

		if(caixa2){
			insereElemento(filaAlmoco, caixa2);
		}


		//E entra na fila de servir, se tiver menos de 4 pessoas lá, já que só temos quatro espaços.
		if(bandeja){
			if(tamGenerica(filaAlimentos) < 4){
				insereElemento(filaAlimentos, bandeja);
				bandeja = NULL;
			}
			else if(tamGenerica(filaAlimentos2) < 4){
				insereElemento(filaAlimentos2, bandeja);
				bandeja = NULL;
			}
		}

		if(bandeja2){
			if(tamGenerica(filaAlimentos) < 4){
				insereElemento(filaAlimentos, bandeja2);
				bandeja2 = NULL;
			}
			else if(tamGenerica(filaAlimentos2) < 4){
				insereElemento(filaAlimentos2, bandeja2);
				bandeja2 = NULL;
			}
		}

	}

	printf("Tempo medio: %d minutos, para %d usuarios atendidos, num total de %d minutos de funcionamento da cantina.\n", calculaTempoMedio(usuarios), usuarios->tam, HORA_ALMOCO);
	liberaGenerica(filaFicha);
	liberaGenerica(filaAlmoco);
	liberaGenerica(pilhaBandeja);
	liberaGenerica(filaAlimentos);
	liberaGenerica(usuarios);
	return 0;

}
