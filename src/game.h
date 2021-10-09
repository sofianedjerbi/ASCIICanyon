#pragma once

#include <stdbool.h>

#ifndef WALLSIZE    // Set Wallsize to 20 if not set
#define WALLSIZE 20 // Wallsize is the wall dimension
#endif

#ifndef TPS    // Set TPS if not set
#define TPS 50 // TPS is the amount of tick per seconds
#endif

#ifndef CURSOR_HEIGHT   // Set Cursor height if not set
#define CURSOR_HEIGHT 7 // Line of the cursor
#endif

extern int cursor;      // The cursor (player) position
extern int height;      // Height of the window
extern int width;       // Width of the window
extern int score;       // Player score (each level)
extern int wallsize;    // Dynamic size of the wall
extern int size[512];   // size[i] is the size of the wallsize level[i]
extern int level[512];  // Current level on screen
extern int trail[CURSOR_HEIGHT]; // Trail effect on cursor

void init_game(int, int); // Initialize game level and player position
void update_level();      // Generate another line of the level
void update_cursor(int);  // Update cursor according to player move
bool is_gameover();       // Check if the player lost

