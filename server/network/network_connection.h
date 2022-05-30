#ifndef SIMPLE_FILE_SHARING_SERVER_NETWORK_CONNECTION_H
#define SIMPLE_FILE_SHARING_SERVER_NETWORK_CONNECTION_H
#include <arpa/inet.h>
int server_listen(int port, int *serverFd);
int server_accept(int serverFd, int *clientFd, struct sockaddr_in *client);
#endif //SIMPLE_FILE_SHARING_SERVER_NETWORK_CONNECTION_H
