#ifndef ENGINE_H
#define ENGINE_H

#include "trex.h"

void trex_initialize(Trex *app);

void trex_load(Trex *app);

void trex_shutdown(Trex *app);

bool trex_change_directory(Trex *trex,
                           const char *path);

void trex_reload(Trex *trex);

bool trex_go_parent(Trex *trex);

void trex_move_up(Trex *trex);

void trex_move_down(Trex *trex);

File *trex_selected_file(Trex *trex);

bool trex_go_parent(Trex *trex);

#endif
