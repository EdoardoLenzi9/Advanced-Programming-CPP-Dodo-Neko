CXX = g++
CXXFLAGS = -o Sieve.bin -pg -std=c++17 -I../include


FILES = *.cpp *.hpp
SRCS = $(FILES) 
OBJS = $(subst .cpp,.o,$SRCS)

.PHONY: all

all:
	$(CXX) $(CXXFLAGS) $(SRCS)

.PHONY: clean 

clean:
	$(RM) *.o *.gch a.out Sieve.bin
