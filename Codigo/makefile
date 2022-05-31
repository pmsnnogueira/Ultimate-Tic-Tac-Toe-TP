CC=gcc
CFLAGS=-std=c99 -Wpedantic -Wall -Wextra -g

all:
	@$(CC) utils.c funcoes.c jogo.c main.c $(CFLAGS) -o output
	@ echo "Compilação realizada com sucesso."

limpa:
	@rm -f *.o output
	@ echo "Diretorio apagado com sucesso!"