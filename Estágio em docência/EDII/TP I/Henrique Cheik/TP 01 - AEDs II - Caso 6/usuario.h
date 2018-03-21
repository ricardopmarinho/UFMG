#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario_cantina USUARIO;

USUARIO* create_user(int ID);

void remove_user(USUARIO* aluno);

void set_arrival_time(USUARIO *aluno, int time);

void set_total_time (USUARIO *aluno, int time);

int get_arrival_time(USUARIO *aluno);

int get_total_time(USUARIO *aluno);

void print_total_time (USUARIO *aluno);


#endif // USUARIO_H
