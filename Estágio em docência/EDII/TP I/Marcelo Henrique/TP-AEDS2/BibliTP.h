
typedef int TTempo;

typedef struct Cliente {
	TTempo Tempo_Chegada;
	int Tempo_Saida;
} TCliente;

typedef struct Celula *Apontador;

typedef struct Celula {
	TCliente Cliente;
	Apontador Prox;
} TCelula;

typedef struct fila{
	Apontador Frente;
	Apontador Tras;
    int Tamanho;
} TFila;

typedef struct pilha{
	Apontador Fundo;
	Apontador Topo;
	int Tamanho;
} TPilha;

// Funções para manipulação da fila
void CriaFila(TFila *Fila);

int Vazia(TFila Fila);

void Enfileira(TCliente cliente, TFila *Fila);

void Desenfileira(TFila *Fila, TCliente *Cliente);

// Funções para manipulação do Tempo

void inicializaTempo(TCliente *cliente);

void AttTempo (TCliente *cliente);

// Funções para manipulação da pilha
void FPVazia(TPilha *Pilha);

int Vaziap(TPilha Pilha);

void Empilha(TCliente x, TPilha *Pilha);

void Desempilha(TPilha *Pilha, TCliente *Cliente);

int Tamanho(TPilha Pilha);
