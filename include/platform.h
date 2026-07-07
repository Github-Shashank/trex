#ifndef PLATFORM_H
#define PLATFORM_H

#include "key.h"

void platform_get_terminal_size(int *rows, int *cols);

char *trex_getcwd(char *buffer, int size);

int trex_strcasecmp(const char *left, const char *right);

void platform_terminal_enable_raw(void);
void platform_terminal_disable_raw(void);

Key platform_read_key(void);

#endif
