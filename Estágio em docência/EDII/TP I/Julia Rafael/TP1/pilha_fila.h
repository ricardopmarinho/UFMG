typedef int t_chave;

typedef struct{
    int chave;
	int comida;
	int ficha;
	int bandeja;
} t_item;

typedef struct celula *t_apontador;

typedef struct celula{
    t_item item;
    t_apontador prox;
} t_celula;


//PILHA-------------------------------------
typedef struct{
    t_apontador fundo;
    t_apontador topo;
    int tamanho;
} t_pilha;

void pilha_FazVazia(t_pilha *pilha);
int pilha_TestaVazia(t_pilha *pilha);
void pilha_empilha(t_item x, t_pilha *pilha);
void pilha_desempilha(t_pilha *pilha, t_item *item);
int pilha_tamanho(t_pilha *pilha);



//FILA--------------------------------------
typedef struct{
    t_apontador frente;
    t_apontador tras;
} t_fila;

void fila_FazVazia(t_fila *fila);
int fila_TestaVazia(t_fila *fila);
void fila_enfileira(t_item x, t_fila *fila);
void fila_desenfileira(t_fila *fila, t_item *item);
