#define MAX 30

typedef int TApontador;
typedef int TChave;

typedef struct {
    TChave Chave;
 } TBANDEJA;

typedef struct {
    TBANDEJA BANDEJA[MAX];
    TApontador Topo;
} TPilha;





void FPVaziaV(TPilha *);

int VaziaV(TPilha);

void EmpilhaV(TBANDEJA, TPilha *);

int DesempilhaV(TPilha*, TBANDEJA*);

int TamanhoV(TPilha);


/**

FPVazia(Pilha): Faz a Pilha ficar vazia
Enfileira(x, Pilha): Insere o item x no topo da pilha
Desenpilha(Pilha, x): Retorna o item x no topo da pilha, retirando-o da pilha
Vazia(Pilha): Esta função retorna true se a Pilha está vazia; senão retorna false

*/
