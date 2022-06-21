
arithprog_make : addmake.o mainmake.o submake.o 	#final executable is depenedent on 2 files#
	gcc -o arithprog_make addmake.o submake.o mainmake.o 	
	
addmake.o : add.c
	gcc -c -o addmake.o add.c

mainmake.o : main.c
	gcc -c -o mainmake.o main.c

submake.o : sub.c
	gcc -c -o submake.o sub.c

clean :
	rm -f addmake.o mainmake.o submake.o arithprog_make