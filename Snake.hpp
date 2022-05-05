#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <windows.h>

class Snake {
    COORD position;
    int direction;
    int score;

    public:
        Snake();
        int getScore();
        void erase();
        void draw();
        void move();
};

#endif