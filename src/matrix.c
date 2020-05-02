#include "header.h"

int rand_value(int max, int min) {
	return(rand() % ((max + 1) - min) + min);
	}

void matrix_rain(void) {
	int rows;
	int columns;
	getmaxyx(stdscr, rows, columns);
	int activ_column[columns];
	int rows_in_column[columns];
	int i;
	for(i = 0; i < columns; i++) {
		activ_column[i] = 0;
		rows_in_column[i] = -1;
	}
	int max = 12538;
        int min = 12449;
	if(flag.japan == 1) {
		max = 126;
        	min = 32;
	}
	int a = 80000;
	if(flag.speed == 1) {
		a = 40000;
	}
	int col = 1;
	if(flag.color == 1) {
		col = 6;
	}
	while(1) {
		int key = getch();
		flag_switch(key);
		a = flag_speed(key, a);
		if(flag.color == 1 && key == 99) {
		//	attroff(COLOR_PAIR(col));
                        col = rand_value(6, 1);
		}
		for(int i = 0; i < columns; i++) {
			if(rows_in_column[i] == -1) {
				activ_column[i] = rand_value(4, 0);
				rows_in_column[i] = rand_value(rows, 0);
			}
		}
		for(int i = 0; i < columns; i++) {
			if(activ_column[i] == 1) {
				attrset(COLOR_PAIR(2));
				mvprintw(rows_in_column[i], i, "%lc", rand_value(max, min));
				attron(COLOR_PAIR(col));
			//	bkgd(COLOR_PAIR(col) | A_BOLD);
                    		mvprintw(rows_in_column[i] - 1, i, "%lc", rand_value(max, min));
			}
			else {
				mvprintw(rows_in_column[i], i, "%c", ' ');
			}
			rows_in_column[i]++;
			if(rows_in_column[i] > rows) {
				rows_in_column[i] = -1;
			}
		}
		refresh();
		usleep(a);
	}
}
