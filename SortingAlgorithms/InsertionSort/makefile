CXX = g++
CXXFLAGS = -o InsertionSort.bin -pg -std=c++17 -I../../include

INSERTION = InsertionSortTest.cpp InsertionSort.hpp
SRCS = $(INSERTION) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main
