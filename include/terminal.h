#ifndef TERMINAL_H
#define TERMINAL_H

void terminal_initialize(void);

void terminal_shutdown(void);

void terminal_clear(void);

int terminal_read_key(void);

void terminal_refresh(void);

void terminal_print(int y, int x, const char *text);

#endif