#ifndef TREX_H
#define TREX_H

#define MAX_FILES 4096
#define MAX_NAME 256
#define MAX_EXT 32
#define MAX_PATH 4096

#include <stdbool.h>
#include <sys/stat.h>

char current_path[MAX_PATH];

int selected_index;

typedef struct
{
    char name[MAX_NAME];

    char extension[MAX_EXT];

    bool is_directory;

    struct stat info;

} File;

typedef struct
{
    File files[MAX_FILES];

    int count;
    int selected;

    char cwd[MAX_PATH];

    int running;

} Trex;

#endif