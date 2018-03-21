#ifndef TAD_USER
#define TAD_USER


typedef struct Usuario{
    int ficha;
    int bandeja;
    int alimento;

    int tempo;

} Usuario;

/// Cria um novo usuario Vazio
Usuario NovoUsuario();
/*
// Adiciona os elementos do usuario
void AddFichaUsuario(Usuario *x);
void AddBanjedaUsuario(Usuario *x);
void AddAlimentoUsuario(Usuario *x);

// Faz o usuario esperar mais um minuto
void EsperaUsuario(Usuario *x);

*/

#endif // TAD_USER
