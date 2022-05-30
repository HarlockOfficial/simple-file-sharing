#include <unistd.h> // write, read, close
#include <arpa/inet.h>
#include "network_connection.h"

int create_socket(int *targetFd){
    *targetFd = socket(AF_INET, SOCK_STREAM, 0);
    if (*targetFd < 0) {
        //Cannot create socket
        return -1;
    }
    return 0;
}

void setup_target(in_addr_t address, int port, struct sockaddr_in *target){
    target->sin_family = AF_INET;
    target->sin_addr.s_addr = address;
    target->sin_port = htons(port);
}

int target_read(int targetFd, char** data, long* length){
    *length = read(targetFd, *data, sizeof(*data));
    if (*length < 0) {
        return -1;
    }
    return 0;
}

int target_write(int targetFd, char* data, int length){
    if (write(targetFd, data, length) < 0) {
        return -1;
    }
    return 0;
}

void target_close(int *targetFd){
    close(*targetFd);
    *targetFd = 0;
}