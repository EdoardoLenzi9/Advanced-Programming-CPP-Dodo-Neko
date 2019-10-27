CXX = g++
CXXFLAGS = -O3 -o main -std=c++17 -I../../include


SORT = SortingTest.cpp
SRCS = $(SORT) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main