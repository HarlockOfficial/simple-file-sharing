#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "../../../../utils/file_manager/file_manager.h"
#include "auth_token_database.h"

#define FILENAME "auth_token.bin"
#define TEMP_FILENAME "tmp_auth_token.bin"

pthread_mutex_t lock;

long long find_by_id(auth_token *data);

long long find_by_token(auth_token *data);

long long create_entry(auth_token *data){
    pthread_mutex_lock(&lock);
    if(strcmp(data->token, "") == 0){
        return -1;
    }
    if(data->user_id <= 0){
        return -2;
    }
    long long position = file_size(FILENAME);
    long long entry_count = elements_count(FILENAME, sizeof(auth_token));
    auth_token token;
    for(long long i = 0; i < entry_count; ++i){
        int result = file_read(FILENAME, sizeof(auth_token), i*(long long)sizeof(auth_token), &token);
        if(result!=0){
            printf("Error reading file %s element number %lld\n", FILENAME, i);
            continue;
        }
        if(strcmp(token.token, data->token) == 0){
            return -3;
        }
        if(token.user_id == data->user_id){
            pthread_mutex_unlock(&lock);
            delete_entry(&token);
            pthread_mutex_lock(&lock);
        }
    }
    data->token_id = token.token_id+1;
    file_write(FILENAME, sizeof(auth_token), position,data);
    pthread_mutex_unlock(&lock);
    return position;
}

long long search_entry(auth_token *data){
    pthread_mutex_lock(&lock);
    if(data->token_id>0){
        return find_by_id(data);
    }if(strcmp(data->token, "") != 0){
        return find_by_token(data);
    }
    pthread_mutex_unlock(&lock);
    return -1;
}

int delete_entry(auth_token *data){
    long long index = search_entry(data);
    pthread_mutex_lock(&lock);
    if(index<=0){
        return -1;
    }
    long long entry_count = elements_count(FILENAME, sizeof(auth_token));
    for(long long i = 0; i<entry_count; ++i){
        if(i == index){
            continue;
        }
        auth_token token;
        file_read(FILENAME, sizeof(auth_token), i*(long long)sizeof(auth_token), &token);
        file_write(TEMP_FILENAME, sizeof(auth_token), i*(long long)sizeof(auth_token), &token);
    }
    delete_file(FILENAME);
    rename_file(TEMP_FILENAME, FILENAME);
    pthread_mutex_unlock(&lock);
    return 0;
}

long long find_by_token(auth_token *data) {
    long long entry_count = elements_count(FILENAME, sizeof(auth_token));
    for(long long i = 0; i<entry_count; ++i){
        auth_token token;
        int result = file_read(FILENAME, sizeof(auth_token), i*(long long)sizeof(auth_token), &token);
        if(result!=0){
            printf("Error reading file %s element number %lld\n", FILENAME, i);
            continue;
        }
        if(strcmp(token.token, data->token) == 0){
            *data=token;
            return i;
        }
    }
    return -1;
}

long long find_by_id(auth_token *data) {
    long long entry_count = elements_count(FILENAME, sizeof(auth_token));
    for(long long i = 0; i<entry_count; ++i){
        auth_token token;
        int result = file_read(FILENAME, sizeof(auth_token), i*(long long)sizeof(auth_token), &token);
        if(result!=0){
            printf("Error reading file %s element number %lld\n", FILENAME, i);
            continue;
        }
        if(token.token_id == data->token_id){
            *data=token;
            return i;
        }
    }
    return -1;
}