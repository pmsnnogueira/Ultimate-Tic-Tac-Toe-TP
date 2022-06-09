#include "utils.h"
#include "funcoes.h"
#include "jogo.h"
#include "file.h"

//Variaveis Globais
#define LINHAS 3
#define COLUNAS 3
#define DIMENSAOTABULEIRO 9



int main(void){

    int opcaoMenu;
    struct dados *matriz;
    int turno = 1;
    int **tabVitorias = NULL;

    //Lista Ligada
    jogadas *lista = NULL;
    int numeroNos = 0;
    apagarEcra();
    //Inicializar o initRandom()
    initRandom();

    //Criar a matriz dinamica
    matriz = criaMatriz();
    if(matriz == NULL){
        printf("Erro na alocação de memória!\n");
        return (1);
    }

    tabVitorias = criarTabVitorias(3);
    //MenuInicial
    opcaoMenu = menuInicial();
    
    switch(opcaoMenu){
        //Jogar com um amigo
        case 1:

            if(jogarAmigo(matriz,&turno , tabVitorias , &lista , &numeroNos) == 0 && (turno == 9*9))
                printf("\nJogo Empatado\n"); 
 
            //Guardar a lista ligada num ficheiro de texto
            guardarFinalJogo(lista);

            putchar('\n');

        break;

        //Jogar com o computador
        case 2:
            jogarComputador(matriz , &turno , tabVitorias , lista , &numeroNos);
            //jogarComputador(matriz , &turno , tabVitorias);
            putchar('\n');
        break;
    }
        

    //Libertar a memoria da matriz
    libertaMatriz(matriz);
    //libertarTabVitorias(tabVitorias);
    
    //free(tabVitorias);// nao sei se está bem
    //free(&lista);
    return (0);
}