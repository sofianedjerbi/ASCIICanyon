#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <math.h> // Floor/ceil

#include "game.h"


int height;
int width;

int score = 0;
int cursor = 0;
int wallsize = WALLSIZE+1;
int size[512] = {[0 ... 511] = WALLSIZE};
int level[512] = {[0 ... 511] = -WALLSIZE/2};
int trail[CURSOR_HEIGHT] = {0};

/* Update cursor with keyboard inputs
 * - key: key id */
void update_cursor(int key){
    if (key == KEY_RIGHT)
        cursor++;
    else if (key == KEY_LEFT)
        cursor--;
}

/*  Check if the game is finished */
bool is_gameover(){
    if ((level[CURSOR_HEIGHT] >= cursor) ||  // Left border
        (level[CURSOR_HEIGHT]+size[CURSOR_HEIGHT]-1 <= cursor)) // Right
        return true;
    return false;
}

/* Add a new line to the level on the top of the screen */
void update_level(){
    for(int i=0; i<height; i++){ // Update level and wallsize
        size[i] = size[i+1];
        level[i] = level[i+1];
    }
    for(int i=0; i<CURSOR_HEIGHT-1; i++) // Update trail effect
        trail[i] = trail[i+1];
    trail[CURSOR_HEIGHT-1] = cursor; // New trail
    size[height] = wallsize;         // Change wall size
    level[height] += rand() % 3 - 1; // Change wall position
    if (level[height] > floor(width/2)-wallsize)
        level[height] -= 1;          // Don't cross the terminal (right)
    else if (level[height] < ceil(-width/2))
        level[height] += 1;          // Don't cross the terminal (left)
    score++;
}

