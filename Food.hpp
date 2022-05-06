#ifndef FOOD_HPP
#define FOOD_HPP

#include <windows.h>

class Food {
    COORD position;

    public:
        Food();
        COORD getPosition();
        void setRandomPosition();
        void erase();
        void draw();
        void spawn();
};

#endif