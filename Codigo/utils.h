// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
#include "globals.h"

#ifndef UTILS_H
#define UTILS_H

typedef struct dados{
    int nTab;
    char **array;
    
}dados;

//Listas Ligas
typedef struct jogadas{

    int turno;
    int posicao;
    int minitabuleiro;
    int jogador;
    struct jogadas *prox;       //Ponteiro para o proximo nó

}jogadas;



// Inicializa o gerador de numeros aleatorios.
// Esta funcao deve ser chamada apenas uma vez no inicio da execucao do programa
void initRandom();

//Devolve um valor inteiro aleatorio distribuido uniformemente entre [a, b]
int intUniformRnd(int a, int b);

// Devolve o valor 1 com probabilidade prob. Caso contrario, devolve 0
int probEvento(float prob);

//Apagar o ecra em windows e linux de forma automatica
void apagarEcra();

#endif /* UTILS_H */