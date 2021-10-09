#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#include "main.h"
#include "game.h"
#include "graphics.h"


int main(int argc, char *argv[]) {

    initscr(); // ncurses init
    noecho();  // Don't print key inputs on screen
    cbreak();  // No need to press enter after char inputs
    keypad(stdscr, true);  // Enable keypad
    curs_set(0);           // Don't print cursor
    nodelay(stdscr, true);

    int height, width, key, speed = 0, tick = 0;
    struct timespec spec;

    getmaxyx(stdscr, height, width); // Get screen size
    init_game(height, width);        // Initialize game vars
    init_colors();                   // Initialize colors

    while(!is_gameover()){
        // INPUTS
        key = getch(); // Get key inputs
        if (key > 0)
            update_cursor(key);
        // INPUTS
        // GAME MECANICS
        if (score % 10 == 0 && tick == 0 && speed < MAX_SPEED)
            speed++;    // Change speed
        if (score % 100 == 0 && tick == 0 && wallsize > MIN_WALLSIZE)
            wallsize--; // Change wall size
        // GAME MECANICS
        // INTERFACE
        show_level();  // Print Level on screen
        show_cursor(); // Print cursor on screen
        mvprintw(0, 0, "Score: %d", score);
        mvprintw(1, 0, "Speed: %d", speed);
        mvprintw(2, 0, "Wallsize: %d", wallsize);
        tick++;
        refresh(); // Print changes on screen
        usleep(5000); // Sleep for 5 ms
        if(tick == 100-speed) {
            update_level(); // Add a line to the level
            erase();
            tick = 0;
        }
        // INTERFACE
    }

    endwin();
    return 0;
}

