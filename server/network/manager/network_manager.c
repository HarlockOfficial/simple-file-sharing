#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../connection/network_connection.h"
#include "../authentication/authentication.h"
#include "../../storage/manager/storage_manager.h"
#include "../../../utils/network/network_connection.h"
#include "../../../utils/thread_data/thread_data.h"
#include "../../../utils/network_communication_delimiter.h"
#include "network_manager.h"

void create_thread(const int* clientFd, const int* serverFd, void* other_data, pthread_t **thread, void * (*thread_function)(void*));
int find_first_free_thread_index();
void thread_exit(pthread_t *threads);

void *network_manager(void *serverFd){
    pthread_t threads[THREAD_COUNT];
    pthread_t *threads_pointer = threads;
    while(manager_is_server_running == 1){
        int clientFd;
        struct sockaddr_in client;
        //accepting a request
        if(server_accept(*(int*)serverFd, &clientFd, &client)!=0){
            continue;
        }

        //get auth details
        char* data = malloc(sizeof(char) * 500);
        long len;
        if(target_read(clientFd, &data, &len) != 0){
            continue;
        }
        if(len<=0){
            continue;
        }
        char* original_string = malloc(sizeof(char) * len);
        strcpy(original_string, data);
        //message received in the format: <action>;<other_data>
        char* action = strtok(data, DELIMITER);
        if(strcmp(action, "login") == 0) {
            create_thread(&clientFd, (int*)serverFd, original_string, &threads_pointer, login);
        }else if(strcmp(action, "register") == 0) {
            create_thread(&clientFd, (int *) serverFd, original_string, &threads_pointer, sign_in);
        }else if(strcmp(action, "logout") == 0) {
            create_thread(&clientFd, (int*)serverFd, original_string, &threads_pointer, logout);
        }else if(strcmp(action, "manage") == 0) {
            create_thread(&clientFd, (int*)serverFd, original_string, &threads_pointer, storage_manager);
        }
    }
    thread_exit(threads_pointer);
    return NULL;
}

void create_thread(const int* clientFd, const int* serverFd, void* other_data, pthread_t **thread, void * (*thread_function)(void*)){
    int index = find_first_free_thread_index();
    struct main_data register_data;
    create_main_data((int*) clientFd, (int*) serverFd, index, other_data, &register_data);
    is_thread_running[index] = 1;
    pthread_create(thread[index], NULL, thread_function, &register_data);
}

int find_first_free_thread_index() {
    while(1) {
        for (int i = 0; i < THREAD_COUNT; ++i) {
            if (is_thread_running[i] == 0) {
                return i;
            }
        }
    }
}


void thread_exit(pthread_t *threads) {
    printf("Waiting for all threads to close\n");
    for(int i = 0; i<THREAD_COUNT; ++i){
        pthread_join(threads[i], NULL);
    }
    pthread_exit(NULL);
}
