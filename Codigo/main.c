#include "utils.h"
#include "funcoes.h"
//Variaveis Globais
#define LINHAS 9
#define COLUNAS 9

#define MarcaX 'X'
#define MARCAO 'O'

int main(void){
//Variaveis
    char **matriz = NULL;
    int opcaoMenu;


//Main

    //Criar a matriz dinamica
    matriz = criaMatriz(LINHAS , COLUNAS);
    if(matriz == NULL){
        printf("Erro na alocação de memória!\n");
        return (1);
    }


    while(1){
        opcaoMenu = printMenu();

        if(opcaoMenu == 3){
            printf("\nSAIR...\n");
            break;
        }
        switch(opcaoMenu){


        }

    }





    //Libertar a memoria da matriz
    libertaMatriz(matriz , LINHAS);

    return (0);
}