#include "thread_data.h"
void create_main_data(int *clientFd, int *serverFd, int thread_index, void* other_data, struct main_data* out){
    out->clientFd = clientFd;
    out->serverFd = serverFd;
    out->thread_index = thread_index;
    out->other_data = other_data;
}