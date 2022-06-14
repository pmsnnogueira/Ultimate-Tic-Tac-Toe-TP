// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
#include "globals.h"

#ifndef UTILS_H
#define UTILS_H

//Variaveis Globais
#define MARCAX 'X'
#define MARCAO 'O'
#define LINHAS 3
#define COLUNAS 3
#define TAMTABVITORIAS 3
#define DIMENSAOTABULEIRO 9
#define FICHBINARIO "fich.bin"

typedef struct dados{
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

//Apagar o ecra em windows e linux de forma automatica
void apagarEcra();

// Libertar a estrutura toda do tabuleiro
void libertaMatriz(struct dados* tab);

// Libertar todo o tabuleiro de Vitorias
void libertarTabVitorias(int **tabVitorias);

//Libertar Toda a lista ligada
void libertaLista(struct jogadas *lista);

//Verificar se Existe um ficheiro com um jogo guardado
int verificarExistenciaFich(char *nome);

#endif /* UTILS_H */