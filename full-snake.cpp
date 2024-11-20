#include <ncurses.h>
#include <chrono>
#include <thread>
#include <deque>
#include <array>

class Tail {
    private:
        std::deque<std::array<int, 2>> body;
        char character;
    public:
        Tail(char set_character, int y, int x) {
            character = set_character;
            body.push_back({y, x - 1});
            body.push_back({y, x - 2});
            body.push_back({y, x - 3});
        }

        void move(int new_y, int new_x) {
            mvaddch(body.back().at(0), body.back().at(1), ' ');
            body.pop_back();
            body.push_front({new_y, new_x});
            mvaddch(body.front().at(0), body.front().at(1), character);
        }

};

class Snake {
    private: 
        int x;
        int y;
        char head;
        Tail tail;
    public:
        Snake(int set_x, int set_y, char set_head):
            x{set_x}, y{set_y}, head{set_head},
            tail{'#', set_y, set_x}{};

        int get_x() { return x; }
        int get_u() { return y; }

        void move(int new_y, int new_x) {
            mvaddch(y, x,' ');
            tail.move(y,x);
            x = new_x;
            y = new_y;
            mvaddch(y, x, head); 
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
    noecho();
    nodelay(stdscr, TRUE);
    cbreak();
    keypad(stdscr, true);

    Snake my_snake(4, 1, '@');

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
                my_snake.move_up();
                break;
            case KEY_DOWN:
                my_snake.move_down();
                break;
            case KEY_RIGHT:
                my_snake.move_right();
                break;
            case KEY_LEFT:
                my_snake.move_left();
                break;
            }

            last_move = current_time;
            refresh();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    endwin();
}