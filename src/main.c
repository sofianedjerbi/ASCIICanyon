#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#include "main.h"
#include "game.h"
#include "graphics.h"
#include "story.h"

int main(int argc, char *argv[]) {

    initscr();             // ncurses init
    noecho();              // Don't print key inputs on screen
    cbreak();              // No need to press enter after char inputs
    keypad(stdscr, true);  // Enable keypad
    curs_set(0);           // Don't print cursor
    timeout(0);            // Don't wait for getch
    init_colors();         // Initialize colors
    srand(time(0));        // Init random seed with current time

    int key, speed = 0, tick = 0; // Loop vars

    while(!is_gameover()){
        getmaxyx(stdscr, height, width); // Get screen size
        // INPUTS
        key = getch(); // Get key inputs
        if (key > 0)
            update_cursor(key);
        // INPUTS
        // GAME MECANICS
        #ifndef HZ
        if (score % 10 == 0 && tick == 0 && speed < MAX_SPEED)
            speed++;    // Change speed
        #endif
        #ifdef WALLREDUCTION
        if (score % 100 == 0 && tick == 0 && wallsize > MIN_WALLSIZE)
            wallsize--; // Change wall size
        #endif
        #ifdef STORY
        if (score % 100 == 0 && tick == 0 && story < MAX_STORY)
            story++;    // Change speed
        #endif
        // GAME MECANICS
        // INTERFACE
        show_level();  // Print Level on screen
        show_cursor(); // Print cursor on screen
        mvprintw(0, 0, "Score: %d", score);
        #ifdef DEBUG
        mvprintw(1, 0, "Speed: %d", speed);
        mvprintw(2, 0, "Wallsize: %d", wallsize);
        #ifdef STORY
        mvprintw(3, 0, "Story: %d", story);
        #endif
        #endif
        tick++;
        #ifdef STORY
        dialogue(dialogues[story]);
        #endif
        refresh(); // Print changes on screen
        usleep(1000); // Sleep for 1 ms
        #ifdef HZ
        if(tick == 1000/HZ){ // A tick = 1 ms, HZ = per sec.
        #else
        if(tick == 100-speed) {
        #endif
            update_level(); // Add a line to the level
            tick = 0;
            erase();
        }
        // INTERFACE
    }
    erase(); // Erase everything for gameover
    #ifdef STORY
    dialogue("- DEATH -");
    #else
    dialogue("- GAME OVER -");
    #endif
    timeout(-1); // Wait for getch
    getch();
    endwin();
    return 0;
}

