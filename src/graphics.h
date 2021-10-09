#pragma once
#include "game.h"

#define CURSOR "^"  // Cursor character

extern int trail[CURSOR_HEIGHT]; // Trail effect on cursor

void init_colors();            // Init colors
void show_line(int, int, int); // Show a single line of the level
void show_level();             // Show the whole level
void show_cursor();            // Show the cursor (player)

