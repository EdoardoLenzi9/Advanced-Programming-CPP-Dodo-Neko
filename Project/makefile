#g++ -pthread -lboost_filesystem -lboost_system routing.cpp client_http.hpp server_http.hpp

CXX = mpic++
CXXFLAGS = -o driver.bin -std=c++11 
CXXINCLUDE = -I. \
			 -I./Repositories \
			 -I./Repositories/Entities \
			 -I./Repositories/Dto \
			 -I./Services \
			 -I./Controllers \
			 -I./Middlewares \
			 -I./Exceptions \
			 -I./Routing \
			 -I./Utils \
			 -I./SHA256 \
			 -I./Console \
			 -I./Include/Simple-Web-Server 
CXXDEBUG = -ggdb
CXXPROF = -pg -no-pie
CXXDB = -lodb-sqlite -lodb
CXXTHREAD = -pthread
CXXBOOST = -lboost_filesystem -lboost_system
CXXOMP = -fopenmp

SRCS = *.cxx \
	   ./Repositories/*.cxx \
	   ./Repositories/Entities/*.cxx \
	   ./Services/*.cxx \
	   ./Controllers/*.cxx \
	   ./Middlewares/*.cxx \
	   ./Routing/*.cxx \
	   ./Utils/*.cxx \
	   ./SHA256/*.cxx \
	   ./Console/*.cxx \
	   ./Include/Simple-Web-Server/client_http.hpp ./Include/Simple-Web-Server/server_http.hpp
FIND = find . -type f -name 
RM = -exec rm {} +


.PHONY: all


all: dependencies odb compile compile-client


compile:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(SRCS) $(CXXDB) $(CXXOMP)

compile-services:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) *.cxx ./Services/*.cxx ./Repositories/*.cxx ./Repositories/Entities/*.cxx $(CXXDB)

compile-client:
	$(CXX) -o ./Client/client.bin ./Client/client.cxx

odb: clean
	cd Repositories/Entities ; \
	odb -d sqlite --generate-query --generate-schema *.hxx


debug: 
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(SRCS) $(CXXDB) $(CXXOMP) $(CXXDEBUG)


prof:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(SRCS) $(CXXDB) $(CXXOMP) $(CXXPROF)

run:
	mpirun -np 1 ./driver.bin

dependencies:
	@echo "Download and setup Simple-Web-Server"
	@mkdir Include; \
	cd Include; \
	git clone https://github.com/eidheim/Simple-Web-Server; \
	cd Simple-Web-Server; \
	mkdir build; \
	cd build; \
	cmake ..; \
	make
	# please dont make the makefile install npm

.PHONY: clean 


clean:
	$(FIND) '*.db' $(RM)
	$(FIND) '*odb.*' $(RM)
	$(FIND) '*.bin' $(RM)
	$(FIND) '*.o' $(RM)
