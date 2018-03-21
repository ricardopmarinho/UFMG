tp1: fila1.o fila2.o pessoa.o pilha.o tp1.o
	gcc fila1.o fila2.o pessoa.o pilha.o tp1.o -o tp1
tp1.o: tp1.c fila1.h fila2.h pessoa.h pilha.h
	gcc -c tp1.c -o tp1.o
fila1.o: fila1.c fila1.h
	gcc -c fila1.c -o fila1.o
fila2.o: fila2.c fila2.h
	gcc -c fila2.c -o fila2.o
pessoa.o: pessoa.c pessoa.h
	gcc -c pessoa.c -o pessoa.o
pilha.o: pilha.c pilha.h
	gcc -c pilha.c -o pilha.o
clean:
	$(RM) *.o tp1
