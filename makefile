# Files

MATRIX_MULTIPLICATION = Utils/GenericAlgorithms/MatrixMultiplication.cpp Utils/GenericAlgorithms/MatrixMultiplication.hpp
MATRIX_MULTIPLICATION_TEST = Tests/MatrixMultiplicationTest.cpp
GAUSSIAN_ELIMINATION = ...
DIJKSTRA = ...
SIEVE_ERATOSTHENES = ...

BUBBLESORT = Utils/SortingAlgorithms/BubbleSort.cpp Utils/SortingAlgorithms/BubbleSort.hpp 
BUBBLESORT_TEST = Tests/BubbleSortTest.cpp
BUCKETSORT = Utils/SortingAlgorithms/BucketSort.cpp Utils/SortingAlgorithms/BucketSort.hpp 
BUCKETSORT_TEST = Tests/BucketSortTest.cpp
INSERTIONSORT = Utils/SortingAlgorithms/InsertionSort.cpp Utils/SortingAlgorithms/InsertionSort.hpp 
INSERTIONSORT_TEST = Tests/InsertionSortTest.cpp
COUNTINGSORT = ...
SELECTIONSORT = ...
QUICKSORT = ...

UTILS = ../SortingUtils.cpp ../SortingUtils.hpp
MATRIX = Matrix.cpp Matrix.hpp
VECTOR = Vector.cpp Vector.hpp
MAIN = main.cpp
TESTS = Tests/RunTests.cpp
FIXTURE = Tests/TestFixture.hpp


# Commands

CXX = g++
CXXFLAGS = -std=c++11
GTEST = -lgtest
RM = rm -f

SRCS =  $(BUBBLE) $(UTILS)
OBJS = $(subst .cpp,.o,$SRCS)
COMPILE = $(CXX) $(CXXFLAGS)

# Rules

.PHONY: clean help dependencies


all:
	$(COMPILE) $(SRCS)


clean:
	@echo "delete compiled/error files"
	$(RM) *.o *.gch


help:
	@echo Team:
	@echo " * Edoardo Lenzi"
	@echo " * ..."
	@echo " * ..."
	@echo " * ...\n"
	@echo Project details:
	@echo " The project provides a solution for some common algorithms\n"
	@echo Provided Rules:
	@echo " help \t\t\t prints Make rules."
	@echo " dependencies \t\t installs dependencies."
	@echo " start \t\t\t sets up dependencies and run tests."
	@echo " test \t\t\t starts test.\n"
	@echo Requirements: g++, bazel, cmake, git 


dependencies:
	@echo "make rule dependencies"
	@echo "setup gtest"
	@git clone https://github.com/google/googletest.git; \
	cd googletest; \
	cmake -DBUILD_SHARED_LIBS=ON .; \
	make; \
	sudo cp -a googletest/include/gtest /usr/include; \
	sudo cp -a lib/libgtest_main.so lib/libgtest.so /usr/lib/; \
	cd ..; \
	rm -rf googletest/


tests:
	@echo "make rule tests"
	@$(COMPILE) $(TESTS) $(FIXTURE) $(VECTOR) $(MATRIX) $(BUCKETSORT) $(BUCKETSORT_TEST) \
														$(BUBBLESORT) $(BUBBLESORT_TEST) \
														$(INSERTIONSORT) $(INSERTIONSORT_TEST) \
														$(MATRIX_MULTIPLICATION) $(MATRIX_MULTIPLICATION_TEST) \
	$(GTEST)
	@./a.out


run:
	@echo "make rule run"
	@echo "run main.cpp"
	@$(COMPILE) $(MAIN) $(VECTOR) $(BUBBLESORT) $(MATRIX) $(MATRIX_MULTIPLICATION)
	@./a.out