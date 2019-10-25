CXX = g++
CXXFLAGS = -o main -std=c++17 -I../../include


SORT = SortingTest.cpp ../BubbleSort/BubbleSort.hpp ../BucketSort/BucketSort.hpp ../QuickSort/QuickSort.hpp
SRCS = $(SORT) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main