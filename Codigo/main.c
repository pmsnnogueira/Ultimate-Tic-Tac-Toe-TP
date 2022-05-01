#include "utils.h"
#include "funcoes.h"
//Variaveis Globais
#define LINHAS 9
#define COLUNAS 9

#define MarcaX 'X'
#define MARCAO 'O'

int main(void){
//Variaveis
    //char **matriz = NULL;
    int opcaoMenu;
    struct dados *matriz;
    
//Main

    //Inicializar o initRandom()
    initRandom();

    //Criar a matriz dinamica
    matriz = criaMatriz();
    if(matriz == NULL){
        printf("Erro na alocação de memória!\n");
        return (1);
    }


    while(1){

        //Escolha do menu
        opcaoMenu = printMenu();
        if(opcaoMenu == 3){
            printf("\nSAIR...\n");
            break;
        }

        switch(opcaoMenu){
            //Jogar com um amigo
            case 1:
                mostraMatriz(matriz,LINHAS ,COLUNAS);
                putchar('\n');



            break;

            //Jogar com o computador
            case 2:

            break;
        }
    }





    //Libertar a memoria da matriz
    libertaMatriz(matriz , LINHAS);

    return (0);
}