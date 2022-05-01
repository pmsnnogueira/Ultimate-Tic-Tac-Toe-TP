#ifndef FUNCOES_H
#define FUNCOES_H

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMatriz(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
struct dados* criaMatriz();

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMatriz(struct dados *tab, int nLin, int nCol);

// Obtém o caracter armazenado na posição (x, y) de uma matriz de caracteres
char getPos(char **p, int x, int y);

// Coloca o caracter c na posição (x, y) de uma matriz dinâmica de caracteres
void setPos(char **p, int x, int y, char c);

//Minhas Funcoes
int printMenu();


#endif