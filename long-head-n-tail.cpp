#include <ncurses.h>
#include <array>
#include <deque>

int main() {
    initscr();
    noecho();
    keypad(stdscr, true);
    halfdelay(1);

    char head{'@'};
    char tail{'#'};

    std::array<int, 2> head_position{{1, 3}};
    std::deque<std::array<int, 2>> tail_positions{{{1, 2}, {1, 1}}};

    mvaddch(tail_positions.at(0).at(0), tail_positions.at(0).at(1), tail);
    mvaddch(tail_positions.at(1).at(0), tail_positions.at(1).at(1), tail);
    mvaddch(head_position.at(0), head_position.at(1), head);
    refresh();

    int direction{KEY_RIGHT};

    while(true) {
        int input = getch();

        mvaddch(head_position.at(0), head_position.at(1), ' ');

        if(input != ERR) {
            direction = input;
        }

        switch(direction) {
        case KEY_RIGHT:
            head_position.at(1)+= 2;
            break;

        case KEY_LEFT:
            head_position.at(1)-= 2;
            break;

        case KEY_DOWN:
            head_position.at(0)++;
            break;
        
        case KEY_UP:
            head_position.at(0)--;
            break;
        }

        mvaddch(head_position.at(0), head_position.at(1), head);
        refresh();
    }

    
}