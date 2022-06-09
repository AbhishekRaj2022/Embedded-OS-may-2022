# CC = gcc
CC = aarch64-none-linux-gnu-gcc

libarith.a: add.o sub.o 
	ar crv libarith.a add.o sub.o

arithprog: add.o main.o sub.o
	$(CC) -o arithprog add.o main.o sub.o

add.o: add.c
	$(CC) -c -o add.o add.c

sub.o: sub.c
	$(CC) -c -o sub.o sub.c	

main.o: main.c
	$(CC) -c -o main.o main.c

clean:
	rm -f add.o sub.o main.o arithprog libarith.a
