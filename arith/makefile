CC = gcc

arithprog: add.o main.o
	$(CC) -o arithprog add.o main.o

add.o: add.c
	$(CC) -c -o add.o add.c

main.o: main.c
	$(CC) -c -o main.o main.c

clean:
	rm -f add.o main.o arithprog
