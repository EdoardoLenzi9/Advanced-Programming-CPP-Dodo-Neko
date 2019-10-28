CXX = g++
CXXFLAGS = -o Dijkstra.bin -std=c++17 -I../include
CXXDEBUG = -g
CXXPROF = -pg

SRCS =  *.cpp *.hpp 

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

debug:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDEBUG)

prof:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXPROF)

.PHONY: clean 

clean:
	$(RM) *.o *.gch Dijkstra.bin
