CXX = g++
CXXFLAGS = -o driver.bin -std=c++11 -I./Repositories -I./Repositories/Entities -I./Services -I./UI
CXXDEBUG = -ggdb
CXXPROF = -pg -no-pie
CXXDB = -lodb-sqlite -lodb
CLIBS = -lreadline
SRCS = *.cxx ./Repositories/*.cxx ./Repositories/Entities/*.cxx ./Services/*.cxx ./UI/*.cxx
FIND = find . -type f -name 
RM = -exec rm {} +

.PHONY: all

all: odb compile

compile:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDB) $(CLIBS)

odb: clean
	cd Repositories/Entities ; \
	odb -d sqlite --generate-query --generate-schema *.hxx

debug: 
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDB) $(CLIBS) $(CXXDEBUG)

prof:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDB)  $(CLIBS) $(CXXPROF)

.PHONY: clean 

clean:
	$(FIND) '*.db' $(RM)
	$(FIND) '*odb.*' $(RM)
	$(FIND) '*.bin' $(RM)
	$(FIND) '*.o' $(RM)
