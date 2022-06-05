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
    
    while(aux != NULL){
        fwrite(&aux , sizeof(jogadas) , 1 , fp);
        aux = aux->prox;
    }

    printf("Jogo guardado com sucesso\n");
    fclose(fp);
   // lerFicheiro(&lista , nome);
    return (0);
}

void lerFicheiro(jogadas* lista , char *nome){

    /*FILE *fp;
    jogadas *tmp;
    int res;
    fp = fopen(nome , "r");
    if(fp == NULL){

        printf("Erro ao abrir o ficheiro\n");
        //return;
    }

    while(fread(tmp , sizeof(jogadas) , 1 , fp)){
        
        
    }


    fclose(fp);*/

   // printf("ola %d\n",res);
    //return (lista);
}

/*void insr(jogadas **lista){

    jogadas *p;

    p = (jogadas*)malloc(sizeof(jogadas));

}*/