 #ifndef PILHA_
 #define PILHA_
 
 typedef int TipoChave;
 typedef struct TipoItemP{
	TipoChave Chave;
	//componentes
 }TipoItemP;
 
 typedef struct TipoCelulaP *TipoApontadorP;
 typedef struct TipoCelulaP{
	TipoItemP Item;
	TipoApontadorP Prox;
 }TipoCelulaP;
 
 typedef struct TipoPilha{
	TipoApontadorP Fundo, Topo;
	int Tamanho;
 }TipoPilha;
 
 void FPVazia(TipoPilha *Pilha);
 int PVazia(TipoPilha Pilha);
 void Empilha(TipoItemP x, TipoPilha *Pilha);
 void Desempilha(TipoPilha *Pilha, TipoItemP *Item);
 int TamanhoPilha(TipoPilha Pilha);
 void ImprimePilha(TipoPilha *Pilha); 
 #endif