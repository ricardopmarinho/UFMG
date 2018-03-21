#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct usuario_cantina{
    int arrival_time;
    int total_time;
    int ID;
};

USUARIO* create_user(int ID){
    USUARIO* aluno = (USUARIO *)malloc(sizeof(USUARIO));
    if(aluno != NULL){
        aluno->arrival_time = 0;
        aluno->total_time = 0;
        aluno->ID = ID;
    }
    return aluno;
}

void remove_user(USUARIO *aluno){
    if(aluno != NULL){
        free(aluno);
        //printf("Usuario removido com sucesso!\n\n");
    }
}

void set_arrival_time(USUARIO *aluno, int time){
    aluno->arrival_time = time;
}

void set_total_time (USUARIO *aluno, int time){
    aluno->total_time = time - aluno->arrival_time;
}

int get_arrival_time(USUARIO *aluno){
    return aluno->arrival_time;
}

int get_total_time(USUARIO *aluno){
    return aluno->total_time;
}

void print_total_time (USUARIO *aluno){
    printf("O aluno %d gastou %d minutos para pegar sua refeicao. Entrada: %d\n", aluno->ID, aluno->total_time, aluno->arrival_time);
}
