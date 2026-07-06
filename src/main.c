#include "engine.h"
#include "screen.h"
#include "input.h"
#include "terminal.h"

int main(void)
{
    Trex trex;

    trex_initialize(&trex);

    trex_load(&trex);

    terminal_initialize();

    while (trex.running)
    {
        draw_screen(&trex);

        handle_input(&trex);
    }

    terminal_shutdown();

    trex_shutdown(&trex);

    return 0;
}