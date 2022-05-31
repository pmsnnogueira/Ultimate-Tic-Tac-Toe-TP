#include "jogo.h"
#include "utils.h"

int jogarComputador(struct dados *tab , int *turno , int *tabVitorias){
    int opcao;
    char string[255];
    int miniTabuleiro , x , y;

    int jogador = 1;
    int ganhou;

   
    while(1){
            if(*turno != 1){
                mostraMatriz(tab,9,9);
            }

            printf("\n[TURNO %d]",*turno);
            printf("\n#### Jogar com Computador ####\n");
            printf("# 1 - Inserir peça          #\n");
            printf("# 2 - Ver Jogadas           #\n");
            printf("# 3 - Pause                 #\n");
            printf("#############################\n");
            printf("Escolha: ");

            fgets(string,sizeof(string)-1,stdin);
            string[strlen(string)-1] = '\0';
            opcao = atoi(string);
            putchar('\n');   

            if(opcao < 0 && opcao > 3)
                printf("\nEscolha uma opcao entre (1 e 3)");

            if(opcao == 1){
                if(*turno == 1){ //Se for o primeiro turno apresentar algumas dicas inciais
                    while(1){
                        printf("\
                        *-----*-----*-----*\n\
                        |  1  |  2  |  3  |\n\
                        *-----*-----*-----*\n\
                        |  4  |  5  |  6  |\n\
                        *-----*-----*-----*\n\
                        |  7  |  8  |  9  |\n\
                        *-----*-----*-----*\n");

                        printf("\nIntroduza o mini tabuleiro a jogar: ");
                       
                        fgets(string,sizeof(string)-1,stdin);
                        string[strlen(string)-1] = '\0';
                        miniTabuleiro = atoi(string);      
                        miniTabuleiro = miniTabuleiro -1;
                        if(miniTabuleiro >= 0 && miniTabuleiro < 9)    //Validações de tabuleiro
                            break;

                        printf("\nIntroduza um mini Tabuleiro válido (entre 1 e 9)\n");
                        
                   }
                }   //Se não for o primeiro turno

                miniTabuleiro = escolhe_jogada(tab , &jogador , miniTabuleiro , tabVitorias , *turno);
                if(tabVitorias[miniTabuleiro] != 0)
                    miniTabuleiro = minitabuleiroAleatorio(tabVitorias , 9);

                if(jogador == 1)
                    jogador = 2;
                else
                    jogador = 1;

                (*turno)++;
            }
        }
}

