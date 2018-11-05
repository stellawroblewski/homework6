
CXX=g++
CXXFLAGS=-Wall -g -Wextra -pedantic -Werror -std=c++11
OPTFLAGS=-O3
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)

all: test_hforest

test_hforest: HForest.o test_hforest.o
	$(CXX) $(LDFLAGS) test_hforest.o HForest.o -o test_hforest

HForest.o: HForest.cc HForest.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c HForest.cc -o HForest.o

test_hforest.o: test_hforest.cc HForest.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c test_hforest.cc -o test_hforest.o

clean:
	rm -rf *.o test_h HForest
