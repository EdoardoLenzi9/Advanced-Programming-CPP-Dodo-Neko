#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
#define MAX_DATA 512

using namespace std;

int main(int argc, char *argv[]){
   MPI_Comm server;
   MPI_Status status;

   int size, rank;
   int tag, dest;
   char portname[MPI_MAX_PORT_NAME]; 
   char buf[MAX_DATA];
   string data;

   bool running = true;


   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   if (argc >= 2){
      printf("Rank: %s", rank);
      printf("Trying connect to %s\n", argv[1]);
      strcpy(portname, argv[1]);
      MPI_Comm_connect(portname, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &server);

      while(running) {

         printf("Enter something (exit to exit): \n");

         getline(cin, data);

         strcpy(buf, data.c_str());

         if(data != "exit") {
            tag = 2; dest = 0;
            MPI_Send(buf, MAX_DATA, MPI_UNSIGNED_CHAR, dest, tag, server);
            MPI_Recv(buf, MAX_DATA, MPI_UNSIGNED_CHAR, MPI_ANY_SOURCE, 2, server, &status);
            printf("msg: %s\n", buf);                  

         } else {
            running = false;
         }

      }

      MPI_Send(buf, 0, MPI_UNSIGNED_CHAR, dest, 1, server);
      MPI_Comm_disconnect(&server);
   }
   MPI_Finalize();
}