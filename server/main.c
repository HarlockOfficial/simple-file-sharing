#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "network/connection/network_connection.h"
#include "network/manager/network_manager.h"

int main(int argc, char **argv){
    int port = 1234;
    int serverFd = 0;
    pthread_t thread;
    if(argc==2){
        port = atoi(argv[1]);
    }
    printf("Starting server on port: %d\n", port);
    server_listen(port, &serverFd);

    printf("Starting threads\n");
    char is_server_running = manager_is_server_running = 1;
    pthread_create(&thread, NULL, network_manager, &serverFd);

    char command[50];
    while(is_server_running==1){
        printf("> ");
        scanf("%s", command);
        if(strcmp(command, "help")==0){
            printf("To stop the server insert one of the following commands:\n\tstop\n\tdie\n\tquit\n\tkill\n\texit\n");
        }else if(strcmp(command, "stop")==0 || strcmp(command, "die")==0 || strcmp(command, "quit")==0 || strcmp(command, "kill")==0 || strcmp(command, "exit")==0){
            printf("Preparing to close the server");
            manager_is_server_running = 0;
            printf("Waiting for threads to close");
            pthread_join(thread, NULL);
            printf("Saving all work");
            //TODO Save all work
            is_server_running = 0;
        }else{
            printf("Command not valid, type help for a list of allowed commands\n");
        }
        printf("\n");
    }
    return 0;
}