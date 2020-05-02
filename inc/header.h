#ifndef HEADER
#define HEADER

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

struct flags_check {
	int screensaver;
	int speed;
	int color;
	int japan;
} flag;

int flag_speed(int key, int a);
void flag_switch(int key);
void errors(int argc, char **argv);
void matrix_rain(void);
void wake_up(void);
int mx_strlen(const char *s);
void mx_printerr(const char *s);

#endif
