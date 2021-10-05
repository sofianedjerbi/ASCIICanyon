#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "game.h"

/* Initialize game
 * - height: height of the terminal */
void init_game(int height){
    int16_t cursor = 0;
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

