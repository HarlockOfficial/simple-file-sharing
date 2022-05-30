#ifndef SIMPLE_FILE_SHARING_FILE_H
#define SIMPLE_FILE_SHARING_FILE_H
typedef struct {
    long long file_id;
    char* filename;
    long long owner_id;
}file;
#endif //SIMPLE_FILE_SHARING_FILE_H
