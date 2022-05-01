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
    int i, j;

    p = malloc(sizeof(dados) * 9);
    if(p == NULL)
        return (NULL);


    for(i = 0 ; i < 9 ; i++){
        p[i].array = malloc(sizeof(char *) * 3);     //Alocar linhas
        if(p[i].array == NULL){
            printf("Erro na alocação de memória!\n");
            return (-1);
        }
        for(int a = 0 ; a < 3 ; a++){
            p[i].array[a] = malloc(sizeof(char *) *3);  //Alocar Colunas
            if(p[i].array[a] == NULL){
                printf("Erro na alocação de memoria!\n");
                return (-1);
            }
        }
    }

    /*p->array = malloc(sizeof(char) * 3);            //Linhas
    for(i = 0 ; i < 3; i++)
        p[]->array[i] = malloc(sizeof(char *) * 3); //Colunas

    if(p->array == NULL)
        return (NULL);*/
    
    //Inicializar as posiçoes com o X
    for(i=0; i<9; i++){    
         for(int k = 0 ; k < 2 ; k++){
            for(int a = 0 ; a < 2 ; a++){
                p[i].array[k][a] = 'X';
            }
        }
    }
    
    return (p);
}

void mostraMatriz(struct dados *tab, int nLin, int nCol){
    int i,j;
    
    //Parte de cima
    for(i = 0 ; i < 3 ; i++){
        printf("*-----------------------");
        if(i == 2)
            printf("*");
    }

    putchar('\n');

    for(int l = 0 ; l < 3 ; l++){
        for(int c = 0 ; c < 3 ; c++){
            for(int ob = 0 ; ob < 9 ; ob++){
                
                printf(" %c ", tab[ob].array[c][l]);
                if(ob == 3){
                   // putchar('\n');
                }
            putchar('\t');
        }
        putchar('\n');
        }
    }



   /* for(int k = 0 ; k < 9 ; k++){

        /*if(k == 3 || k == 6)
            putchar('\n');*/
       /*printf("%d",k);
        for(int l = 0 ; l < 3 ; l++){
                //putchar('\t');
            for(int col = 0 ; col < 3 ; col++){
                printf(" %c " , tab[k].array[l][col]);
                if(col == 2)
                    printf("\n");
            }
        }
        putchar('\t');
        if(k == 2 || k == 5)
            putchar('\n');


    }*/
    
    putchar('\n');
    /*for(i=0; i<nLin; i++){
        if(i == 3 || i == 6){
            printf("\n");
            for(int a = 0 ; a < 3 ; a++){
                printf("*-----------------------");
                if(a == 2)
                    printf("*");
            }
        }
        putchar('\n');
        for(j=0; j < nCol; j++){
            if(j == 0)
                printf("|   %c\t );
            else
                printf("    %c\t");
            if(j == 2 || j == 5)
                printf("|");
        }
            
        printf("|\n");
    }*/
    for(i = 0 ; i < 3 ; i++){
        printf("*-----------------------");
        if(i == 2)
            printf("*");
    }
     






}

char getPos(char **p, int x, int y){
    return p[x][y];
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}


int printMenu(){
    int opcao;
    int flagSair = 0;

    while(flagSair == 0){
        printf("\n############ Menu ############\n");
        printf("# 1 - Jogar com amigo        #\n");
        printf("# 2 - Jogar com o computador #\n");
        printf("# 3 - Sair                   #\n");
        printf("##############################\n");

        printf("Escolha: ");
        scanf("%d",&opcao);
        putchar('\n');
        
        if(opcao > 0 && opcao < 4)
            return (opcao);

       // apagarEcra();
        printf("\nEscolha uma opcao entre (1 e 2)");
    }

    return (opcao);
}