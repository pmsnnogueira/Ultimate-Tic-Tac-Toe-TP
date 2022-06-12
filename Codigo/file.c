#include "utils.h"
#include "file.h"
#include "funcoes.h"

int gravarFicheiro(jogadas *lista , int numeroJogadas, char *nome){

    FILE *fp;
    jogadas *aux = lista;
    fp = fopen(nome,"wb");
    if(fp == NULL){
        printf("\n<ERRO> ao abrir o ficheiro para guardar\n");
        return (1); 
    }
    
    fwrite(&numeroJogadas , sizeof(int) , 1 , fp);
    while(aux != NULL){
        /*//printf("ola\n");
        fwrite(aux->prox , sizeof(jogadas) , 1 , fp);
        //printf("ola");
        //aux = aux->prox;
        i++;*/
        fwrite(&aux->turno , sizeof(int) , 1 , fp);
        fwrite(&aux->minitabuleiro , sizeof(int) , 1 , fp);                 //Vou ter de usar este acho eu, 
        fwrite(&aux->jogador , sizeof(int) , 1 , fp);                       //Na aula o stor pedeiu para estudarmos o exemplo da lista duplamente ligada
        fwrite(&aux->posicao , sizeof(int) , 1 , fp);
        //fwrite(&aux->prox , sizeof(int) , 1 , fp);
        
        aux = aux->prox;
    }

    printf("Jogo guardado com sucesso com %d jogadas\n",numeroJogadas);
    fclose(fp);
    aux = lerFicheiro(nome);
    
    return (0);
}

jogadas* lerFicheiro(char *nome){

    FILE *fp;

    jogadas *lista = NULL;
    
    int numeroJogadas = 0;
    int i = 0;
    int turno , minitabuleiro , jogador , posicao;
    fp = fopen(nome , "rb");
    if(fp == NULL){

        printf("Erro ao abrir o ficheiro\n");
        return NULL;
    }
    

    fread(&numeroJogadas , sizeof(int) , 1 , fp);
    while(i < numeroJogadas){
        fread(&turno , sizeof(int) , 1 , fp);
        fread(&minitabuleiro , sizeof(int) , 1 , fp);
        fread(&jogador , sizeof(int) , 1 , fp);
        fread(&posicao , sizeof(int) , 1 , fp);
        


        //limpar a lista
        if(lista == NULL){
            lista = (jogadas*)malloc(sizeof(lista)); 
            if(lista == NULL){
                printf("Erro a alocar memoria para a lista ligada\n");
                return (NULL);
            }
            lista->jogador = jogador;
            lista->minitabuleiro = minitabuleiro;
            lista->posicao = posicao;
            lista->turno = turno;
            lista->prox = NULL;
            printf("Aqui");

        }else{
            while(lista->prox != NULL){
                lista = lista->prox;
            }
            //printf("fsafsaf");
            lista->prox = (jogadas*)malloc(sizeof(lista));
            if(lista->prox == NULL){
                //freeLista(lista);                 //Corrigir esta funcao 
                //Fazer o apagar a lista apagarLista(*lista);
                printf("Erro a alocar memoria para a lista ligada\n");
                return(NULL);
            }
            lista->prox->jogador = jogador;
            lista->prox->minitabuleiro = minitabuleiro;
            lista->prox->posicao = posicao;
            lista->prox->turno = turno;
            lista->prox->prox = NULL;        
        }
       // printf("%d %d %d %d\n",lista->turno, lista->minitabuleiro , lista->jogador , lista->posicao);
        //lista = lista->prox;

       i++;
    }
    imprimirLista(lista);
    printf("Numero jogadas a ler: %d\n",numeroJogadas);
    printf("\nA ler a lista...\n");
    //imprimirLista(&tmp);
    printf("\n");


    fclose(fp);
    printf("Aqui");
    
    return (lista);
    //return;
}

/*void insr(jogadas **lista){

    jogadas *p;

    p = (jogadas*)malloc(sizeof(jogadas));

}*/


//Guardar jogo em Ficheiro de texto
void guardarFinalJogo(jogadas *lista){

    char nome[100];
    FILE *fp;
    jogadas *aux = lista;

    printf("Introduza o nome do ficheiro para guardar o jogo: ");
    fgets(nome,sizeof(nome)-1,stdin);
    nome[strlen(nome)-1] = '\0';
    putchar('\n');
    fp = fopen(nome , "wt");
    if(fp == NULL){
        printf("\nErro ao abrir o ficheiro para guardar o jogo!\n");
        return ;
    }

    while(aux != NULL){
        
        fprintf(fp,"\n######JOGADAS######\n");
        fprintf(fp , "# Turno: %d         #\n",aux->turno);
        fprintf(fp , "# Minitabuleiro: %d #\n",aux->minitabuleiro);
        fprintf(fp , "# Jogador: %d       #\n",aux->jogador);
        fprintf(fp , "# Posicao: %d       #\n",aux->posicao);
        fprintf(fp , "####################\n");

        aux = aux->prox;
    }
    
    fclose(fp);
    return;
}