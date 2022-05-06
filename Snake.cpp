#include "Snake.hpp"
#include "HandleConsole.hpp"
#include <cstdio>
#include <conio.h>

Snake::Snake(int velocity) {
    setVelocity(velocity);
    setDefaultProperties();
}

int Snake::getScore() {
    return this->score;
}

void Snake::setDefaultPosition() {
    this->position.X = INTERFACE_CENTER_X;
    this->position.Y = INTERFACE_CENTER_Y;
}

void Snake::setDefaultScore() {
    this->score = 0;
}

void Snake::setDefaultProperties() {
    setDefaultPosition();
    setDefaultScore();
}

void Snake::setVelocity(int velocity) {
    if (velocity >= 1 && velocity <= 10) {
        this->velocity = (-200 / 9 * velocity) + (2450 /9);
    } else {
        velocity = 5;
        this->velocity = (-200 / 9 * velocity) + (2450 /9);
    }
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
    Sleep(this->velocity);
}

bool Snake::hasCollidedWithWall() {
    bool collidDetected = false;

    collidDetected = this->position.X <= LEFT_SPACING || this->position.X >= LEFT_SPACING + INTERFACE_WIDTH
    || this->position.Y <= UP_SPACING || this->position.Y >= UP_SPACING + INTERFACE_HEIGHT;

    return collidDetected;
}