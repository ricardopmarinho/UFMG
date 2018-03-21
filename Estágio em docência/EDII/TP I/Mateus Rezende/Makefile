all: clean bandejao.out

bandejao.out: fila.o pilha.o bandejao.o
		gcc -w main.c -o bandejao.out fila.o pilha.o bandejao.o 

fila.o: fila.c
		gcc -c fila.c -o fila.o

pilha.o: pilha.c
		gcc -c pilha.c -o pilha.o

bandejao.o: bandejao.c
		gcc -c bandejao.c -o bandejao.o

clean:
	-rm -f bandejao.out
	-rm -f bandejao.o
	-rm -f fila.o
	-rm -f pilha.o