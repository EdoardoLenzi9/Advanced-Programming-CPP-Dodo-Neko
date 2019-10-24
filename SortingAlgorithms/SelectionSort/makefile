CXX = g++
CXXFLAGS = -std=c++11


UTILS = ../SortingUtils.cpp ../SortingUtils.hpp ../SortingInterface.hpp
SSORT = SelectionSortTest.cpp SelectionSort.hpp
SRCS =  $(UTILS) $(SSORT) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out
