#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, j, ini, fim, somatotal=0, negativo=0, maiorsoma=0, soma=0, AuxIni=0, AuxFim=0;
	printf ("n = ");
	scanf("%d", &N);					//Tamanho do vetor 
	while ((N<3)||(N>20)){				//Mensagem criada para prevenir que numeros fora o intervalo de 3 a 20 sejam inseridos
		printf ("Por favor insira um numero entre 3 e 20.\nn = ");
		scanf("%d", &N);
	}
	int vet[N];				
	printf ("Insira %d numeros inteiros.\n", N);	//Mensagem criada para sinalizar o momento que deve-se inserir os numeros do vetor
	for (i=0; i<N; i++){				//Loop para escrita e varredura do vetor
		scanf("%d", &vet[i]);
		somatotal+=vet[i];				//Armazena a soma total
		if (vet[i]<0) {					//Se o numero for negativo
			negativo++;					//Variavel que guarda o numero de negativos contido no vetor
			if (((soma+vet[i])>0)&&(i!=(N-1))) {	//Se ao somar um negativo a soma continuar positiva
				soma+=vet[i];			//Soma esse numero pois na proxima repeticao pode haver um numero positivo o qual compensa alcancar
				AuxFim++;				//A cada novo numero somado a soma incrementa o indice final
			}
			else {						//Se ao soma um negativo a soma ficar negativa
				AuxFim=0;				//Zerar os indices e a soma
				AuxIni=0;
				soma=0;
			}
		}
		else {							//Se o numero for positivo
			if (AuxIni==0) AuxIni=i+1;	//Marca o indice inicial
			AuxFim++;					//Incrementa o final
			soma+=vet[i];				//Soma este numero
		}
		if (soma>maiorsoma) {			//A cada repeticao do laco compara se a soma obtida e maior que a maior soma
			ini=AuxIni;					//Se sim armazena os indices final e inicial 
			fim=(AuxIni+AuxFim)-1;
			maiorsoma=soma;				//E a maior soma recebe o valor da soma neste instante
		}
	}
	if ((negativo!=N)&&(negativo!=0)) {						//Se tiveram negativos mas nem todos os numeros foram negativos 
		printf ("Soma: %d\n", maiorsoma);					//Imprimir a maior soma obtida e os indices inicial e final
		printf ("Indices: %d a %d\n", ini, fim);
	}
	else {
		if (negativo==0) printf("Soma: %d\nIndices: 1 a %d\n", somatotal, N);	//Se nenhum negativo foi identificado, logicamente a maior soma e a soma total
		else if (negativo==N) printf("Soma: 0\nIndice invalido");				//Se todos os numeros forem negativos assumir que a soma vale 0
	}
	return 0;
}
