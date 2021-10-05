#include <stdbool.h>
#include <ncurses.h>


int main(int argc, char *argv[]) {
    
    initscr(); // On initialise ncurses
    noecho(); // On affiche pas la frappe des touches
    cbreak(); // Pas besoin d'appuyer sur entrée pour saisir les chars

    while(1){
        printw("%d", getch());
        refresh();
    }

    endwin();

    return 0;
}
