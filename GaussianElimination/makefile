CXX = g++
CXXFLAGS = -std=c++11 -pg
CXXDEBUG = -g

SRCS =  *.cpp *.hpp 

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDEBUG)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out
