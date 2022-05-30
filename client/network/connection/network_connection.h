#ifndef SIMPLE_FILE_SHARING_CLIENT_NETWORK_CONNECTION_H
#define SIMPLE_FILE_SHARING_CLIENT_NETWORK_CONNECTION_H
typedef struct {
     char ip[15];
     int port;
}connection_details;

int client_connect(connection_details connection, int* serverFd);
#endif //SIMPLE_FILE_SHARING_CLIENT_NETWORK_CONNECTION_H
