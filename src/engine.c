#include "engine.h"

#include "file.h"

#include <string.h>

bool trex_change_directory(Trex *trex, const char *path);

bool trex_go_parent(Trex *trex);

void trex_reload(Trex *trex);

void trex_initialize(Trex *app)
{
    memset(app, 0, sizeof(Trex));
}

void trex_load(Trex *app)
{
    load_directory(app);

    sort_files(app);
}

void trex_shutdown(Trex *app)
{
    (void)app;
}