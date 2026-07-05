#include "file.h"

#include <dirent.h>
#include <string.h>

static void detect_extension(File *file);

static void detect_file_type(File *file);

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
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        strcpy(app->files[app->count].name, entry->d_name);

        detect_extension(&app->files[app->count]);
        detect_file_type(&app->files[app->count]); 

        app->count++;
    }

    closedir(directory);
}

static void detect_extension(File *file)
{
    char *dot;

    file->extension[0] = '\0';

    dot = strrchr(file->name, '.');

    if (dot == NULL)
        return;

    if (dot == file->name)
        return;

    if (*(dot + 1) == '\0')
        return;

    strcpy(file->extension, dot + 1);
}

static void detect_file_type(File *file)
{
    (void)file;
}