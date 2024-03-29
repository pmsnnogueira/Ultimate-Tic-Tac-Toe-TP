#include "utils.h"
#include "funcoes.h"
#include "jogo.h"
#include "file.h"

int main(void){

    int opcaoMenu;              //Opcao Menu
    struct dados *matriz;       //É o meu array de estruturas 
    int turno = 1;              //Turnos do jogo
    int **tabVitorias = NULL;   //Tabuleiro dinamico de vitorias 3x3
    //Lista Ligada
    jogadas *lista = NULL;      //Lista ligada
    int numeroNos = 0;          //Numero de nos na minha lista ligada
    int flagRecomecar = 0;      //Flag para recomeçar o jogo
    int res;                    //Resultado da funcao
    apagarEcra();  

    //Inicializar o initRandom()
    initRandom();

    //Criar a matriz dinamica
    matriz = criaMatriz();
    if(matriz == NULL){
        printf("Erro na alocação de memória!\n");
        return (1);
    }

    //Criar tabVitorias 3*3 Dinamicamente
    tabVitorias = criarTabVitorias(TAMTABVITORIAS);

    //MenuInicial
    opcaoMenu = menuInicial();
    switch(opcaoMenu){
        //Jogar com um amigo
        case 1:
            if(verificarExistenciaFich("fich.bin") == 1){
                //Se quiser utilizar o ficheiro que já foi criado
                flagRecomecar = 1;
            }

            res = jogarAmigo(matriz,&turno , tabVitorias , &lista , &numeroNos , &flagRecomecar);

            if(res == 0 && turno > 9*9)
                printf("\nJogo Empatado\n"); 
            if(res == 0 || res == 1){
                //Guardar a lista ligada num ficheiro de texto
                guardarFinalJogo(lista);

            }
                
            putchar('\n');
        break;

        //Jogar com o computador
        case 2:

            if(verificarExistenciaFich("fich.bin") == 1){
                //Se quiser utilizar o ficheiro que já foi criado
                flagRecomecar = 1;
            }


            res = jogarComputador(matriz,&turno , tabVitorias , &lista , &numeroNos , &flagRecomecar);            
            if(res == 0 && turno > 9*9)
                printf("\nJogo Empatado\n"); 
            if(res == 0 || res == 1){
                //Guardar a lista ligada num ficheiro de texto
                guardarFinalJogo(lista);

            }
            putchar('\n');
        break;
    }
    //Libertar memoria
    libertaMatriz(matriz);
    libertarTabVitorias(tabVitorias);
    libertaLista(lista);


    return (0);
}