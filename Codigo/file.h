#ifndef FILE_H
#define FILE_H

    int gravarFicheiro(jogadas *lista , int numeroJogadas, char *nome);


    jogadas* lerFicheiro(char *nome , struct dados *tab , int *turno , int **tabVitorias , int *numeroJogadas , int *miniTabuleiro , int *jogador , int *posicao);

    void guardarFinalJogo(jogadas *lista);


#endif