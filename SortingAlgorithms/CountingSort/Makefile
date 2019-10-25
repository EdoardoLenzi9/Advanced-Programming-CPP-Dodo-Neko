CXX = g++
CXXFLAGS = -o main -std=c++17 -I../../include

COUNTING = CountingSortTest.cpp CountingSort.hpp
SRCS = $(COUNTING) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main