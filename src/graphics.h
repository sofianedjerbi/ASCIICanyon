#pragma once
#include "game.h"

#define CURSOR "^"

extern int trail[CURSOR_HEIGHT];

void init_colors();
void show_line(int, int, int);
void show_level();
void show_cursor();

