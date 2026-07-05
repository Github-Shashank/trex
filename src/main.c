#include "trex.h"
#include "screen.h"
#include "input.h"
#include "terminal.h"
#include "file.h"

#include <string.h>
#include <stdio.h>

int main(void)
{
    Trex app;

    memset(&app, 0, sizeof(Trex));

    app.running = 1;

    load_directory(&app);

    for (int i = 0; i < app.count; i++)
    {
        printf("[%c] %-20s -> %s\n",
            app.files[i].is_directory ? 'D' : 'F',
            app.files[i].name,
            app.files[i].extension);
    }
    return 0;

    terminal_initialize();

    while (app.running)
    {
        draw_screen(&app);

        handle_input(&app);
    }

    terminal_shutdown();

    return 0;
}