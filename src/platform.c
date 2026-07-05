#include "platform.h"

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