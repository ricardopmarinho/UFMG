typedef int TChave;

typedef struct {
	TChave Chave;
	// outros componentes
} TItem;

typedef struct Celula
	*Apontador;
	
typedef struct Celula {
	TItem Item;
	Apontador Prox;
} TCelula;

typedef struct {
	Apontador Fundo;
	Apontador Topo;
	int Tamanho;
} TPilha;


void FPVazia(TPilha *Pilha);

int Vazia(TPilha Pilha);

void Empilha(TItem x, TPilha *Pilha);

void Desempilha(TPilha *Pilha, TItem *Item);

int Tamanho(TPilha Pilha);