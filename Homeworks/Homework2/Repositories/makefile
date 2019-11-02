CXX = g++
CXXFLAGS = -o driver.bin -std=c++17
CXXDEBUG = -g
CXXPROF = -pg -no-pie
CXXDB = -lodb-sqlite -lodb

SRCS =  *.cxx *.hxx 
FIND = find . -type f -name 
RM = -exec rm {} +

.PHONY: all

all:
	g++ -o driver.bin driver.cxx Repository.cxx DBManager.cxx Entities/*-odb.cxx -lodb-sqlite -lodb -g
	#$(CXX) $(CXXFLAGS) driver.cxx $(CXXDB)

odb: clean
	cd Entities ; \
	odb -d sqlite --generate-query --generate-schema *.hxx

debug:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXDEBUG)

prof:
	$(CXX) $(CXXFLAGS) $(SRCS) $(CXXPROF)

.PHONY: clean 

clean:
	$(FIND) '*odb.*' $(RM)
	$(FIND) '*.bin' $(RM)
	$(FIND) '*.o' $(RM)