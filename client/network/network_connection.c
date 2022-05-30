#include <arpa/inet.h>
#include "network_connection.h"
#include "../../utils/network/network_connection.h"

int client_connect(connection_details connection, int *serverFd){
    struct sockaddr_in server;
    if(create_socket(serverFd)!=0){
        return -1;
    }
    setup_target(inet_addr(connection.ip), connection.port, &server);
    int len = sizeof(server);
    if (connect(*serverFd, (struct sockaddr *)&server, len) < 0) {
        //Cannot connect to server
        return -2;
    }
    return 0;
}
