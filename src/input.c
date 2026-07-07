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

    default:
        break;
}
}
