#include "Snake.hpp"
#include "HandleConsole.hpp"
#include <cstdio>
#include <conio.h>

Snake::Snake() {
    this->position.X = INTERFACE_CENTER_X;
    this->position.Y = INTERFACE_CENTER_Y;
    this->score = 0;
}

int Snake::getScore() {
    return this->score;
}

void Snake::erase() {
    gotoxy(this->position.X, this->position.Y);
    printf(" ");
}

void Snake::draw() {
    gotoxy(this->position.X, this->position.Y);
    printf("0");
}

void Snake::move() {
    erase();

    if (kbhit()) {
        int keyPressed = getch();

        if (keyPressed == 0 || keyPressed == 224)
            this->direction = 256 + getch();
    }

    switch (direction) {
        case LEFT_KEY:
            this->position.X--;
            break;

        case RIGHT_KEY:
            this->position.X++;
            break;

        case UP_KEY:
            this->position.Y--;
            break;

        case DOWN_KEY:
            this->position.Y++;
            break;
    }

    draw();
    Sleep(150);
}