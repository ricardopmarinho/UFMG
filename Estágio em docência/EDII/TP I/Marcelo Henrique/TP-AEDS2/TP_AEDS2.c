#include <stdio.h>
#include <stdlib.h>
#include "BibliTP.h"

int main(int argc, char *argv[]){

	int i,j,k,aux,TempoTotal = 0, ClientesAtendidos = 0;
	float TempoMedio;
	TFila  fila1, fila2, fila3;
	TCliente Cliente, Caixa, PegaBandeija, bandeija, p, Atendido;
    inicializaTempo(&Cliente);
    TPilha pilha1;

    CriaFila(&fila1);
	CriaFila(&fila2);
	CriaFila(&fila3);
	FPVazia(&pilha1);
	
    inicializaTempo(&Caixa);
    inicializaTempo(&PegaBandeija);
    inicializaTempo(&Atendido);
	
	for (i = 0;i < 240; i++){
		//Chegada cliente
		Enfileira(Cliente, &fila1);
		Enfileira(Cliente, &fila1);
		AttTempo(&Cliente);
		// Atendimento caixa
		Desenfileira(&fila1, &Caixa);
        Enfileira(Caixa, &fila2);
		// Adicionar bandejas
		if(i % 12 == 0){
			if (i == 0){
                    for (j = 1;j <= 30; j++){
                        inicializaTempo(&bandeija);
                        Empilha(bandeija, &pilha1);
                    }
				} else{
                    for (j = 1;j <= 10; j++){
							inicializaTempo(&bandeija);
							Empilha(bandeija, &pilha1);
							if (pilha1.Tamanho >= 30){
								break;
							}
						}
				    
					}
		}
		// Atendimento bandeijas e retirada de alimentos
            if (!Vaziap(pilha1)){
                Desenfileira(&fila2, &PegaBandeija);
                PegaBandeija.Tempo_Saida = i + 6;
                Enfileira(PegaBandeija,&fila3);
                Desempilha(&pilha1, &p);

            }
	}
	// Clientes atendidos
	while(!Vazia(fila3)){
        Desenfileira(&fila3, &Atendido);
        aux = Atendido.Tempo_Saida - Atendido.Tempo_Chegada;
        if(Atendido.Tempo_Saida <= 240){
            ClientesAtendidos++;
            TempoTotal += aux;
        }
	}
	TempoMedio = TempoTotal*(1.0)/ClientesAtendidos;
	printf("O tempo gasto em atendimento foi: %d minutos \n",TempoTotal);
	printf("O numero de clientes atendidos em 4 horas foi: %d clientes\n",ClientesAtendidos);
	printf("O tempo medio de atendimento foi: %.2f minutos\n",TempoMedio);

	return 0;

}