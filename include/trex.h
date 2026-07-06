#ifndef TREX_H
#define TREX_H

#include <stdbool.h>
#include <sys/stat.h>

#define MAX_FILES 4096
#define MAX_NAME 256
#define MAX_EXT 32
#define MAX_PATH 4096

typedef struct
{
    char name[MAX_NAME];

    char path[MAX_PATH];

    char extension[MAX_EXT];

    bool is_directory;

    struct stat info;

} File;

typedef struct
{
    File *files;

    int count;

    int selected_index;

    char current_path[MAX_PATH];

    bool running;

} Trex;

#endif