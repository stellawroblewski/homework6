
CXX=g++
CXXFLAGS=-Wall -g -Wextra -pedantic -Werror -std=c++11
OPTFLAGS=-O3
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)

all: test_htree

test_htree: htree.o test_htree.o
	$(CXX) $(LDFLAGS) test_htree.o htree.o -o test_htree

tree.o: htree.cc htree.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c htree.cc -o htree.o

test_htree.o: test_htree.cc htree.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c test_htree.cc -o test_htree.o

clean:
	rm -rf *.o test_h tree
