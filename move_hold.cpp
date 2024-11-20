#include <ncurses.h>
#include <utility>

int main() {
    initscr();
    noecho();
    halfdelay(1);

    std::pair<int, int> position;

    getbegyx(stdscr, position.first, position.second);

    printw("@");
    refresh();

    int direction = KEY_RIGHT;

    while (true)
    {
        keypad(stdscr, true);
        int input = getch();

       if(input == ERR) {
        input = direction;
       }

       switch (input)
       {
        case KEY_UP:
            position.first--;
            direction = KEY_UP;
            break;
        case KEY_DOWN:
            position.first++;
            direction = KEY_DOWN;
            break;
        case KEY_LEFT:
            position.second -= 2;
            direction = KEY_LEFT;
            break;
        case KEY_RIGHT:
            position.second += 2;
            direction = KEY_RIGHT;
            break;
       }

        mvprintw(position.first, position.second, "@");
        refresh();
    }
    

    getch();

    endwin();
}