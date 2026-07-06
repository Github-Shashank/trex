#include "platform.h"

#include <stdio.h>
#include <ctype.h>

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

int trex_strcasecmp(const char *left, const char *right)
{
    while (*left && *right)
    {
        int a = tolower((unsigned char)*left);
        int b = tolower((unsigned char)*right);

        if (a != b)
        {
            return a - b;
        }

        left++;
        right++;
    }

    return tolower((unsigned char)*left) -
           tolower((unsigned char)*right);
}

void platform_terminal_enable_raw(void)
{
}

void platform_terminal_disable_raw(void)
{
}

int platform_read_key(void)
{
    return getchar();
}