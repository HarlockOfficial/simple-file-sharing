#ifndef SIMPLE_FILE_SHARING_FILE_MANAGER_H
#define SIMPLE_FILE_SHARING_FILE_MANAGER_H
#include <stdlib.h>
int file_read(char* filename, size_t size, long long start_position, void* output);
int file_write(char* filename, size_t size, long long start_position, void* input);
long long file_size(char* filename);
long long elements_count(char* filename, size_t size);
int delete_file(char* filename);
int rename_file(char* old_filename, char* new_filename);
#endif //SIMPLE_FILE_SHARING_FILE_MANAGER_H
