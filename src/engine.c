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

void trex_load(Trex *app)
{
    load_directory(app);

    sort_files(app);
}

void trex_shutdown(Trex *trex)
{
    free(trex->files);
    trex->files = NULL;
}