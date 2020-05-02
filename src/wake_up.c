#include "header.h"

void wake_up(void) {
	int key;
	const char start_phrases[][25] = {"Wake up , Neo",
		                          "The Matrix has you",
		                          "Follow the white rabbit",
		                          "Knock, knock, Neo"
		                         };
	for(int i = 0; i < 4; i++) {
		move(4, 7);
		for(int j = 0; j < mx_strlen(start_phrases[i]); j++) {
			key = getch();
			flag_switch(key);
			printw("%c",start_phrases[i][j]);
	        refresh();
	        usleep(80000);
		}
		if(i == 0 || i == 1) {
			move(4, mx_strlen(start_phrases[i]) + 7);
			usleep(100000);
			addch('.');
			refresh();
			usleep(300000);
			addch('.');
			refresh();
		}
		usleep(200000);
		clear();
		usleep(300000);
	}
	usleep(500000);
	clear();
	refresh();
	return;
}
