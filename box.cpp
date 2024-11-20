#include <ncurses.h>

int main() {
    initscr();

    WINDOW * win{newwin(10, 20, 20, 20)};
    refresh();

    box(win, '#', '#');
    wrefresh(win);

    getch();

    endwin();
}