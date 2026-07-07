#include "platform.h"
#include "key.h"

#include <termios.h>
#include <unistd.h>
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

static struct termios original_termios;

void platform_terminal_enable_raw(void)
{
    tcgetattr(STDIN_FILENO, &original_termios);

    struct termios raw = original_termios;

    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void platform_terminal_disable_raw(void)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}



Key platform_read_key(void)
{
    int c = getchar();

    if (c == 27)
    {
        int second = getchar();

        if (second != '[')
        {
            return KEY_NONE;
        }

        int third = getchar();

        switch (third)
        {
            case 'A':
                return KEY_UP;

            case 'B':
                return KEY_DOWN;

            case 'C':
                return KEY_RIGHT;

            case 'D':
                return KEY_LEFT;

            default:
                return KEY_NONE;
        }
    }

    switch (c)
    {
        case 'w':
            return KEY_UP;

        case 's':
            return KEY_DOWN;

        case 'q':
            return KEY_QUIT;
        case '\n':
        case '\r':
            return KEY_ENTER;
        default:
            return KEY_NONE;
    }
}
