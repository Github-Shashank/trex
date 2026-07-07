#include "screen.h"
#include <stdio.h>
#include "terminal.h"

void draw_screen(const Trex *trex)
{
    terminal_clear();
    printf("Current path: %s\n\n", trex->current_path);
    
    int start = trex->scroll_offset;

    int end = start + trex->screen_rows;

    if (end > trex->count)
    {
        end = trex->count;
    }

    for (int i = start; i < end; i++)
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
