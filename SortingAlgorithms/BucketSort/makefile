CXX = g++
CXXFLAGS = -std=c++14 -I.

RM=rm -f

INTERFACE = ../SortingInterface.hpp
UTILS = ../SortingUtils.hpp ../SortingUtils.cpp 
BUCKET = BucketSortTest.cpp BucketSort.cpp BucketSort.hpp
SRCS =  $(INTERFACE) $(UTILS) $(BUCKET) 
OBJS=$(subst .cpp,.o,$SRCS)

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 