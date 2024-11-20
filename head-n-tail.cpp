#include <ncurses.h>
#include <utility>

int main() {
    initscr();
    noecho();
    halfdelay(1);

    std::pair<int, int> position;
    std::pair<int, int> tail_position;

    getbegyx(stdscr, position.first, position.second);


    char head{'@'};
    addch(head);
    refresh();
    char tail{'#'};
    mvaddch(position.first, position.second - 1, tail);
    

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

        switch (direction)
        {
        case KEY_UP:
            tail_position.first = position.first + 1;
            tail_position.second = position.second;
            break;
        case KEY_DOWN:
            tail_position.first = position.first - 1;
            tail_position.second = position.second;
            break;
        case KEY_LEFT:
            tail_position.first = position.first;
            tail_position.second = position.second + 1;
            break;
        case KEY_RIGHT:
            tail_position.first = position.first;
            tail_position.second = position.second - 1;
            break;
        }

        
        clear();
        mvaddch(position.first, position.second, head);
        mvaddch(tail_position.first, tail_position.second, tail);
        refresh();
    }   

    getch();

    endwin();
}