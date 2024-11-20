#include "ncurses.h"
#include <chrono>
#include <thread>

struct Object {
    char character;
    int x;
    int y;

    void move(int new_y, int new_x) {
        mvaddch(y, x, ' ');
        x = new_x;
        y = new_y;
        mvaddch(y, x, character);
    }

    void move_up() {
        move(y - 1, x);
    }
    void move_down() {
        move(y + 1, x);
    }
    void move_right() {
        move(y, x + 2);
    }
    void move_left() {
        move(y, x - 2);
    }
};

int main() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);

    Object head = {'@', 1, 1};

    int input;
    int direction = KEY_RIGHT;

    const int MOVE_DELAY = 100;
    auto last_move = std::chrono::steady_clock::now();

    while(true) {
        input = getch();
        if(input != ERR) {
            switch(input) {
            case KEY_RIGHT:
                direction = KEY_RIGHT;
                break;
            case KEY_LEFT:
                direction = KEY_LEFT;
                break;
            case KEY_UP:
                direction = KEY_UP;
                break;
            case KEY_DOWN:
                direction = KEY_DOWN;
                break;
            }
        }

        auto current_time = std::chrono::steady_clock::now();
        auto time_since_last_move = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_move).count();

        if(time_since_last_move >= MOVE_DELAY) {
            switch(direction) {
            case KEY_UP:
                head.move_up();
                break;
            case KEY_DOWN:
                head.move_down();
                break;
            case KEY_RIGHT:
                head.move_right();
                break;
            case KEY_LEFT:
                head.move_left();
                break;
            }

            last_move = current_time;
            refresh();
        }
        // Small sleep to prevent CPU hogging
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    endwin();

}