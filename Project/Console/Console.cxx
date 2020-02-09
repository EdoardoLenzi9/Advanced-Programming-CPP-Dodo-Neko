#include "Console.hxx"

void Console::start() {

    t = thread(&Console::run, this);

}

void Console::run() {
    printf("console running...\n");

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    MPI_Open_port(MPI_INFO_NULL, portname);
    printf("portname: %s\n", portname);

    while(running) {

		MPI_Comm_accept(portname, MPI_INFO_NULL, 0, MPI_COMM_SELF, &client);
    	printf("client connected\n");

		bool open = true;

		while(open) {
			MPI_Recv(buf, MAX_DATA, MPI_UNSIGNED_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, client, &status);

			switch(status.MPI_TAG) {
				case 0: 
					running = false;
					break;
				case 1:
					MPI_Comm_disconnect(&client); 
					open = false; 
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

	MPI_Comm_free(&client); 
	MPI_Close_port(portname);
    MPI_Finalize();
}

void Console::stop() {
    running = false;
}