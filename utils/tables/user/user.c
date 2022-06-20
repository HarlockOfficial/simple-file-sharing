#include <string.h>
#include "user.h"

void create_user(long long user_id, char* username, char* password, long long token_id, user* out){
    out->user_id = user_id;
    strcpy(out->username, username);
    strcpy(out->password, password);
    out->token_id = token_id;
}