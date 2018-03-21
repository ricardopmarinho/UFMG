//ESTRUTURAS//////////////////////////////////////////////////////////////////////////

typedef int TChave;

typedef struct TItem {
    TChave posicao;
	int ultima;
	int tempo;
	int arroz;
	int feijao;
	int guarnicao;
	int salada;
} Aluno;

typedef struct Celula   	*Apontador;

typedef struct Celula {
    Aluno* Item;
    Apontador Prox;
} TCelula;

typedef struct {
    Apontador Frente;
    Apontador Tras;
} TFila;


//funcoes/////////////////////////////////////////////////////////////////////////
void IniciaFila(TFila *Fila);
int Vazia(TFila Fila);
void Enfileira(Aluno* x, TFila *Fila);
Aluno * Desenfileira(TFila *Fila);
void Nulifica(Aluno* Item);
