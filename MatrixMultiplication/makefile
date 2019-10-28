CXX = g++
CXXFLAGS = -o Matrix.bin -pg -std=c++17 -I../include


MATRIX = MatrixTest.cpp Matrix.hpp
SRCS = $(MATRIX) 
OBJS=$(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch Matrix.bin
