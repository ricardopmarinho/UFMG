#include <stdio.h>
#include <stdlib.h>

#include "usuario.h"
#include "fila.h"
#include "pilha.h"


int main()
{
    int i, usuariosAtendidos=0, usuariosRecebidos=0;
    int tempo = 0; //MAX = 60*4= 240
    //Variaveis pra calcular a media de tempo e atendimento
    int totalTempo = 0;

    Fila filaCaixa;
    FilaNova(&filaCaixa);

    Fila filaBandeja;
    FilaNova(&filaBandeja);

    Pilha pilhaBandeja;
    PilhaNova(&pilhaBandeja);
    /*
    Caso Basico
    */
    while (tempo < 240){
        // Adiciona 10 banjedas
        if (tempo%12 == 0){
            for (i=0;i<10;i++){
                if (PilhaTamanho(pilhaBandeja) < 30){
                    Bandeja tmpNew=1;
                    PilhaAddBandeja(&pilhaBandeja, tmpNew);
                }
            }
        }
        // Adiciona duas novas pessoas
        Usuario novoUser1 = NovoUsuario();
        novoUser1.tempo = tempo;
        Usuario novoUser2 = NovoUsuario();
        novoUser2.tempo = tempo;
        FilaAddUsuario(&filaCaixa, novoUser1);
        FilaAddUsuario(&filaCaixa, novoUser2);
        usuariosRecebidos += 2;

        //Passa 1 User da fila do caixa para a fila de bandeja
        if (FilaVazia(filaCaixa) == 0){
            Usuario trocaUser;
            FilaRemoveUsuario(&filaCaixa, &trocaUser);
            FilaAddUsuario(&filaBandeja, trocaUser);
        }

        // Faz o primeiro usuario da fila de Bandejas pegar uma bandeja (caso exista)
        if (FilaVazia(filaBandeja) == 0 && PilhaTamanho(pilhaBandeja) > 0){
            Usuario trocaUser;
            FilaRemoveUsuario(&filaBandeja, &trocaUser);
            PilhaRemoveBandeja(&pilhaBandeja, &trocaUser.bandeja);
            // Se deu tempo, nas 4 horas, do usuario se servir...
            if (tempo+4 < 240){
                usuariosAtendidos++;
                totalTempo += (tempo+4)-trocaUser.tempo;
                //printf("%d %d\n", i, trocaUser.tempo);
            }

        }

        // Add 1 minuto
        tempo++;
    }
    printf("Usuarios recebidos: %d\n", usuariosRecebidos);
    printf("Usuarios atendidos: %d\n", usuariosAtendidos);
    float mediaTempo = ((float)totalTempo/usuariosAtendidos)/60.0;
    printf("Tempo medio de atendimento: %.1f horas.", mediaTempo);

    return 0;
}










