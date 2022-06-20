#ifndef SIMPLE_FILE_SHARING_THREAD_DATA_H
#define SIMPLE_FILE_SHARING_THREAD_DATA_H
struct main_data{
    int* clientFd;
    int* serverFd;
    int thread_index;
    void* other_data;
};
void create_main_data(int *clientFd, int *serverFd, int thread_index, void* other_data, struct main_data* out);
#endif //SIMPLE_FILE_SHARING_THREAD_DATA_H
