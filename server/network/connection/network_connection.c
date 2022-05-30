#include "network_connection.h"
#include "../../../utils/network/network_connection.h"
int server_listen(int port, int *serverFd){
    struct sockaddr_in server;
    if(create_socket(serverFd) != 0){
        return -1;
    }
    setup_target(INADDR_ANY, port, &server);
    int len = sizeof(server);
    if (bind(*serverFd, (struct sockaddr *)&server, len) < 0) {
        //Cannot bind socket
        return -2;
    }
    if (listen(*serverFd, 10) < 0) {
        //Listen error
        return -3;
    }
    return 0;
}
int server_accept(int serverFd, int *clientFd, struct sockaddr_in *client){
    unsigned int len = sizeof(*client);
    if ((*clientFd = accept(serverFd, (struct sockaddr*)client, &len)) < 0) {
        //accept error
        return -1;
    }
    return 0;
}