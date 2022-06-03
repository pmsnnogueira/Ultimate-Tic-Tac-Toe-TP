// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
#include "utils.h"
#include "funcoes.h"
#include "jogo.h"

void initRandom(){
    srand(time(NULL));
}

int intUniformRnd(int a, int b){
    return a + rand()%(b-a+1);
}

int probEvento(float prob){
    return prob > ((float)rand()/RAND_MAX);
}

//Apagar o ecra em windows e linux de forma automatica
void apagarEcra()
{
    system("cls||clear");
}
