#include "auth.h"
int get_auth_token(char* username, char* password, int serverFd, auth_token *token){
    //TODO finish, method stub
    auth_token auth = {
            1,
            1,
            "token_value"
    };
    *token = auth;
    return 0;
}