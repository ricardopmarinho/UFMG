typedef int TChave;

typedef struct{
    TChave Chave;
    int entrouLanchonete;
    int saiuLanchonete;
}TItemCliente;

typedef struct CelulaCliente *ApontadorCliente;

typedef struct CelulaCliente{
    TItemCliente Item;
    ApontadorCliente Prox;
} TCelulaCliente;

typedef struct{
    ApontadorCliente Frente;
    ApontadorCliente Tras;
} TFila;

void FFVazia(TFila *);
int FVazia(TFila);
void Enfileira(TItemCliente, TFila *);
void Desenfileira(TFila *, TItemCliente *);
void liberaFila(TFila *);