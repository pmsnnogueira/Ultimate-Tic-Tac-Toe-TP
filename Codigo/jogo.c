#include "utils.h"
#include "jogo.h"
#include "funcoes.h"
#include "file.h"

//Jogar com Amigo

int jogarAmigo(struct dados *tab , int *turno , int **tabVitorias ,struct jogadas **lista , int *numeroNos , int *flagRecuperar){

    int opcao;
    char string[255];
    int miniTabuleiro;
    int pos;

    int count = 0;

    int jogador = 1;
    char jogadorCaracter = MARCAX;

    if(*flagRecuperar == 1){
        //Recuperar o Jogo
        *lista = lerFicheiro(FICHBINARIO, tab ,turno , tabVitorias , numeroNos , &miniTabuleiro , &jogador , &pos);
        //imprimirLista(*lista);
        //mostraMatriz(tab);
        
        //printf("\n%d %d %d\n",*turno , miniTabuleiro , jogador);

       // mostraTabuleiroJogo(tab);
        if(tabVitorias[(miniTabuleiro-1)/3][(miniTabuleiro-1)%3] != 0 || tabVitorias[(pos-1)/3][(pos-1)%3])       //verificar se o minitabuleiro que vai a seguir nao é um que já está ganho se for meter um aleatorio
            miniTabuleiro = minitabuleiroAleatorio(tabVitorias , 9);
        else
            miniTabuleiro = pos;

        if(jogador == 1)
            jogador = 2;
        else
            jogador = 1;

        //imprimirLista(*lista);
    }
    while(*turno < 9 * 9){
        if(*turno != 1){
                mostraTabuleiroJogo(tab);
        }

        //imprimirTabuleiroVitorias(tabVitorias);
        printf("\n[TURNO %d]",*turno);
        printf("\n###### Jogar com Amigo ######\n");
        printf("# 1 - Inserir peça          #\n");
        printf("# 2 - Ver Jogadas           #\n");
        printf("# 3 - Salvar jogo e SAIR    #\n");
        printf("# 4 - SAIR sem salvar       #\n");
        printf("#############################\n");
        printf("Escolha: ");

        fgets(string,sizeof(string)-1,stdin);
        string[strlen(string)-1] = '\0';
        opcao = atoi(string);
        putchar('\n');   
        
        if(opcao < 0 && opcao > 4)
            printf("\nEscolha uma opcao entre (1 e 4)");

        if(opcao == 1){
            if(*turno == 1 && *flagRecuperar == 0){ //Se for o primeiro turno apresentar algumas dicas inciais
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
            }   //Se não for o primeiro turno

            escolhe_jogada(tab , &jogador , &miniTabuleiro , &pos);
            insereJogadaFim(lista , numeroNos ,miniTabuleiro , jogador , pos , *turno);

            if(verificarLinha(tab , miniTabuleiro-1) || verificarColuna(tab , miniTabuleiro-1) || verificarDiagonal(tab , miniTabuleiro-1) ){
                tabVitorias[(miniTabuleiro-1) / 3][(miniTabuleiro-1) % 3] = jogador;
               // imprimirTabuleiroVitorias(tabVitorias);
                ganharMiniJogo(tab , miniTabuleiro-1 , jogadorCaracter);          //Apagar o minitabuleiro e meter no meio a letra
                if(verificarVitoria(tabVitorias) == 1){
                    mostraTabuleiroJogo(tab);
                    escreveResultado(jogador);
                    return (1);
                }
                else
                    escreveResultadoMini(jogador , miniTabuleiro-1);
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
            *flagRecuperar = 0;
        }
        if(opcao == 2){
            printf("\nImprimir Lista\n");
            printf("Escolha o numero de jogadas a visualizar: ");
            fgets(string,sizeof(string)-1,stdin);
            string[strlen(string)-1] = '\0';
            opcao = atoi(string);
            putchar('\n');   

            imprimirListaAoContrario(*lista , &count,opcao);
            count = 0;
        }
        if(opcao == 3){

            printf("Guardar o jogo\n");
            gravarFicheiro(*lista , *numeroNos , "fich.bin");

            return (3);
        }
        if(opcao == 4){
            printf("A SAIR DO JOGO...\n");
            return(4);
        }
    }
    *flagRecuperar = 0;
    printf("Jogo Empatado");
    return (0);
}

int escolhe_jogada(struct dados *tab, int *jogador , int *miniTabuleiro, int *pos){

    int N = 3;
    
    char string[50];
    char jogador1 = 'X';
    char jogador2 = 'O';

	printf("\nÉ a vez do jogador %d [Mini tabuleiro: %d]\n", *jogador , *miniTabuleiro);
	do{
        strcpy(string , " ");  // Meti para limpar a string de varios inputs errados 
        printf("Posição para colocar peca entre (1 e 9): ");

		fgets(string,sizeof(int),stdin);
        *pos = atoi(string);
        putchar('\n');

	}while(*pos < 1 || *pos > N*N || tab[*miniTabuleiro-1].array[(*pos-1)/N][(*pos-1)%N] != '_');                              //Tenho de corrigir o minitabuleiro, nao esta a mudar na funcao

	if(*jogador == 1){
		tab[*miniTabuleiro-1].array[(*pos-1)/N][(*pos-1)%N] = jogador1;
    }
	else{       //Se for o jogador 2
        tab[*miniTabuleiro-1].array[(*pos-1)/N][(*pos-1)%N] = jogador2;
    }   

    
    return (0);
}


//Jogar com o Computador

int jogarComputador(struct dados *tab , int *turno , int **tabVitorias ,struct jogadas **lista, int *numeroNos , int *flagRecuperar){

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
    if(*flagRecuperar == 1){
        //Recuperar o Jogo
        *lista = lerFicheiro(FICHBINARIO , tab ,turno , tabVitorias , numeroNos , &miniTabuleiro , &jogador , &pos);

        if(tabVitorias[(miniTabuleiro-1)/3][(miniTabuleiro-1)%3] != 0 || tabVitorias[(pos-1)/3][(pos-1)%3])       //verificar se o minitabuleiro que vai a seguir nao é um que já está ganho se for meter um aleatorio
            miniTabuleiro = minitabuleiroAleatorio(tabVitorias , 9);
        else
            miniTabuleiro = pos;

        if(jogador == 1)
            jogador = 2;
        else
            jogador = 1;
    }
    while(1){
        if(*turno != 1){
            mostraTabuleiroJogo(tab);
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
            if(*turno == 1 && *flagRecuperar == 0){
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
            insereJogadaFim(lista , numeroNos ,miniTabuleiro , jogador , pos , *turno);

            if(verificarLinha(tab , miniTabuleiro-1) || verificarColuna(tab , miniTabuleiro-1) || verificarDiagonal(tab , miniTabuleiro-1) ){
                tabVitorias[(miniTabuleiro-1) / 3][(miniTabuleiro-1) % 3] = jogador;
                ganharMiniJogo(tab , miniTabuleiro-1 , jogadorCaracter);          //Apagar o minitabuleiro e meter no meio a letra
                if(verificarVitoria(tabVitorias) == 1){
                    escreveResultado(jogador);
                    return (1);
                }
                else
                    escreveResultadoMini(jogador , miniTabuleiro-1);
            }  

            //verificar se o minitabuleiro que vai a seguir nao é um que já está ganho se for meter um aleatorio
            if(tabVitorias[(miniTabuleiro-1)/3][(miniTabuleiro-1)%3] != 0 || tabVitorias[(pos-1)/3][(pos-1)%3]){         
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
            insereJogadaFim(lista , numeroNos , miniTabuleiro , jogador , pos , *turno);   //Inserir na lista o Nó da jogada
        
            if(verificarLinha(tab , miniTabuleiro-1) || verificarColuna(tab , miniTabuleiro-1) || verificarDiagonal(tab , miniTabuleiro-1)){ 
                tabVitorias[(miniTabuleiro-1) / 3][(miniTabuleiro-1) % 3] = jogador;
                printf("O computador Ganhou o minitabuleiro!\n");
                ganharMiniJogo(tab , miniTabuleiro-1 ,'O');
                if(verificarVitoria(tabVitorias) ){
                    printf("Ganharam o jogo!\n");
                    return (1);
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
            *flagRecuperar = 0;
        }
        if(opcao == 2){
            //Imprimir Lista 
            printf("\nImprimir Lista\n");
            printf("Escolha o numero de jogadas a visualizar: ");
            fgets(string,sizeof(string)-1,stdin);
            string[strlen(string)-1] = '\0';
            opcao = atoi(string);
            putchar('\n');   

            imprimirListaAoContrario(*lista , &count,opcao);
            count = 0;
        }
        if(opcao == 3){

            printf("Guardar o jogo\n");
            gravarFicheiro(*lista , *numeroNos , "fich.bin");

            return (3);
        }
        if(opcao == 4){

            return(4);
        } 
    }

    *flagRecuperar = 0;
    printf("Jogo Empatado");
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