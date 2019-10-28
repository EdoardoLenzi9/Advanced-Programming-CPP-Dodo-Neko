CXX = g++
CXXFLAGS = -o main -pg -std=c++17 -I../include


MATRIX = MatrixTest.cpp Matrix.hpp
SRCS = $(MATRIX) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out main
