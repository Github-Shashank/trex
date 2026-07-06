#include "input.h"
#include <stdio.h>
#include "engine.h"
#include "terminal.h"

void handle_input(Trex *trex)
{
    int key = getchar();

    switch (key)
    {
        case 'w':
            trex_move_up(trex);
            break;

        case 's':
            trex_move_down(trex);
            break;

        case 'q':
            trex->running = false;
            break;
        case '\n':
            break;
        case '\r':
            break;
    }
}