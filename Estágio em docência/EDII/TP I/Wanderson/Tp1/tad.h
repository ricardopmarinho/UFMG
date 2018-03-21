//Tad Pilha de Bandejas
#define NUM_PILHAS_BAND 1 //Numero de pilhas de bandejas
#define NUM_BAND_PILHA 30 //Numero de bandejas em cada pilha
#define MAX_BANDEJA NUM_BAND_PILHA * NUM_PILHAS_BAND //Numero maximo de bandejas

typedef struct p_band *p_apontador;

typedef struct p_band
{
	p_apontador prox;
} p_band;

typedef struct
{
	p_apontador fundo;
	p_apontador topo;
	int tamanho;
}p_pilha;

void faz_p_vazia (p_pilha *pilha);

int p_vazia (p_pilha *pilha);

void empilha (p_pilha *pilha);

void desempilha (p_pilha *pilha);

int tamanho (p_pilha *pilha);


//Tad Fila de Clientes

typedef struct f_tempo
{
	unsigned int tempo_fila;
	unsigned int tempo_bandeja;
	unsigned int tempo_almoco;
} f_tempo;

typedef struct cliente *f_apontador;

typedef struct cliente
{
	f_tempo tempo;
	f_apontador prox;
}f_cliente;

typedef struct
{
	f_apontador frente;
	f_apontador tras;
} f_fila;

void faz_f_vazia (f_fila *fila);

int f_vazia (f_fila *fila);

void enfileira (f_tempo x, f_fila *fila);

void desenfileira (f_fila *fila, f_tempo *tempo);

void troca_fila (f_fila *fila1, f_fila *fila2);

void passa_tempo (int x, f_fila *fila);



