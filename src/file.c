#include "file.h"

#include <dirent.h>
#include <string.h>

void load_directory(Trex *app)
{
    DIR *directory;
    struct dirent *entry;

    app->count = 0;

    directory = opendir(".");

    if (directory == NULL)
        return;

    while ((entry = readdir(directory)) != NULL)
    {
        strcpy(app->files[app->count].name, entry->d_name);

        app->count++;
    }

    closedir(directory);
}