#include "utils.h"
#include "jogo.h"
#include "funcoes.h"
#include "file.h"

int jogarComputador(struct dados *tab , int *turno , int **tabVitorias ,struct jogadas *lista, int *numeroNos){

    int opcao;
    char string[255];
    int miniTabuleiro;
    int pos;                //Pos da jogada
    int jogador = 1;
    char jogadorCaracter = MARCAX;
    int dimensao = 3;
    int posAleatoriaBot;
    int count = 0;

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
                    miniTabuleiro = miniTabuleiro;
                    if(miniTabuleiro > 0 && miniTabuleiro <= 9)    //Validações de tabuleiro
                        break;

                    printf("\nIntroduza um mini Tabuleiro válido (entre 1 e 9)\n");
                    
                }
            }
            escolhe_jogada(tab , &jogador , &miniTabuleiro , &pos);
            insereJogadaFim(&lista , numeroNos ,miniTabuleiro , jogador , pos , *turno);

            if(verificarLinha(tab , miniTabuleiro-1) || verificarColuna(tab , miniTabuleiro-1) || verificarDiagonal(tab , miniTabuleiro-1) ){
                tabVitorias[(miniTabuleiro-1) / 3][(miniTabuleiro-1) % 3] = jogador;
                ganharMiniJogo(tab , miniTabuleiro-1 , jogadorCaracter);          //Apagar o minitabuleiro e meter no meio a letra
                if(verificarVitoria(tabVitorias) == 1){
                    escreveResultado(jogador);
                    return (1);
                }
                else
                    escreveResultadoMini(jogador , miniTabuleiro-1);
                //mostraMatriz(tab,9,9);
            }  

            if(tabVitorias[(miniTabuleiro-1)/3][(miniTabuleiro-1)%3] != 0 || tabVitorias[(pos-1)/3][(pos-1)%3]){         //verificar se o minitabuleiro que vai a seguir nao é um que já está ganho se for meter um aleatorio
                miniTabuleiro = minitabuleiroAleatorio(tabVitorias , 9);
                
            }else{
                miniTabuleiro = pos;      //Avançar o minitabuleiro para a proxima jogada
            }


            if(jogador == 1){
                jogador = 2;
                jogadorCaracter = MARCAO;
            }
            else{
                jogador = 1;
                jogadorCaracter = MARCAX;
            }
            
            (*turno)++;

            //Agora é o Bot a jogar
            posAleatoriaBot = botAleatorio(tab , miniTabuleiro-1 , 9);        //PosAleatoria para o bot jogar

            tab[miniTabuleiro-1].array[(posAleatoriaBot - 1) / dimensao][(posAleatoriaBot - 1) % dimensao] = 'O';
            insereJogadaFim(&lista , numeroNos , miniTabuleiro , jogador , pos , *turno);   //Inserir na lista o Nó da jogada
        
            if(verificarLinha(tab , miniTabuleiro-1) || verificarColuna(tab , miniTabuleiro-1) || verificarDiagonal(tab , miniTabuleiro-1)){
                //ganhou = jogador;   
                tabVitorias[(miniTabuleiro-1) / 3][(miniTabuleiro-1) % 3] = jogador;
                printf("O computador Ganhou o minitabuleiro!\n");
                ganharMiniJogo(tab , miniTabuleiro-1 ,'O');
                
                if(verificarVitoria(tabVitorias) ){
                    printf("Ganharam o jogo!\n");
                    exit (1);
                }
                else
                    escreveResultadoMini(jogador , miniTabuleiro-1);
            }  
            
            if(tabVitorias[(miniTabuleiro-1)/3][(miniTabuleiro-1)%3] != 0 || tabVitorias[(pos-1)/3][(pos-1)%3]){         //verificar se o minitabuleiro que vai a seguir nao é um que já está ganho se for meter um aleatorio
                miniTabuleiro = minitabuleiroAleatorio(tabVitorias , 9);                
            }else{
                miniTabuleiro = pos;      //Avançar o minitabuleiro para a proxima jogada
            }

            if(jogador == 1)
                jogador = 2;
            else
                jogador = 1;

            (*turno)++;
        }
        if(opcao == 2){
            printf("\nImprimir Lista\n");
            imprimirListaAoContrario(lista , &count,5);
            count = 0;
        }
        if(opcao == 3){

            printf("Guardar o jogo\n");
            gravarFicheiro(lista , *numeroNos , "fich.bin");
            return (3);
        }   
    }

    return(0);
}


int escolhe_jogadaComputador(struct dados *tab, int *jogador , int miniTabuleiro){

	int pos;
    int N = 3;
    
    char string[50];
    char jogador1 = 'X';
    //char jogador2 = 'O';
    //char jogadorAtual;

        printf("\nÉ a vez do jogador %d [Mini tabuleiro: %d]\n", *jogador , miniTabuleiro + 1);
    do{
            strcpy(string , " ");  // Meti para limpar a string de varios inputs errados 
            printf("Posição para colocar peca entre (1 e 9): ");

            fgets(string,sizeof(pos),stdin);
            pos = atoi(string);
            putchar('\n');

    }while(pos<1 || pos > N*N || tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] != '_');

    tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] = jogador1;
    //jogadorAtual = jogador1; 

    return (0);
}


int botAleatorio(struct dados *tab ,int minitabuleiro, int dimensaoTabuleiro){
    
    int nLinhas = 3;
    int aleatorio; 
    do{
        aleatorio = intUniformRnd(1, dimensaoTabuleiro);
    }while(tab[minitabuleiro].array[(aleatorio-1) / nLinhas][(aleatorio-1) % nLinhas] != '_');
    
    return (aleatorio);
}