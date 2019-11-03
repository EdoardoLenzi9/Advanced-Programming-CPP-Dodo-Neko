CXX = g++
CXXFLAGS = -o BucketSort.bin -pg -std=c++17 -I../../include

BUCKET = BucketSortTest.cpp BucketSort.hpp
SRCS = $(BUCKET) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main
