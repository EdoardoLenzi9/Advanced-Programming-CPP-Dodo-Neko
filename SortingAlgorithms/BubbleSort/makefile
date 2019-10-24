CXX = g++
CXXFLAGS = -o main -std=c++17 -I../../include


BUBBLE = BubbleSortTest.cpp BubbleSort.hpp
SRCS = $(BUBBLE) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main