#pragma once
#include "game.h"

#ifndef CURSOR
#define CURSOR "^"  // Cursor Character
#endif

#ifndef TRAIL
#define TRAIL "|"   // Trail character
#endif

#ifndef WALL
#define WALL '|'   // Wall character
#endif

void init_colors();            // Init colors
void show_line(int, int, int); // Show a single line of the level
void show_level();             // Show the whole level
void show_cursor();            // Show the cursor (player)
void dialogue();               // Show a dialogue on screen
