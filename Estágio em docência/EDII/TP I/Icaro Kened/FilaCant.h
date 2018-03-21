typedef int TChave;

typedef struct TItem {
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
	Apontador Frente;
	Apontador Tras;
} TFila;



void FFVazia(TFila *Fila);

int Vazia(TFila Fila);

void Enfileira(TItem x, TFila *Fila);

void Desenfileira(TFila *Fila, TItem *Item);