#directory for make, use space not : for dividing
VPATH=. ../headers ../traversal ../util 

#headers for gcc
GCCINC=-I../headers

#lib not standard
LIB_SUFFIX=

#parameter for gcc
CC=gcc
DEBUG=-pg -g
CFLAGS+=-Wall $(GCCINC) $(DEBUG)
DNAYMIC=-Wl,-rpath=
STATIC=-static

SRC:=$(foreach DIR,$(VPATH),$(wildcard $(DIR)/*.c))
SRC:=$(notdir $(SRC))
OBJS:=$(patsubst %.c,%.o,$(SRC))

#######################user's define start##############################
RECURSION:=Recursion.o CreateTree.o test_re.o
MACNONRECURSION:=MacNonRecursion.o CreateTree.o test_non_mac.o
NONRECURSION:=NonRecursion.o CreateTree.o Stack.o test_non.o
BREADTHFIRST:=BreadthFirst.o CreateTree.o Queue.o test_br.o

all:Recursion MacNonRecursion NonRecursion BreadthFirst

Recursion:$(RECURSION)
	$(CC) $(FLAGS) -o re_test $^

MacNonRecursion:$(MACNONRECURSION)
	$(CC) $(FLAGS) -o mac_non_test $^

NonRecursion:$(NONRECURSION)
	$(CC) $(FLAGS) -o non_test $^

BreadthFirst:$(BREADTHFIRST)
	$(CC) $(FLAGS) -o br_test $^


#######################user's define end################################

#generate dependency file
GenDependency:$(SRC)
	gcc -MM $^ $(GCCINC) > makefile.d

#include dependency file
-include makefile.d

#clean the current directory
.PHONY:clean
clean:
	-rm *.o *_test
	make GenDependency

#package the source
.PHONY:package
package:
	tar -cvf binarytree.tar $(VPATH)

