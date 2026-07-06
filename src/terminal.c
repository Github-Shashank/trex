#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>

void terminal_initialize(void)
{
}

void terminal_shutdown(void)
{
}

void terminal_clear(void)
{
    system("clear");
}

void terminal_refresh(void)
{
    fflush(stdout);
}

int terminal_read_key(void)
{
    return getchar();
}

void terminal_print(int y, int x, const char *text)
{
    (void)y;
    (void)x;

    printf("%s", text);
}