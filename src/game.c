#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "game.h"

/* Initialize game
 * - height: height of the terminal */
void init_game(int height){
    int16_t cursor = 0;
    int16_t size = height;
    int16_t level[height];
    for(int i=0; i<height; i++)
        level[i] = -WALLSIZE/2;
}

/* Update cursor with keyboard inputs
 * - key: key id */
void update_cursor(int key){
    if (key == RIGHT)
        cursor++;
    else if (key == LEFT)
        cursor--;
}

/*  Check if the game is finished */
bool is_gameover(){
    for(int i=0; i<size; i++)
        if (level[i] == cursor)
            return true;
    return false;
}

void update_level(){
    for(int i=0; i<size; i++)
        level[i] = level[i+1];
    level[size] = rand() % 3 - 1;
}

