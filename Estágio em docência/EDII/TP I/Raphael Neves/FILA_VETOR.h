#define MAX 30


typedef int TFApontador;
typedef int TFChave;

typedef struct {
    TFChave Chave;
} TFBANDEJA;

typedef struct {
    TFBANDEJA FBANDEJA[MAX];
    TFApontador Frente, Tras;
} TFilaV;






void FFVVazia(TFilaV *);

int Vazia_FV(TFilaV );

int EnfileiraV(TFBANDEJA , TFilaV *);

int DesenfileiraV(TFilaV *, TFBANDEJA *);


/**

FFVazia(Fila): Faz a fila ficar vazia
Enfileira(x, Fila): Insere o item x no final da fila
Desenfileira(Fila, x): Retorna o item x no in�cio da fila, retirando-o da fila
Vazia(Fila): Esta fun��o retorna true se a fila est� vazia; sen�o retorna false

*/



