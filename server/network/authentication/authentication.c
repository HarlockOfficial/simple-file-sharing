#include <string.h>
#include <uuid/uuid.h>
#include "../../utils/close_thread.h"
#include "../../../utils/thread_data/thread_data.h"
#include "authentication.h"
#include "../../../utils/network_communication_delimiter.h"
#include "../../../utils/tables/auth_token/auth_token.h"
#include "../../../utils/tables/user/user.h"
#include "../../storage/database_wrapper/auth_token/auth_token_database.h"
#include "../../storage/database_wrapper/user/user_database.h"

void *login(void *data){
    struct main_data thread_data = *((struct main_data*) data);
    char *username, *password;
    //remove "action"
    strtok((char*)thread_data.other_data,DELIMITER);
    //get username and password
    username = strtok(NULL, DELIMITER);
    password = strtok(NULL, DELIMITER);
    user user_data;
    create_user(-1, username, password, -1, &user_data);
    search_entry_user(&user_data);
    auth_token token_data;
    create_token_random(&token_data);
    token_data.user_id = user_data.user_id;
    if(create_entry_auth_token(&token_data)!=0){
        //TODO server write to client "error"
    } else {
        user_data.token_id = token_data.token_id;
        update_entry_user(&user_data);
        //TODO server write to client token
    }
    thread_exit(thread_data.thread_index);
    return NULL;
}

void *sign_in(void *data){
    struct main_data thread_data = *((struct main_data*) data);
    char *username, *password;
    //remove "action"
    strtok((char*)thread_data.other_data,DELIMITER);
    //get username and password
    username = strtok(NULL, DELIMITER);
    password = strtok(NULL, DELIMITER);
    user user_data;
    create_user(-1, username, password, -1, &user_data);
    if(create_entry_user(&user_data)>0){
        //TODO server write to client "ok"
    }else{
        //TODO server write to client "error"
    }
    thread_exit(thread_data.thread_index);
    return NULL;
}

void *logout(void *data){
    struct main_data thread_data = *((struct main_data*) data);
    char* token_string;
    uuid_t token;
    //remove "action"
    strtok((char*)thread_data.other_data,DELIMITER);
    //get token
    token_string = strtok(NULL, DELIMITER);
    uuid_parse(token_string, token);
    auth_token token_data;
    create_token_from_string(token_string, &token_data);
    delete_entry_auth_token(&token_data);
    //TODO server write to client "ok"
    thread_exit(thread_data.thread_index);
    return NULL;
}