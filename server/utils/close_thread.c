#include <pthread.h>
#include "../network/manager/network_manager.h"
#include "close_thread.h"
void thread_exit(int thread_index){
    is_thread_running[thread_index] = 0;
    pthread_exit(NULL);
}