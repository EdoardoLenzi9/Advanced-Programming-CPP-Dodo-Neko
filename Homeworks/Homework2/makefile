CXX = g++
CXXFLAGS = -o driver.bin -std=c++17 -I./Repositories -I./Repositories/Entities -I./Services
CXXDEBUG = -g
CXXPROF = -pg -no-pie
CXXDB = -lodb-sqlite -lodb

SRCS = *.cxx ./Repositories/*.cxx ./Repositories/Entities/*.cxx ./Services/*.cxx
FIND = find . -type f -name 
RM = -exec rm {} +

.PHONY: all

all: odb compile

compile:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDB)

odb: clean
	cd Repositories/Entities ; \
	odb -d sqlite --generate-query --generate-schema *.hxx

debug:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDB) $(CXXDEBUG)

prof:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDB) $(CXXPROF)

.PHONY: clean 

clean:
	$(FIND) '*.db' $(RM)
	$(FIND) '*odb.*' $(RM)
	$(FIND) '*.bin' $(RM)
	$(FIND) '*.o' $(RM)