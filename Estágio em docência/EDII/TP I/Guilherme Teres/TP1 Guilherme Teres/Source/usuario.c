#include "usuario.h"

Usuario NovoUsuario(){
    Usuario p;
    p.alimento = 0;
    p.bandeja  = 0;
    p.ficha    = 0;
    p.tempo    = 0;
    return p;
}
/*
void AddFichaUsuario(Usuario *x){
    x->ficha = 1;
}
void AddBanjedaUsuario(Usuario *x){
    x->bandeja = 1;
}
void AddAlimentoUsuario(Usuario *x){
    x->alimento += 1;
}
void EsperaUsuario(Usuario *x){
    x->tempo += 1;
}
*/
