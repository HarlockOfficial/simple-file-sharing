#include <stdio.h>
#include "../../utils/close_thread.h"
#include "../../../utils/thread_data.h"
#include "storage_manager.h"

void *storage_manager(void* data){
    struct main_data thread_data = *((struct main_data*) data);

    thread_exit(thread_data.thread_index);
    //TODO method stub
    return NULL;
}