#include "bandejao.h"

//Testa se os parametros foram passados por linha de comando, e atribui valores.
void VerificaParametro(char **argv, int *tam_caixa, int *tam_bandeja, int *tam_prato, 
	int *qtd_prato, int *tmp_prato, int *reposicao){
	
	//Recebe parametros por linha de comando
	*tam_caixa = atoi(argv[1]);//numero de fila de caixas
	*tam_bandeja = atoi(argv[2]);//numero de fila de bandejas
	*tam_prato = atoi(argv[3]);//numero de pilha de pratos
	if(argv[4] == NULL){//atribui valores default
		*qtd_prato = 30;
		*tmp_prato = 12;
		*reposicao = 10;
	}else{
		*qtd_prato = atoi(argv[4]);//quantidade de pratos na pilha
		*tmp_prato = atoi(argv[5]);//tempo de reposicao de pratos
		*reposicao = atoi(argv[6]);//quantidade de pratos para reposicao
	}
}

//Aloca dinamicamente 2 matrizes de filas e inicia as filas
void IniciaFila(int tam_caixa, int tam_bandeja, t_fila ***caixa, t_fila ***bandeja){
	
	int i;
	
	*caixa = (t_fila**)calloc(tam_caixa, sizeof(t_fila*));
	for(i = 0; i < tam_caixa; i++){
		*(*caixa+i) = FFVazia();
	}
	
	*bandeja = (t_fila**)calloc(tam_bandeja, sizeof(t_fila*));
	for(i = 0; i < tam_bandeja; i++){
		*(*bandeja+i) = FFVazia();
	}
}

//Preenche a pilha de pratos em funcao de tmp_prato
void PreenchePilha(t_pilha *prato, t_conteudo *talher, int qtd_prato){
	
	int i = 0;
	
	for(i = 1; i <= qtd_prato; i++){
		talher->chave = i;
		Empilha(*talher, prato);
	}
}

//Aloca dinamicamente uma matriz de pilha, inicia as pilhas e as preenche
void IniciaPilha(int tam_prato, int qtd_prato, t_conteudo *talher, t_pilha ***prato){
	
	int i;
	
	*prato = (t_pilha**)calloc(tam_prato, sizeof(t_pilha*));
	for(i = 0; i < tam_prato; i++){
		*(*prato+i) = FPVazia();
		PreenchePilha(*(*prato+i), talher, qtd_prato);
	}
}


//Incrementa os dados do individuo e enfileira a quantidade de individuos em caixa[]
void InserePessoa(t_item *pessoa, t_fila ***fila, int *id_pessoa, int tempo, 
	int tam_fila, int qtd){
	
	int i, j = 0;
	
	for(i = 0; i < qtd; i++){
		pessoa->chave = *id_pessoa;
		pessoa->tempo = tempo;
		j = VerificaFMenor(*fila, tam_fila);
		Enfileira(*pessoa, *(*fila+j));
		(*id_pessoa)++;
	}
}

//Funcao que retorna a condicao de parada do procedimento TrocaFila
int Parametro(int tam_fila1, int qtd){
	
	if(tam_fila1 >= qtd){
		return tam_fila1;
	}
	else{
		return qtd;
	}
}

//Desenfileira a pessoa de uma fila de caixa e enfileira em uma fila de bandeja
void TrocaFila(t_item *pessoa, t_fila ***fila1, t_fila ***fila2, int tam_fila1, 
	int tam_fila2, int qtd, int tempo){
	
	int i, j = 0, k = 0, qtd_remocao = 0;
	t_item primeiro_fila;
	
	qtd_remocao = Parametro(tam_fila1, qtd);//recebe quantidade de remocao
	for(i = 0; i < qtd_remocao; i++){
		j = VerificaFMaior(*fila1, tam_fila1);//recebe indice da fila caixa
		if(!VaziaF(*(*(*fila1+j)))){
			primeiro_fila = RetornaPrimeiro(*(*fila1+j));//recebe primeiro da fila caixa
			if((tempo - primeiro_fila.tempo) > 0){
				Desenfileira(pessoa, *(*fila1+j));
				k = VerificaFMenor(*fila2, tam_fila2);//recebe indice da fila bandeja
				Enfileira(*pessoa, *(*fila2+k));
			}
		}
	}
}

//Verifica tempo de reposicao dos pratos e empilha pratos ate condicao de parada
void ReporPrato(t_pilha ***pilha, t_conteudo *talher, int tam_prato, int tmp_prato, 
	int reposicao, int qtd_prato, int tempo){
	
	int h, i;
	
	if((tempo % tmp_prato) == 0 && tempo > 1){//verifica o momento de reposicao
		//Empilha os pratos nas diferentes pilhas
		for(h = 0; h < tam_prato; h++){
			//Empilha a quantidade definida de pratos sem ultrapassar o limite
			for(i = 0; (i < reposicao) && (talher->chave <= qtd_prato); i++, 
				talher->chave++){
				Empilha(*talher, *(*pilha+h));
			}
		}
	}
}

//Desenfileira pessoas da matriz bandeja e desempilha da matriz prato 
int RemovePessoa(t_fila ***fila, t_pilha ***pilha, t_item *pessoa, t_conteudo *talher,
	int tam_fila, int tam_pilha, int tempo){
	
	int h, i = 0, j = 0, med_tempo = 0; 
	t_item primeiro_fila;
	
	for(h = 0; h < tam_fila; h++){
		j = VerificaFMaior(*fila, tam_fila);//recebe indice da fila bandeja
		i = VerificaPMaior(*pilha, tam_pilha);//recebe indice da pilha prato
		if((!VaziaF(*(*(*fila+j)))) && !VaziaP(*(*(*pilha+i)))){
			primeiro_fila = RetornaPrimeiro(*(*fila+j));//recebe o primeiro da fila
			if((tempo - primeiro_fila.tempo) > 2){
				Desenfileira(pessoa, *(*fila+j));
				Desempilha(talher, *(*pilha+i));
				pessoa->tempo = (tempo - pessoa->tempo) + 4;
				med_tempo += pessoa->tempo;
			}
		
		}
	}
	return med_tempo;
}

//Retorna a quantidade de filas bandeja Vazias
int Funcionamento(t_fila ***bandeja, int tam_bandeja, int tempo, int maxtempo){
	
	int i, funcionamento = 0;
	
	for(i = 0, funcionamento = 0; i < tam_bandeja && tempo >= maxtempo; i++){
		if(VaziaF(*(*(*bandeja+i)))){
			funcionamento++;
		}
	}
	return funcionamento;
}

//Destroi as filas e desaloca o espacao em memoria das matrizes
void LimpaPonteiros(t_fila ***fila1, t_fila ***fila2, t_pilha ***pilha, int tam_fila1,
	int tam_fila2, int tam_pilha){
	
	int i;
	
	for(i = 0; i < tam_fila1; i++){
		DestroiFila(*(*fila1+i));
	}
	free(*fila1);
	for(i = 0; i < tam_fila2; i++){
		DestroiFila(*(*fila2+i));
	}
	free(*fila2);
	for(i = 0; i < tam_pilha; i++){
		DestroiPilha(*(*pilha+i));
	}
	free(*pilha);
}
