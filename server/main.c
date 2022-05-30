#include <stdio.h>
#include <string.h>

int main(){
    //TODO Start 3 threads:
    // 1. Authenticate users
    // 2. Register users
    // 3. Logout users (destroy access_token)
    // 4. Manage Files (upload, download, edit, delete)
    char is_server_running=1;
    char command[50];
    while(is_server_running==1){
        printf("> ");
        scanf("%s", command);
        if(strcmp(command, "help")==0){
            printf("To stop the server insert one of the following commands:\n\tstop\n\tdie\n\tquit\n\tkill\n\texit\n");
        }else if(strcmp(command, "stop")==0 || strcmp(command, "die")==0 || strcmp(command, "quit")==0 || strcmp(command, "kill")==0 || strcmp(command, "exit")==0){
            printf("Preparing to close the server");
            //TODO Stop 3 threads
            // Save all work
            is_server_running = 0;
        }else{
            printf("Command not valid, type help for a list of allowed commands\n");
        }
        printf("\n");
    }
    return 0;
}