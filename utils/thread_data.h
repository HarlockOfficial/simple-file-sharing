#ifndef SIMPLE_FILE_SHARING_THREAD_DATA_H
#define SIMPLE_FILE_SHARING_THREAD_DATA_H
struct main_data{
    int* targetFd;
    int thread_index;
    void* other_data;
};
#endif //SIMPLE_FILE_SHARING_THREAD_DATA_H
