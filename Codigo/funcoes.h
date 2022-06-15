#ifndef FUNCOES_H
#define FUNCOES_H

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
struct dados* criaMatriz();

int **criarTabVitorias(int dimensao);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraTabuleiroJogo(struct dados *tab);

//Minhas Funcoes
int printMenuInical();

void printfMenuAjudas();

int menuInicial();

int minitabuleiroAleatorio(int **tabVitorias , int dimensaotabVitorias);

int verificarLinha(struct dados *tab , int miniTabuleiro);

int verificarColuna(struct dados *tab , int miniTabuleiro);

int verificarDiagonal(struct dados *tab , int miniTabuleiro);

int verificarEmpate(struct dados *tab , int miniTabuleiro);

int verificarVitoria(int **tabVitorias );

void ganharMiniJogo(struct dados *tab , int miniTabuleiro , char caracter);

void escreveResultadoMini(int jogador , int miniTabuleiro);

void escreveResultado(int jogador);

void insereJogadaFim(struct jogadas **lista , int *numeroNos ,int miniTabuleiro , int jogador , int posicao , int turno);

void preencheLista(jogadas *lista  , int miniTabuleiro , int jogador , int posicao , int turno);

void imprimirLista(jogadas *lista);

//Imprimir lista ao contrario usando recursividade
void imprimirListaAoContrario(jogadas *lista , int *count ,int numero);

void imprimirTabuleiroVitorias(int **tabVitorias);


#endif