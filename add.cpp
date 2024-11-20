#include <ncurses.h>
#include <vector>
#include <array>

int main() {
    initscr();
    noecho();

    WINDOW *game_board = newwin(30, 80, 10, 10);
    box(game_board, 0, 0);
    refresh();
    wrefresh(game_board);

    char snake{'@'};
    mvwaddch(game_board, 1, 1, snake);

    std::vector<std::array<int, 2>> positions;
    int x_current_value;
    int y_current_value;
    getbegyx(game_board, y_current_value, x_current_value);

    positions.push_back({y_current_value, x_current_value});

    int input{wgetch(game_board)};



    getch();

    endwin();
}