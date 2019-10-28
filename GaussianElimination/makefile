CXX = g++
CXXFLAGS = -o GaussianElimination.bin -std=c++11 -I../include
CXXDEBUG = -g

SRCS =  *.cpp *.hpp 

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDEBUG)

.PHONY: clean 

clean:
	$(RM) *.o *.gch GaussianElimination.bin
