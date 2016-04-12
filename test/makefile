VPATH=../headers:../traversal:../util
GCCINC=-I../headers/
SOURCE=test_re.c test_non_mac.c test_non.c test_br.c \
       CreateTree.c Recursion.c NonRecursion.c MacNonRecursion.c \
       BreadthFirst.c Stack.c Queue.c
CFLAGS+=-Wall $(GCCINC)
CC=gcc
PG=

all:Recursion MacNonRecursion NonRecursion BreadthFirst

Recursion:Recursion.o CreateTree.o  test_re.o
	$(CC) $(PG) -o re_test $^ $(GCCINC)

MacNonRecursion:MacNonRecursion.o CreateTree.o test_non_mac.o
	$(CC) $(PG) -o mac_non_test $^ $(GCCINC)

NonRecursion:NonRecursion.o CreateTree.o Stack.o test_non.o
	$(CC) $(PG) -o non_test $^ $(GCCINC)

BreadthFirst:BreadthFirst.o CreateTree.o Queue.o test_br.o
	$(CC) $(PG) -o br_test $^ $(INC)

GenMakefile:$(SOURCE)
	gcc -MM $^ $(GCCINC) >> makefile

clean:
	rm *.o *_test

test_re.o: test_re.c ../headers/BinaryTree.h ../headers/CreateTree.h \
 ../headers/BinaryTree.h ../headers/Log.h
test_non_mac.o: test_non_mac.c ../headers/BinaryTree.h \
 ../headers/CreateTree.h ../headers/BinaryTree.h ../headers/Log.h
test_non.o: test_non.c ../headers/BinaryTree.h ../headers/CreateTree.h \
 ../headers/BinaryTree.h ../headers/Log.h
test_br.o: test_br.c ../headers/BinaryTree.h ../headers/CreateTree.h \
 ../headers/BinaryTree.h ../headers/Log.h
CreateTree.o: ../traversal/CreateTree.c ../headers/Log.h \
 ../headers/CreateTree.h ../headers/BinaryTree.h
Recursion.o: ../traversal/Recursion.c ../headers/BinaryTree.h
NonRecursion.o: ../traversal/NonRecursion.c ../headers/BinaryTree.h \
 ../headers/Stack.h
MacNonRecursion.o: ../traversal/MacNonRecursion.c ../headers/BinaryTree.h
BreadthFirst.o: ../traversal/BreadthFirst.c ../headers/BinaryTree.h \
 ../headers/Queue.h
Stack.o: ../util/Stack.c ../headers/Stack.h ../headers/Log.h
Queue.o: ../util/Queue.c ../headers/Queue.h ../headers/Log.h
