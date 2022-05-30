#ifndef SIMPLE_FILE_SHARING_UTILS_NETWORK_CONNECTION_H
#define SIMPLE_FILE_SHARING_UTILS_NETWORK_CONNECTION_H
int create_socket(int* targetFd);
void setup_target(in_addr_t address, int port, struct sockaddr_in *target);
int target_read(int targetFd, char** data, long *length);
int target_write(int targetFd, char* data, int length);
void target_close(int* targetFd);
#endif //SIMPLE_FILE_SHARING_UTILS_NETWORK_CONNECTION_H
