#include <stdio.h>
#include <stdlib.h>

#include "usuario.h"
#include "fila.h"
#include "pilha.h"


int main()
{
    int i,j, usuariosAtendidos=0, usuariosRecebidos=0;
    int tempo = 0; //MAX = 60*4= 240
    //Variaveis pra calcular a media de tempo e atendimento
    int totalTempo = 0;

    printf("Cantina Simulator 2k17\n\n");
    // Tipo de caso
    int quantCaixa, quantFilaBandeja, quantPilhas, maxBandeja, reporBandeja;
    printf("Digite a quantidade de caixas (max = 100): ");
    scanf("%d", &quantCaixa);
    if (quantCaixa > 100) quantCaixa = 100;

    printf("Digite a quantidade de filas de pegar Bandeja (max = 100): ");
    scanf("%d", &quantFilaBandeja);
    if (quantFilaBandeja > 100) quantFilaBandeja = 100;

    printf("Digite a quantidade de pilhas de bandeja (max = 100): ");
    scanf("%d", &quantPilhas);
    if (quantPilhas > 100) quantPilhas = 100;

    printf("Digite a quantidade maxima de bandejas por pilha: ");
    scanf("%d", &maxBandeja); // OK

    printf("Digite a quantidade de bandejas repostas a cada 12 minutos: ");
    scanf("%d", &reporBandeja); //OK

    printf("\nExecutando...\n");

    //Fila filaCaixa[100];
    //for (i=0; i<quantCaixa;i++)
    //    FilaNova(&filaCaixa[i]);
    Fila filaCaixa;
    FilaNova(&filaCaixa);

    //Fila filaBandeja[100];
    //for (i=0; i<quantFilaBandeja;i++)
    //    FilaNova(&filaBandeja[i]);
    Fila filaBandeja;
    FilaNova(&filaBandeja);

    //Pilha pilhaBandeja[100];
    //for (i=0; i<quantPilhas;i++)
    //    PilhaNova(&pilhaBandeja[i]);
    Pilha pilhaBandeja;
    PilhaNova(&pilhaBandeja);

    /*
    Caso Basico
    */
    while (tempo < 240){
        // Adiciona 10 banjedas
        if (tempo%12 == 0){
            for (j=0;j<quantPilhas;j++){
                for (i=0;i<reporBandeja;i++){
                    if (PilhaTamanho(pilhaBandeja) < maxBandeja*quantPilhas){
                        Bandeja tmpNew=1;
                        PilhaAddBandeja(&pilhaBandeja, tmpNew);
                    }
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

        //Passa 1 User de cada fila dos caixas para a fila de bandeja
        for (i=0; i<quantCaixa;i++){
            if (FilaVazia(filaCaixa) == 0){
                Usuario trocaUser;
                FilaRemoveUsuario(&filaCaixa, &trocaUser);
                FilaAddUsuario(&filaBandeja, trocaUser);
            }
        }

        // Faz o primeiro usuario da fila de Bandejas pegar uma bandeja (caso exista)
        for (i=0; i<quantFilaBandeja;i++){
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










