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

//Apagar o ecra em windows e linux de forma automatica
void apagarEcra()
{
    system("cls||clear");
}

// Libertar a estrutura toda do tabuleiro
void libertaMatriz(struct dados* tab){

    int l , m ;
    for(m = 0 ; m < 9 ; m++){
        for(l = 0 ; l < 3 ; l++)
            free(tab[m].array[l]);
        free(tab[m].array);
    }
    
    free(tab);
    return;
}

// Libertar todo o tabuleiro de Vitorias
void libertarTabVitorias(int **tabVitorias){

    for(int i = 0 ; i < 3 ; i++){
        free(tabVitorias[i]);    
    }

    free(tabVitorias);
    return;
}

//Libertar toda a Lista Ligada
void libertaLista(struct jogadas *lista){

    jogadas* aux;
    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return;
}

//Verificar se Existe um ficheiro com um jogo guardado
int verificarExistenciaFich(char *nome){
    
    FILE *fp;
    char string[100];        
    fp = fopen(nome,"rb");
    if(fp == NULL)
        return (0);

    //Se existir
    fclose(fp);

    do{
        printf("Deseja retomar o jogo anterior? (s = sim , n = nao): ");
        fgets(string,sizeof(string)-1,stdin);
        string[strlen(string)-1] = '\0';
        putchar('\n'); 

        if(string[0] == 's')
            return(1);

        if(string[0] == 'n')
            return(0);

    }while(1);
}
