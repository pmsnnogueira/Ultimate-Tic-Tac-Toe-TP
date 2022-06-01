#include <stdio.h>
#include <stdlib.h>

typedef struct jogo{

    int minijogo;

}jogo;

typedef struct lista{

    int minijogo;
    struct lista *prox;
}lista ;


void adicionarNo(struct lista **head , int i){

    lista *aux = *head;

    if(*head == NULL){
        *head = (lista*)malloc(sizeof(lista)); 
        if(*head == NULL){
            printf("Erro \n");
            exit(1);
        }
        (*head)->minijogo = i;
        (*head)->prox = NULL;
    }else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = (lista*)malloc(sizeof(lista));
        if(aux->prox == NULL){
            //Limpar a lista
        }
        aux->prox->minijogo = i;
        aux->prox->prox = NULL;
    }


}

void imprimirLista(struct lista *tab){
    while(tab != NULL){
        
        printf("\nMinijogo: %d\n",tab->minijogo);
        tab = tab->prox;
    }

}


int main(void){

    lista *tab = NULL;
    int i;

    adicionarNo(&tab , 1);

    adicionarNo(&tab , 5);

    imprimirLista(tab);


    return (0);
}