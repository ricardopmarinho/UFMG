typedef int TChave;

typedef struct {
    TChave Chave;
    // outros componentes
} TItemPilha;

typedef struct Celula 	*Apontador;

typedef struct Celula {
    TItemPilha Item;
    Apontador Prox;
} TCelulaPilha;

typedef struct {
    Apontador Fundo;
    Apontador Topo;
    int Tamanho;
} PilhaPratos;


void FPVazia(PilhaPratos *Pilha);
int PilhaVazia(PilhaPratos Pilha);
void EmpilhaPratos(TItemPilha x, PilhaPratos *Pilha);
void DesempilhaPratos(PilhaPratos *Pilha, TItemPilha *Item);
void TamanhoPilha(PilhaPratos Pilha);
int EscolhePilha(PilhaPratos **Pilha, int nPilha);
void FazArranjoPilha(PilhaPratos *Pilha, int nPilha);
