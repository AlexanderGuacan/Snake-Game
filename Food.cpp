#include "Food.hpp"
#include "HandleConsole.hpp"
#include <ctime>
#include <cstdio>

Food::Food() {
    srand(time(NULL));

    setRandomPosition();
}

COORD Food::getPosition() {
    return this->position;
}

void Food::setRandomPosition() {
    this->position.X = LEFT_SPACING + 1 + rand() % (INTERFACE_WIDTH - 1);
    this->position.Y = UP_SPACING + 1 + rand() % (INTERFACE_HEIGHT - 1);

}

void Food::erase() {
    gotoxy(this->position.X, this->position.Y);
    printf(" ");
}

void Food::draw() {
    const char FOOD_ICON = 254;
    gotoxy(this->position.X, this->position.Y);
    printf("%c", FOOD_ICON);
}

void Food::spawn() {
    erase();
    draw();
}