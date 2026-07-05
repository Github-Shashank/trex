#include "input.h"

#include "terminal.h"

void handle_input(Trex *trex)
{
    switch(terminal_read_key())
    {
        case 'q':

            trex->running = 0;

            break;
    }
}