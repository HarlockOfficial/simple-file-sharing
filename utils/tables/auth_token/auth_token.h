#ifndef SIMPLE_FILE_SHARING_AUTH_TOKEN_H
#define SIMPLE_FILE_SHARING_AUTH_TOKEN_H
#include <uuid/uuid.h>
typedef struct {
    long long token_id;
    long long user_id;
    uuid_t token;
}auth_token;
void create_token(long long token_id, long long user_id, uuid_t token, auth_token* out);
void create_token_from_string(char* token, auth_token* out);
void create_token_random(auth_token* out);
#endif //SIMPLE_FILE_SHARING_AUTH_TOKEN_H
