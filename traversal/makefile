INC=../headers/

recursion:Recursion.c
	gcc -Wall -c Recursion.c -I$(INC)

nonrecursion:Nonrecursion.c ../util/Stack.c
	gcc -Wall -c Nonrecursion.c ../util/Stack.c -I$(INC)

breadthfirst:BreadthFirst.c ../util/Queue.c
	gcc -Wall -c BreadthFirst.c ../util/Queue.c -I$(INC)

clean:
	rm *.o


