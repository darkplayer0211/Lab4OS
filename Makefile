all: main.o
	gcc -o ex main.o ex1.o
main.o: ex1.o
	gcc -c ex1.c main.c
ex1.o: ex1.c ex1.h
	gcc -c ex1.c
clean:
	rm -f *.o ex
	