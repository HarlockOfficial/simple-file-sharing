#include <string.h>
#include "../../utils/close_thread.h"
#include "../../../utils/thread_data/thread_data.h"
#include "storage_manager.h"
#include "../../../utils/network_communication_delimiter.h"

void *storage_manager(void* data){
    struct main_data thread_data = *((struct main_data*) data);
    char *token_string, *action, *filename;
    //remove "action"
    strtok((char*)thread_data.other_data,DELIMITER);
    token_string = strtok(NULL, DELIMITER);
    action = strtok(NULL, DELIMITER);
    /**
     * action may be "delete", "update", "create"
     */
    filename = strtok(NULL, DELIMITER);
    if(strcmp(action, "delete") == 0){
        //TODO delete file with path user_id/filename
        //TODO server write to client "ok" if delete correct else "error"
    }else if(strcmp(action, "update") == 0) {
        //TODO get file from user (read from network stream)
        //TODO overwrite file with path user_id/filename
        //TODO server write to client "ok" if delete correct else "error"
    }else if(strcmp(action, "create") == 0) {
        //TODO get file from user (read from network stream)
        //TODO create file with path user_id/filename
        //TODO server write to client "ok" if delete correct else "error"
    }
    thread_exit(thread_data.thread_index);
    return NULL;
}