#include "file.h"

#include <dirent.h>
#include <string.h>

#include <sys/stat.h>
#include <stdio.h>

#include "platform.h"

static void detect_extension(File *file);

static void detect_file_type(File *file);

static void initialize_file(File *file, const char *current_path, const char *name);

static bool should_swap(const File *left, const File *right);

static void swap_files(File *left, File *right);

void load_directory(Trex *app)
{
    DIR *directory;
    struct dirent *entry;

    app->count = 0;

    directory = opendir(".");

    if (directory == NULL)
    {
        perror("opendir");
        return;
    }

    if (directory == NULL)
        return;
    
    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        initialize_file(&app->files[app->count],
                        app->current_path,
                        entry->d_name);

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
    if (stat(file->path, &file->info) != 0)
        return;

    file->is_directory = S_ISDIR(file->info.st_mode);
}

static void initialize_file(File *file, const char *current_path, const char *name)
{
    snprintf(file->path, MAX_PATH, "%s/%s", current_path, name);

    file->extension[0] = '\0';

    file->is_directory = false;

    strcpy(file->name, name);

    detect_extension(file);

    detect_file_type(file);
}

static bool should_swap(const File *left, const File *right)
{
    if (left->is_directory != right->is_directory)
    {
        return !left->is_directory;
    }

    return trex_strcasecmp(left->name, right->name) > 0;
}

static void swap_files(File *left, File *right)
{
    File temp = *left;

    *left = *right;

    *right = temp;
}

void sort_files(Trex *app)
{
    for (int i = 1; i < app->count; i++)
    {
        int j = i;

        while (j > 0 &&
               should_swap(&app->files[j - 1],
                           &app->files[j]))
        {
            swap_files(&app->files[j - 1],
                       &app->files[j]);

            j--;
        }
    }
}