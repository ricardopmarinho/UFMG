CC=gcc
CFLAGS=-I. -std=c99
EXECUTABLE=Tp1
DEPS = fila.h pilha.h
OBJ = main.o fila.o pilha.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Tp1: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
