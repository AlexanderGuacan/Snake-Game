#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <windows.h>
#include "Food.hpp"

class Snake {
    COORD position;
    int direction;
    int score;
    int velocity;

    private:
        void setVelocity(int velocity);

    public:
        Snake(int velocity);
        int getScore();
        void setDefaultPosition();
        void setDefaultScore();
        void setDefaultProperties();
        void erase();
        void draw();
        void move();
        bool hasEating(Food food);
        bool hasCollidedWithWall();
};

#endif