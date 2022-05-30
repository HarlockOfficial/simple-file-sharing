#ifndef SIMPLE_FILE_SHARING_AUTH_TOKEN_H
#define SIMPLE_FILE_SHARING_AUTH_TOKEN_H
typedef struct {
    long long token_id;
    long long user_id;
    char* token;
}auth_token;
#endif //SIMPLE_FILE_SHARING_AUTH_TOKEN_H
