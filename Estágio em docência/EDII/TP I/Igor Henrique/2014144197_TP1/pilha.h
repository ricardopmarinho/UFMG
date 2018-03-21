typedef int TChave;

typedef struct{
    TChave Chave;
}TItemBandeja;

typedef struct CelulaBandeja *ApontadorBandeja;

typedef struct CelulaBandeja{
    TItemBandeja Item;
    ApontadorBandeja Prox;
}TCelulaBandeja;

typedef struct{
    ApontadorBandeja Fundo;
    ApontadorBandeja Topo;
    int Tamanho;
}TPilha;

//CABEÇALHO FUNÇOES PILHA
void FPVazia(TPilha *);
int PVazia(TPilha);
void Empilha(TItemBandeja, TPilha *);
void Desempilha(TPilha *, TItemBandeja *);
int Tamanho(TPilha);
void liberaPilha(TPilha *);
