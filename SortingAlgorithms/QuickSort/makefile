CXX = g++
CXXFLAGS = -o main -std=c++17 -I../../include

QUICK = QuickSortTest.cpp QuickSort.hpp
SRCS = $(QUICK) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main

