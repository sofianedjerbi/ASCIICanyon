#include<stdlib.h>
#include<ncurses.h>

#include "game.h"
#include "graphics.h"


/* Insert a line of size n (4 -> *  *) into the string s */
char insert_line(char s[], int n){
    s[0] = '*'; s[n-1] = '*' ; s[n] = '\0';
    for(int i=1; i < n-1; i++)
        s[i] = ' ';
}


/* Show a single line of the level
 * width: the terminal width
 * pos: the height of the line
 * siz: size of the line
 * dec: the position relative to the middle of the terminal */
void show_line(int pos, int siz, int dec) {
    char line[WALLSIZE + 2];
    insert_line(line, siz);
    mvprintw(pos, width/2+dec, line);
}

/* Show the whole level
 * width: terminal width
 * height: terminal height
 * level: level int tab */
void show_level() {
    for(int i=0; i<height; i++)
        show_line(height-i, size[i], level[i]);
}

/* Show the cursor (player) on screen
 * width: terminal width
 * height: terminal height
 * pos: middle-relative position */
void show_cursor() {
    mvprintw(height-CURSOR_HEIGHT, width/2+cursor, CURSOR);
}

