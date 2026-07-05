#include "file.h"

#include <dirent.h>
#include <string.h>

#include <sys/stat.h>
#include <stdio.h>

static void detect_extension(File *file);

static void detect_file_type(File *file);

static void initialize_file(File *file, const char *name);

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
        initialize_file(&app->files[app->count], entry->d_name);

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
    struct stat info;

    file->is_directory = false;

    if (stat(file->name, &info) != 0)
        return;

    if (S_ISDIR(info.st_mode))
        file->is_directory = true;
}

static void initialize_file(File *file, const char *name)
{
    snprintf(file->name, MAX_NAME, "%s", name);

    file->extension[0] = '\0';

    file->is_directory = false;

    detect_extension(file);

    detect_file_type(file);
}