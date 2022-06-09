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
        fwrite(&aux->prox , sizeof(int) , 1 , fp);
        
        aux = aux->prox;
    }

    printf("Jogo guardado com sucesso com %d jogadas\n",numeroJogadas);
    fclose(fp);
    lerFicheiro(nome);
    
    return (0);
}

void lerFicheiro(char *nome){

    FILE *fp;
    jogadas tmp;
    int numeroJogadas = 0;
    
    fp = fopen(nome , "rb");
    if(fp == NULL){

        printf("Erro ao abrir o ficheiro\n");
        return;
    }

    fread(&numeroJogadas , sizeof(int) , 1 , fp);
    
    fread(&tmp.turno , sizeof(int) , 1 , fp);
    fread(&tmp.minitabuleiro , sizeof(int) , 1 , fp);
    fread(&tmp.jogador , sizeof(int) , 1 , fp);
    fread(&tmp.posicao , sizeof(int) , 1 , fp);
    //fread(&tmp , sizeof(jogadas) , numeroJogadas , fp);

    printf("Numero jogadas a ler: %d\n",numeroJogadas);
    printf("\nA ler a lista...\n");
    //imprimirLista(&tmp);
    printf("\n");


    fclose(fp);
    printf("Aqui");
    
    //return (lista);
    return;
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