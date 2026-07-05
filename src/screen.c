#include "screen.h"

#include "terminal.h"

void draw_screen(const Trex *trex)
{
    (void)trex;

    terminal_clear();

    terminal_print(1,2,"Trex");

    terminal_print(3,2,"Press q to quit.");

    terminal_refresh();
}