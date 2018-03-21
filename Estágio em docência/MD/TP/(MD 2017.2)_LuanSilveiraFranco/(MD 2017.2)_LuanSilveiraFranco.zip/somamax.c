#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int vetor[20] ;
	int tamvet , i , j , soma = 0 , somainst = 0;
	int inicio , fim ;
	scanf("%d" ,&tamvet) ;
	//aqui ele armazena o vetor
	for(i = 0 ; i < tamvet ; i++){
		scanf("%d" , &vetor[i]);
	}

	for(i = 0 ; i <= tamvet ; ++i){
		//esse segundo for garante que ele some cada termo com ele mesmo , depos com seu sucessor
		//imediato e todos os sucessores em geral sendo que ele armazena apenas se
		//a soma do termo atual com a soma passada for maior que a soma passada
		//ao final do for ,na soma estará guardado o maior valor de somas possivel
		//comecando do termo i.Ao sair do segundo for ele zera o valor da somainst
		//e inicia o processo novamente até o final do vetor, assim quando ele sair
		//de ambos os for's a variavel soma terá a maior soma armazenada em si
		for(j = i ; j <= tamvet ; j++){			
			somainst += vetor[j] ;
			if(somainst > soma){
				soma = somainst ;
				inicio = i + 1 ; 
				fim = j + 1 ;
			} 
		}
		somainst = 0 ;		
	}	
	printf("Soma: %d\n" , soma) ;
	printf("Indices: %d a %d" , inicio , fim) ;
	
	return 0;
}
