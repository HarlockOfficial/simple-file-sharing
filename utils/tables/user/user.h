#ifndef SIMPLE_FILE_SHARING_USER_H
#define SIMPLE_FILE_SHARING_USER_H
typedef struct{
    long long user_id;
    char* username;
    char* password;
    long long token_id;
}user;
void create_user(long long user_id, char* username, char* password, long long token_id, user* out);
#endif //SIMPLE_FILE_SHARING_USER_H
