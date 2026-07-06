#include "engine.h"

#include <stdio.h>

int main(void)
{
    Trex trex;

    trex_initialize(&trex);

    trex_load(&trex);

    for (int i = 0; i < trex.count; i++)
    {
        printf("[%c] %-20s -> %s\n",
               trex.files[i].is_directory ? 'D' : 'F',
               trex.files[i].name,
               trex.files[i].path);
    }

    trex_shutdown(&trex);

    return 0;
}