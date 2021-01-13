#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

int main(void) {
	WINDOW * mainwin = initscr();

	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);

	color_set(1, NULL);
	mvaddstr(8, 32, "Hello, world!");

	refresh();
	sleep(2);
    
	delwin(mainwin);
	endwin();
	refresh();

	return 0;
}
