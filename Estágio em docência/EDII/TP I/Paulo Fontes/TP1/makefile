all: clean tp1.out

tp1.out: TAD/Cliente/cliente.o TAD/Fila/filas.o TAD/Pilha/pilha.o
	gcc -w main.c -o tp1.out TAD/Cliente/cliente.o TAD/Fila/filas.o TAD/Pilha/pilha.o

TAD/Cliente/cliente.o: TAD/Cliente/cliente.c
			gcc -c TAD/Cliente/cliente.c -o TAD/Cliente/cliente.o

TAD/Pilha/pilha.o: TAD/Pilha/pilha.c
			gcc -c TAD/Pilha/pilha.c -o TAD/Pilha/pilha.o

TAD/Fila/filas.o: TAD/Fila/filas.c
		        gcc -c TAD/Fila/filas.c -o TAD/Fila/filas.o

clean:
	-rm -f tp1.out
	-rm -f TAD/Fila/filas.o
	-rm -f TAD/Cliente/cliente.o
	-rm -f TAD/Pilha/pilha.o