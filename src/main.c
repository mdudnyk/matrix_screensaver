#include "header.h"
#include <locale.h>

int main(int argc, char *argv[]){
    errors(argc, argv);
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	bkgd(COLOR_PAIR(1) | A_BOLD);	
	wake_up();
	matrix_rain();	
	endwin();
	return 0;
}
