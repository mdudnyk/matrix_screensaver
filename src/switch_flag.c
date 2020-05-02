#include "header.h"

void flag_switch(int key) {
	if(flag.screensaver == 1) {
		if(key != ERR) {
			clear();
			endwin();
			exit(0);
		}
	}
	else {
		if(key == 113) {
			clear();
			endwin();
			exit(0);
		}
	}
	return;
}
