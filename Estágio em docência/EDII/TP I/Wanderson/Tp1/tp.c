#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#define NUM_CHEGADA 2 //Numero de pessoas que chegao na fila a cada minuto
#define NUM_CAIXAS 1 //Numero de caixas operando
#define TEMPO_MAX 240 //Tempo de duracao do atendimento em minutos
#define TEMPO_REP 12 //Intervalo de reposicao das bandejas
#define REPOSICAO_BAND 10 //Numero de bandejas repostas a cada n minutos
#define TEMPO_SERVIR 4 //Tempo total para servir o almoco
#define NUM_ATENDENTES 1 //Numero de atendentes servindo os clientes

int main (int argc, char* argv[])
{
	//Declaracao variaveis
	unsigned int min = 0;
	int i, n_clientes ,j = 0;
	f_fila caixa, band, almoco;
	p_pilha bandeja;
	f_tempo ini, final, aux;
	
	//Inicializacao variaveis
	n_clientes = 0;
	faz_p_vazia(&bandeja);
	faz_f_vazia (&caixa);
	faz_f_vazia (&band);
	faz_f_vazia (&almoco);
	ini.tempo_fila = 0;
	ini.tempo_bandeja = 0;
	ini.tempo_almoco = 0;
	final = ini;
	
	for (i = 0; i < MAX_BANDEJA; i++)
		empilha(&bandeja);

	
	//Inicio do loop do-while
	do
	{
		//Chegada dos clientes na fila
		for(i = 0; i < NUM_CHEGADA; i++)
			enfileira (ini, &caixa);
		
		
		
		//Reposicao das bandejas a cada intervalo de n minutos
		if (min % TEMPO_REP == 0)
		{
		for (i = 0; i < REPOSICAO_BAND && tamanho (&bandeja) < MAX_BANDEJA; i++)
			empilha(&bandeja);
		}
	
	
		
		//Operacoes sobre a fila almoco
		passa_tempo (3, &almoco);
		if (f_vazia (&almoco) == 0)
		{
			j++;
			for(i = 0; i < NUM_ATENDENTES; i++)
				if (j > 0 && j % (TEMPO_SERVIR + i) == 0)
				{
					desenfileira (&almoco, &aux);
					final.tempo_fila += aux.tempo_fila;
					final.tempo_bandeja += aux.tempo_bandeja;
					final.tempo_almoco += aux.tempo_almoco;
					n_clientes++;
				}
		}
		
		
		
		//Operacoes sobre a fila bandeja
		
			passa_tempo (2, &band);
			for(i = 0; i < NUM_PILHAS_BAND; i++)
			{
				if( tamanho (&bandeja) > 0)
				{
					if(f_vazia(&band) == 0)
						troca_fila (&band, &almoco);
				}
			}
		
		
		
		//Operacoes sobre a fila caixa
		passa_tempo (1, &caixa);
		for(i = 0; i < NUM_CAIXAS; i++)
			if (f_vazia(&caixa) == 0)
				troca_fila (&caixa, &band);
		
		
		
		min++;
		
		//Fim da Interacao
	}while(min < TEMPO_MAX);
	
	//Impressao dos resultados finais
	printf("Resultados apos %d minutos:\n\n", TEMPO_MAX);
	printf("Numero clientes atendidos: %d\n\n", n_clientes);
	printf("Tempo total na fila do caixa: %d\n", final.tempo_fila);
	printf("Tempo total na fila de bandejas: %d\n", final.tempo_bandeja);
	printf("Tempo total na fila de almoco: %d\n", final.tempo_almoco);
	printf("Tempo total: %d\n\n", (final.tempo_fila + final.tempo_bandeja + final.tempo_almoco));
	printf("Tempo medio na fila do caixa: %d\n", final.tempo_fila/n_clientes);
	printf("Tempo medio na fila de bandejas: %d\n", final.tempo_bandeja/n_clientes);
	printf("Tempo medio na fila de almoco: %d\n", final.tempo_almoco/n_clientes);
	printf("Tempo medio total: %d\n\n", (final.tempo_fila + final.tempo_bandeja + final.tempo_almoco)/n_clientes);
	
	//Liberacao das vairiaveis alocadas
	while(tamanho (&bandeja) > 0)
		desempilha (&bandeja);
	
	while(f_vazia(&caixa) == 0)
		desenfileira (&caixa, &aux);
	
	while(f_vazia(&band) == 0)
		desenfileira (&band, &aux);
	
	while(f_vazia(&almoco) == 0)
		desenfileira (&almoco, &aux);
	
	
	return 1;
}
