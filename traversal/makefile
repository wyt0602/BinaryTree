INC=../headers/

recursion:Recursion.c
	gcc -Wall -c $^ -I$(INC)

nonrecursion:NonRecursion.c ../util/Stack.c
	gcc -Wall -c $^ -I$(INC)

breadthfirst:BreadthFirst.c ../util/Queue.c
	gcc -Wall -c $^ -I$(INC)

clean:
	rm *.o


