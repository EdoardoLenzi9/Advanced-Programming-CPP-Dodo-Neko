CXX = g++
CXXFLAGS = -o BucketSort.bin -pg -std=c++17 -I../../include -fopenmp

BUCKET = BucketSortTest.cpp BucketSort.hpp BucketSortPar.hpp
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(BUCKET)

norm:
	$(CXX) $(CXXFLAGS) $(BUCKET)

.PHONY: clean 

clean:
	$(RM) *.o *.gch *.out *.bin
