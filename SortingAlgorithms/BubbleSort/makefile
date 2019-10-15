CXX = g++
CXXFLAGS = -std=c++11
RM=rm -f

UTILS = ../SortingUtils.cpp ../SortingUtils.hpp
BUBBLE = BubbleSortTest.cpp BubbleSort.cpp BubbleSort.hpp
SRCS =  $(BUBBLE) $(UTILS)
OBJS=$(subst .cpp,.o,$SRCS)

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch
