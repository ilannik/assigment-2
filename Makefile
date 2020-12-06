all:main.o myBank.o libmyBank.a main

main:main.o myBank.o libmyBank.a
	gcc -g -Wall -o main main.c myBank.o libmyBank.a -L.

main.o:main.c
	gcc -g -Wall -c main.c
	
myBank.o:myBank.c
	gcc -g -Wall -c myBank.c
	
libmyBank.a: myBank.o myBank.h	
	ar -rcs libmyBank.a myBank.o myBank.h
	 
clean:
	rm *.o *.a *.gch
