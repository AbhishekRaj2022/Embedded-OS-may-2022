	CC=gcc


libarith.so : addmake.o submake.o mulpmake.o divmake.o 
	$(CC) -shared -fPIC -o libarith.so addmake.o submake.o mulpmake.o divmake.o

arithprog_make : addmake.o mainmake.o submake.o mulpmake.o divmake.o	#final executable is depenedent on 2 files#
	$(CC) -o arithprog_make addmake.o submake.o mainmake.o 	mulpmake.o divmake.o
	
addmake.o : add.c
	$(CC) -c -o addmake.o add.c

mainmake.o : main.c
	$(CC) -c -o mainmake.o main.c

submake.o : sub.c
	$(CC) -c -o submake.o sub.c

mulpmake.o : mulp.c
	$(CC) -c -o mulpmake.o mulp.c

divmake.o : div.c
	$(CC) -c -o divmake.o div.c

clean :
	rm -f addmake.o mainmake.o submake.o mulpmake.o divmake.o arithprog_make libarith.so