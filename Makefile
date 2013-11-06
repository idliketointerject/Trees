CXXFLAGS=-std=gnu++0x
LDFLAGS=

SRC=\
     avl.o \
     bst.o \
     btree.o

HEADERS=\
     avl.h \
     bst.h \
     btree.h

all: bst avl tree_testing

.PHONY: all test bench clean

tree_testing: $(SRC) tree_testing.o $(HEADERS)
	$(CXX) $(LDFLAGS) $(SRC) tree_testing.o -o $@

bst: $(SRC) main.o $(HEADERS)
	$(CXX) $(LDFLAGS) $(SRC) main.o -o $@

avl: bst
	cp bst avl

clean:
	rm -f *.o
	rm -f bst avl tree_testing

