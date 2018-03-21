 #ifndef FILA_
 #define FILA_
 
 typedef int TipoChave;
 typedef int TipoFicha;
 typedef int TipoTempo;
 typedef struct TipoItemF{
	TipoChave Chave;
	TipoFicha Ficha;
	int Bandeja;
	TipoTempo TempoGasto;
	//componentes
 }TipoItemF;

 typedef struct TipoCelulaF *TipoApontadorF;
 
 typedef struct TipoCelulaF{
	TipoItemF Item;
	TipoApontadorF Prox;
 }TipoCelulaF;
 
 typedef struct TipoFila{
	TipoApontadorF Frente, Tras;
 }TipoFila;
 
 void FFVazia(TipoFila *Fila); 
 int FVazia(TipoFila Fila);
 void Enfileira(TipoItemF x, TipoFila *Fila);
 void Desenfileira(TipoFila *Fila, TipoItemF *Item);
 void ImprimeFila(TipoFila Fila);
 #endif