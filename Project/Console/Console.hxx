#ifndef CONSOLE_HXX
#define CONSOLE_HXX

#include <thread>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_DATA 512

class Console { 
    
    public:
        Console() : t(), running { true } {};
        void start();
        void run();
        void stop();

    private:
        thread t;
        bool running;
        int size, rank;
        char portname[MPI_MAX_PORT_NAME];
        char buf[MAX_DATA];
        MPI_Comm client;
        MPI_Status status;
        
};


#endif