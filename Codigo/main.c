#include "utils.h"
#include "funcoes.h"
#include "jogo.h"

//Variaveis Globais
#define LINHAS 3
#define COLUNAS 3
#define DIMENSAOTABULEIRO 9

#define MarcaX 'X'
#define MARCAO 'O'

int main(void){

    int opcaoMenu;
    struct dados *matriz;
    int turno = 1;
    int *tabVitorias = NULL;

    //Lista Ligada
    jogadas *lista = NULL;
    printf("\n\n\n");
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
                jogarAmigo(matriz,&turno , tabVitorias , lista);
               
                putchar('\n');

            break;

            //Jogar com o computador
            case 2:
                jogarComputador(matriz , &turno , tabVitorias);
                //jogarComputador(matriz , &turno , tabVitorias);
                putchar('\n');
            break;
        }
    }while(turno < 9 * 9);

    //Libertar a memoria da matriz
    //libertaMatriz(matriz , LINHAS);
    //libertarTabVitorias(tabVitorias);
    
    free(tabVitorias);// nao sei se está bem
    //free(&lista);
    return (0);
}