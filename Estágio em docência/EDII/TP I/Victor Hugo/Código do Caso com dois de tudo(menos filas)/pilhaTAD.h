typedef int TPChave;

typedef struct {
    TPChave Bandeja;
} TPItem;

typedef struct TPCelula 	*ApontadorP;

typedef struct TPCelula {
    TPItem Item;
    ApontadorP Prox;
} TPCelula;

typedef struct {
    ApontadorP Fundo;
    ApontadorP Topo;
    int Tamanho;
} TPilha;

void IniciaPilha (TPilha *Pilha);
int VaziaP(TPilha Pilha);
void Empilha(TPItem x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TPItem *Item);
int Tamanho(TPilha Pilha);