CXX = g++
CXXFLAGS = -o BucketSort.bin -pg -std=c++17 -I../../include -fopenmp
CXXFLAGSP = -o BucketSortParallel.bin -pg -std=c++17 -I../../include -fopenmp

BUCKET = BucketSortTest.cpp BucketSort.hpp BucketSortParallel.hpp
BUCKETP = BucketSortTestParallel.cpp BucketSort.hpp BucketSortParallel.hpp

OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(BUCKET)
	$(CXX) $(CXXFLAGSP) $(BUCKETP)
	sleep 5s
	echo "Parallel Version"
	./BucketSortParallel.bin
	sleep 5s
	echo "Normal Version"
	./BucketSort.bin

norm:
	$(CXX) $(CXXFLAGS) $(BUCKET)

.PHONY: clean 

clean:
	$(RM) *.o *.gch *.out *.bin
