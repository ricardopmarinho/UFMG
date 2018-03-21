tp1: tp.o tp1.o
	gcc tp.o tp1.o -o tp1
tp1.o: tp1.c tp.h
	gcc -c tp1.c -o tp1.o
tp.o: tp.c tp.h
	    gcc -c tp.c -o tp.o
clean:
	$(RM) *.o tp1
