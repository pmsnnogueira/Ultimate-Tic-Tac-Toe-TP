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
    int i, a , k;

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

void mostraMatriz(struct dados *tab, int nLin, int nCol){

    printf("\
    \t\t\t*---------*---------*---------*\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t*---------*---------*---------*\n" , 
    tab[0].array[0][0] , tab[0].array[0][0] , tab[0].array[2][0],     tab[1].array[0][0] , tab[1].array[0][1] , tab[1].array[0][2],   tab[2].array[0][0] , tab[2].array[0][1] , tab[2].array[0][2],   
    tab[0].array[1][0] , tab[0].array[1][1] , tab[0].array[1][2] ,    tab[1].array[1][0] , tab[1].array[1][1] , tab[1].array[1][2],   tab[2].array[1][0] , tab[2].array[1][1] , tab[2].array[1][2],
    tab[0].array[2][0] , tab[0].array[2][1] , tab[0].array[2][2] ,    tab[1].array[2][0] , tab[1].array[2][1] , tab[1].array[2][2],   tab[2].array[2][0] , tab[2].array[2][1] , tab[2].array[2][2]
    );

    printf("\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t*---------*---------*---------*\n" , 
    tab[3].array[0][0] , tab[3].array[0][0] , tab[3].array[2][0],     tab[4].array[0][0] , tab[4].array[0][1] , tab[4].array[0][2],   tab[5].array[0][0] , tab[5].array[0][1] , tab[5].array[0][2],   
    tab[3].array[1][0] , tab[3].array[1][1] , tab[3].array[1][2] ,    tab[4].array[1][0] , tab[4].array[1][1] , tab[4].array[1][2],   tab[5].array[1][0] , tab[5].array[1][1] , tab[5].array[1][2],
    tab[3].array[2][0] , tab[3].array[2][1] , tab[3].array[2][2] ,    tab[4].array[2][0] , tab[4].array[2][1] , tab[4].array[2][2],   tab[5].array[2][0] , tab[5].array[2][1] , tab[5].array[2][2]
    );

    printf("\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t|  %c %c %c  |  %c %c %c  |  %c %c %c  |\n\
    \t\t\t*---------*---------*---------*" , 
    tab[6].array[0][0] , tab[6].array[0][0] , tab[6].array[2][0],     tab[7].array[0][0] , tab[7].array[0][1] , tab[7].array[0][2],   tab[8].array[0][0] , tab[8].array[0][1] , tab[8].array[0][2],   
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



int jogarAmigo(struct dados *tab , int *turno){
    int opcao;
    char string[255];
    int miniTabuleiro , x , y;

    int jogador = 1;

   
    while(1){
            if(*turno != 0)
                mostraMatriz(tab,9,9);
            printf("\n###### Jogar com Amigo ######\n");
            printf("# 1 - Inserir peça          #\n");
            printf("# 2 - Ver Jogadas           #\n");
            printf("#############################\n");

            printf("Escolha: ");

            fgets(string,sizeof(string)-1,stdin);
            string[strlen(string)-1] = '\0';
 
            opcao = atoi(string);
            
            putchar('\n');   
            if(opcao < 0 && opcao > 2)
                printf("\nEscolha uma opcao entre (1 e 2)");

            if(opcao == 1){
                if(*turno == 0){ //Se for o primeiro turno apresentar algumas dicas inciais
                    while(1){
                        printf("\
                        *-----*-----*-----*\n\
                        |  0  |  1  |  2  |\n\
                        *-----*-----*-----*\n\
                        |  3  |  4  |  5  |\n\
                        *-----*-----*-----*\n\
                        |  6  |  7  |  8  |\n\
                        *-----*-----*-----*\n");

                        printf("\nIntroduza o mini tabuleiro a jogar: ");
                       
                        fgets(string,sizeof(string)-1,stdin);
                        string[strlen(string)-1] = '\0';
                        miniTabuleiro = atoi(string);      
                        
                        if(miniTabuleiro >= 0 && miniTabuleiro <= 8)    //Validações de tabuleiro
                            break;

                        printf("\nIntroduza um mini Tabuleiro válido (entre 0 e 8)\n");
  
                   }
                }   //Se não for o primeiro turno
                (*turno)++;
               /* do{
                    putchar('\n');
                    mostraMatriz(tab , 9, 9);
                    printf("\nIntroduza as coordenadas de x e y entre (0,0) e (2,2): ");
                    scanf("%d %d" , &x , &y);
                }while((x > 0 && x < 2) && (y > 0 && y < 2));*/


                miniTabuleiro = escolhe_jogada(tab , &jogador , miniTabuleiro);

            //TENHO DE FAZER AS VITORIAS
               /* if(verificarLinha(tab , miniTabuleiro) || verificarColuna(tab , miniTabuleiro)  || verificarDiagonal(tab , miniTabuleiro) ){
                    ganhou = *jogador;   
                    tabVitorias[miniTabuleiro] = *jogador;
                    if(verificaJogo(tabVitorias , *jogador) == *jogador){
                        escreveResultado(*jogador);
                        return (1);
                    }
                }  */    


            }
        }
}

int escolhe_jogada(struct dados *tab, int *jogador , int miniTabuleiro)
{

	int pos;
    int N = 3;
    int ganhou = 0;
    
    char string[2];

    int tabVitorias[9];

	printf("\nÉ a vez do jogador %d [Mini tabuleiro: %d]\n", *jogador,miniTabuleiro);
	do{
        //mostraMatriz(tab,9,9);
        printf("Posição para colocar peca: ");

		fgets(string,sizeof(pos),stdin);
        pos = atoi(string);

	}while(pos<1 || pos > N*N || tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] != '_');

	if(*jogador == 1)
		tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] = 'X';
	else
        tab[miniTabuleiro].array[(pos-1)/N][(pos-1)%N] = 'O';



    //verificarVitoria();

    if(*jogador == 1)
        *jogador = 2;
    else
        *jogador = 1;

    return (pos);
}

int verificarLinha(struct dados *tab , int miniTabuleiro){

    int i , j;

    for(i = 0 ; i < 2 ; i++)        //Acho que tenho mal este 2
        if(tab[miniTabuleiro].array[i][0] != '_')
            for(j = 0 ; j < 2-1 && tab[miniTabuleiro].array[i][j] == tab[miniTabuleiro].array[i][j+1]; j++)
                ;
            if(j == 2-1)
                return (1);
        
    return (0);
}

int verificarColuna(struct dados *tab , int miniTabuleiro){
    int i , j;

    for(i = 0 ; i < 2 ; i++)        //Acho que tenho mal este 2
        if(tab[miniTabuleiro].array[0][i] != '_')
            for(j = 0 ; j < 2-1 && tab[miniTabuleiro].array[j][i] == tab[miniTabuleiro].array[j+1][i]; j++)
                ;
            if(j == 2-1)
                return (1);

   return (0);
}

int verificarDiagonal(struct dados *tab , int miniTabuleiro){

    return (0);
}

int verificarVitoria(int *tab , int jogador){

    int soma = 0;
    for(int i = 0 ; i < 9 ; i++){
        if(tab[i] == jogador)
            soma++;
    }
    if(soma == 3)
        return (jogador);
    
    return (0);
}

void escreveResultado(int jogador){
    printf("\nGanhou o Jogador %d\n",jogador);
}