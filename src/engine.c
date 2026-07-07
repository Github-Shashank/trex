#include "engine.h"

#include "file.h"
#include "platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool trex_change_directory(Trex *trex, const char *path);

bool trex_go_parent(Trex *trex);

void trex_reload(Trex *trex);

#include <stdlib.h>

void trex_initialize(Trex *trex)
{
    memset(trex, 0, sizeof(Trex));

    trex->files = malloc(sizeof(File) * MAX_FILES);

    if (trex->files == NULL)
    {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    trex_getcwd(trex->current_path, MAX_PATH);

    trex->running = true;
}

void trex_load(Trex *trex)
{
    trex_reload(trex);
}

void trex_shutdown(Trex *trex)
{
    free(trex->files);
    trex->files = NULL;
}

void trex_reload(Trex *trex)
{
    load_directory(trex);

    sort_files(trex);

    trex->selected_index = 0;
}

bool trex_change_directory(Trex *trex, const char *path)
{
    printf("Changing to: %s\n", path);
    struct stat info;

    if (stat(path, &info) != 0)
    {
        return false;
    }

    if (!S_ISDIR(info.st_mode))
    {
        return false;
    }

    strncpy(trex->current_path, path, MAX_PATH - 1);

    trex->current_path[MAX_PATH - 1] = '\0';

    trex_reload(trex);

    return true;
} 

void trex_move_up(Trex *trex)
{
    if (trex->selected_index > 0)
    {
        trex->selected_index--;
    }
}

void trex_move_down(Trex *trex)
{
    if (trex->selected_index < trex->count - 1)
    {
        trex->selected_index++;
    }
}

File *trex_selected_file(Trex *trex)
{
    if (trex->count == 0)
    {
        return NULL;
    }

    return &trex->files[trex->selected_index];
}

