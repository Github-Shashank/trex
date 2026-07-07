#include "screen.h"
#include <stdio.h>
#include "terminal.h"

void draw_screen(const Trex *trex)
{
    terminal_clear();
    printf("Current path: %s\n\n", trex->current_path);
    for (int i = 0; i < trex->count; i++)
    {
        printf("%c [%c] %-20s\n",

            (i == trex->selected_index)
                ? '>'
                : ' ',

            trex->files[i].is_directory
                ? 'D'
                : 'F',

            trex->files[i].name);
    }

    terminal_refresh();
}
