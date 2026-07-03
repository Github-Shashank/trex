#ifndef TREX_H
#define TREX_H

#define MAX_FILES 4096
#define MAX_NAME 256
#define MAX_EXT 32
#define MAX_PATH 4096

typedef struct
{
    char name[MAX_NAME];
    char extension[MAX_EXT];

    int is_directory;

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