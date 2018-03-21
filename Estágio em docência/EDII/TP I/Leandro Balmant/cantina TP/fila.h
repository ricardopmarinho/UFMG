typedef int TChave;

typedef struct TItem {
    TChave Chave;
    TChave Tempo;
    // outros componentes
} TItem;

typedef struct CelulaFila *ApontadorFila;

typedef struct CelulaFila {
    TItem Item;
    ApontadorFila Prox;
} TCelula;

typedef struct {
    ApontadorFila Frente;
    ApontadorFila Tras;
    int Tamanho;
} TFila;

void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Enfileira(TItem x, TFila *Fila);
void Desenfileira(TFila *Fila, TItem *Item);
void exibe(TFila Fila);
int EscolheFila(TFila **Fila, int nFila);
int EscolheFilaMaior(TFila **Fila, int nFila);
void FazArranjoFila(TFila *Fila, int nFila);
