#include "utils.h"
#include "funcoes.h"
//Variaveis Globais
#define LINHAS 3
#define COLUNAS 3
#define DIMENSAOTABULEIRO 9

#define MarcaX 'X'
#define MARCAO 'O'

int main(void){

    int opcaoMenu;
    struct dados *matriz;
    int turno = 0;
    int *tabVitorias = NULL;
    
    //Inicializar o initRandom()
    initRandom();

    //Criar a matriz dinamica
    matriz = criaMatriz();
    if(matriz == NULL){
        printf("Erro na alocação de memória!\n");
        return (1);
    }

    tabVitorias = criarTabVitorias(DIMENSAOTABULEIRO);

    //MenuInicial
    opcaoMenu = menuInicial();


    do{
        switch(opcaoMenu){
            //Jogar com um amigo
            case 1:
                jogarAmigo(matriz,&turno , tabVitorias);
               
                putchar('\n');

            break;

            //Jogar com o computador
            case 2:
            
            break;
        }
    }while(turno < 9 * 9);

    //Libertar a memoria da matriz
    //libertaMatriz(matriz , LINHAS);
    //libertarTabVitorias(tabVitorias);
    
    free(tabVitorias);// nao sei se está bem

    return (0);
}