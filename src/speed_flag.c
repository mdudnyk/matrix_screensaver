#include "header.h"

int flag_speed(int key, int a) {
	int b;
	if(key == 114) {
		if(a < 5000) {
			return 60000;
		}
		b = a/2;
		return b;
	}
	return a;
}
