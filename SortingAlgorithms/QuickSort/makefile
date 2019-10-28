CXX = g++
CXXFLAGS = -o QuickSort.bin -pg -std=c++11 -I../../include

QUICK = QuickSortTest.cpp QuickSort.hpp
SRCS = $(QUICK) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main

