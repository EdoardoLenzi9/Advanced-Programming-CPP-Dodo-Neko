CXX = g++
CXXFLAGS = -std=c++11

UTILS = ../SortingUtils.cpp ../SortingUtils.hpp
BUBBLE = QuickSortTest.cpp QuickSort.cpp QuickSort.hpp
SRCS =  $(UTILS) $(BUBBLE) 
OBJS=$(subst .cpp,.o,$SRCS)
PROG = prog

.PHONY: all
all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o prog

.PHONY: clean
clean:
	$(RM) *.o *.gch a.out
