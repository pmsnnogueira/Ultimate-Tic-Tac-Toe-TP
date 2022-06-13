#ifndef JOGO_H
#define JOGO_H

//Jogar Com um Amigo

int jogarAmigo(struct dados *tab , int *turno , int **tabVitorias ,struct jogadas **lista , int *numeroNos , int *flagRecuperar);

int escolhe_jogada(struct dados *tab, int *jogador , int *miniTabuleiro, int *pos);

//Jogar com o Computador
int jogarComputador(struct dados *tab , int *turno , int **tabVitorias ,struct jogadas **lista, int *numeroNos , int *flagRecuperar);

int escolhe_jogadaComputador(struct dados *tab, int *jogador , int miniTabuleiro);

int botAleatorio(struct dados *tab ,int minitabuleiro, int dimensaoTabuleiro);

#endif /* UTILS_H */