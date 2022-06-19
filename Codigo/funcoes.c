#include "utils.h"
#include "funcoes.h"
#include "file.h"

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
struct dados* criaMatriz(){
    struct dados *p = NULL;
    int i, a , f , l , k;

    p = malloc(sizeof(dados) * 9);
    if(p == NULL)
        exit(EXIT_FAILURE);


    for(i = 0 ; i < 9 ; i++){
        p[i].array = malloc(sizeof(char *) * 3);     //Alocar linhas para cada minitabuleiro
        if(p[i].array == NULL){
            printf("Erro na alocação de memória!\n");   //Libertar a memoria ate ao erro
            for(f = 0 ; f < i; f++){
                free(p[f].array);                                        
            }
            free(p);
            exit(EXIT_FAILURE);
        }
        for(a = 0 ; a < 3 ; a++){
            p[i].array[a] = malloc(sizeof(char *) *3);  //Alocar Colunas para cada minitabuleiro
            if(p[i].array[a] == NULL){
                printf("Erro na alocação de memoria!\n");

                for(f = 0 ; f < i ; f++){
                    for(l = 0 ; l < a ; l++)
                        free(p[f].array[l]);                       
                    free(p[f].array);
                }
                free(p);

                exit(EXIT_FAILURE);
            }
        }
    }

    for(i=0; i<9; i++){    
         for(k = 0 ; k < 3 ; k++){
            for(a = 0 ; a < 3 ; a++){
                p[i].array[k][a] = '_';
            }
        }
    }
    return (p);
}

// cria dinamicamente um tabuleiro de vitorias 3x3
int **criarTabVitorias(int dimensao){
    
    int **tab = NULL;
    int i , l,c;
    
    tab = malloc(sizeof(int) * dimensao);
    if(tab == NULL){
        printf("Erro na alocacao de memoria no tabuleiro Vitorias\n");
        exit (EXIT_FAILURE);
    }
    for(i = 0 ; i < dimensao ; i++){
        tab[i] = malloc(sizeof(int) * dimensao);
        if(tab[i] == NULL){
            printf("Erro na alocacao de memoria no tabuleiro Vitorias\n");

            for(int k = 0 ; k < i ; k++)
                free(tab[k]);
            free(tab);
            
            exit(EXIT_FAILURE);
        }

    }

    for(l = 0; l < dimensao ; l++)
        for(c = 0 ; c < dimensao ; c++)
            tab[l][c] = 0;

    return (tab);
}

void mostraTabuleiroJogo(struct dados *tab){

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

int menuInicial(){

    int opcaoMenu;
    //Menu Inicial
    opcaoMenu = printMenuInical();
    if(opcaoMenu == 1 || opcaoMenu == 2)
        return opcaoMenu;

    if(opcaoMenu == 3){
        printf("\nA SAIR DO JOGO...\n");
        return(0);
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
        printf("# 3 - Sair                   #\n");
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

//Gerar uma posicao para um minitabuleiro aleatorio
int minitabuleiroAleatorio(int **tabVitorias , int dimensaotabVitorias){
    
    int pos = 0;

    do{
        pos = intUniformRnd(1 , dimensaotabVitorias);
    }while(tabVitorias[(pos-1)/3][(pos-1)%3] != 0);                              //Possivelmente fazer dois ciclos um para o x e outro para o y
                                                                    //Ou meter duas variaveis que façam aleatoriamente a cena
    return (pos);
}

//Colocar o caracter no meio do mintabuleiro quando o jogador ganha
void ganharMiniJogo(struct dados *tab , int miniTabuleiro , char caracter){


    for(int l = 0 ; l < 3 ; l++)
        for(int c = 0 ; c < 3 ; c++)
            tab[miniTabuleiro].array[l][c] = ' ';

    tab[miniTabuleiro].array[1][1] = caracter;


    return;
}

//Verificacoes por minitabuleiro
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

//Verificar empate, só é considerado empate quando o minitabuleiro está totalmente preenchido
int verificarEmpate(struct dados *tab , int miniTabuleiro){
    int l , c;
    for(l = 0 ; l < 3 ; l++){
        for(c = 0 ; c < 3 ; c++){
            if(tab[miniTabuleiro].array[l][c] == '_')
                return (0);
        }
    }
    return (1);
}

//Verificar se algum dos jogadores ganhou o jogo completo
int verificarVitoria(int **tabVitorias){

    int i = 0, j = 0;

    //Verificar Linhas
    for(i = 0; i < 3; i++)
    if(tabVitorias[i][0] != 0 && tabVitorias[i][0] != 3){
        for(j = 0; j < 3-1 && tabVitorias[i][j] == tabVitorias[i][j+1]; j++)
            ;
        if(j == 3-1)
            return (1);
    }

    //Verificar Colunas
    for(i = 0 ; i < 3 ; i++)        
    if(tabVitorias[0][i] != 0 && tabVitorias[0][i] != 3){
        for(j = 0 ; j < 3-1 && tabVitorias[j][i] == tabVitorias[j+1][i]; j++)
            ;
        if(j == 3-1)
            return (1);
    }

    //Verificar Diagonal
     if(tabVitorias[0][0] != 0 && tabVitorias[0][0] != 3 &&               
    tabVitorias[0][0] == tabVitorias[1][1]  && tabVitorias[0][0] == tabVitorias[2][2])         
        return (1); 
    
    if(tabVitorias[0][2] != 0 && tabVitorias[0][2] !=3 &&        
    tabVitorias[0][2] == tabVitorias[1][1] &&         
    tabVitorias[0][2] == tabVitorias[2][0])           
        return (1);
    


    return (0);
}

void escreveResultadoMini(int jogador , int miniTabuleiro){
    printf("\nO jogador %d ganho o minitabuleiro %d\n",jogador , miniTabuleiro+1);
}

void escreveResultado(int jogador){
    printf("\nGanhou o Jogador %d\n",jogador);
}

//Inserir nos na Lista Ligada
void insereJogadaFim(struct jogadas **lista , int *numeroNos, int miniTabuleiro , int jogador , int posicao , int turno){

    jogadas *aux = *lista;
   
    if(*lista == NULL){
        *lista = (jogadas*)malloc(sizeof(lista)); 
        if(*lista == NULL){
            printf("Erro a alocar memoria para a lista ligada\n");
            return;
        }
        (*lista)->jogador = jogador;
        (*lista)->minitabuleiro = miniTabuleiro;
        (*lista)->posicao = posicao;
        (*lista)->turno = turno;
        (*lista)->prox = NULL;
    }else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = (jogadas*)malloc(sizeof(lista));
        if(aux->prox == NULL){
            //freeLista(lista);                 //Corrigir esta funcao 
            //Fazer o apagar a lista apagarLista(*lista);
            printf("Erro a alocar memoria para a lista ligada\n");
            return;
        }
        aux->prox->jogador = jogador;
        aux->prox->minitabuleiro = miniTabuleiro;
        aux->prox->posicao = posicao;
        aux->prox->turno = turno;
        aux->prox->prox = NULL;        
    }
    (*numeroNos)++;
    return;
}

//Imprimir lista ligada toda de seguida
void imprimirLista(jogadas *lista){
    
    if(lista == NULL){
        printf("\nNão há jogadas anteriores!\n");
        return;
    }

    while(lista != NULL){
        printf("\n#####JOGADAS####\n");
        printf("# Turno: %d         #\n",lista->turno);
        printf("# Minitabuleiro: %d #\n",lista->minitabuleiro);
        printf("# Jogador: %d       #\n",lista->jogador);
        printf("# Posicao: %d       #\n",lista->posicao);
        printf("#####################\n");
        lista = lista->prox;
    }
   return;
}

//Imprimir a lista ligada Recursivamente ao contrario ate um limite inserido por um utilizador
void imprimirListaAoContrario(jogadas *lista , int *count ,int numero){

    if(lista == NULL)
        return ;
        
    imprimirListaAoContrario(lista->prox , count , numero);

    (*count)++;
    if(numero >= *count && *count <= 10){           //Apenas vai imprimir as primeiras iterações até atingir o numero pretendido, pq temos de pensar com a recursividade ele vai fazer as coisas ao contrario
        printf("\n######JOGADAS######\n");
        printf("# Turno: %d         #\n",lista->turno);
        printf("# Minitabuleiro: %d #\n",lista->minitabuleiro);
        printf("# Jogador: %d       #\n",lista->jogador);
        printf("# Posicao: %d       #\n",lista->posicao);
        printf("####################\n");
    }
    return;
}

//Imprimir o tabuleiro de Vitorias
void imprimirTabuleiroVitorias(int **tabVitorias){

    putchar('\n');
    for(int l = 0 ; l < 3 ; l++){
        for(int c = 0 ; c < 3 ; c++)
            printf("|%d" , tabVitorias[l][c]);
        putchar('\n');
    }
}





