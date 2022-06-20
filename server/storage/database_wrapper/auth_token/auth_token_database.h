#ifndef SIMPLE_FILE_SHARING_AUTH_TOKEN_DATABASE_H
#define SIMPLE_FILE_SHARING_AUTH_TOKEN_DATABASE_H
#include "../../../../utils/tables/auth_token/auth_token.h"
long long create_entry_auth_token(auth_token *data);
long long search_entry_auth_token(auth_token *data);
int delete_entry_auth_token(auth_token *data);
#endif //SIMPLE_FILE_SHARING_AUTH_TOKEN_DATABASE_H
