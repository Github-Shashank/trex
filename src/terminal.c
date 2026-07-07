#include "terminal.h"
#include "platform.h"
#include "trex.h"
#include <stdio.h>
#include <stdlib.h>

void terminal_initialize(void)
{
    platform_terminal_enable_raw();
}

void terminal_shutdown(void)
{
    platform_terminal_disable_raw();
}

void terminal_clear(void)
{
    system("clear");
}

void terminal_refresh(void)
{
    fflush(stdout);
}

Key terminal_read_key(void)
{
    return platform_read_key();
}

void terminal_print(int y, int x, const char *text)
{
    (void)y;
    (void)x;

    printf("%s", text);
}
