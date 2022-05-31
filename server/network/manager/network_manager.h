#ifndef SIMPLE_FILE_SHARING_NETWORK_MANAGER_H
#define SIMPLE_FILE_SHARING_NETWORK_MANAGER_H
#define THREAD_COUNT 50

char manager_is_server_running = 0;
char is_thread_running[THREAD_COUNT] = {0};

void *network_manager(void* serverFd);
#endif //SIMPLE_FILE_SHARING_NETWORK_MANAGER_H
