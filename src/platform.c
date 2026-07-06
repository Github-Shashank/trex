#ifdef _WIN32

#include <direct.h>

char *trex_getcwd(char *buffer, int size)
{
    return _getcwd(buffer, size);
}

#else

#include <unistd.h>

char *trex_getcwd(char *buffer, int size)
{
    return getcwd(buffer, size);
}

#endif

#ifdef _WIN32

#include <string.h>

int trex_strcasecmp(const char *left,
                    const char *right)
{
    return strcmp(left, right);
}

#else

#include <strings.h>

int trex_strcasecmp(const char *left,
                    const char *right)
{
    return strcasecmp(left, right);
}

#endif