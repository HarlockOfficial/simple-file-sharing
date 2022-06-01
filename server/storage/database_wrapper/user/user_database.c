#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "../../../../utils/file_manager/file_manager.h"
#include "user_database.h"

#define FILENAME "user.bin"
#define TEMP_FILENAME "tmp_user.bin"

pthread_mutex_t lock, lock2;

long long find_by_id(user *data);

long long find_by_username(user *data);

long long create_entry(user *data){
    pthread_mutex_lock(&lock2);
    pthread_mutex_lock(&lock);
    if(strcmp(data->username, "") == 0 || strcmp(data->password, "") == 0){
        return -1;
    }
    long long position = file_size(FILENAME);
    long long entry_count = elements_count(FILENAME, sizeof(user));
    user account;
    for(long long i = 0; i < entry_count; ++i){
        int result = file_read(FILENAME, sizeof(user), i*(long long)sizeof(user), &account);
        if(result!=0){
            printf("Error reading file %s element number %lld\n", FILENAME, i);
            continue;
        }
        if(strcmp(account.username, data->username) == 0){
            return -3;
        }
    }
    data->user_id = account.user_id + 1;
    file_write(FILENAME, sizeof(user), position,data);
    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&lock2);
    return position;
}

long long search_entry(user *data){
    pthread_mutex_lock(&lock);
    if(data->user_id>0){
        return find_by_id(data);
    }if(strcmp(data->username, "") != 0){
        return find_by_username(data);
    }
    pthread_mutex_unlock(&lock);
    return -1;
}

long long update_entry(user *data){
    pthread_mutex_lock(&lock2);
    pthread_mutex_lock(&lock);
    if(data->user_id<=0){
        return -1;
    }
    user updated_data = {
            data->user_id,
            "",
            "",
            data->token_id
    };
    strcpy(updated_data.username, data->username);
    strcpy(updated_data.password, data->password);
    pthread_mutex_unlock(&lock);
    long long index = search_entry(data);
    pthread_mutex_lock(&lock);
    *data = updated_data;
    long long result = file_write(FILENAME, sizeof(user), index*(long long)sizeof(user), data);
    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&lock2);
    return result;
}

int delete_entry(user *data){
    pthread_mutex_lock(&lock2);
    long long index = search_entry(data);
    pthread_mutex_lock(&lock);
    if(index<=0){
        return -1;
    }
    long long entry_count = elements_count(FILENAME, sizeof(user));
    for(long long i = 0; i<entry_count; ++i){
        if(i == index){
            continue;
        }
        user token;
        file_read(FILENAME, sizeof(user), i*(long long)sizeof(user), &token);
        file_write(TEMP_FILENAME, sizeof(user), i*(long long)sizeof(user), &token);
    }
    delete_file(FILENAME);
    rename_file(TEMP_FILENAME, FILENAME);
    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&lock2);
    return 0;
}

long long find_by_username(user *data) {
    long long entry_count = elements_count(FILENAME, sizeof(user));
    for(long long i = 0; i<entry_count; ++i){
        user account;
        int result = file_read(FILENAME, sizeof(user), i*(long long)sizeof(user), &account);
        if(result!=0){
            printf("Error reading file %s element number %lld\n", FILENAME, i);
            continue;
        }
        if(strcmp(account.username, data->username) == 0){
            *data=account;
            return i;
        }
    }
    return -1;
}

long long find_by_id(user *data) {
    long long entry_count = elements_count(FILENAME, sizeof(user));
    for(long long i = 0; i<entry_count; ++i){
        user token;
        int result = file_read(FILENAME, sizeof(user), i*(long long)sizeof(user), &token);
        if(result!=0){
            printf("Error reading file %s element number %lld\n", FILENAME, i);
            continue;
        }
        if(token.user_id == data->user_id){
            *data=token;
            return i;
        }
    }
    return -1;
}