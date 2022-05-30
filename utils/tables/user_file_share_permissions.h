#ifndef SIMPLE_FILE_SHARING_USER_FILE_PERMISSIONS_H
#define SIMPLE_FILE_SHARING_USER_FILE_PERMISSIONS_H
typedef struct {
    long long destination_user_id;
    long long file_id;
    char can_read;
    char can_write;
}user_file_share_permission;
#endif //SIMPLE_FILE_SHARING_USER_FILE_PERMISSIONS_H
