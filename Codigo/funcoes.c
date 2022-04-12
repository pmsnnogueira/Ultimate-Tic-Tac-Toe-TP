#include "funcoes.h"
#include "utils.h"

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMatriz(char** p, int nLin){

    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** criaMatriz(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL)
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMatriz(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++)
            p[i][j] = '_';
    }
    return p;
}

void mostraMatriz(char **p, int nLin, int nCol){
    int i,j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%c\t", p[i][j]);
        putchar('\n');
    }
}

char getPos(char **p, int x, int y){
    return p[x][y];
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}


int printMenu(){
    int opcao;
    int flagSair = 0;

    while(flagSair == 0){
        printf("\n############ Menu ############\n");
        printf("# 1 - Jogar com amigo        #\n");
        printf("# 2 - Jogar com o computador #\n");
        printf("# 3 - Sair                   #\n");
        printf("##############################\n");

        printf("Escolha: ");
        scanf("%d",&opcao);
        putchar('\n');
        
        if(opcao > 0 && opcao < 4)
            return (opcao);

        apagarEcra();
        printf("\nEscolha uma opcao entre (1 e 2)");
    }

    return (opcao);
}