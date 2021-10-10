#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "game.h"
#include "graphics.h"


// Init colors pairs
void init_colors(){
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
}

/* Insert a line of size n (4 -> *  *) into the string s */
void insert_line(char s[], int n){
    s[0] = '|'; s[n-1] = '|' ; s[n] = '\0';
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
    for(int i=0; i<=height; i++){
        attron(COLOR_PAIR(size[i]%3 + 1));
        show_line(height-i, size[i], level[i]);
        attroff(COLOR_PAIR(size[i]%3 + 1));
    }
    for(int i=0; i<CURSOR_HEIGHT; i++){
        mvprintw(height-i, width/2+trail[i], TRAIL);
    }
}

/* Show the cursor (player) on screen
 * width: terminal width
 * height: terminal height
 * pos: middle-relative position */
void show_cursor() {
    mvprintw(height-CURSOR_HEIGHT, width/2+cursor, CURSOR);
}

/* Game Over screen */
void gameover() {
    mvprintw(height/2, width/2-7, "- GAME OVER -");
}

/* Print a dialogue on the screen
 * txt: Dialogue printed on screen */
void dialogue(char txt[]) {
    int w = width/2 - strlen(txt)/2 - 1; // Width position
    mvprintw(height/2, w, txt);
}

