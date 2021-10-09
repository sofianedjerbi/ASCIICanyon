#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "game.h"


int height;
int width;

int score = 0;
int cursor = 0;
int wallsize = WALLSIZE+2;
int size[512] = {[0 ... 511] = WALLSIZE};
int level[512] = {[0 ... 511] = -WALLSIZE/2};

/* Init global vars
 * - h: height of the terminal
 * - w: width of the terminal */
void init_game(int h, int w){
    height = h;
    width = w;
}

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
    if ((level[CURSOR_HEIGHT] == cursor) ||  // Left border
        (level[CURSOR_HEIGHT] + size[CURSOR_HEIGHT] == cursor)) // Right border
        return true;
    return false;
}

/* Add a new line to the level on the top of the screen */
void update_level(){
    for(int i=0; i<height; i++){
        size[i] = size[i+1];
        level[i] = level[i+1];
    }
    size[height] = wallsize;         // Change wall size
    level[height] += rand() % 3 - 1; // Change wall position
    score++;
}

