#ifndef SIMPLE_FILE_SHARING_USER_DATABASE_H
#define SIMPLE_FILE_SHARING_USER_DATABASE_H
#include "../../../../utils/tables/user.h"
long long create_entry(user *data);
long long search_entry(user *data);
long long update_entry(user *data);
int delete_entry(user *data);
#endif //SIMPLE_FILE_SHARING_USER_DATABASE_H
