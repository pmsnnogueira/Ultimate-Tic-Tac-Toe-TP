#ifndef FUNCOES_H
#define FUNCOES_H

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMatriz(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
struct dados* criaMatriz();

int *criarTabVitorias(int dimensao);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMatriz(struct dados *tab);

// Obtém o caracter armazenado na posição (x, y) de uma matriz de caracteres
char getPos(char **p, int x, int y);

// Coloca o caracter c na posição (x, y) de uma matriz dinâmica de caracteres
void setPos(char **p, int x, int y, char c);

//Minhas Funcoes
int printMenuInical();

int menuInicial();

int jogarAmigo(struct dados *tab , int *turno , int *tabVitorias ,struct jogadas *lista);

int escolhe_jogada(struct dados *tab, int *jogador , int *miniTabuleiro, int *tabVitorias , int *pos);

int minitabuleiroAleatorio(int *tabVitorias , int dimensaotabVitorias);

int verificarLinha(struct dados *tab , int miniTabuleiro);

int verificarColuna(struct dados *tab , int miniTabuleiro);

int verificarDiagonal(struct dados *tab , int miniTabuleiro);

int verificarVitoria(int *tab , int jogador);

void ganharMiniJogo(struct dados *tab , int miniTabuleiro , char caracter);

void escreveResultadoMini(int jogador , int miniTabuleiro);

void escreveResultado(int jogador);

void insereJogadaFim(struct jogadas **lista , int miniTabuleiro , int jogador , int posicao , int turno);

void preencheLista(jogadas *lista  , int miniTabuleiro , int jogador , int posicao , int turno);

void imprimirLista(jogadas *lista);

void freeLista(jogadas* lista);

//Imprimir lista ao contrario usando recursividade
void imprimirListaAoContrario(jogadas *lista , int *count ,int numero);


#endif