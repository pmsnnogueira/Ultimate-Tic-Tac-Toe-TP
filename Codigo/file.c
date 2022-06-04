#include "utils.h"
#include "file.h"

int gravarFicheiro(jogadas **lista , int numeroJogadas, char *nome){

    FILE *fp;
    jogadas *aux = *lista;
    //int res;
    int i;

    fp = fopen(nome,"wb");
    if(fp == NULL){
        printf("\n<ERRO> ao abrir o ficheiro para guardar\n");
        return (1); 
    }

    
    while(aux != NULL){
        fwrite(aux , sizeof(jogadas) , 1 , fp);
        aux = aux->prox;
    }


    printf("Sucesso\n");
    fclose(fp);
    return (0);
}

jogadas* lerFicheiro(char *nome){

    FILE *fp;
    jogadas *tmp;
    fp = fopen(nome , "r");
    if(fp == NULL){

        printf("Erro ao abrir o ficheiro\n");
        //return;
    }

    while(fread(tmp , sizeof(jogadas) , 1 , fp)){
        //if()
    }


    //return (lista);
}