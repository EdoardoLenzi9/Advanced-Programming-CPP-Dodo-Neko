CXX = g++
CXXFLAGS = -std=c++11


UTILS = ../SortingUtils.cpp ../SortingUtils.hpp ../SortingInterface.hpp
BUBBLE = BubbleSortTest.cpp BubbleSort.hpp
SRCS =  $(UTILS) $(BUBBLE) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out
