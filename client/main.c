#include <stdio.h>
#include <string.h>
#include "../utils/tables/auth_token.h"
#include "network/auth/auth.h"

void login(auth_token *token, int serverFd);

int main() {
    char command[50];
    int serverFd = 0;
    auth_token token = {
        0,
        0,
        ""
    };
    //TODO connect to server
    // also the login will need a reference to the serverFd
    login(&token, serverFd);
    char is_client_running = 1;
    while(is_client_running == 1){
        printf("> ");
        scanf("%s", command);
        if(strcmp(command, "help") == 0){
            //TODO print menu
        }else if(strcmp(command, "stop")==0 || strcmp(command, "die")==0 || strcmp(command, "quit")==0 || strcmp(command, "kill")==0 || strcmp(command, "exit")==0){
            //TODO Logs out the user
            is_client_running = 0;
        }
        //TODO After login the user can access all personal shared files and manage them
        // After login the user can access all others shared files and manage them based on its permissions
    }
    return 0;
}

void login(auth_token *token, int serverFd) {
    char username[50], password[50];
    while (token->token_id == 0) {
        printf("Username> ");
        scanf("%s", username);
        printf("Password> ");
        scanf("%s", password);
        get_auth_token(username, password, serverFd, token);
    }
}
