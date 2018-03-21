#include <stdio.h>
#include <stdlib.h>
#include "tp.h"

int main(int argc, char *argv[]){
    	
    //-> Crio as Filas e Pilhas e Inicializo <-
    TFila Fila1,Fila2;
	TFila Almoco;
	FFVazia(&Almoco);
    FFVazia(&Fila1);
    FFVazia(&Fila2);
    TPilha Pilha1;
    FPVazia(&Pilha1);
	
		if(!FVazia(Fila1) || !FVazia(Fila2) || !FVazia(Almoco) || !PVazia(Pilha1))
			return 0;
	
    int t,i;
	int PessoasTotal=0,TempoTotal=0;
	float media;
	TItem Temp, ContP;
	
	for(i=0;i<30;i++){
		Empilha(&Pilha1);
	}
		
		//No tempo 0:
		t = 0;
			ContP.Chave = 1;
			ContP.Time = t;
			//printf("chave: %d",ContP.Chave);
			Enfileira(ContP,&Fila2);
			ContP.Chave +=1;
			ContP.Time = t;
			//printf("chave: %d",ContP.Chave);
			Enfileira(ContP,&Fila1);
		
		//A partir do tempo 1:
		t = 1;
		
			while(t<240){
				//Verificacoes:
				VerificaTudo(t,&Pilha1);
				
				//Chega 2 na fila:
				ChegaCliente(&Fila1, &ContP,t);
				
				//Entra 1 no caixa:
				Caixa(&Fila1,&Fila2);
				
					if(t<236){
						if(!PVazia(Pilha1)){
							Desenfileira(&Fila2,&Temp);
							Desempilha(&Pilha1);
							t++;							
							Temp.Time = (t - Temp.Time) + 4;
							Enfileira(Temp,&Almoco);
						}
						else
							t++;
					}
					else
						t++;			
			}
		
		while(!FVazia(Almoco)){
			Desenfileira(&Almoco,&Temp);			
			TempoTotal += Temp.Time;			
			PessoasTotal +=1;
		}
		
		media = TempoTotal/PessoasTotal;
		
		printf("Tempo  medio de atendimento completo por cliente: %.f\n",media);
			
		
		//-> Finalizo tudo! <-
		//TItem FimP;
		
			while(!PVazia(Pilha1)){
				Desempilha(&Pilha1);
			}
			free(Pilha1.Topo);			
		
		TItem FimF;
		
			while(!FVazia(Fila1)){
				Desenfileira(&Fila1, &FimF);
			}
			free(Fila1.Frente);			

			while(!FVazia(Fila2)){
				Desenfileira(&Fila2, &FimF);
			}
			free(Fila2.Frente);
			
			while(!FVazia(Almoco)){
				Desenfileira(&Almoco, &FimF);
			}
			free(Almoco.Frente);
	
    system("pause");
    return 0;
}
