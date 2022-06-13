#include "utils.h"
#include "file.h"
#include "funcoes.h"

//Ler toda a lista e gravar em um ficheiro binario
int gravarFicheiro(jogadas *lista , int numeroJogadas, char *nome){

    FILE *fp;
    jogadas *aux = lista;
    fp = fopen(nome,"wb");
    if(fp == NULL){
        printf("\n<ERRO> ao abrir o ficheiro para guardar\n");
        return (1); 
    }
    
    if(aux == NULL){
        remove(nome);
        printf("Ficheiro apagado devido a tentativa de salvar um jogo sem jogadas\n");
        return(0);
    }
        
    fwrite(&numeroJogadas , sizeof(int) , 1 , fp);
    while(aux != NULL){
        fwrite(&aux->turno , sizeof(int) , 1 , fp);
        fwrite(&aux->minitabuleiro , sizeof(int) , 1 , fp);                 //Vou ter de usar este acho eu, 
        fwrite(&aux->jogador , sizeof(int) , 1 , fp);                       //Na aula o stor pedeiu para estudarmos o exemplo da lista duplamente ligada
        fwrite(&aux->posicao , sizeof(int) , 1 , fp);

       // printf("A guardar: %d %d %d %d\n",aux->turno , aux->minitabuleiro , aux->jogador , aux->posicao);
        aux = aux->prox;
    }

    printf("Jogo guardado com sucesso com %d jogadas\n",numeroJogadas);
    fclose(fp);
    
    return (0);
}

//Ler o ficheiro binario e reconstruir toda a lista, tabuleiro e tabVitoria
jogadas* lerFicheiro(char *nome , struct dados *tab, int *turno , int **tabVitorias , int *numeroJogadas , int *miniTabuleiro , int *jogador , int *posicao){

    FILE *fp;
    jogadas *lista = NULL;
    jogadas *aux = lista;
    char jogadorCaracter;
    
    int i = 0;
    fp = fopen(nome , "rb");
    if(fp == NULL){

        printf("Erro ao abrir o ficheiro\n");
        return NULL;
    }

    printf("\nA ler o jogo guardado em '%s'\n",nome);

    fread(numeroJogadas , sizeof(int) , 1 , fp);
   // printf("%d" , numeroJogadas);
    for(i = 0 ; i < *numeroJogadas ;){
        fread(turno , sizeof(int) , 1 , fp);
        fread(miniTabuleiro , sizeof(int) , 1 , fp);
        fread(jogador , sizeof(int) , 1 , fp);
        fread(posicao , sizeof(int) , 1 , fp);
        
        //Adicionar o no na nova esttrutura
        insereJogadaFim(&lista , &i , *miniTabuleiro , *jogador , *posicao , *turno);
        /*if(lista == NULL){
            lista = (jogadas*)malloc(sizeof(lista)); 
            if(lista == NULL){
                printf("Erro a alocar memoria para a lista ligada\n");
                return (NULL);
            }
            lista->jogador = *jogador;
            lista->minitabuleiro = *miniTabuleiro;
            lista->posicao = *posicao;
            lista->turno = *turno;
            lista->prox = NULL;
           
        }else{
            while(aux.prox != NULL){
                aux = aux.prox;
            }
            aux->prox = (jogadas*)malloc(sizeof(lista));
            if(aux->prox == NULL){
                //freeLista(lista);                 //Corrigir esta funcao 
                //Fazer o apagar a lista apagarLista(*lista);
                printf("Erro a alocar memoria para a lista ligada\n");
                return(NULL);
            }
            aux->prox->jogador = *jogador;
            aux->prox->minitabuleiro = *miniTabuleiro;
            aux->prox->posicao = *posicao;
            aux->prox->turno = *turno;
            aux->prox->prox = NULL;        
        }*/
       // printf("Turno: %d\n" , lista->turno);
        //printf("\nA ler: %d %d %d %d\n", lista->turno , lista->jogador , lista->minitabuleiro , lista->posicao);
        //Reconstruir aqui o tabuliro
        

    }

    aux = lista;
    while(aux != NULL){
        if(aux->jogador == 1){
            jogadorCaracter = MARCAX;
            tab[aux->minitabuleiro-1].array[(aux->posicao-1) / 3][(aux->posicao-1) % 3] = 'X';
        }else if(aux->jogador == 2){
            jogadorCaracter = MARCAO;
            tab[aux->minitabuleiro-1].array[(aux->posicao-1) / 3][(aux->posicao-1) % 3] = 'O';
        }

        if(verificarLinha(tab , aux->minitabuleiro-1) || verificarColuna(tab , aux->minitabuleiro-1) || verificarDiagonal(tab , aux->minitabuleiro-1) ){
            tabVitorias[(aux->minitabuleiro-1) / 3][(aux->minitabuleiro-1) % 3] = aux->jogador;
            ganharMiniJogo(tab , aux->minitabuleiro-1 , jogadorCaracter);          //Apagar o minitabuleiro e meter no meio a letra
        }   
        aux = aux->prox;
    }

    
   // imprimirLista(lista);
    putchar('\n');
    putchar('\n');
    putchar('\n');
    (*turno)++; //preparar o proximo turno
    printf("Numero jogadas lidas: %d\n",*numeroJogadas);
    fclose(fp); 

    //imprimirLista(lista);
    return (lista);
}

//Guardar a lista toda em um Ficheiro de texto
void guardarFinalJogo(jogadas *lista){

    char nome[100];
    FILE *fp;
    jogadas *aux = lista;

    if(aux == NULL)
        return;

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