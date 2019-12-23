CXX = g++
CXXFLAGS = -o tests.bin -std=c++11 
CXXINCLUDE = -I. \
			 -I../Repositories \
			 -I../Repositories/Entities \
			 -I../Services \
			 -I../Controllers \
			 -I../Middlewares \
			 -I../Routing \
			 -I../Utils \
			 -I../Include/Simple-Web-Server \
			 -I./RepositoryTests 
CXXDEBUG = -ggdb
CXXPROF = -pg -no-pie
CXXDB = -lodb-sqlite -lodb
CXXTHREAD = -pthread
CXXBOOST = -lboost_filesystem -lboost_system
CXXTEST = -g -lcppunit 
SRCS = *.cxx \
	   ../Repositories/*.cxx \
	   ../Utils/*.cxx \
	   ../Repositories/Entities/*.cxx \
	   ./RepositoryTests/RepositoryTest.cxx
	   #../Services/*.cxx \
	   #../Controllers/*.cxx \
	   #../Middlewares/*.cxx \
	   #../Routing/*.cxx \
	   #../Include/Simple-Web-Server/client_http.hpp ../Include/Simple-Web-Server/server_http.hpp \

FIND = find . -type f -name 
RM = -exec rm {} +


.PHONY: all


all: odb compile test


compile:
	$(CXX)  $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(CXXTEST) $(SRCS) $(CXXDB)


test: compile
	./tests.bin


odb: clean
	cd ../Repositories/Entities ; 
	odb -d sqlite --generate-query --generate-schema *.hxx


debug: 
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(CXXTEST) $(SRCS) $(CXXDB) $(CXXDEBUG)


prof:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(CXXTEST) $(SRCS) $(CXXDB) $(CXXPROF)


.PHONY: clean 


clean:
	$(FIND) '*.db' $(RM)
	$(FIND) '*odb.*' $(RM)
	$(FIND) '*.bin' $(RM)
	$(FIND) '*.o' $(RM)
