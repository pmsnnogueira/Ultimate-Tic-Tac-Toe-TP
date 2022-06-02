#include "utils.h"
#include "jogo.h"
#include "funcoes.h"

int jogarComputador(struct dados *tab , int *turno , int *tabVitorias ,struct jogadas *lista){
    int opcao;
    char string[255];
    int miniTabuleiro;
    int pos;                //Pos da jogada
    int jogador = 1;
    int dimensao = 3;
    int posAleatoriaBot;
    //int ganhou;

   
    while(1){
        if(*turno != 1){
            mostraMatriz(tab);
        }
        
        printf("\n[TURNO %d]",*turno);
        printf("\n#### Jogar VS Computador ####\n");
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
            if(*turno == 1){
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
            }
            //Se não for o primeiro turno
            miniTabuleiro = escolhe_jogada(tab , &jogador , miniTabuleiro , tabVitorias  , &pos);
            insereJogadaFim(&lista , miniTabuleiro , jogador , pos , *turno);
            //Apaguei mas é para meter a lista
            if(jogador == 1)
                jogador = 2;
            else
                jogador = 1;

            (*turno)++;

            //Bot
            posAleatoriaBot = botAleatorio(tab , miniTabuleiro , 9);
            printf("\n%d\n",posAleatoriaBot);

            tab[miniTabuleiro].array[(posAleatoriaBot - 1) / dimensao][(posAleatoriaBot - 1) % dimensao] = 'O';
            insereJogadaFim(&lista , miniTabuleiro , jogador , pos , *turno);   //Inserir no Nó o jogo
        
            if(verificarLinha(tab , miniTabuleiro) || verificarColuna(tab , miniTabuleiro) || verificarDiagonal(tab , miniTabuleiro)){
                //ganhou = jogador;   
                tabVitorias[miniTabuleiro] = jogador;
                printf("O computador Ganhou o minitabuleiro!\n");
                ganharMiniJogo(tab , miniTabuleiro ,'O');
                
                if(verificarVitoria(tabVitorias , jogador) ){
                    printf("Ganharam o jogo!\n");
                    exit (1);
                }
                else
                    escreveResultadoMini(jogador , miniTabuleiro);
                    
                    
            }  
            miniTabuleiro = posAleatoriaBot - 1;        //Proxima posicao do jogo

            if(tabVitorias[miniTabuleiro] != 0)
            miniTabuleiro = minitabuleiroAleatorio(tabVitorias , 9);

            if(jogador == 1)
                jogador = 2;
            else
                jogador = 1;

            (*turno)++;
        }
          
        if(opcao == 2){     //Listar Menu    
            printf("\nImprimir Lista\n");
            imprimirLista(lista);
        }      
    }

    return(0);
}


int escolhe_jogadaComputador(struct dados *tab, int *jogador , int miniTabuleiro, int *tabVitorias){

	int pos;
    int N = 3;
    
    char string[50];
    char jogador1 = 'X';
    //char jogador2 = 'O';
    char jogadorAtual;

        printf("\nÉ a vez do jogador %d [Mini tabuleiro: %d]\n", *jogador , miniTabuleiro + 1);
    do{
            strcpy(string , " ");  // Meti para limpar a string de varios inputs errados 
            printf("Posição para colocar peca entre (1 e 9): ");

            fgets(string,sizeof(pos),stdin);
            pos = atoi(string);
            putchar('\n');

    }while(pos<1 || pos > N*N || tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] != '_');

    tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] = jogador1;
    jogadorAtual = jogador1; 

    if(verificarLinha(tab , miniTabuleiro) || verificarColuna(tab , miniTabuleiro) || verificarDiagonal(tab , miniTabuleiro) ){
        //ganhou = jogador;   
        tabVitorias[miniTabuleiro] = *jogador;
        ganharMiniJogo(tab , miniTabuleiro , jogadorAtual);
        
        if(verificarVitoria(tabVitorias , *jogador) ){

        }
        else
            escreveResultadoMini(*jogador , miniTabuleiro);
    }  
    return (pos-1);
}


int botAleatorio(struct dados *tab ,int minitabuleiro, int dimensaoTabuleiro){
    
    int aleatorio; 
    do{
        aleatorio = intUniformRnd(1, dimensaoTabuleiro - 1);
    }while(tab[minitabuleiro].array[(aleatorio-1)/3][(aleatorio-1)%3] != '_');
    
    return (aleatorio);
}