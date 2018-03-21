#include<stdio.h>
#include<stdlib.h>
//#include<stdin.h>
#include<string.h>

typedef int TChave;

typedef struct {
    TChave Chave;
	int TempoChegada;
	int TempoAntendimento;
    // outros componentes
} TItem;

typedef struct Celula 	*Apontador;

typedef struct Celula {
    TItem Item;
    Apontador Prox;
} TCelula;

typedef struct {
    Apontador Fundo;
    Apontador Topo;
    int Tamanho;
} TPilha;

typedef struct {
    Apontador Frente;
    Apontador Tras;
	int Tamanho;
} TFila;


void FPVazia(TPilha *Pilha) {
    Pilha->Topo = malloc(sizeof(TCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int PilhaVazia(TPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TItem x, TPilha *Pilha) {
    Apontador Aux = malloc(sizeof(TCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TPilha *Pilha, TItem *Item) {
    if (PilhaVazia(*Pilha)) {
        printf("Erro lista vazia\n");    
        return;
    }
    Apontador q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}

int Tamanho(TPilha Pilha) {
    return Pilha.Tamanho;
}

void FFVazia(TFila *Fila) {
    Fila->Frente = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
	Fila->Tamanho = 0;
}

int FilaVazia(TFila Fila) {
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TItem x, TFila *Fila) {
    Fila->Tras->Prox = malloc(sizeof(TCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
	Fila->Tamanho++;
}

void Desenfileira(TFila *Fila, TItem *Item) {
    if (FilaVazia(*Fila)) { 
        printf("Erro: fila vazia\n");
        return;
    }
    Apontador q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->Item;
    free(q);
	Fila->Tamanho--;
}

void AbreRestaurante(TPilha *Bandeja,TFila *Compra,TFila *Serve,TFila *Comida){//Inicializa as filas e a pilha com a quantidade inicial de bandejas
	FFVazia(Compra);
	FFVazia(Serve);
	FFVazia(Comida);
	FPVazia(Bandeja);
	TItem unidade;
	int i;
	for(i=1;i<=30;i++){
		unidade.Chave = i;
		Empilha(unidade,Bandeja);
	}
}

int main(int argc,char *argv){
	int i,j,Diferenca,TempoAtual,TempoTotal = 0,TempoDeFila = 0,NumeroAtendimentos = 0,ContadorChave = 0;
	float TempoMedio = 0;
	TFila FilaCompra;
	TFila FilaBandeja;
	TFila FilaComida;
	TPilha PilhaBandeja;
	TItem UsuarioCaixa,UsuarioAtendido,UsuarioNovo,UsuarioServindo,Unidade;

	AbreRestaurante(&PilhaBandeja,&FilaCompra,&FilaBandeja,&FilaComida);
	for(TempoAtual=0;TempoAtual<240;TempoAtual++){
		UsuarioNovo.TempoChegada = TempoAtual;
		UsuarioNovo.TempoAntendimento = 0;
		UsuarioNovo.Chave = ContadorChave;	
		Enfileira(UsuarioNovo,&FilaCompra);		
		UsuarioNovo.Chave = ContadorChave+1;		
		Enfileira(UsuarioNovo,&FilaCompra);
		ContadorChave+=2;// Dá sequencia na geração de chaves, levando em conta que a cada tempo entram 2 novos usuarios
		Desenfileira(&FilaCompra,&UsuarioCaixa);
		Enfileira(UsuarioCaixa,&FilaBandeja);		
		if((!(FilaVazia(FilaComida)))&&(TempoDeFila>=4)){//Só começa a desenfileirar os usuarios que se serviram dos 4 alimentos.
			Desenfileira(&FilaComida,&UsuarioAtendido);
			UsuarioAtendido.TempoAntendimento = TempoAtual - UsuarioAtendido.TempoChegada;
			printf("ID Usuario: %d \n",UsuarioAtendido.Chave);
			printf("Tempo de chegada: %d \n",UsuarioAtendido.TempoChegada);
			printf("Tempo de atendimento: %d \n",UsuarioAtendido.TempoAntendimento);
			NumeroAtendimentos++;	
			TempoTotal+= UsuarioAtendido.TempoAntendimento;
		}
		if((!(FilaVazia(FilaBandeja)))&&(!(PilhaVazia(PilhaBandeja)))){
			if(FilaComida.Tamanho<4)
			Desenfileira(&FilaBandeja,&UsuarioServindo);
			Desempilha(&PilhaBandeja,&Unidade);
			Enfileira(UsuarioServindo,&FilaComida);
			TempoDeFila++;			
		}		
		if((TempoAtual % 12)==0){//doze tempos passaram
			if (Tamanho(PilhaBandeja)<30){
				if((30 - Tamanho(PilhaBandeja))<10)
					Diferenca = 30 - Tamanho(PilhaBandeja);
				else
					Diferenca = 10;
				for(j=0;j<Diferenca;j++)
					Empilha(Unidade,&PilhaBandeja);
			}
		}
		printf("Tempo atual: %d \n",TempoAtual);
		
	}
	TempoMedio = TempoTotal/NumeroAtendimentos;
	printf("O tempo total de atendimentos foi: %d \n",TempoTotal);
	printf("O numero total de atendimentos foi: %d \n",NumeroAtendimentos);
	printf("O tempo medio de atendimentos foi: %f \n",TempoMedio);
	
	return 1;
}