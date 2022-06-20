#ifndef SIMPLE_FILE_SHARING_USER_DATABASE_H
#define SIMPLE_FILE_SHARING_USER_DATABASE_H
#include "../../../../utils/tables/user/user.h"
long long create_entry_user(user *data);
long long search_entry_user(user *data);
long long update_entry_user(user *data);
int delete_entry_user(user *data);
#endif //SIMPLE_FILE_SHARING_USER_DATABASE_H
