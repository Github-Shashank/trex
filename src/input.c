#include "input.h"
#include <stdio.h>
#include "engine.h"
#include "terminal.h"

void handle_input(Trex *trex)
{
Key key = terminal_read_key();
//printf("Key = %d\n", key);
switch (key)
{
    case KEY_UP:
        trex_move_up(trex);
        break;

    case KEY_DOWN:
        trex_move_down(trex);
        break;

    case KEY_QUIT:
        trex->running = false;
        break;
    case KEY_RIGHT:
    case KEY_ENTER:
    {
        File *selected = trex_selected_file(trex);

        if (selected == NULL)
            break;

        if (!selected->is_directory)
            break;

        trex_change_directory(trex, selected->path);

        break;
    }
    case KEY_LEFT:
    case KEY_BACKSPACE:
    {
        trex_go_parent(trex);
        break;
    }
    default:
        break;
}
}
