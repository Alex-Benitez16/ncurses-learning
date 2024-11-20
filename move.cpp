#include <ncurses.h>
#include <utility>

int main() {
    initscr();
    noecho();

    std::pair<int, int> position;

    getbegyx(stdscr, position.first, position.second);

    printw("@");
    refresh();

    while (true)
    {
        keypad(stdscr, true);
        int input = getch();
        
        if(input == KEY_DOWN) {
            position.first = position.first + 1;
        } else if(input == KEY_UP) {
            position.first = position.first - 1;
        } else if(input == KEY_RIGHT) {
            position.second = position.second + 2;
        } else if(input == KEY_LEFT) {
            position.second = position.second - 2;
        }

        mvprintw(position.first, position.second, "@");
        refresh();
    }
    

    getch();

    endwin();
}