CC=gcc
CFLAGS=-std=c99 -Wpedantic -Wall -Wextra -g
LDFLAGS=-lm -lpthread -lrt

all:
	@$(CC) retangulo.c main.c $(CFLAGS) $(LDFLAGS) -o output
	@ echo "Compilation finished sucessfully."

limpa:
	@rm -f *.o output
	@ echo "Directory cleaned."