#pragma once
#include <stdint.h>

#ifndef WALLSIZE    // Set Wallsize to 20 if not set
#define WALLSIZE 20 // Wallsize is the wall dimension
#endif

#ifndef TPS // Set TPS if not set
#define TPS 50 // TPS is the amount of tick per seconds
#endif

#define LEFT 279168  // ID of left arrow
#define RIGHT 279167 // ID of right arrow
#define QUIT 113     // ID of Q key

int16_t cursor;  // The cursor (player) position
int16_t level[]; // Current level on screen
int32_t score;   // Player score (each level)

void init_game(int)      // Initialize game level and player position
void update_level();     // Generate another line of the level
void update_cursor(int); // Update cursor according to player move
void is_gameover();      // Check if the player lost

