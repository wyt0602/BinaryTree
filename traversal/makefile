INC=../headers/

Recursion.o:Recursion.c
	gcc -Wall -c $^ -I$(INC)

NonRecursion.o:NonRecursion.c ../util/Stack.c
	gcc -Wall -c $^ -I$(INC)

MacNonRecursion.o:MacNonRecursion.c
	gcc -Wall -c $^ -I$(INC)

BreadthFirst.o:BreadthFirst.c ../util/Queue.c
	gcc -Wall -c $^ -I$(INC)

clean:
	rm *.o


