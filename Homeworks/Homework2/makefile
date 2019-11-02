CXX = g++
CXXFLAGS = -o driver.bin -std=c++17 -I./Repositories/Entities
CXXDEBUG = -g
CXXPROF = -pg -no-pie

SRCS =  *.cxx *.hxx 

.PHONY: all

all:
	$(CXX) driver.cxx $(CXXFLAGS) $(SRCS)

debug:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDEBUG)

prof:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXPROF)

.PHONY: clean 

clean:
	$(RM) *.o *.gch driver.bin
