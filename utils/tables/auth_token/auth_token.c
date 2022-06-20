#include <uuid/uuid.h>
#include "auth_token.h"
void create_token(long long token_id, long long user_id, uuid_t token, auth_token* out){
    out->token_id = token_id;
    out->user_id = user_id;
    uuid_copy(out->token, token);
}
void create_token_from_string(char* token, auth_token* out){
    uuid_t uuid;
    out->token_id = -1;
    out->user_id = -1;
    uuid_parse(token, uuid);
    uuid_copy(out->token, uuid);
}
void create_token_random(auth_token* out){
    uuid_t uuid;
    uuid_generate_random(uuid);
    out->token_id = -1;
    out->user_id = -1;
    uuid_copy(out->token, uuid);
}