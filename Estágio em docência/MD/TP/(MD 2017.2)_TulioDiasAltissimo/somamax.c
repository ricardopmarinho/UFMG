#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int n, aux, aux2, aux3;
	int soma, Msoma, indiceI, indiceF;
	while(n<3||n>20){       //Garante que a sequência fique entre 3 e 20
	    scanf ("%d", &n);
	    if(n<3||n>20)printf("tamanho de sequencia invalido, entre com um numero de 3 a 20\n");
    }
	int vetor[n];
	for (aux=0; aux<n; aux++) scanf("%d", &vetor[aux]);     //entrada de cada valor do vetor
	for (aux=0; aux<n; aux++){
		for (aux2=0; aux2<n; aux2++){
			soma=0;
			for (aux3=aux; aux3<n-aux2; aux3++) soma+=vetor[aux3];      //Para cada ciclo do laço ele soma o valor do numero do vetor, e a cada novo laço
			if (Msoma<soma){                                            //ele diminui o ultimo valor do vetor ate sobrar apenas um numero, e começar tudo 
			    Msoma=soma;                                             //de novo, começando de um indice superior
			    indiceI=aux+1;   //guarda o valor do indice inicial da maior soma
			    indiceF=n-aux2;  //guarda o valor do indice final da maior soma
			}
		}
	}
	if (Msoma>=0){
	    printf("Soma: %d\n", Msoma);
	    printf("Indices: %d a %d", indiceI, indiceF);
	}
	else {
	    printf("Soma: 0\n");
	    printf("Indices: 0 a 0");
	}
	return 0;
}
