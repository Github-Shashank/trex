#include "terminal.h"

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

void terminal_initialize(void)
{
    initscr();

    cbreak();

    noecho();

    keypad(stdscr, TRUE);

    curs_set(0);
}

void terminal_shutdown(void)
{
    endwin();
}

void terminal_clear(void)
{
    clear();
}

void terminal_refresh(void)
{
    refresh();
}

void terminal_print(int y,int x,const char *text)
{
    mvprintw(y,x,"%s",text);
}

int terminal_read_key(void)
{
    return getch();
}