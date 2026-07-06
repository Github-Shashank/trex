#include "engine.h"
#include <stdio.h>

int main(void)
{
    Trex trex;

    trex_initialize(&trex);

    trex_load(&trex);

    for (int i = 0; i < trex.count; i++)
    {
        printf("%c %s\n",
               (i == trex.selected_index) ? '>' : ' ',
               trex.files[i].name);
    }

    trex_shutdown(&trex);

    return 0;
}