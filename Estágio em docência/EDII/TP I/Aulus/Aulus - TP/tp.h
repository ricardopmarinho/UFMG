typedef struct Item{
    int Chave;
	int Time;
}TItem;

typedef struct CelulaF *Pessoa;

typedef struct CelulaF{
    TItem NumPessoa;
    Pessoa Prox;
}CelulaF;

typedef struct{
    Pessoa Frente;
    Pessoa Tras;
}TFila;

typedef struct CelulaP *Prato;

typedef struct CelulaP{
    //TItem NumPrato;
    Prato Prox;
}CelulaP;

typedef struct {
    Prato Fundo;
    Prato Topo;
    int Tamanho;
} TPilha;

void FFVazia(TFila *Fila);

void FPVazia(TPilha *Pilha);

int FVazia(TFila F);

int PVazia(TPilha P);

void Enfileira(TItem x, TFila *Fila);

void Empilha(/*TItem x,*/ TPilha *Pi);

void Desenfileira(TFila *Fila, TItem *Item);

void Desempilha(TPilha *Pi/*, TItem *Item*/);

void ChegaCliente(TFila *Fi, TItem *cont, int tempo);

void Caixa(TFila *Ent,TFila *Sai);

void VerificaTudo(int tempo,TPilha *Pr);