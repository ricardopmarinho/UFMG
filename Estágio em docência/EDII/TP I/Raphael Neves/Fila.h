typedef int TChave;

typedef struct Titem {
    int Chave;
}TItem;

typedef struct Celula *Apontador;

typedef struct Celula {
    TItem Item;
    Apontador Prox;
}TCelula;

typedef struct {
    Apontador Frente;
    Apontador Tras;
}TFila;



void FFVazia(TFila *);
int Vazia_fila(TFila );
void Enfileira(TItem , TFila *);
void Desenfileira(TFila *, TItem *);

/**

FFVazia(Fila): Faz a fila ficar vazia
Enfileira(x, Fila): Insere o item x no final da fila
Desenfileira(Fila, x): Retorna o item x no início da fila, retirando-o da fila
Vazia(Fila): Esta função retorna true se a fila está vazia; senão retorna false

*/
