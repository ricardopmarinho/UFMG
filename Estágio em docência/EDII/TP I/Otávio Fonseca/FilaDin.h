
struct clientes{
    int tempodechegada;
};


typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct clientes *al);
int insere_Fila(Fila* fi, struct clientes al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
int InserirNaPilha(int topo, int max);
int RemoverDaPilha(int topo);
int EnchePilhaBandeja (int topo, int max);


