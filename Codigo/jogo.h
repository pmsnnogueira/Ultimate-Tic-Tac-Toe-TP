#ifndef JOGO_H
#define JOGO_H

int jogarComputador(struct dados *tab , int *turno , int **tabVitorias ,struct jogadas **lista , int *numeroNos);

int escolhe_jogadaComputador(struct dados *tab, int *jogador , int miniTabuleiro);

int botAleatorio(struct dados *tab ,int minitabuleiro, int dimensaoTabuleiro);

#endif /* UTILS_H */