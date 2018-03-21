typedef int TipoChave;

typedef struct {
    int Chave;
}TipoItem;

typedef struct TipoCelula 	*TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct {
    TipoApontador Fundo;
    TipoApontador Topo;
    int Tamanho;
}TipoPilha;



void FPVazia(TipoPilha *);
int Vazia_pilha(TipoPilha );
void Empilha(TipoItem , TipoPilha *);
void Desempilha(TipoPilha *, TipoItem *);
int Tamanho(TipoPilha );
void Imprime_pilha(TipoPilha *);


/**

FPVazia(Pilha): Faz a Pilha ficar vazia
Enfileira(x, Pilha): Insere o item x no topo da pilha
Desenpilha(Pilha, x): Retorna o item x no topo da pilha, retirando-o da pilha
Vazia(Pilha): Esta função retorna true se a Pilha está vazia; senão retorna false

*/
