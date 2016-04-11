INC=../headers/
#PG= -O1 -pg
PG=
Recursion:Recursion.o CreateTree.o  test_re.c
	gcc -Wall $(PG) -o re_test $^ -I$(INC)

NonRecursion:NonRecursion.o CreateTree.o Stack.o test_non.c
	gcc -Wall $(PG) -o non_test $^ -I$(INC)

BreadthFirst:BreadthFirst.o CreateTree.o Queue.o test_br.c
	gcc -Wall $(PG) -o br_test $^ -I$(INC)

CreateTree.o:../traversal/CreateTree.c
	gcc -Wall $(PG) -c $^ -I$(INC)

Recursion.o:../traversal/Recursion.c
	gcc -Wall $(PG) -c $^ -I$(INC)

NonRecursion.o:../traversal/NonRecursion.c
	gcc -Wall $(PG) -c $^ -I$(INC)

BreadthFirst.o:../traversal/BreadthFirst.c
	gcc -Wall $(PG) -c $^ -I$(INC)

Stack.o:../util/Stack.c
	gcc -Wall $(PG) -c $^ -I$(INC)

Queue.o:../util/Queue.c
	gcc -Wall $(PG) -c $^ -I$(INC)

clean:
	rm *.o re_test br_test non_test


