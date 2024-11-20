#include <ncurses.h>

int main() {
    initscr();            // Initialize ncurses
    printw("Hello World"); // Print "Hello World"
    refresh();            // Refresh the screen to show output
    getch();              // Wait for user input
    endwin();             // End ncurses mode
    return 0;
}
