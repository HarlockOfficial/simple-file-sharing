#ifndef SIMPLE_FILE_SHARING_AUTH_H
#define SIMPLE_FILE_SHARING_AUTH_H
#include "../../../utils/tables/auth_token.h"
int get_auth_token(char* username, char* password, int serverFd, auth_token *token);
#endif //SIMPLE_FILE_SHARING_AUTH_H
