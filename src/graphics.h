#pragma once
#include "game.h" // Global var access

// Line str for printing (*          *)
char[WALLSIZE] line = {[0] = '*',
                       [1 ... WALLSIZE-2] = ' ',
                       [WALLSIZE-1] = '*' };

void show_level(int);
void show_player(int);

