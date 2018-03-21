#include <stdio.h>
#include <stdlib.h>
#include "cantina.h"


int main(){

	int tempo_total, tempo_aux, aux_comida, num_clientes, num_pratos = 0;
	float tempo_media;
	int entrada_filaFicha, entrada_filaBandeja, entrada_filaComida, insere_pratos, max_bandejas, intervalo;
	int i;

	printf("Bem vindo ao programa de controle da cantina!\n");
	printf("Escolha algumas configurações de controle das filhas e pilha para que a media de tempo gasto por cliente seja calculado.\n");
	printf("Digite o número de pessoas que chegam a fila de fichas por minuto:");
	scanf("%d",&entrada_filaFicha);
	printf("\nDigite o número de pessoas que são atendidas por minuto:");
	scanf("%d",&entrada_filaBandeja);
	printf("\nDigite o número de pessoas que pegam bandejas por minuto:");
	scanf("%d",&entrada_filaComida);
	printf("\nDigite o número máximo de bandejas:");
	scanf("%d",&max_bandejas);
	printf("\nDigite o intervalo de tempo para repor bandejas:");
	scanf("%d",&intervalo);
    //inicializar fila de compra de ficha;
	Node *FilaFicha = (Node *) malloc(sizeof(Node));

	if(!FilaFicha){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(FilaFicha);
    }


	//inicializar fila de bandejas e talheres;
	Node *FilaBandeja = (Node *) malloc(sizeof(Node));
	if(!FilaBandeja){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(FilaBandeja);
	}
	// inicilizar pilha de bandejas;
	
	//inicializar fila de servir comida;
	Node *FilaComida = (Node *) malloc(sizeof(Node));
	if(!FilaComida){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(FilaBandeja);
	}

	Node *PilhaPratos = (Node *) malloc(sizeof(Node));
	if(!PilhaPratos){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(PilhaPratos);
	}

	insere_pratos = intervalo;
	//fazer os whiles. Em cada iteração dois usuários chegam na fila de compra, uma pessoa é atendtempoa (sai da fila),
	tempo_total = 1;

	for(i=0;i<max_bandejas;i++){
		push(PilhaPratos);
		num_pratos++;
	}


	for(i=0;i<entrada_filaFicha;i++){
			insere(FilaFicha,0);
		}
	aux_comida = 4;
	tempo_media = 0;
	num_clientes = 0;
	// número de iteraçoes igual a quantidade de segundos
	for(tempo_total=0;tempo_total<240;tempo_total++){

		if (aux_comida == 0){
			if(vazia(FilaFicha)==0){
				tempo_aux = retira(FilaComida);
				tempo_media = tempo_media + tempo_aux;
				num_clientes++;
				aux_comida = 4;
			}
		}

		if(insere_pratos == 0){
			for(i=0;i<10;i++){
				if(num_pratos<=max_bandejas){
					push(PilhaPratos);
					num_pratos++;
				}
			}
			insere_pratos = intervalo;
		}

		// a cada iteração, x pessoas pegam bandeja:
		//for para quantidade de pessoas que pegam bandeja (saem da filaBandeja e entram na filaComida por segundo)
		percorreFila(FilaComida);
		for(i=0;i<entrada_filaComida;i++){
			if(vazia(FilaBandeja)==0){
				if(vaziaPilha(PilhaPratos) == 0){
					tempo_aux = retira(FilaFicha);
					pop(PilhaPratos);
					num_pratos--;
					insere(FilaComida, tempo_aux+1);
				}
			}
		}

		// a cada iteração, x pessoas são atendidas no caixa:
		//for para quantidade de pessoas que são atendidas no caixa (saem da filaFicha e entram na filaBandeja por segundo)
		percorreFila(FilaBandeja);
		for(i=0;i<entrada_filaBandeja;i++){
			if(vazia(FilaFicha)==0){
				tempo_aux = retira(FilaFicha);
				insere(FilaBandeja, tempo_aux+1);
			}
		}

		

		//TRATAR QUANTIDAD DE BANDEJAS NA PILHA, QUANDO INSERIR ETC

		percorreFila(FilaFicha);
		//for para quantidade de pessoas que vao entrar na filaFicha a cada segundo
		for(i=0;i<entrada_filaFicha;i++){
			insere(FilaFicha,0);
		}


		if(vazia(FilaComida)==0)
			aux_comida--;

		insere_pratos--;		

		//tratar caso de servir a comida, só tirar a pesso da fila a cada 4 iterações

	}
	tempo_media = tempo_media/num_clientes;
	printf("\ntempo medio: %f\n", tempo_media);
	//imprimeTempo(FilaFicha);

	


	return 0;
}

//gcc cantina.c main.c -o cantina -g 
//./cantina