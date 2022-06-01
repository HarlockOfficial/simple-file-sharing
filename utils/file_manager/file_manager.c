#include <stdio.h>
#include "file_manager.h"

int file_read(char* filename, size_t size, long long start_position, void* output){
    FILE *f = fopen(filename, "rb");
    if(fseek(f, start_position, SEEK_SET)!=0){
        return -1;
    }
    if(fread(output, size, 1, f)<=0){
        return -2;
    }
    fclose(f);
    return 0;
}

int file_write(char* filename, size_t size, long long start_position, void* input){
    FILE *f = fopen(filename, "ab+");
    if(fseek(f, start_position, SEEK_SET)!=0){
        return -1;
    }
    if(fwrite(input, size, 1, f)<=0){
        return -2;
    }
    return 0;
}

long long file_size(char* filename){
    FILE *f = fopen(filename, "r");
    fseek(f, 0, SEEK_END);
    long long len = ftell(f);
    fclose(f);
    return len;
}

long long elements_count(char* filename, size_t size){
    return file_size(filename) / (long long)size;
}

int delete_file(char* filename){
    return remove(filename);
}

int rename_file(char* old_filename, char* new_filename){
    return rename(old_filename, new_filename);
}