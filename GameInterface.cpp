#include "GameInterface.hpp"
#include "HandleConsole.hpp"
#include <cstdio>
#include <cstdlib>
#include <windows.h>

void drawGameInterface() {
    system("cls");

    updateGameInterface(0);
    drawLeftAndRightWalls();
    drawSuperiorAndInferiorWalls();
    
}

void drawSuperiorAndInferiorWalls() {
    const int SUPERIOR_WALL_POSITION = UP_SPACING;
    const int INFERIOR_WALL_POSITION = UP_SPACING + INTERFACE_HEIGHT;
    const char WALL_ICON = 219;

    for (int i = 0; i <= INTERFACE_WIDTH; i++) {
        gotoxy(LEFT_SPACING + i, SUPERIOR_WALL_POSITION);
        printf("%c", WALL_ICON);

        gotoxy(LEFT_SPACING + i, INFERIOR_WALL_POSITION);
        printf("%c", WALL_ICON);
    }
}

void drawLeftAndRightWalls() {
    const int LEFT_WALL_POSITION = LEFT_SPACING;
    const int RIGHT_WALL_POSITION = LEFT_SPACING + INTERFACE_WIDTH;
    const char WALL_ICON = 219;

    for (int i = 1; i < INTERFACE_HEIGHT; i++) {
        gotoxy(LEFT_WALL_POSITION, UP_SPACING + i);
        printf("%c", WALL_ICON);

        gotoxy(RIGHT_WALL_POSITION, UP_SPACING + i);
        printf("%c", WALL_ICON);
    }
}

void updateGameInterface(int score) {
    COORD scorePosition;
    scorePosition.X = LEFT_SPACING;
    scorePosition.Y = UP_SPACING - 2;

    gotoxy(scorePosition.X, scorePosition.Y);
    printf("Score: %d", score);
}