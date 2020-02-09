#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_DATA 512

int size, rank;
 
int main(int argc, char *argv[]){
   MPI_Comm client;
   MPI_Status status;
   char portname[MPI_MAX_PORT_NAME];
   char buf[MAX_DATA];
 
   bool running = true;

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 
   MPI_Open_port(MPI_INFO_NULL, portname);
   printf("portname: %s\n", portname);
   MPI_Comm_accept(portname, MPI_INFO_NULL, 0, MPI_COMM_SELF, &client);
   printf("client connected\n");

   while(running) {

      MPI_Recv(buf, MAX_DATA, MPI_UNSIGNED_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, client, &status);

      switch(status.MPI_TAG) {

         case 0:
            MPI_Comm_free(&client); 
            MPI_Close_port(portname); 
            MPI_Finalize(); 
            return 0;
         case 1:
            MPI_Comm_disconnect(&client); 
            running = false; 
            break; 
         case 2:
            printf("msg: %s\n", buf);
            strcat(buf, "_RETURN");
            printf("ans: %s\n", buf);

            MPI_Send(buf, MAX_DATA, MPI_UNSIGNED_CHAR, 0, 2, client);

            break;
         default:
            MPI_Abort(MPI_COMM_WORLD, 1);

      }

   }

}