#include "funcoes.h"
#include "utils.h"

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMatriz(char** p, int nLin){

    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
struct dados* criaMatriz(){
    struct dados *p = NULL;
    int i, a;

    p = malloc(sizeof(dados) * 9);
    if(p == NULL)
        return (NULL);


    for(i = 0 ; i < 9 ; i++){
        p[i].array = malloc(sizeof(char *) * 3);     //Alocar linhas
        if(p[i].array == NULL){
            printf("Erro na alocação de memória!\n");
            //libertaMatriz(p , 3);
            exit (EXIT_FAILURE);
        }
        for(a = 0 ; a < 3 ; a++){
            p[i].array[a] = malloc(sizeof(char *) *3);  //Alocar Colunas
            if(p[i].array[a] == NULL){
                printf("Erro na alocação de memoria!\n");
                exit (EXIT_FAILURE);
            }
        }
    }

    for(i=0; i<9; i++){    
         for(int k = 0 ; k < 3 ; k++){
            for(a = 0 ; a < 3 ; a++){
                p[i].array[k][a] = '_';
            }
        }
    }
    /*for(int k = 0 ; k < 3 ; k++){
            for(int a = 0 ; a < 3 ; a++){
                p[1].array[k][a] = '1';
            }
        }

    p[3].array[1][1] = '3';
    p[4].array[2][1] = '3';
    p[5].array[1][1] = '3';*/
    
    return (p);
}

int *criarTabVitorias(int dimensao){
    
    int *tab = NULL;
    int i;
    
    tab = malloc(sizeof(int) * dimensao);
    if(tab == NULL){
        printf("Erro na alocacao de memoria no tabuleiro Vitorias\n");
        exit (EXIT_FAILURE);
    }

    for(i = 0; i < dimensao ; i++)
        tab[i] = 0;

    return (tab);
}

void libertarTabVitorias(int *tabVitorias , int dimensao){
    for(int i = 0 ; i < dimensao ; i++)
        free(tabVitorias);
}

void mostraMatriz(struct dados *tab){

    printf("\
    \t\t\t*---------*---------*---------*\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t*---------*---------*---------*\n" , 
    tab[0].array[0][0] , tab[0].array[0][1] , tab[0].array[0][2],     tab[1].array[0][0] , tab[1].array[0][1] , tab[1].array[0][2],   tab[2].array[0][0] , tab[2].array[0][1] , tab[2].array[0][2],   
    tab[0].array[1][0] , tab[0].array[1][1] , tab[0].array[1][2] ,    tab[1].array[1][0] , tab[1].array[1][1] , tab[1].array[1][2],   tab[2].array[1][0] , tab[2].array[1][1] , tab[2].array[1][2],
    tab[0].array[2][0] , tab[0].array[2][1] , tab[0].array[2][2] ,    tab[1].array[2][0] , tab[1].array[2][1] , tab[1].array[2][2],   tab[2].array[2][0] , tab[2].array[2][1] , tab[2].array[2][2]
    );

    printf("\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t*---------*---------*---------*\n" , 
    tab[3].array[0][0] , tab[3].array[0][1] , tab[3].array[0][2],     tab[4].array[0][0] , tab[4].array[0][1] , tab[4].array[0][2],   tab[5].array[0][0] , tab[5].array[0][1] , tab[5].array[0][2],   
    tab[3].array[1][0] , tab[3].array[1][1] , tab[3].array[1][2] ,    tab[4].array[1][0] , tab[4].array[1][1] , tab[4].array[1][2],   tab[5].array[1][0] , tab[5].array[1][1] , tab[5].array[1][2],
    tab[3].array[2][0] , tab[3].array[2][1] , tab[3].array[2][2] ,    tab[4].array[2][0] , tab[4].array[2][1] , tab[4].array[2][2],   tab[5].array[2][0] , tab[5].array[2][1] , tab[5].array[2][2]
    );

    printf("\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t*---------*---------*---------*" , 
    tab[6].array[0][0] , tab[6].array[0][1] , tab[6].array[0][2],     tab[7].array[0][0] , tab[7].array[0][1] , tab[7].array[0][2],   tab[8].array[0][0] , tab[8].array[0][1] , tab[8].array[0][2],   
    tab[6].array[1][0] , tab[6].array[1][1] , tab[6].array[1][2] ,    tab[7].array[1][0] , tab[7].array[1][1] , tab[7].array[1][2],   tab[8].array[1][0] , tab[8].array[1][1] , tab[8].array[1][2],
    tab[6].array[2][0] , tab[6].array[2][1] , tab[6].array[2][2] ,    tab[7].array[2][0] , tab[7].array[2][1] , tab[7].array[2][2],   tab[8].array[2][0] , tab[8].array[2][1] , tab[8].array[2][2]
    );

  
}

char getPos(char **p, int x, int y){
    return p[x][y];
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}

int menuInicial(){
    int opcaoMenu;
    //Menu Inicial
    opcaoMenu = printMenuInical();
    if(opcaoMenu == 1 || opcaoMenu == 2)
        return opcaoMenu;

    if(opcaoMenu == 3)
        menuInicial(); //Por enquanto fica assim

    if(opcaoMenu == 4){
        printf("\nSAIR DO JOGO...\n");
        exit(0);
    }

    return (0);
}

int printMenuInical(){
    
    int opcao;
    char string[255];
  
    while(1){

        //apagarEcra();
        printf("\n############ Menu ############\n");
        printf("# 1 - Jogar com amigo        #\n");
        printf("# 2 - Jogar com o computador #\n");
        printf("# 3 - Ajudas                 #\n");
        printf("# 4 - Sair                   #\n");
        printf("##############################\n");
        printf("Escolha: ");
    
        fgets(string,sizeof(string)-1,stdin);
        string[strlen(string)-1] = '\0';
        opcao = atoi(string);
    
        putchar('\n');   
        if(opcao > 0 && opcao < 5)
            return (opcao);

      
        printf("\nEscolha uma opcao entre (1 e 4)");
    }

}

int jogarAmigo(struct dados *tab , int *turno , int *tabVitorias){
    int opcao;
    char string[255];
    int miniTabuleiro;

    int jogador = 1;
    //int ganhou;

   
    while(1){
            if(*turno != 1){
                mostraMatriz(tab);
            }

            printf("\n[TURNO %d]",*turno);
            printf("\n###### Jogar com Amigo ######\n");
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

int escolhe_jogada(struct dados *tab, int *jogador , int miniTabuleiro, int *tabVitorias , int turno){

	int pos;
    int N = 3;
    
    char string[50];
    char jogador1 = 'X';
    char jogador2 = 'O';
    char jogadorAtual;

	printf("\nÉ a vez do jogador %d [Mini tabuleiro: %d]\n", *jogador , miniTabuleiro + 1);
	do{
        strcpy(string , " ");  // Meti para limpar a string de varios inputs errados 
        printf("Posição para colocar peca entre (1 e 9): ");

		fgets(string,sizeof(pos),stdin);
        pos = atoi(string);
        putchar('\n');

	}while(pos<1 || pos > N*N || tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] != '_');

	if(*jogador == 1){
		tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] = jogador1;
        jogadorAtual = jogador1;
    }
	else{       //Se for o jogador 2
        tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] = jogador2;
        jogadorAtual = jogador2;
    }   

    if(verificarLinha(tab , miniTabuleiro) || verificarColuna(tab , miniTabuleiro) || verificarDiagonal(tab , miniTabuleiro) ){
        //ganhou = jogador;   
        tabVitorias[miniTabuleiro] = *jogador;
        ganharMiniJogo(tab , miniTabuleiro , jogadorAtual);
        
        if(verificarVitoria(tabVitorias , *jogador) ){

        }
        else
            escreveResultadoMini(*jogador , miniTabuleiro);
        //mostraMatriz(tab,9,9);
       //exit(1); 
    }  
    return (pos-1);
}

int minitabuleiroAleatorio(int *tabVitorias , int dimensaotabVitorias){
    
    int aleatorio; 
    do{
        aleatorio = intUniformRnd(1, dimensaotabVitorias-1);
    }while(tabVitorias[aleatorio] != 0);

    return (aleatorio);

}

void ganharMiniJogo(struct dados *tab , int miniTabuleiro , char caracter){


    for(int l = 0 ; l < 3 ; l++)
        for(int c = 0 ; c < 3 ; c++)
            tab[miniTabuleiro].array[l][c] = ' ';

    tab[miniTabuleiro].array[1][1] = caracter;


    return;
}

int verificarLinha(struct dados *tab , int miniTabuleiro){

    int i , j;
	for(i=0; i<3; i++)
		if(tab[miniTabuleiro].array[i][0] != '_'){
			for(j=0; j < 3-1 && tab[miniTabuleiro].array[i][j] == tab[miniTabuleiro].array[i][j+1]; j++)
				;
			if(j == 3-1)
				return 1;
		}
	return 0; 
}

int verificarColuna(struct dados *tab , int miniTabuleiro){
    int i , j;

    for(i = 0 ; i < 3 ; i++)        
        if(tab[miniTabuleiro].array[0][i] != '_'){
            for(j = 0 ; j < 3-1 && tab[miniTabuleiro].array[j][i] == tab[miniTabuleiro].array[j+1][i]; j++)
                ;
            if(j == 3-1)
                return (1);
        }

   return (0);
}

int verificarDiagonal(struct dados *tab , int miniTabuleiro){

    if(tab[miniTabuleiro].array[0][0] != '_' &&                                 //_
    tab[miniTabuleiro].array[0][0] == tab[miniTabuleiro].array[1][1] &&         //  _
    tab[miniTabuleiro].array[0][0] == tab[miniTabuleiro].array[2][2])           //     _
        return (1); 
    
    if(tab[miniTabuleiro].array[0][2] != '_' &&                                 //      _
    tab[miniTabuleiro].array[0][2] == tab[miniTabuleiro].array[1][1] &&         //   _
    tab[miniTabuleiro].array[0][2] == tab[miniTabuleiro].array[2][0])           // _
        return (1);

   return (0);
}

int verificarVitoria(int *tab , int jogador){

    int soma = 0;
    for(int i = 0 ; i < 9 ; i++){
        if(tab[i] == jogador)
            soma += 1;
    }
    if(soma == 3)
        return (jogador);
    
    return (0);
}

void escreveResultadoMini(int jogador , int miniTabuleiro){
    printf("\nO jogador %d ganho o minitabuleiro %d\n",jogador , miniTabuleiro+1);
}

void escreveResultado(int jogador){
    printf("\nGanhou o Jogador %d\n",jogador);
}