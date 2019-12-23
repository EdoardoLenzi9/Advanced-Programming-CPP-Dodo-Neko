#g++ -pthread -lboost_filesystem -lboost_system routing.cpp client_http.hpp server_http.hpp

CXX = g++
CXXFLAGS = -o driver.bin -std=c++11 
CXXINCLUDE = -I. \
			 -I./Repositories \
			 -I./Repositories/Entities \
			 -I./Services \
			 -I./Controllers \
			 -I./Middlewares \
			 -I./Routing \
			 -I./Utils \
			 -I./Include/Simple-Web-Server 
CXXDEBUG = -ggdb
CXXPROF = -pg -no-pie
CXXDB = -lodb-sqlite -lodb
CXXTHREAD = -pthread
CXXBOOST = -lboost_filesystem -lboost_system
SRCS = *.cxx \
	   ./Repositories/*.cxx \
	   ./Repositories/Entities/*.cxx \
	   ./Services/*.cxx \
	   ./Controllers/*.cxx \
	   ./Middlewares/*.cxx \
	   ./Routing/*.cxx \
	   ./Utils/*.cxx \
	   ./Include/Simple-Web-Server/client_http.hpp ./Include/Simple-Web-Server/server_http.hpp
FIND = find . -type f -name 
RM = -exec rm {} +


.PHONY: all


all: dependencies odb compile


compile:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(SRCS) $(CXXDB)

compile-services:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) *.cxx ./Services/*.cxx ./Repositories/*.cxx ./Repositories/Entities/*.cxx $(CXXDB)


odb: clean
	cd Repositories/Entities ; 
	odb -d sqlite --generate-query --generate-schema *.hxx


debug: 
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(SRCS) $(CXXDB) $(CXXDEBUG)


prof:
	$(CXX) $(CXXFLAGS) $(CXXINCLUDE) $(CXXTHREAD) $(CXXBOOST) $(SRCS) $(CXXDB) $(CXXPROF)


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
	@echo "Download and setup npm dependencies"
	@cd web/; \
	npm install


.PHONY: clean 


clean:
	$(FIND) '*.db' $(RM)
	$(FIND) '*odb.*' $(RM)
	$(FIND) '*.bin' $(RM)
	$(FIND) '*.o' $(RM)
