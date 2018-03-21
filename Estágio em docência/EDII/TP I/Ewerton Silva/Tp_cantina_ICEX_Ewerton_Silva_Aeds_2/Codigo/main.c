#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "filas.h"//filas 
#include "band.h"

int main (){

	int MAX_TEMP = 241; // corresponde ao tempo decorrido de 4 horas ( 240 min)
    int i;
	int qtd_bandeja=0; //quantidade de bandiejas
	int insere_bandeja = 0; //numero de bandeijas que serao inseridas
	int total_bandeijas = 30; // numero maximo de bandeijas
	int flag_tempo_usuario=0;
	int r_remove = 0;

	/*Referente aos quatro tipo de comida*/
	USUARIO comida_pri;
	USUARIO comida_seg; 
	USUARIO comida_ter;
	USUARIO comida_qua;
	
	USUARIO caixa ;
	USUARIO flag_usuario;
	USUARIO bandej;
	USUARIO	flag_comida;
    USUARIO tempo_en;//recebe o tempo de entrada dos usuarios
	
	int NULO = -1;
	
	//iniciando os quantro tipos de comida como sem usuarios
	comida_pri = insere_val_users(comida_pri, NULO);
	comida_seg = insere_val_users(comida_seg, NULO);
	comida_ter = insere_val_users(comida_ter, NULO);
	comida_qua = insere_val_users(comida_qua, NULO);
	
	TItem num_band;//numero de bandeijas a ser inseridas
	TItem total_bandeja;//maximo de bandejas

	TFila fila_caixa; //declaracao da fila do caixa
	TFila fila_band; // declaracao da fila de bandejas

	FFVazia(&fila_band);//cria a fila das bandeijas
	FFVazia(&fila_caixa);//cria a fila do caixa

	TPilha p_bandeja; //declaracao da pilha de bandejas

	FPVazia(&p_bandeja); //criacao da pilha de bandejas

	float media_tempo = 0; 
	int tempo_atual=1; // vairal que se refere ao tempo(ciclo do loop while principal)
	int num_users = 0; // numero de usuario
	int soma_tempo = 0; //soma dos tempos de atendimento
	float flag_temp2 = 0.0;
	float flag_temp1 = 0.0;

	for (i=0;i<total_bandeijas;i++){

        Empilha(num_band,&p_bandeja); //insere a quantidade total de bandeijas na pilha 

	}

	while(tempo_atual<=MAX_TEMP){
        //insercao dos dois usuarios por minuto//
        //tempo_en.tempo_entrada = tempo_atual;
		tempo_en = insere_val_users(tempo_en,tempo_atual);

		//insercao de dois usuarios por interacao na fila do caixa
        Enfileira(tempo_en,&fila_caixa);
        Enfileira(tempo_en,&fila_caixa);
		
		Desenfileira(&fila_caixa,&caixa);//remocao do primeiro usuarios da fila do caixa 
        Enfileira_caixa(caixa,&fila_band);//enviando usuario removido para a fila de bandejas
	
		qtd_bandeja = Tamanho(p_bandeja);//verifica o numero de bandeijas disponiveisa	
	
		if((tempo_atual % 12) == 0){//insere ate 10 bandeja a cada 12 espacos de tempo
			
			i=0;
			
			//verifica quantas bandeijas que podem ser adicionadas respeitando a quantidade maxima
			insere_bandeja = total_bandeijas - qtd_bandeja;

			if (insere_bandeja<=10){
				
				num_band = emiplha_bandeja(num_band,insere_bandeja);//enviando o numero de bandejas a serem inseridas para uma variavel da pilha de bandejas
	
				for(i=0;i<insere_bandeja;i++){
					Empilha(num_band,&p_bandeja);//coloca novas bandejas na fila	
				}
			}else {
				num_band = emiplha_bandeja(num_band,10);//enviando o numero de bandejas a serem inseridas para uma variavel da pilha de bandejas
				//envia para a funçao de inserçao a quantidade de bandejas a serem inseridas
				for(i=0;i<10;i++){
					Empilha(num_band, &p_bandeja);//coloca novas bandejas na fila
				}
			}
		}
		
		if (retorna_entrada(comida_qua) != NULO){//execucao quando existem elementos na pilha de bandeja 
			
			soma_tempo = soma_tempo + (tempo_atual - retorna_entrada(comida_qua));			
			num_users++;

		}
	
		if( Tamanho(p_bandeja)!= 0){

			Desempilha(&p_bandeja);//
			Desenfileira(&fila_band,&flag_comida);
					
			comida_qua = comida_ter;
			comida_ter = comida_seg;
			comida_seg = comida_pri;	
			comida_pri = flag_comida;

		}	
		else {
		
			comida_qua = comida_ter;
			comida_ter = comida_seg;
			comida_seg = comida_pri;	
			comida_pri = insere_val_users(comida_pri, NULO);

		}

		
        tempo_atual++;//incrementacao do tempo
	}


	flag_temp1 = soma_tempo;
	flag_temp2 = num_users;
	
	//media_tempo = (soma_tempo(float) / num_users (float));
	media_tempo = flag_temp1/flag_temp2;

	printf("o Tempo total de atendimento: %i\n\nO tempo medio e: %0.2f\n\nO numero de atendimentos e: %i\n",soma_tempo,media_tempo, num_users);
	
	
	
	destroi_fila (&fila_caixa);
	destroi_fila (&fila_band);
	
	destroi_pilha(&p_bandeja);
	
	

    return 0;

}
