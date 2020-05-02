#include "header.h"
                                                     //function checks of it is basic or creative mode
int argc_err(int argc) {
	if(argc == 1) {
		return 0;
	}
	return 1;
}
                                                     //function checks if entered flag is correct
void flag_err(int argc, char *argv[]) { 
	int len;
	int temp;
	int f = 4;                                   // program flags count, you have to put it here manual
        char flags[4] = {
		's', 		                     //number 1    screen saver
		'r',  		                     //number 2    speed run
		'c',
		'j'		                     //number 3    color
	       };                                 
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			len = mx_strlen(argv[i]);
			for(int j = 1; j < len; j++) {
				temp = 0;
				for(int k = 0; k < f; k++) {
					if(argv[i][j] != flags[k]){
						temp++;				
					}
				}
				if(temp == f) {
					mx_printerr("race05: illegal option -- ");
                        		mx_printerr(&argv[i][j]);
                        		mx_printerr("\n");
                        		mx_printerr("usage: ./race05 [-flag]\n");
					exit(1);
				}
			}
		}
		else {
			mx_printerr("race05: illegal option -- ");
			mx_printerr(&argv[i][0]);
			mx_printerr("\n");
			mx_printerr("usage: ./race05 [-flag]\n"); 
			exit(1);
		}
	} 
	for(int i = 1; i < argc; i++) {
        	len = mx_strlen(argv[i]);
                for(int j = 1; j < len; j++) {       
	      		if(argv[i][j] == flags[0]) {				 // in case of new flags needs to chagne manualy
				flag.screensaver = 1;
			}
			if(argv[i][j] == flags[1]) {
				flag.speed = 1;
			}
			if(argv[i][j] == flags[2]) {
                                flag.color = 1;
                        }
            if(argv[i][j] == flags[3]) {
                                flag.japan = 1;
                        }
		}
	}
	return;
}
						             // main error function
void errors(int argc, char **argv) {
	if (argc_err(argc) == 0) {
 		return;                                    //if program was started without flags in BASIC mode 
	}
	flag_err(argc, argv);
	return;
}
