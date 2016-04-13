test_br.o: test_br.c ../headers/BinaryTree.h ../headers/CreateTree.h \
 ../headers/BinaryTree.h ../headers/Log.h
test_non.o: test_non.c ../headers/BinaryTree.h ../headers/CreateTree.h \
 ../headers/BinaryTree.h ../headers/Log.h
test_non_mac.o: test_non_mac.c ../headers/BinaryTree.h \
 ../headers/CreateTree.h ../headers/BinaryTree.h ../headers/Log.h
test_re.o: test_re.c ../headers/BinaryTree.h ../headers/CreateTree.h \
 ../headers/BinaryTree.h ../headers/Log.h
BreadthFirst.o: ../traversal/BreadthFirst.c ../headers/BinaryTree.h \
 ../headers/Queue.h
CreateTree.o: ../traversal/CreateTree.c ../headers/Log.h \
 ../headers/CreateTree.h ../headers/BinaryTree.h
MacNonRecursion.o: ../traversal/MacNonRecursion.c ../headers/BinaryTree.h
NonRecursion.o: ../traversal/NonRecursion.c ../headers/BinaryTree.h \
 ../headers/Stack.h
Recursion.o: ../traversal/Recursion.c ../headers/BinaryTree.h
Queue.o: ../util/Queue.c ../headers/Queue.h ../headers/Log.h
Stack.o: ../util/Stack.c ../headers/Stack.h ../headers/Log.h
