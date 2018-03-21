#include "bandejao.h"

#define MAXTEMPO 240
#define PESSOA_VEZ 2

int main(int argc, char *argv[]){
	
	int tempo = 0, funciona = 0;//limitadores e condicao de parada
	float med_tempo = 0.0;//calculo de atendimento
	int	tam_caixa = 0, tam_bandeja = 0, tam_prato = 0;//limitadores de fila e pilha
	int qtd_prato = 0, tmp_prato = 0, reposicao = 0; //controladores de pilha

//--------------------------- Inicializacao das TADs ---------------------------
	//Declaracao das matrizes que conterão cada tipo
	t_fila **caixa, **bandeja;
	t_pilha **prato;
	//Variaveis auxiliares para manipulacao
	int id_pessoa = 0;
	t_item pessoa;
	t_conteudo talher;
	
	VerificaParametro(argv, &tam_caixa, &tam_bandeja, &tam_prato, &qtd_prato, 
		&tmp_prato, &reposicao);
	IniciaFila(tam_caixa, tam_bandeja, &caixa, &bandeja);
	IniciaPilha(tam_prato, qtd_prato, &talher, &prato);

//-------------------------- Funcionamento do Bandejao -------------------------------
	//Percorre um ciclo dentro do bandejao
	for(id_pessoa = 1, funciona = 0, tempo = 0; funciona < tam_bandeja; tempo++){
		if(tempo < MAXTEMPO){//Limita a entrada em funcao do tempo de 4h
			InserePessoa(&pessoa, &caixa, &id_pessoa, tempo, tam_caixa, PESSOA_VEZ);
			TrocaFila(&pessoa, &caixa, &bandeja, tam_caixa, tam_bandeja, PESSOA_VEZ,
				tempo);
		}
		med_tempo += RemovePessoa(&bandeja, &prato, &pessoa, &talher, tam_bandeja,
			tam_prato, tempo);
		ReporPrato(&prato, &talher, tam_prato, tmp_prato, reposicao, qtd_prato, tempo);
		funciona = Funcionamento(&bandeja, tam_bandeja, tempo, MAXTEMPO);

	}
//--------------------------- Exibe os Resultados ----------------------------------
	med_tempo = med_tempo/pessoa.chave;
	id_pessoa = id_pessoa - pessoa.chave - 1;
	printf("\t\tFUNCIONAMENTO RESTAURANTE\n");
	printf("\nAtendidos: %d \nNao Atendidos: %d \nMedia: %.2f \nTempo: %d\n", 
		pessoa.chave, id_pessoa, med_tempo, tempo);
		
//------------------------------ Limpa os TADs ------------------------------------
	LimpaPonteiros(&caixa, &bandeja, &prato, tam_caixa, tam_bandeja, tam_prato);
	
	return 0;
}